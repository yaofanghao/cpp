#include "sys.h"
#include "delay.h"  
#include "usart.h"   
#include "led.h"
#include "lcd.h"
#include "key.h" 
#include "malloc.h" 
#include "tpad.h"
#include "beep.h" 
#include "adc.h"
#include "timer.h" 
#include "includes.h" 
#include "timer.h"
#include "rtc.h"
#include "spi.h"
#include "w25qxx.h"

//��Ŀ:Ƕ��ʽ��δ���ҵ
//��Ա: Ҧ���� ��� �Ŵ�Ϊ 
//����ʱ�䣺2022.1.5 LED�������Լ첻��ת������ģʽ
 
/////////////////////////UCOSII��������///////////////////////////////////
//��ʼ����
//�����������ȼ�
#define START_TASK_PRIO      				10 //��ʼ��������ȼ�����Ϊ���
//���������ջ��С
#define START_STK_SIZE  						64
//�����ջ	
OS_STK START_TASK_STK[START_STK_SIZE];
//������
void start_task(void *pdata);	

//ʵʱ��ʾ����
//�����������ȼ�
#define RTSHOW_TASK_PRIO       			8
//���������ջ��С
#define RTSHOW_STK_SIZE  						512
//�����ջ	
OS_STK RTSHOW_TASK_STK[RTSHOW_STK_SIZE];
//������
void RTshow_task(void *pdata);	

//��������
//�����������ȼ�
#define ALARM_TASK_PRIO       			7
//���������ջ��С
#define ALARM_STK_SIZE  		    		64
//�����ջ
OS_STK ALARM_TASK_STK[ALARM_STK_SIZE];
//������
void alarm_task(void *pdata);

//������
//�����������ȼ�
#define MAIN_TASK_PRIO       				6 
//���������ջ��С
#define MAIN_STK_SIZE  							512
//�����ջ	
OS_STK MAIN_TASK_STK[MAIN_STK_SIZE];
//������
void main_task(void *pdata);
				 
//�˵�����
//�����������ȼ�
#define MENU_TASK_PRIO       				5 
//���������ջ��С
#define MENU_STK_SIZE  							512
//�����ջ	
OS_STK MENU_TASK_STK[MENU_STK_SIZE];
//������
void menu_task(void *pdata);			 		 
			
//ADC�ɼ�����
//�����������ȼ�
#define ADC_TASK_PRIO								4 
//���������ջ��С
#define ADC_STK_SIZE  		 					512
//�����ջ	
OS_STK ADC_TASK_STK[ADC_STK_SIZE];
//������
void adc_task(void *pdata);

//����ɨ������
//�����������ȼ�
#define KEY_TASK_PRIO       				3 
//���������ջ��С
#define KEY_STK_SIZE  							64
//�����ջ	
OS_STK KEY_TASK_STK[KEY_STK_SIZE];
//������
void key_task(void *pdata);

/////////////////////////UCOSII�¼�����///////////////////////////////////

OS_EVENT * msg_key;					//������ֵ��Ϣ����
OS_EVENT * msg_check;				//�Լ�״̬��Ϣ����
OS_EVENT * q_msg_adc;				//8·ADCֵ��Ϣ����
OS_FLAG_GRP * flags_alarm;	//������Ϣ�ź�����


void * MsgGrp[100];					//��Ϣ���д洢��ַ,���֧��100����Ϣ

/////////////////////////ʱ��ṹ��///////////////////////////////////

RTC_DateTypeDef RTC_DateStruct;//���ڽṹ��	
RTC_TimeTypeDef RTC_TimeStruct;//ʱ��ṹ��

/////////////////////////FLASH�洢����///////////////////////////////////
#define W25Q128_SIZE 		((u32)256*1024*1024)			//W25Q128��С
#define W25Q128_ALARM		((u32)100*1024*1024)			//W25Q128�����洢��ʼ��ַ
#define W25Q128_STARTUP ((u32)100*1024*1024+3000)	//W25Q128����ʱ��洢��ַ
#define W25Q128_RESET		((u32)100*1024*1024+4100)	//W25Q128��λ��¼�洢

////////////////////////////////����///////////////////////////////////

