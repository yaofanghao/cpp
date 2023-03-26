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

//项目:嵌入式结课大作业
//组员: 姚方浩 李福龙 张春为 
//更新时间：2022.1.5 LED不亮，自检不跳转到正常模式
 
/////////////////////////UCOSII任务设置///////////////////////////////////
//开始任务
//设置任务优先级
#define START_TASK_PRIO      				10 //开始任务的优先级设置为最低
//设置任务堆栈大小
#define START_STK_SIZE  						64
//任务堆栈	
OS_STK START_TASK_STK[START_STK_SIZE];
//任务函数
void start_task(void *pdata);	

//实时显示任务
//设置任务优先级
#define RTSHOW_TASK_PRIO       			8
//设置任务堆栈大小
#define RTSHOW_STK_SIZE  						512
//任务堆栈	
OS_STK RTSHOW_TASK_STK[RTSHOW_STK_SIZE];
//任务函数
void RTshow_task(void *pdata);	

//报警任务
//设置任务优先级
#define ALARM_TASK_PRIO       			7
//设置任务堆栈大小
#define ALARM_STK_SIZE  		    		64
//任务堆栈
OS_STK ALARM_TASK_STK[ALARM_STK_SIZE];
//任务函数
void alarm_task(void *pdata);

//主任务
//设置任务优先级
#define MAIN_TASK_PRIO       				6 
//设置任务堆栈大小
#define MAIN_STK_SIZE  							512
//任务堆栈	
OS_STK MAIN_TASK_STK[MAIN_STK_SIZE];
//任务函数
void main_task(void *pdata);
				 
//菜单任务
//设置任务优先级
#define MENU_TASK_PRIO       				5 
//设置任务堆栈大小
#define MENU_STK_SIZE  							512
//任务堆栈	
OS_STK MENU_TASK_STK[MENU_STK_SIZE];
//任务函数
void menu_task(void *pdata);			 		 
			
//ADC采集任务
//设置任务优先级
#define ADC_TASK_PRIO								4 
//设置任务堆栈大小
#define ADC_STK_SIZE  		 					512
//任务堆栈	
OS_STK ADC_TASK_STK[ADC_STK_SIZE];
//任务函数
void adc_task(void *pdata);

//按键扫描任务
//设置任务优先级
#define KEY_TASK_PRIO       				3 
//设置任务堆栈大小
#define KEY_STK_SIZE  							64
//任务堆栈	
OS_STK KEY_TASK_STK[KEY_STK_SIZE];
//任务函数
void key_task(void *pdata);

/////////////////////////UCOSII事件设置///////////////////////////////////

OS_EVENT * msg_key;					//按键键值消息邮箱
OS_EVENT * msg_check;				//自检状态消息邮箱
OS_EVENT * q_msg_adc;				//8路ADC值消息队列
OS_FLAG_GRP * flags_alarm;	//报警信息信号量集


void * MsgGrp[100];					//消息队列存储地址,最大支持100个消息

/////////////////////////时间结构体///////////////////////////////////

RTC_DateTypeDef RTC_DateStruct;//日期结构体	
RTC_TimeTypeDef RTC_TimeStruct;//时间结构体

/////////////////////////FLASH存储设置///////////////////////////////////
#define W25Q128_SIZE 		((u32)256*1024*1024)			//W25Q128大小
#define W25Q128_ALARM		((u32)100*1024*1024)			//W25Q128报警存储开始地址
#define W25Q128_STARTUP ((u32)100*1024*1024+3000)	//W25Q128开机时间存储地址
#define W25Q128_RESET		((u32)100*1024*1024+4100)	//W25Q128复位记录存储

////////////////////////////////函数///////////////////////////////////

