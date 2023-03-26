#include "adc.h"
#include "delay.h"		 
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//ADC ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/6
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	


//��ʼ��ADC															   
void  Adc_Init(void)
{    
		GPIO_InitTypeDef  GPIO_InitStructure;
		ADC_CommonInitTypeDef ADC_CommonInitStructure;
		ADC_InitTypeDef       ADC_InitStructure;
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOC, ENABLE);//ʹ��GPIOA,GPIOB,GPIOCʱ��
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); //ʹ��ADC1ʱ��

		//�ȳ�ʼ��ADC1ͨ��0-7 IO��
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;//PA0-7 ͨ��0-7
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//ģ������
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;//����������
		GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��  
		
		//��ʼ��ADC1ͨ��8-9 IO��
//		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;//PB0 PB1 ͨ��9 10
//		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//ģ������
//		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;//����������
//		GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��  
//		
//		//��ʼ��ADC1ͨ��10-15 IO��
//		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;//PC0-5 ͨ��0-5
//		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//ģ������
//		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;//����������
//		GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��  
	
		RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC1,ENABLE);	  //ADC1��λ
		RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC1,DISABLE);	//��λ����	 
	
		ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//����ģʽ
		ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//���������׶�֮����ӳ�5��ʱ��
		ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMAʧ��
		ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//Ԥ��Ƶ4��Ƶ��ADCCLK=PCLK2/4=84/4=21Mhz,ADCʱ����ò�Ҫ����36Mhz 
		ADC_CommonInit(&ADC_CommonInitStructure);//��ʼ��
	
		ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12λģʽ
		ADC_InitStructure.ADC_ScanConvMode = DISABLE;//��ɨ��ģʽ	
		ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//�ر�����ת��
		ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//��ֹ������⣬ʹ���������
		ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//�Ҷ���	
		ADC_InitStructure.ADC_NbrOfConversion = 1;//1��ת���ڹ��������� Ҳ����ֻת����������1 
		ADC_Init(ADC1, &ADC_InitStructure);//ADC��ʼ��	
 
		ADC_Cmd(ADC1, ENABLE);//����ADת����	
}				  
//���ADCֵ
//ch: @ref ADC_channels 
//ͨ��ֵ 0~16ȡֵ��ΧΪ��ADC_Channel_0~ADC_Channel_16
//����ֵ:ת�����
u16 Get_Adc(u8 ch)   
{
	  	//����ָ��ADC�Ĺ�����ͨ����һ�����У�����ʱ��
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_480Cycles );	//ADC1,ADCͨ��,480������,��߲���ʱ�������߾�ȷ��			    
	ADC_SoftwareStartConv(ADC1);		//ʹ��ָ����ADC1�����ת����������	
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//�ȴ�ת������
	return ADC_GetConversionValue(ADC1);	//�������һ��ADC1�������ת�����
}
//��ȡͨ��ch��ת��ֵ��ȡtimes��,Ȼ��ƽ�� 
//ch:ͨ�����
//times:��ȡ����
//����ֵ:ͨ��ch��times��ת�����ƽ��ֵ
u16 Get_Adc_Average(u8 ch,u8 times)
{
	u32 temp_val=0;
	u8 t;
	for(t=0;t<times;t++)
	{
		temp_val+=Get_Adc(ch);
				delay_ms(5);
	}
	return temp_val/times;
} 

//��ȡ��ǰ16·ADC״̬ 1:���� 2:���ޱ��� 3:���ޱ��� 4:����
u8 Flags_Type(u16 *Date_Adc,u16 Alarm_H,u16 Alarm_L,u16 Fault_L,u16 Fault_H)
{   
	  u8 i;
    u8 AlarmL_Value;   
    u8 AlarmH_Value;
	  u8 Fault_Value;
	
	
     for (i=0; i<8; i++)
	   {
         if (Alarm_H<Date_Adc[i] && Date_Adc[i]<=Fault_H)//���ޱ���
			   {
             AlarmH_Value = 1;    
         } 
		     else if ( Alarm_L<Date_Adc[i] && Date_Adc[i] <=Alarm_H)//���ޱ��� 
			   {      
             AlarmL_Value = 1; 
         }
         else if (Date_Adc[i] <=Fault_L || Date_Adc[i] >Fault_H )//���ϱ���
		     {
		         Fault_Value = 1;; 
		     }			 
     }
		 
		 if (Fault_Value == 1)	return 4;
		 else if ((Fault_Value != 1) && (AlarmH_Value == 1)) return 3;
		 else if ((Fault_Value != 1) && (AlarmH_Value != 1) && (AlarmL_Value == 1)) return 2;
		 else if((Fault_Value != 1) && (AlarmH_Value != 1) && (AlarmL_Value != 1)) return 1;
		 else return 0;
}