//�Լ캯��
void self_check(u8 mode)
{
	static u16 normal[16]={6,100,200,300,400,500,600,555,444,777,666,888,999,123,456,789},
	lowalarm[16]={1100,1200,1300,1400,1500,1600,1234,1456,1789,1874,1987,1654,1321,1987,1654,1741},
	highalarm[16]={2100,2200,2300,2400,2500,2600,2700,2800,2900,3000,3100,3200,3300,3400,3500,3600};
	u8 check=1;
						
	if(mode==0)				//����ģʽ
	{
		OSMboxPostOpt(msg_check,(void*)check,OS_POST_OPT_BROADCAST);
		OSQPostOpt(q_msg_adc,(void*)normal,OS_POST_OPT_BROADCAST);
		delay_ms(490);
  }
	else if(mode==1)	//�߱�ģʽ
	{
		OSMboxPostOpt(msg_check,(void*)check,OS_POST_OPT_BROADCAST);
		OSQPostOpt(q_msg_adc,(void*)highalarm,OS_POST_OPT_BROADCAST);
		delay_ms(490);			
	}
	else if(mode==2)	//�ͱ�ģʽ
	{
		OSMboxPostOpt(msg_check,(void*)check,OS_POST_OPT_BROADCAST);
		OSQPostOpt(q_msg_adc,(void*)lowalarm,OS_POST_OPT_BROADCAST);
		delay_ms(490);				
	}
}

//��λ����
void mcuRestart(void)
{
  __set_FAULTMASK(1); //�ر������ж�
  NVIC_SystemReset(); //�����λ
}

//������
int main(void)
{ 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//����ϵͳ�ж����ȼ�����2
	delay_init(168);  								//��ʼ����ʱ����
	uart_init(115200);								//��ʼ�����ڲ�����Ϊ115200
	RTC_Set_WakeUp(RTC_WakeUpClock_CK_SPRE_16bits,0);	//����WAKE UP�ж�,1�����ж�һ��
	
	My_RTC_Init();				//��ʼ��ʱ��
	my_mem_init(SRAMIN);	//��ʼ���ڲ��ڴ�� 	
	LED_Init();				//��ʼ���й�����		
	LCD_Init();					
	BEEP_Init();					
	KEY_Init();						 
	TPAD_Init(8);				
	Adc_Init();					
	W25QXX_Init();			
	ucos_load_main_ui();	//���ؽ���

	OSInit();  	 					//��ʼ��UCOSII
  OSTaskCreate(start_task,(void *)0,(OS_STK *)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO );	//������ʼ����
	OSStart();	    
}
 
////////////////////////////////����///////////////////////////////////

//��ʼ����
//Priority:10
//post:��
//Pend:��
//Function:�������������¼�����FLASH�м�¼����ʱ��
void start_task(void *pdata)
{
  OS_CPU_SR cpu_sr=0;
	u8 Start_Rtc[4];											//����ʱ�䱣�滺����
	u8 err;	    	    
	pdata = pdata; 
	
	msg_key=OSMboxCreate((void*)0);				//����������ֵ��Ϣ����
	msg_check=OSMboxCreate((void*)0);			//�����Լ�״̬��Ϣ����
	q_msg_adc=OSQCreate(&MsgGrp[0],100);	//����8·ADCֵ��Ϣ����
 	flags_alarm=OSFlagCreate(0,&err); 		//����������Ϣ�ź�����	  
	
	//��FLASH��д�뿪��ʱ��
	RTC_GetTime(RTC_Format_BIN,&RTC_TimeStruct);	//�õ���ǰʱ��
	Start_Rtc[0] = (u8) RTC_TimeStruct.RTC_Hours;
	Start_Rtc[1] = (u8) RTC_TimeStruct.RTC_Minutes;
	Start_Rtc[2] = (u8) RTC_TimeStruct.RTC_Seconds;
	OS_ENTER_CRITICAL();									//�����ٽ���(�޷����жϴ��)   
	W25QXX_Write(Start_Rtc,W25Q128_STARTUP,3);		//д��FLASH
	OS_EXIT_CRITICAL();										//�˳��ٽ���(���Ա��жϴ��)
	
	OSStatInit();													//��ʼ��ͳ������.�������ʱ1��������	
 	OS_ENTER_CRITICAL();									//�����ٽ���(�޷����жϴ��)    
 	OSTaskCreate(RTshow_task,(void *)0,(OS_STK*)&RTSHOW_TASK_STK[RTSHOW_STK_SIZE-1],RTSHOW_TASK_PRIO);	//����ʵʱ��ʾ����
	OSTaskCreate(alarm_task,(void *)0,(OS_STK*)&ALARM_TASK_STK[ALARM_STK_SIZE-1],ALARM_TASK_PRIO);			//������������
 	OSTaskCreate(main_task,(void *)0,(OS_STK*)&MAIN_TASK_STK[MAIN_STK_SIZE-1],MAIN_TASK_PRIO);					//����������
 	OSTaskCreate(menu_task,(void *)0,(OS_STK*)&MENU_TASK_STK[MENU_STK_SIZE-1],MENU_TASK_PRIO);					//�����˵�����
	OSTaskCreate(adc_task,(void *)0,(OS_STK*)&ADC_TASK_STK[ADC_STK_SIZE-1],ADC_TASK_PRIO);							//����ADC�ɼ�����
 	OSTaskCreate(key_task,(void *)0,(OS_STK*)&KEY_TASK_STK[KEY_STK_SIZE-1],KEY_TASK_PRIO);	 				 	 	//��������ɨ������
 	OSTaskSuspend(START_TASK_PRIO);				//����ʼ����
	OS_EXIT_CRITICAL();										//�˳��ٽ���(���Ա��жϴ��)
}