//自检函数
void self_check(u8 mode)
{
	static u16 normal[16]={6,100,200,300,400,500,600,555,444,777,666,888,999,123,456,789},
	lowalarm[16]={1100,1200,1300,1400,1500,1600,1234,1456,1789,1874,1987,1654,1321,1987,1654,1741},
	highalarm[16]={2100,2200,2300,2400,2500,2600,2700,2800,2900,3000,3100,3200,3300,3400,3500,3600};
	u8 check=1;
						
	if(mode==0)				//正常模式
	{
		OSMboxPostOpt(msg_check,(void*)check,OS_POST_OPT_BROADCAST);
		OSQPostOpt(q_msg_adc,(void*)normal,OS_POST_OPT_BROADCAST);
		delay_ms(490);
  }
	else if(mode==1)	//高报模式
	{
		OSMboxPostOpt(msg_check,(void*)check,OS_POST_OPT_BROADCAST);
		OSQPostOpt(q_msg_adc,(void*)highalarm,OS_POST_OPT_BROADCAST);
		delay_ms(490);			
	}
	else if(mode==2)	//低报模式
	{
		OSMboxPostOpt(msg_check,(void*)check,OS_POST_OPT_BROADCAST);
		OSQPostOpt(q_msg_adc,(void*)lowalarm,OS_POST_OPT_BROADCAST);
		delay_ms(490);				
	}
}

//复位函数
void mcuRestart(void)
{
  __set_FAULTMASK(1); //关闭所有中断
  NVIC_SystemReset(); //软件复位
}

//主函数
int main(void)
{ 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//设置系统中断优先级分组2
	delay_init(168);  								//初始化延时函数
	uart_init(115200);								//初始化串口波特率为115200
	RTC_Set_WakeUp(RTC_WakeUpClock_CK_SPRE_16bits,0);	//配置WAKE UP中断,1秒钟中断一次
	
	My_RTC_Init();				//初始化时间
	my_mem_init(SRAMIN);	//初始化内部内存池 	
	LED_Init();				//初始化有关外设		
	LCD_Init();					
	BEEP_Init();					
	KEY_Init();						 
	TPAD_Init(8);				
	Adc_Init();					
	W25QXX_Init();			
	ucos_load_main_ui();	//加载界面

	OSInit();  	 					//初始化UCOSII
  OSTaskCreate(start_task,(void *)0,(OS_STK *)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO );	//创建起始任务
	OSStart();	    
}
 
////////////////////////////////任务///////////////////////////////////

//开始任务
//Priority:10
//post:无
//Pend:无
//Function:创建其他任务、事件；向FLASH中记录开机时间
void start_task(void *pdata)
{
  OS_CPU_SR cpu_sr=0;
	u8 Start_Rtc[4];											//开机时间保存缓冲区
	u8 err;	    	    
	pdata = pdata; 
	
	msg_key=OSMboxCreate((void*)0);				//创建按键键值消息邮箱
	msg_check=OSMboxCreate((void*)0);			//创建自检状态消息邮箱
	q_msg_adc=OSQCreate(&MsgGrp[0],100);	//创建8路ADC值消息队列
 	flags_alarm=OSFlagCreate(0,&err); 		//创建报警信息信号量集	  
	
	//向FLASH中写入开机时间
	RTC_GetTime(RTC_Format_BIN,&RTC_TimeStruct);	//得到当前时间
	Start_Rtc[0] = (u8) RTC_TimeStruct.RTC_Hours;
	Start_Rtc[1] = (u8) RTC_TimeStruct.RTC_Minutes;
	Start_Rtc[2] = (u8) RTC_TimeStruct.RTC_Seconds;
	OS_ENTER_CRITICAL();									//进入临界区(无法被中断打断)   
	W25QXX_Write(Start_Rtc,W25Q128_STARTUP,3);		//写入FLASH
	OS_EXIT_CRITICAL();										//退出临界区(可以被中断打断)
	
	OSStatInit();													//初始化统计任务.这里会延时1秒钟左右	
 	OS_ENTER_CRITICAL();									//进入临界区(无法被中断打断)    
 	OSTaskCreate(RTshow_task,(void *)0,(OS_STK*)&RTSHOW_TASK_STK[RTSHOW_STK_SIZE-1],RTSHOW_TASK_PRIO);	//创建实时显示任务
	OSTaskCreate(alarm_task,(void *)0,(OS_STK*)&ALARM_TASK_STK[ALARM_STK_SIZE-1],ALARM_TASK_PRIO);			//创建报警任务
 	OSTaskCreate(main_task,(void *)0,(OS_STK*)&MAIN_TASK_STK[MAIN_STK_SIZE-1],MAIN_TASK_PRIO);					//创建主任务
 	OSTaskCreate(menu_task,(void *)0,(OS_STK*)&MENU_TASK_STK[MENU_STK_SIZE-1],MENU_TASK_PRIO);					//创建菜单任务
	OSTaskCreate(adc_task,(void *)0,(OS_STK*)&ADC_TASK_STK[ADC_STK_SIZE-1],ADC_TASK_PRIO);							//创建ADC采集任务
 	OSTaskCreate(key_task,(void *)0,(OS_STK*)&KEY_TASK_STK[KEY_STK_SIZE-1],KEY_TASK_PRIO);	 				 	 	//创建按键扫描任务
 	OSTaskSuspend(START_TASK_PRIO);				//挂起开始任务
	OS_EXIT_CRITICAL();										//退出临界区(可以被中断打断)
}