//ʵʱ��ʾ����
//Priority:8
//post:��
//Pend:q_msg_adc
//Function:ʵʱ��ʾ��ǰ8·ADCֵ��״̬
void RTshow_task(void *pdata)
{
	u16* data;							//��ѹֵ�洢����
	u8 err;		
	u8 i;	
	u8 low_alarm;						//�ͱ�·��
	u8 high_alarm;					//�߱�·��
	// u8 fault;								//����·��
	data = (u16*)mymalloc(SRAMIN,32);				//���붯̬�ڴ�32�ֽ�
	
	while(1)
	{	
		low_alarm=0;					//�ͱ�·������
		high_alarm=0;					//�߱�·������
		// fault=0;							//����·������
		
		data=OSQPend(q_msg_adc,0,&err);								//�����ѹֵ��Ϣ���У�����Ҫ���޵ȴ�
		
		for(i=0;i<8;i++)
		{	
			LCD_ShowxNum(82,50+20*i,data[i],4,16,0X80);	//��ʾ8·ADC��ѹֵ
		
			if(500<data[i] && data[i]<=1000)
			{
				low_alarm++;
				LCD_ShowString(150,50+20*i,200,16,16,"Low Alarm ");				
			}			
			else if(data[i]>1000)
			{
				high_alarm++;
				LCD_ShowString(150,50+20*i,200,16,16,"High Alarm");					
			}	
		}		
		myfree(SRAMIN,data);	//�ͷ��ڴ�
		
		LCD_ShowxNum(154,450,low_alarm,2,16,0);						//��ʾ�ͱ�·��
		LCD_ShowxNum(154,470,high_alarm,2,16,0);					//��ʾ�߱�·��		
		
		RTC_GetDate(RTC_Format_BIN, &RTC_DateStruct);			//��ȡ����
		RTC_GetTime(RTC_Format_BIN,&RTC_TimeStruct);			//��ȡʱ��
		
		LCD_ShowString(10,600,200,16,16,"20  .  .  ");							//��ʾ��ע
		LCD_ShowxNum(10+2*8,600,RTC_DateStruct.RTC_Year,2,16,0);		//��ʾ��
		LCD_ShowxNum(10+5*8,600,RTC_DateStruct.RTC_Month,2,16,0);		//��ʾ��
		LCD_ShowxNum(10+8*8,600,RTC_DateStruct.RTC_Date,2,16,0);		//��ʾ��
		
		LCD_ShowString(100,600,200,16,16,"  :  :  ");								//��ʾ��ע		
		LCD_ShowxNum(100,600,RTC_TimeStruct.RTC_Hours,2,16,0);			//��ʾʱ
		LCD_ShowxNum(100+3*8,600,RTC_TimeStruct.RTC_Minutes,2,16,0);//��ʾ��
		LCD_ShowxNum(100+6*8,600,RTC_TimeStruct.RTC_Seconds,2,16,0);//��ʾ��		
		
		delay_ms(100);
	}
}

//��������
//Priority:7
//post:��
//Pend:flags_alarm
//Function:�������󵽵�״̬��Ϣ������LED��BEEP������Ӧ����
void alarm_task(void *pdata)
{	
    u16 flags;	
	  u8 err;	
	
	  while(1)
	  {
		    flags=OSFlagPend(flags_alarm,0X000F,OS_FLAG_WAIT_SET_ANY,0,&err);	//�ȴ��ź�����

			  if(flags&0X0004)	//�߱� 10HZ������LED1��
		    {
				  LED0=1;
					LED1=0;
					
			    BEEP=1;
			    delay_ms(50);
			    BEEP=0;
			    delay_ms(50); 	  	
		    }
			  else if(flags&0X0002)	//�ͱ� 1HZ������LED1��
			  {	
				  LED0=1;
					LED1=0;	
					
			    BEEP=1;
			    delay_ms(500);
			    BEEP=0;
		 	    delay_ms(500);    
			  }	 
		    else if(flags&0X0001 || flags&0X0000)	//����״̬��Ĭ��״̬
		    {
			    LED1=1;
			    LED0=1;
					
					BEEP=0;	    
			    delay_ms(10);	
		    }
			delay_ms(100);	
 	}					 							 
}

//������
//Priority:6
//post:flags_alarm
//Pend:msg_check��q_msg_adc
//Function:�����жϵ�ǰ8·ADCֵ�������жϡ���ʾ��ǰ����״̬������״̬��Ϣ����FLASH�м�¼������Ϣ��ͨ���š�ʱ�䣩��������Ϣ��ͨ���š��߱�/�ͱ���ʱ�䡢����ֵ����������Ϣ�����͡�ʱ�䣩
void main_task(void *pdata)
{		
	OS_CPU_SR cpu_sr=0;
	u16* data;							//��ѹֵ�洢����
	u8  Alarm_Type;     		//�ж�ADC��������-�ͱ����߱�������
	u16 Alarm_Point=0;   		//�ͱ�ָ��ƫ��
	u32 check;							//�Լ��־
	u8  err;
	u8 i;
	data = (u16*)mymalloc(SRAMIN,32);				//���붯̬�ڴ�32�ֽ�
	
  while(1)
	{	
		check=0;							//�Լ�״̬����
		
		check=(u32)OSMboxPend(msg_check,10,&err);	//�����Լ�״̬��Ϣ����		
	  data = OSQPend(q_msg_adc,0,&err);  				//����8·ADCֵ��Ϣ���У��������޵ȴ�

		Alarm_Type=Flags_Type(data,500,1000,5,3900);	//��8·ͨ��ADCֵ������� 1:���� 2:�ͱ� 3:�߱�	 
		
		if (Alarm_Type == 0)			//Ĭ��״̬
		{	
			 OSFlagPost(flags_alarm,0x000F,OS_FLAG_CLR,&err);
		}	
    else if (Alarm_Type == 1)	//����״̬			
		{	
			 OSFlagPost(flags_alarm,0x000F,OS_FLAG_CLR,&err);
			 OSFlagPost(flags_alarm,0x0001,OS_FLAG_SET,&err);//�����ź�����0001
		}		
	  else if (Alarm_Type == 2)	//���ޱ���
		{	
			OSFlagPost(flags_alarm,0x000F,OS_FLAG_CLR,&err);						
			OSFlagPost(flags_alarm,0x0002,OS_FLAG_SET,&err);  //�����ź�����0010
		}				
    else if (Alarm_Type == 3)	//���ޱ���
		{
			OSFlagPost(flags_alarm,0x000F,OS_FLAG_CLR,&err);						
			OSFlagPost(flags_alarm,0x0004,OS_FLAG_SET,&err);  //�����ź�����0100
		}   				
		delay_ms(100);
		
			
		if(check != 1)//���������Լ�״̬
		{
			//��FLASH��д�뱨����������Ϣ
			for (i=0; i<8; i++)
			{			
				if(1000<data[i] && data[i]<=2000)
					{	
						OS_ENTER_CRITICAL();  //�����ٽ���
						if((Save_Alarm(1,i, data[i]>>8,data[i],W25Q128_ALARM+Alarm_Point))==0)
							{
								Alarm_Point=Alarm_Point+7;  //ָ��ƫ����
								if (Alarm_Point >1400) 
									Alarm_Point = 0;  //�洢�㹻200��ʱ���¸���
								}
							OS_EXIT_CRITICAL();		//�˳��ٽ���(���Ա��жϴ��)
								delay_ms(10);
					}
					else if(2000<data[i] && data[i] <=3900)
					{	
						OS_ENTER_CRITICAL();  //�����ٽ���					
						if((Save_Alarm(2,i, data[i]>>8,data[i],W25Q128_ALARM+Alarm_Point))==0)
						{
							Alarm_Point=Alarm_Point+7;  //ָ��ƫ����
							if (Alarm_Point >1400) Alarm_Point = 0;  //�洢�㹻200��ʱ���¸���
						}
						OS_EXIT_CRITICAL();		//�˳��ٽ���(���Ա��жϴ��)
						delay_ms(10);
					}							 
		  }
		myfree(SRAMIN,data);								//�ͷ��ڴ�ռ�
	  }
  }		   
}
//�˵�����
//Priority:5
//post:msg_check��q_msg_adc
//Pend:msg_key
//Function:��ʾ��ʷ��Ϣ�������Լ칦�ܣ���FLASH�м�¼������Ϣ��������ʱ�䣩����FLASH�ж�ȡ��������������λ��Ϣ
void menu_task(void *pdata)
{
	u32 temp=0;				//��Ϣ���䴢��
	u8 menu=0;				//�˵�ҳ�滮�� 0:��ҳ�� 1:�鿴��ʷ��¼ 2:�����Լ칦��
	u8 cur_menu=0;		//���λ�ñ��� ��ҳ��ʹ�� 0:��ʼλ�� 1:History 2:Check

	u8 cur_history=0;	//���λ�ñ��� �鿴��ʷ��¼ҳ��ʹ�� 0:��ʼλ�� 1:����  2:�¼� 3������
	u8 cur_check=0;		//���λ�ñ��� �����Լ칦��ҳ��ʹ�� 0:��ʼλ�� 1:ȷ������
	u8 check_mode=0;	//�Լ�ģʽ���� 0:����ģʽ 1:����ģʽ 

	u8 page=0;				//��¼ҳ��
	u8 page_skip=1;		//��ҳ����
	u8 *read_data;		//��ȡ���ݻ�����
	u16 read_data_adc; //��ȡ��ѹֵ������
	u8 err;
	u8 i;
	read_data = (u8*)mymalloc(SRAMIN,8);			//���붯̬�ڴ�16�ֽ� 

	while(1)
	{
		temp=(u32)OSMboxPend(msg_key,10,&err);//���󰴼���ֵ��Ϣ����
		delay_ms(100);
		
		if(menu == 0)	 	//�˵�λ����ҳ�棬��ʱmsg_key����Ӧ�Ĳ���Ϊ  KEY0:ȷ�� KEY1:���� KEY2:����
		{			
		  LCD_ShowString(270,50,200,16,16,"1.History");			
			LCD_ShowString(270,100,200,16,16,"2.Check");
			
			if(temp ==KEY0_PRES)    					//KEY0���£�����������λ�õĲ˵�
			{
				if(cur_menu == 1)								//����鿴��ʷ��¼ҳ��
				{
					menu=1;
					LCD_Fill(250,50,lcddev.width,lcddev.height,WHITE);
				} 
				if(cur_menu == 2)								//���������Լ칦��ҳ��
				{
					menu=2;		
					LCD_Fill(250,50,lcddev.width,lcddev.height,WHITE);				
				}
			}
			
			if(temp == KEY1_PRES)							//KEY1���£���������ƶ�
			{
				if(cur_menu < 3)
				{
					LCD_ShowString(250,cur_menu*50,200,16,16,"  ");	//������ǰ����ͷ
					cur_menu++;
					if(cur_menu == 3) cur_menu = 1;									//���λ�ø�λ
					LCD_ShowString(250,cur_menu*50,200,16,16,"->");	//����ͷ������һλ
				}
			}			
		}
		
		if(menu == 1)			//�˵�λ�ڲ鿴��ʷ��¼ҳ�棬��ʱmsg_key����Ӧ�Ĳ���Ϊ  KEY0:ȷ�� KEY1:���� KEY2:����
		{
			LCD_ShowString(270,50,200,16,16,"1.History");				
			LCD_ShowString(270,100,200,16,16,"a.ALARM");	
			LCD_ShowString(270,120,200,16,16,"b.RESET");
			LCD_ShowString(270,140,200,16,16,"c.STARTUP");
			LCD_ShowString(270,160,200,16,16,"Page:     ");
			LCD_ShowString(270,180,200,16,16,"Page Skip:");			
			
			if(temp ==KEY0_PRES)    					//KEY0���£���ʾ��ǰλ�õ���ʷ��¼
			{
				if(cur_history == 1)						//��ʾ������ʷ��¼
				{
					LCD_Fill(250,220,lcddev.width,lcddev.height,WHITE);
					LCD_ShowString(250,220,250,16,16,"Time       CH   Value   Type");
					for(i=0;i<10;i++)																				//һ�ζ�ȡ10������
					{					
						W25QXX_Read(read_data,W25Q128_ALARM+page*10*7+i*7,7);	//��ȡ����
						read_data_adc=((u16)read_data[5]<<4)+read_data[6];		//��ADֵת����8λ����
						Display_Save_Time(read_data,250,240+i*20);						//ʱ��
						LCD_ShowxNum(250+11*8,240+i*20,read_data[3],2,16,0);	//ͨ����
		    	 	LCD_ShowxNum(250+16*8,240+i*20,read_data_adc,4,16,0);	//ADCֵ
						if(read_data[4] == 1) LCD_ShowString(250+24*8,240+i*20,50,16,16,"Low");
						if(read_data[4] == 2) LCD_ShowString(250+24*8,240+i*20,50,16,16,"High");
					}
					myfree(SRAMIN,read_data);			//�ͷ��ڴ�ռ�
					page=page+page_skip;
					LCD_ShowxNum(270+10*8,200,page,2,16,0);
					if(page>=10) page=0;						//10ҳ���0	
				}
				if(cur_history == 2)						//��ʾ��λ��ʷ��¼
				{
					LCD_Fill(250,220,lcddev.width,lcddev.height,WHITE);
					LCD_ShowString(250,220,250,16,16,"Time");
					W25QXX_Read(read_data,W25Q128_RESET,3);	//��ȡ����
					Display_Save_Time(read_data,250,240);		//ʱ��
					myfree(SRAMIN,read_data);								//�ͷ��ڴ�ռ�
					page=1;
					LCD_ShowxNum(270+10*8,200,page,2,16,0);
				}
				if(cur_history == 3)						//��ʾ������ʷ��¼
				{
					LCD_Fill(250,220,lcddev.width,lcddev.height,WHITE);
					LCD_ShowString(250,220,250,16,16,"Time");
					W25QXX_Read(read_data,W25Q128_STARTUP,3);		//��ȡ����
					Display_Save_Time(read_data,250,240);				//ʱ��
					myfree(SRAMIN,read_data);										//�ͷ��ڴ�ռ�
					page=1;
					LCD_ShowxNum(270+10*8,200,page,2,16,0);		
				}
			}	
			
			if(temp == KEY1_PRES)							//KEY1���£���������ƶ�
			{
				page=0;
				LCD_ShowxNum(270+10*8,200,page,2,16,0);
				if(cur_history < 4)
				{
					LCD_ShowString(250,80+cur_history*20,200,16,16,"  ");	//������ǰ����ͷ
					cur_history++;
					if(cur_history == 4) cur_history = 1;									//���λ�ø�λ
					LCD_ShowString(250,80+cur_history*20,200,16,16,"->");	//����ͷ������һλ																									//��¼ҳ������
				}
			}

			if(temp == KEY2_PRES)							//KEY2���£�����
			{
				LCD_Fill(250,50,lcddev.width,lcddev.height,WHITE);
				menu=0;													//�ص����˵�
				cur_menu=0;											//�ص������ʼλ��
				cur_history=0;									//�ص������ʼλ��
			}			
		}
		
		if(menu == 2)												//�˵�λ�������Լ칦��ҳ�棬��ʱmsg_key����Ӧ�Ĳ���Ϊ  KEY0:ȷ�� KEY1:���� KEY2:����
		{		
			LCD_ShowString(270,50,200,16,16,"2.Check");
			LCD_ShowString(270,100,200,16,16,"Start Self Check");
			
			if(temp ==KEY0_PRES)    					//KEY0���£�ִ�й������λ�ò���
			{
				if(cur_check == 1)							//�����Լ칦��
				{
					OSTaskSuspend(ADC_TASK_PRIO);	//����ADC�ɼ�����
					LCD_ShowString(270,150,200,16,16,"Checking...      ");	
					for(check_mode=0;check_mode<3;check_mode++)			//�����Լ��������
					{
						for(i=0;i<120;i++)
						{		
							self_check(check_mode);
							temp=(u32)OSMboxPend(msg_key,10,&err);//��⵽KEY1���£���������ǰforѭ������⵽KEY2���£��������Լ�
							if(temp == KEY1_PRES) break;	
							if(temp == KEY2_PRES) goto finish_check;
						}
					}
					finish_check:temp=0;					//�����ֵ����ֹ�����˳������˵�
					LCD_ShowString(270,150,200,16,16,"Finish Self Check");				
					OSTaskResume(ADC_TASK_PRIO);	//���ADC�ɼ�����
				}
			}
			
			if(temp == KEY1_PRES)							//KEY1���£���������ƶ�
			{
				
				if(cur_check < 2)
				{
					LCD_ShowString(250,80+cur_check*20,200,16,16,"  ");	//������ǰ����ͷ
					cur_check++;
					if(cur_check == 2) cur_check = 1;										//���λ�ø�λ
					LCD_ShowString(250,80+cur_check*20,200,16,16,"->");	//����ͷ������һλ
				}
			}
			
			if(temp == KEY2_PRES)						//KEY2���£�����
			{
				LCD_Fill(250,50,lcddev.width,lcddev.height,WHITE);
				menu=0;												//�ص����˵�
				cur_menu=0;										//�ص������ʼλ��	
				cur_check=0;									//�ص������ʼλ��	
			}
		}			
	}
}	
		