//实时显示任务
//Priority:8
//post:无
//Pend:q_msg_adc
//Function:实时显示当前8路ADC值和状态
void RTshow_task(void *pdata)
{
	u16* data;							//电压值存储数组
	u8 err;		
	u8 i;	
	u8 low_alarm;						//低报路数
	u8 high_alarm;					//高报路数
	// u8 fault;								//故障路数
	data = (u16*)mymalloc(SRAMIN,32);				//申请动态内存32字节
	
	while(1)
	{	
		low_alarm=0;					//低报路数清零
		high_alarm=0;					//高报路数清零
		// fault=0;							//故障路数清零
		
		data=OSQPend(q_msg_adc,0,&err);								//请求电压值消息队列，必须要无限等待
		
		for(i=0;i<8;i++)
		{	
			LCD_ShowxNum(82,50+20*i,data[i],4,16,0X80);	//显示8路ADC电压值
		
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
		myfree(SRAMIN,data);	//释放内存
		
		LCD_ShowxNum(154,450,low_alarm,2,16,0);						//显示低报路数
		LCD_ShowxNum(154,470,high_alarm,2,16,0);					//显示高报路数		
		
		RTC_GetDate(RTC_Format_BIN, &RTC_DateStruct);			//获取日期
		RTC_GetTime(RTC_Format_BIN,&RTC_TimeStruct);			//获取时间
		
		LCD_ShowString(10,600,200,16,16,"20  .  .  ");							//显示标注
		LCD_ShowxNum(10+2*8,600,RTC_DateStruct.RTC_Year,2,16,0);		//显示年
		LCD_ShowxNum(10+5*8,600,RTC_DateStruct.RTC_Month,2,16,0);		//显示月
		LCD_ShowxNum(10+8*8,600,RTC_DateStruct.RTC_Date,2,16,0);		//显示日
		
		LCD_ShowString(100,600,200,16,16,"  :  :  ");								//显示标注		
		LCD_ShowxNum(100,600,RTC_TimeStruct.RTC_Hours,2,16,0);			//显示时
		LCD_ShowxNum(100+3*8,600,RTC_TimeStruct.RTC_Minutes,2,16,0);//显示分
		LCD_ShowxNum(100+6*8,600,RTC_TimeStruct.RTC_Seconds,2,16,0);//显示秒		
		
		delay_ms(100);
	}
}

//报警任务
//Priority:7
//post:无
//Pend:flags_alarm
//Function:根据请求到的状态信息，驱动LED、BEEP做出相应操作
void alarm_task(void *pdata)
{	
    u16 flags;	
	  u8 err;	
	
	  while(1)
	  {
		    flags=OSFlagPend(flags_alarm,0X000F,OS_FLAG_WAIT_SET_ANY,0,&err);	//等待信号量集

			  if(flags&0X0004)	//高报 10HZ报警，LED1亮
		    {
				  LED0=1;
					LED1=0;
					
			    BEEP=1;
			    delay_ms(50);
			    BEEP=0;
			    delay_ms(50); 	  	
		    }
			  else if(flags&0X0002)	//低报 1HZ报警且LED1亮
			  {	
				  LED0=1;
					LED1=0;	
					
			    BEEP=1;
			    delay_ms(500);
			    BEEP=0;
		 	    delay_ms(500);    
			  }	 
		    else if(flags&0X0001 || flags&0X0000)	//正常状态或默认状态
		    {
			    LED1=1;
			    LED0=1;
					
					BEEP=0;	    
			    delay_ms(10);	
		    }
			delay_ms(100);	
 	}					 							 
}

//主任务
//Priority:6
//post:flags_alarm
//Pend:msg_check、q_msg_adc
//Function:请求、判断当前8路ADC值，请求、判断、显示当前联动状态，发送状态信息；向FLASH中记录故障信息（通道号、时间）、报警信息（通道号、高报/低报、时间、报警值）、联动信息（类型、时间）
void main_task(void *pdata)
{		
	OS_CPU_SR cpu_sr=0;
	u16* data;							//电压值存储数组
	u8  Alarm_Type;     		//判断ADC数据类型-低报、高报、正常
	u16 Alarm_Point=0;   		//低报指针偏移
	u32 check;							//自检标志
	u8  err;
	u8 i;
	data = (u16*)mymalloc(SRAMIN,32);				//申请动态内存32字节
	
  while(1)
	{	
		check=0;							//自检状态清零
		
		check=(u32)OSMboxPend(msg_check,10,&err);	//请求自检状态消息邮箱		
	  data = OSQPend(q_msg_adc,0,&err);  				//请求8路ADC值消息队列，必须无限等待

		Alarm_Type=Flags_Type(data,500,1000,5,3900);	//对8路通道ADC值检查类型 1:正常 2:低报 3:高报	 
		
		if (Alarm_Type == 0)			//默认状态
		{	
			 OSFlagPost(flags_alarm,0x000F,OS_FLAG_CLR,&err);
		}	
    else if (Alarm_Type == 1)	//正常状态			
		{	
			 OSFlagPost(flags_alarm,0x000F,OS_FLAG_CLR,&err);
			 OSFlagPost(flags_alarm,0x0001,OS_FLAG_SET,&err);//发送信号量集0001
		}		
	  else if (Alarm_Type == 2)	//低限报警
		{	
			OSFlagPost(flags_alarm,0x000F,OS_FLAG_CLR,&err);						
			OSFlagPost(flags_alarm,0x0002,OS_FLAG_SET,&err);  //发送信号量集0010
		}				
    else if (Alarm_Type == 3)	//高限报警
		{
			OSFlagPost(flags_alarm,0x000F,OS_FLAG_CLR,&err);						
			OSFlagPost(flags_alarm,0x0004,OS_FLAG_SET,&err);  //发送信号量集0100
		}   				
		delay_ms(100);
		
			
		if(check != 1)//若不处于自检状态
		{
			//向FLASH中写入报警、故障信息
			for (i=0; i<8; i++)
			{			
				if(1000<data[i] && data[i]<=2000)
					{	
						OS_ENTER_CRITICAL();  //进入临界区
						if((Save_Alarm(1,i, data[i]>>8,data[i],W25Q128_ALARM+Alarm_Point))==0)
							{
								Alarm_Point=Alarm_Point+7;  //指针偏移量
								if (Alarm_Point >1400) 
									Alarm_Point = 0;  //存储足够200条时重新覆盖
								}
							OS_EXIT_CRITICAL();		//退出临界区(可以被中断打断)
								delay_ms(10);
					}
					else if(2000<data[i] && data[i] <=3900)
					{	
						OS_ENTER_CRITICAL();  //进入临界区					
						if((Save_Alarm(2,i, data[i]>>8,data[i],W25Q128_ALARM+Alarm_Point))==0)
						{
							Alarm_Point=Alarm_Point+7;  //指针偏移量
							if (Alarm_Point >1400) Alarm_Point = 0;  //存储足够200条时重新覆盖
						}
						OS_EXIT_CRITICAL();		//退出临界区(可以被中断打断)
						delay_ms(10);
					}							 
		  }
		myfree(SRAMIN,data);								//释放内存空间
	  }
  }		   
}
//菜单任务
//Priority:5
//post:msg_check、q_msg_adc
//Pend:msg_key
//Function:显示历史信息、启动自检功能；向FLASH中记录联动信息（动作、时间），从FLASH中读取开机、报警、复位信息
void menu_task(void *pdata)
{
	u32 temp=0;				//消息邮箱储存
	u8 menu=0;				//菜单页面划分 0:主页面 1:查看历史记录 2:启动自检功能
	u8 cur_menu=0;		//光标位置变量 主页面使用 0:起始位置 1:History 2:Check

	u8 cur_history=0;	//光标位置变量 查看历史记录页面使用 0:起始位置 1:报警  2:事件 3；开机
	u8 cur_check=0;		//光标位置变量 启动自检功能页面使用 0:起始位置 1:确认启动
	u8 check_mode=0;	//自检模式变量 0:正常模式 1:报警模式 

	u8 page=0;				//记录页数
	u8 page_skip=1;		//翻页倍率
	u8 *read_data;		//读取数据缓存区
	u16 read_data_adc; //读取电压值缓存区
	u8 err;
	u8 i;
	read_data = (u8*)mymalloc(SRAMIN,8);			//申请动态内存16字节 

	while(1)
	{
		temp=(u32)OSMboxPend(msg_key,10,&err);//请求按键键值消息邮箱
		delay_ms(100);
		
		if(menu == 0)	 	//菜单位于主页面，此时msg_key所对应的操作为  KEY0:确认 KEY1:下移 KEY2:返回
		{			
		  LCD_ShowString(270,50,200,16,16,"1.History");			
			LCD_ShowString(270,100,200,16,16,"2.Check");
			
			if(temp ==KEY0_PRES)    					//KEY0按下，进入光标所在位置的菜单
			{
				if(cur_menu == 1)								//进入查看历史记录页面
				{
					menu=1;
					LCD_Fill(250,50,lcddev.width,lcddev.height,WHITE);
				} 
				if(cur_menu == 2)								//进入启动自检功能页面
				{
					menu=2;		
					LCD_Fill(250,50,lcddev.width,lcddev.height,WHITE);				
				}
			}
			
			if(temp == KEY1_PRES)							//KEY1按下，光标向下移动
			{
				if(cur_menu < 3)
				{
					LCD_ShowString(250,cur_menu*50,200,16,16,"  ");	//消除当前光标箭头
					cur_menu++;
					if(cur_menu == 3) cur_menu = 1;									//光标位置复位
					LCD_ShowString(250,cur_menu*50,200,16,16,"->");	//光标箭头向下移一位
				}
			}			
		}
		
		if(menu == 1)			//菜单位于查看历史记录页面，此时msg_key所对应的操作为  KEY0:确认 KEY1:下移 KEY2:返回
		{
			LCD_ShowString(270,50,200,16,16,"1.History");				
			LCD_ShowString(270,100,200,16,16,"a.ALARM");	
			LCD_ShowString(270,120,200,16,16,"b.RESET");
			LCD_ShowString(270,140,200,16,16,"c.STARTUP");
			LCD_ShowString(270,160,200,16,16,"Page:     ");
			LCD_ShowString(270,180,200,16,16,"Page Skip:");			
			
			if(temp ==KEY0_PRES)    					//KEY0按下，显示当前位置的历史记录
			{
				if(cur_history == 1)						//显示报警历史记录
				{
					LCD_Fill(250,220,lcddev.width,lcddev.height,WHITE);
					LCD_ShowString(250,220,250,16,16,"Time       CH   Value   Type");
					for(i=0;i<10;i++)																				//一次读取10个数据
					{					
						W25QXX_Read(read_data,W25Q128_ALARM+page*10*7+i*7,7);	//读取数据
						read_data_adc=((u16)read_data[5]<<4)+read_data[6];		//将AD值转换成8位数据
						Display_Save_Time(read_data,250,240+i*20);						//时间
						LCD_ShowxNum(250+11*8,240+i*20,read_data[3],2,16,0);	//通道号
		    	 	LCD_ShowxNum(250+16*8,240+i*20,read_data_adc,4,16,0);	//ADC值
						if(read_data[4] == 1) LCD_ShowString(250+24*8,240+i*20,50,16,16,"Low");
						if(read_data[4] == 2) LCD_ShowString(250+24*8,240+i*20,50,16,16,"High");
					}
					myfree(SRAMIN,read_data);			//释放内存空间
					page=page+page_skip;
					LCD_ShowxNum(270+10*8,200,page,2,16,0);
					if(page>=10) page=0;						//10页后回0	
				}
				if(cur_history == 2)						//显示复位历史记录
				{
					LCD_Fill(250,220,lcddev.width,lcddev.height,WHITE);
					LCD_ShowString(250,220,250,16,16,"Time");
					W25QXX_Read(read_data,W25Q128_RESET,3);	//读取数据
					Display_Save_Time(read_data,250,240);		//时间
					myfree(SRAMIN,read_data);								//释放内存空间
					page=1;
					LCD_ShowxNum(270+10*8,200,page,2,16,0);
				}
				if(cur_history == 3)						//显示开机历史记录
				{
					LCD_Fill(250,220,lcddev.width,lcddev.height,WHITE);
					LCD_ShowString(250,220,250,16,16,"Time");
					W25QXX_Read(read_data,W25Q128_STARTUP,3);		//读取数据
					Display_Save_Time(read_data,250,240);				//时间
					myfree(SRAMIN,read_data);										//释放内存空间
					page=1;
					LCD_ShowxNum(270+10*8,200,page,2,16,0);		
				}
			}	
			
			if(temp == KEY1_PRES)							//KEY1按下，光标向下移动
			{
				page=0;
				LCD_ShowxNum(270+10*8,200,page,2,16,0);
				if(cur_history < 4)
				{
					LCD_ShowString(250,80+cur_history*20,200,16,16,"  ");	//消除当前光标箭头
					cur_history++;
					if(cur_history == 4) cur_history = 1;									//光标位置复位
					LCD_ShowString(250,80+cur_history*20,200,16,16,"->");	//光标箭头向下移一位																									//记录页数清零
				}
			}

			if(temp == KEY2_PRES)							//KEY2按下，返回
			{
				LCD_Fill(250,50,lcddev.width,lcddev.height,WHITE);
				menu=0;													//回到主菜单
				cur_menu=0;											//回到光标起始位置
				cur_history=0;									//回到光标起始位置
			}			
		}
		
		if(menu == 2)												//菜单位于启动自检功能页面，此时msg_key所对应的操作为  KEY0:确认 KEY1:下移 KEY2:返回
		{		
			LCD_ShowString(270,50,200,16,16,"2.Check");
			LCD_ShowString(270,100,200,16,16,"Start Self Check");
			
			if(temp ==KEY0_PRES)    					//KEY0按下，执行光标所在位置操作
			{
				if(cur_check == 1)							//启动自检功能
				{
					OSTaskSuspend(ADC_TASK_PRIO);	//挂起ADC采集任务
					LCD_ShowString(270,150,200,16,16,"Checking...      ");	
					for(check_mode=0;check_mode<3;check_mode++)			//发送自检测试数据
					{
						for(i=0;i<120;i++)
						{		
							self_check(check_mode);
							temp=(u32)OSMboxPend(msg_key,10,&err);//检测到KEY1按下，则跳出当前for循环；检测到KEY2按下，则跳出自检
							if(temp == KEY1_PRES) break;	
							if(temp == KEY2_PRES) goto finish_check;
						}
					}
					finish_check:temp=0;					//清除键值，防止连续退出两级菜单
					LCD_ShowString(270,150,200,16,16,"Finish Self Check");				
					OSTaskResume(ADC_TASK_PRIO);	//解挂ADC采集任务
				}
			}
			
			if(temp == KEY1_PRES)							//KEY1按下，光标向下移动
			{
				
				if(cur_check < 2)
				{
					LCD_ShowString(250,80+cur_check*20,200,16,16,"  ");	//消除当前光标箭头
					cur_check++;
					if(cur_check == 2) cur_check = 1;										//光标位置复位
					LCD_ShowString(250,80+cur_check*20,200,16,16,"->");	//光标箭头向下移一位
				}
			}
			
			if(temp == KEY2_PRES)						//KEY2按下，返回
			{
				LCD_Fill(250,50,lcddev.width,lcddev.height,WHITE);
				menu=0;												//回到主菜单
				cur_menu=0;										//回到光标起始位置	
				cur_check=0;									//回到光标起始位置	
			}
		}			
	}
}	
		
//ADC采集任务
//Priority:4
//post:q_msg_adc
//Pend:无
//Function:获取、发送当前8路ADC值
void adc_task(void *pdata)
{	
	OS_CPU_SR cpu_sr=0;						 			
	float vol[8];	
	u16 adcx[8];
	u16* data;
	u8 i=0;
	data = (u16*)mymalloc(SRAMIN,32);			//申请动态内存32字节
						
	while(1)
	{	
		for(i=0;i<8;i++)
		{			
			//读取ADC 转换为电压  			
			OS_ENTER_CRITICAL();							//进入临界区(无法被中断打断)    			
			adcx[i]=Get_Adc_Average(i,5);			//读取
			OS_EXIT_CRITICAL();								//退出临界区(可以被中断打断)
	
			vol[i]=(float)adcx[i]*(3.3/4096); //adcx的值转换为电压值
			data[i]=vol[i]*1000;      
		}
		
		OSQPostOpt(q_msg_adc,(void*)data,OS_POST_OPT_BROADCAST);//发送队列
		myfree(SRAMIN,data);								//释放内存空间
		delay_ms(500);	
	}	
}

//按键扫描任务
//Priority:3
//post:msg_key、sem_tpad
//Pend:无
//Function:获取、发送当前键值，监控tpad，执行复位操作
void key_task(void *pdata)
{	
	OS_CPU_SR cpu_sr=0;
	u8 key;		
	while(1)
	{
		key=KEY_Scan(0);	//获取当前按键键值
		if(key==0)
		{
			if(TPAD_Scan(0)) key=5;		
		}
		if(key)OSMboxPostOpt(msg_key,(void*)key,OS_POST_OPT_BROADCAST);	//发送按键键值消息邮箱	
		if(key==5)		                                   //TPAD按下则向FLASH写入复位信息
		{
			//向FLASH中写入复位事件信息
			OS_ENTER_CRITICAL();									//进入临界区(无法被中断打断)   
			Save_Reset(W25Q128_RESET);   		
			OS_EXIT_CRITICAL();										//退出临界区(可以被中断打断)
			mcuRestart();	//复位
		}
 		delay_ms(10);
	}
}