//ADC�ɼ�����
//Priority:4
//post:q_msg_adc
//Pend:��
//Function:��ȡ�����͵�ǰ8·ADCֵ
void adc_task(void *pdata)
{	
	OS_CPU_SR cpu_sr=0;						 			
	float vol[8];	
	u16 adcx[8];
	u16* data;
	u8 i=0;
	data = (u16*)mymalloc(SRAMIN,32);			//���붯̬�ڴ�32�ֽ�
						
	while(1)
	{	
		for(i=0;i<8;i++)
		{			
			//��ȡADC ת��Ϊ��ѹ  			
			OS_ENTER_CRITICAL();							//�����ٽ���(�޷����жϴ��)    			
			adcx[i]=Get_Adc_Average(i,5);			//��ȡ
			OS_EXIT_CRITICAL();								//�˳��ٽ���(���Ա��жϴ��)
	
			vol[i]=(float)adcx[i]*(3.3/4096); //adcx��ֵת��Ϊ��ѹֵ
			data[i]=vol[i]*1000;      
		}
		
		OSQPostOpt(q_msg_adc,(void*)data,OS_POST_OPT_BROADCAST);//���Ͷ���
		myfree(SRAMIN,data);								//�ͷ��ڴ�ռ�
		delay_ms(500);	
	}	
}

//����ɨ������
//Priority:3
//post:msg_key��sem_tpad
//Pend:��
//Function:��ȡ�����͵�ǰ��ֵ�����tpad��ִ�и�λ����
void key_task(void *pdata)
{	
	OS_CPU_SR cpu_sr=0;
	u8 key;		
	while(1)
	{
		key=KEY_Scan(0);	//��ȡ��ǰ������ֵ
		if(key==0)
		{
			if(TPAD_Scan(0)) key=5;		
		}
		if(key)OSMboxPostOpt(msg_key,(void*)key,OS_POST_OPT_BROADCAST);	//���Ͱ�����ֵ��Ϣ����	
		if(key==5)		                                   //TPAD��������FLASHд�븴λ��Ϣ
		{
			//��FLASH��д�븴λ�¼���Ϣ
			OS_ENTER_CRITICAL();									//�����ٽ���(�޷����жϴ��)   
			Save_Reset(W25Q128_RESET);   		
			OS_EXIT_CRITICAL();										//�˳��ٽ���(���Ա��жϴ��)
			mcuRestart();	//��λ
		}
 		delay_ms(10);
	}
}
