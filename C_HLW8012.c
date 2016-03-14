/*=============================================================================
  * File Name	     : HLW8012�ο�����
  * Describe 	     : �������ʡ���ѹ����������������
  * Author	     : �����к���Ϊ�Ƽ����޹�˾
  * Version	     : V1.0
  * Record	     : 2014/04/10
=============================================================================*/
/* Includes -----------------------------------------------------------------*/

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//Time1��ʱ����ʱ,ʱ����� = 1ms
#define D_TIME1_20MS				20		
#define D_TIME1_100MS				100	
#define D_TIME1_150MS				150	
#define D_TIME1_200MS				200	
#define D_TIME1_400MS				400	
#define D_TIME1_500MS				500	
#define D_TIME1_1S				1000		//Time1��ʱ����ʱ1Sʱ�䳣��
#define D_TIME1_2S				2000	
#define D_TIME1_3S				2000	
#define D_TIME1_4S				4000	
#define D_TIME1_6S				6000
#define D_TIME1_8S				8000
#define D_TIME1_9S				9000
#define D_TIME1_10S				10000
#define D_TIME1_20S				20000


#define D_TIME1_V_OVERFLOW                      500        //Time1��ʱ��,��ѹ��������趨Ϊ500mS,���˵���������ڴ���500mS
#define D_TIME1_I_OVERFLOW			8000	   //Time1��ʱ��,������������趨Ϊ10S,���˵���������ڴ���10S
#define D_TIME1_P_OVERFLOW			12000	   //Time1��ʱ��,������������趨Ϊ10S(Լ0.5W��Сֵ),���˵���������ڴ���10S
//#define D_TIME1_P_OVERFLOW			40000	   //Time1��ʱ��,������������趨Ϊ40S(Լ0.2W��Сֵ)
#define D_TIME1_CAL_TIME			36000	   //У��ʱ�䣬��¼�ڴ�ʱ���ڵ���������1000W�������õ�36Sʱ���ںķ�0.01�ȵ�
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------


//HLW 8012 IO����
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
#define IO_HLW8012_CF1_S      PD_ODR_ODR3		//HLW8012 PIN8		
#define IO_HLW8012_CF1        PA_IDR_IDR2		//HLW8012 PIN7	
#define IO_HLW8012_CF         PC_IDR_IDR5		//HLW8012 PIN6
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------	


//����ģʽ
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
#define D_ERR_MODE                	0x00        //������ʾģʽ
#define D_NORMAL_MODE		      	0x10	    //��������ģʽ
#define D_CAL_START_MODE		0x21	    //У��ģʽ������
#define D_CAL_END_MODE		        0x23	    //У��ģʽ�����
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------


//ROM����
//--------------------------------------------------------------------------------------------
#define u1      _Bool
#define u8	unsigned char
#define u16	unsigned int
#define u32	unsigned long
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
union IntData
{
	u16  inte;			
	u8 byte[2];		
};
union LongData
{
    u32  word;		
    u16  inte[2];		
    u8   byte[4];		
};
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
u16	U16_P_TotalTimes;			//��ǰ���� ���ʲ�����ʱ��
u16	U16_V_TotalTimes;			//��ǰ���� ��ѹ������ʱ��
u16	U16_I_TotalTimes;			//��ǰ���� ����������ʱ��

u16	U16_P_OneCycleTime;			//���ʲ���ʱ�����
u16	U16_V_OneCycleTime;			//��ѹ����ʱ�����
u16	U16_I_OneCycleTime;			//��������ʱ�����

u16	U16_P_Last_OneCycleTime;		//���ʲ���ʱ���������һ������ֵ
u16	U16_V_Last_OneCycleTime;		//��ѹ����ʱ���������һ������ֵ
u16	U16_I_Last_OneCycleTime;		//��������ʱ���������һ������ֵ

u16	U16_P_CNT;				//���ʲ�����������
u16	U16_V_CNT;				//��ѹ������������
u16	U16_I_CNT;				//����������������

u16	U16_P_Last_CNT;				//���ʲ���������������һ������ֵ
u16	U16_V_Last_CNT;				//��ѹ����������������һ������ֵ
u16	U16_I_Last_CNT;				//��������������������һ������ֵ

u1	B_P_TestOneCycle_Mode;			//���ʲ���ģʽ 1:�����ڲ�����0:1S��ʱ����
u1	B_V_TestOneCycle_Mode;
u1	B_I_TestOneCycle_Mode;

u1	B_P_Last_TestOneCycle_Mode;
u1	B_V_Last_TestOneCycle_Mode;
u1	B_I_Last_TestOneCycle_Mode;
    		
u1  	B_P_OVERFLOW;       			// ������������ �����־λ 
u1  	B_V_OVERFLOW;       			// ��ѹ�������� �����־λ
u1  	B_I_OVERFLOW;       			// ������������ �����־λ

u1	B_P_Last_OVERFLOW;       		// ������������ �����־λ 
u1  	B_V_Last_OVERFLOW;       		// ��ѹ�������� �����־λ
u1  	B_I_Last_OVERFLOW;       		// ������������ �����־λ

u1    	B_VI_Test_Mode;				//1:��ѹ����ģʽ;0:��������ģʽ
u16   	U16_VI_Test_Times;				
u16   	U16_Cal_Times;	

u16   	U16_AC_P;				//����ֵ 1000.0W
u16   	U16_AC_V;				//��ѹֵ 220.0V
u16   	U16_AC_I;				//����ֵ 4.545A
u32   	U32_AC_E;				//�õ���   0.01��
u32   	U32_AC_BACKUP_E;			//�õ�������	
u8    	U8_AC_COS;				//�������� 0.00

u16   	U16_REF_001_E_Pluse_CNT;        	//0.01�ȵ����������ο�ֵ
u16   	U16_E_Pluse_CNT;          	 	//��������Ĵ���

u32   	U32_Cal_Times;                 		//У��ʱ��

u32   	U32_P_REF_PLUSEWIDTH_TIME;      	//�ο����� ��������
u32   	U32_V_REF_PLUSEWIDTH_TIME;      	//�ο���ѹ ��������
u32   	U32_I_REF_PLUSEWIDTH_TIME;      	//�ο����� ��������

u32   	U32_P_CURRENT_PLUSEWIDTH_TIME;      	//��ǰ���� ��������
u32   	U32_V_CURRENT_PLUSEWIDTH_TIME;      	//��ǰ��ѹ ��������
u32   	U32_I_CURRENT_PLUSEWIDTH_TIME;      	//��ǰ���� ��������

u16   	U16_P_REF_Data;				//�ο�����ֵ,����1000WУ����1000.0W
u16   	U16_V_REF_Data;				//�ο���ѹ  220.0V
u16   	U16_I_REF_Data;				//�ο�����  1000W,220V��������4.545A

u8    	U8_CURR_WorkMode;
//--------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
void main(void)
{
   //��ʼ��MCU 
   //��ʼ��ROM
   Init_Rom();
   //��ȡ�����EEPROM��У������
   Read_CalData_EEPROM(); //��ȡ�ο����ʡ��ο���ѹ���ο���������������
 
   while(1)
  {
     if (B_KeyScanEn == TRUE)
     {
        ScaningKey();			//����
        KeyFun_NormalMode();
     } 
     
     if (U8_CURR_WorkMode == D_NORMAL_MODE)
     {	
	HLW8012_Measure();		//���㹦�ʡ���ѹ������
     }
     else if (U8_CURR_WorkMode == D_CAL_END_MODE)   //У��ģʽ
     {
            //��¼У��ֵ������ǰ���ʡ���ѹ������ֵ����EEPROM;��0.01�ȵ����������ֵҲ����EEPROM
            Write_CalData_EEPROM();
            //��ȡУ��ֵ�����õ�������
            Read_CalData_EEPROM();
	    //���ز���ģʽ
            U8_CURR_WorkMode = D_NORMAL_MODE;
     }
	
  }
}


//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
/*=====================================================
 * Function : void Init_Rom(void)
 * Describe : rom�ռ��ʼ��
 * Input    : none
 * Output   : none
 * Return   : none
 * Record   : 2014/04/14
=====================================================*/
void Init_Rom(void)
{
    U8_CURR_WorkMode = D_NORMAL_MODE;
    U8_DspMode = 0;
    
    U16_AC_P = 0;
    U16_AC_V = 0;
    U16_AC_I = 0;
    U8_AC_COS = 0;

 
  U16_P_TotalTimes = 0;
  U16_V_TotalTimes = 0;
  U16_I_TotalTimes = 0;

  
  U16_P_OneCycleTime = 0;
  U16_V_OneCycleTime = 0;
  U16_I_OneCycleTime = 0;
  U16_P_Last_OneCycleTime = 0;
  U16_V_Last_OneCycleTime = 0;
  U16_I_Last_OneCycleTime = 0;
  
  U16_P_CNT = 0;
  U16_V_CNT = 0;
  U16_I_CNT = 0;
  U16_P_Last_CNT = 0;
  U16_V_Last_CNT = 0;
  U16_I_Last_CNT = 0;
  
//��ʼ�������ڲ���ģʽ
  B_P_TestOneCycle_Mode = 1;
  B_V_TestOneCycle_Mode = 1;
  B_I_TestOneCycle_Mode = 1;
  B_P_Last_TestOneCycle_Mode = 1;
  B_V_Last_TestOneCycle_Mode = 1;
  B_I_Last_TestOneCycle_Mode = 1;

//��ʼ�������������־λΪ1  
  B_P_OVERFLOW = 1;
  B_V_OVERFLOW = 1;
  B_I_OVERFLOW = 1;
  
  B_P_Last_OVERFLOW = 1;
  B_V_Last_OVERFLOW = 1;
  B_I_Last_OVERFLOW = 1;
  
//�ϵ��ʼ��Ϊ��ѹ����ģʽ 
  B_VI_Test_Mode = 1;
  IO_HLW8012_CF1_S = 1;
  U16_VI_Test_Times = D_TIME1_2S;
  
//��ʾ��ʼ��
  U8_DspMode = 0;
  B_DIS_EN = FALSE;
  U16_SendUart_Time = 0;
  
}
/*=====================================================
 * ��������: PC�ж�,IO---PC5
 * ��������: CF�ж� ���ʲ���
 * �������: ��
 * �������: 
 * ��    ��:
=====================================================*/
  #pragma vector = 7
__interrupt void PC5_EXTI_Interrupt(void)
{
//���ʲ���
    U16_P_TotalTimes = 0;       //���һ����Ч�Ĳ���������Ĵ�������    
    U16_P_CNT++;
    if (B_P_OVERFLOW == TRUE)
    {  
        //�����ģʽת��,��ʼ����     
        B_P_TestOneCycle_Mode = 0;  //��ʼ��Ϊ�����������ģʽ
        U16_P_TotalTimes = 0;       //������Ĵ�������
        U16_P_OneCycleTime = 0;     //������Ĵ���
        U16_P_CNT = 1;              
        B_P_OVERFLOW = FALSE;       //�������־λ
    }
    else
    {
        if (B_P_TestOneCycle_Mode == 1)
        {
            if (U16_P_OneCycleTime >= D_TIME1_100MS)
            {
                //�����ڲ���ģʽ 
                U16_P_Last_OneCycleTime = U16_P_OneCycleTime;
                B_P_Last_TestOneCycle_Mode = B_P_TestOneCycle_Mode;
                B_P_OVERFLOW = FALSE;       //�����־λ����
                B_P_Last_OVERFLOW = B_P_OVERFLOW;
                 //��״̬����,���¿�ʼ����
                B_P_TestOneCycle_Mode = 0;  //��ʼ��Ϊ�����������ģʽ
                U16_P_TotalTimes = 0;       //���һ����Ч�Ĳ���������Ĵ�������
                U16_P_OneCycleTime = 0;     //������Ĵ���
                U16_P_CNT = 1;
 
            }
        }
        else
        {
            if (U16_P_OneCycleTime >= D_TIME1_1S)
            {   
                U16_P_Last_OneCycleTime = U16_P_OneCycleTime;
                U16_P_Last_CNT = U16_P_CNT;
                B_P_Last_TestOneCycle_Mode = B_P_TestOneCycle_Mode;
                B_P_OVERFLOW = FALSE;       //�����־λ����
                B_P_Last_OVERFLOW = B_P_OVERFLOW;
                //��״̬����,���¿�ʼ����
                B_P_TestOneCycle_Mode = 0;  //��ʼ��Ϊ�����������ģʽ
                U16_P_TotalTimes = 0;       //���һ����Ч�Ĳ���������Ĵ�������
                U16_P_OneCycleTime = 0;     //������Ĵ���
                U16_P_CNT = 1;
            }
        }
    }
    
    
//У��ģʽ
    if (U8_CURR_WorkMode == D_CAL_START_MODE)
    {
        //��¼��λʱ���ڵ��õ���
        U16_E_Pluse_CNT++;
    }
    
//�õ���������ÿ0.01�ȵ磬�õ����Ĵ�������0.01��
    if (U8_CURR_WorkMode == D_NORMAL_MODE)
    {
        U16_E_Pluse_CNT++;
        if (U16_E_Pluse_CNT == U16_REF_001_E_Pluse_CNT )
        {
            U16_E_Pluse_CNT = 0;
            U32_AC_E++;
        }
    }
}
/*=====================================================
 * ��������: PD�ж�,IO---PD2
 * ��������: CF1�ж� ��ѹ����������
 * �������: 
 * �������:
 * ��    ��:
=====================================================*/
  #pragma vector = 8
__interrupt void PD2_EXTI_Interrupt(void)
{
  
//��ѹ����ģʽ
    if (B_VI_Test_Mode == 1)
    {
        U16_V_TotalTimes = 0; 
        U16_V_CNT++;
        if (B_V_OVERFLOW == TRUE)
        {                  
            //�����ģʽת��,��ʼ����     
            B_V_TestOneCycle_Mode = 0;  //��ʼ��Ϊ�����������ģʽ
            U16_V_TotalTimes = 0;       //������Ĵ�������
            U16_V_OneCycleTime = 0;     //������Ĵ���
            U16_V_CNT = 1;              
            B_V_OVERFLOW = FALSE;       //�������־λ
        }
        else
        {
            if (B_V_TestOneCycle_Mode == 1)
            {
                if (U16_V_OneCycleTime >= D_TIME1_100MS)
                {
                    //�����ڲ���ģʽ 
                    U16_V_Last_OneCycleTime = U16_V_OneCycleTime;
                    B_V_Last_TestOneCycle_Mode = B_V_TestOneCycle_Mode;
                    B_V_OVERFLOW = FALSE;       //�����־λ����
                    B_V_Last_OVERFLOW = B_V_OVERFLOW;
                     //��״̬����,���¿�ʼ����
                    B_V_TestOneCycle_Mode = 0;  //��ʼ��Ϊ�����������ģʽ
                    U16_V_TotalTimes = 0;       //���һ����Ч�Ĳ���������Ĵ�������
                    U16_V_OneCycleTime = 0;     //������Ĵ���
                    U16_V_CNT = 1;
                }
            }
            else
            {
                if (U16_V_OneCycleTime >= D_TIME1_200MS)
                {   
                    U16_V_Last_OneCycleTime = U16_V_OneCycleTime;
                    U16_V_Last_CNT = U16_V_CNT;
                    B_V_Last_TestOneCycle_Mode = B_V_TestOneCycle_Mode; 
                    B_V_OVERFLOW = FALSE;       //�����־λ����
                    B_V_Last_OVERFLOW = B_V_OVERFLOW;
                    //��״̬����,���¿�ʼ����
                    B_V_TestOneCycle_Mode = 0;  //��ʼ��Ϊ�����������ģʽ
                    U16_V_TotalTimes = 0;       //���һ����Ч�Ĳ���������Ĵ�������
                    U16_V_OneCycleTime = 0;     //������Ĵ���
                    U16_V_CNT = 1;
                    B_V_OVERFLOW = FALSE;       //�����־λ����
                }
            }
        }
     }

//��������ģʽ
    if (B_VI_Test_Mode == 0)
    {
        U16_I_TotalTimes = 0; 
        U16_I_CNT++;
        if (B_I_OVERFLOW == TRUE)
        {
            //�����ģʽת��,��ʼ����     
            B_I_TestOneCycle_Mode = 0;  //��ʼ��Ϊ�����������ģʽ
            U16_I_TotalTimes = 0;       //������Ĵ�������
            U16_I_OneCycleTime = 0;     //������Ĵ���
            U16_I_CNT = 1;              
            B_I_OVERFLOW = FALSE;       //�������־λ
        }
        else
        {
            if (B_I_TestOneCycle_Mode == 1)
            {
                if (U16_I_OneCycleTime >= D_TIME1_100MS)
                {
                    //�����ڲ���ģʽ 
                    U16_I_Last_OneCycleTime = U16_I_OneCycleTime;
                    B_I_Last_TestOneCycle_Mode = B_I_TestOneCycle_Mode;
                    B_I_OVERFLOW = FALSE;       //�����־λ����
                    B_I_Last_OVERFLOW = B_I_OVERFLOW;
                     //��״̬����,���¿�ʼ����
                    B_I_TestOneCycle_Mode = 0;  //��ʼ��Ϊ�����������ģʽ
                    U16_I_TotalTimes = 0;       //���һ����Ч�Ĳ���������Ĵ�������
                    U16_I_OneCycleTime = 0;     //������Ĵ���
                    U16_I_CNT = 1;
                }
            }
            else
            {
                if (U16_I_OneCycleTime >= D_TIME1_1S)
                {   
                    U16_I_Last_OneCycleTime = U16_I_OneCycleTime;
                    U16_I_Last_CNT = U16_I_CNT;
                    B_I_Last_TestOneCycle_Mode = B_I_TestOneCycle_Mode;  
                    B_I_OVERFLOW = FALSE;       //�����־λ����
                    B_I_Last_OVERFLOW = B_I_OVERFLOW;
                    //��״̬����,���¿�ʼ����
                    B_I_TestOneCycle_Mode = 0;  //��ʼ��Ϊ�����������ģʽ
                    U16_I_TotalTimes = 0;       //���һ����Ч�Ĳ���������Ĵ�������
                    U16_I_OneCycleTime = 0;     //������Ĵ���
                    U16_I_CNT = 1;
                }
            }
        }
    }
}
/*=====================================================
 * ��������: TIM1
 * ��������: �������ʡ���ѹ������
 * �������:
 * �������: 
 * ��    ��:
=====================================================*/
  #pragma vector = 13
__interrupt void TIM1_UPD_Interrupt(void)
{
//У��ģʽ
    if (U8_CURR_WorkMode == D_CAL_START_MODE)
    {
        U32_Cal_Times++;//У��ʱ��36S��1000W����36Sʱ������0.01�ȵ�
        if (U32_Cal_Times == D_TIME1_CAL_TIME)
        {
            U8_CURR_WorkMode = D_CAL_END_MODE;			
            U16_REF_001_E_Pluse_CNT = U16_E_Pluse_CNT;		//��¼36Sʱ���ڵ�������������������ʾ0.01���õ���
        }
    }
    
//���ʲ���
    if (U16_P_CNT != 0)
    {
        U16_P_OneCycleTime++;
        U16_P_TotalTimes++;
    }  
    if (U16_P_TotalTimes >= D_TIME1_P_OVERFLOW)
    {
        B_P_OVERFLOW = TRUE; 		//�����
        B_P_Last_OVERFLOW = B_P_OVERFLOW;
        //��״̬����,���¿�ʼ����
        U16_P_TotalTimes = 0;       //������Ĵ���
        U16_P_OneCycleTime = 0;
        U16_P_CNT = 0;              //�ȴ���һ���жϿ�ʼ����
        B_P_TestOneCycle_Mode = 0;   //��ʼ��Ϊ�����������ģʽ      
    }
    else if (U16_P_OneCycleTime == D_TIME1_100MS)
    {
      if (U16_P_CNT < 2)
      {
        // 100ms��ֻ��һ���жϣ�˵������>100ms,���õ����ڲ���ģʽ 
        B_P_TestOneCycle_Mode = 1;
      }
      else
      {
         // 100ms����2�λ������������壬˵������<100ms�����ü����������ģʽ
         B_P_TestOneCycle_Mode = 0;   
      }
    }
    
//��ѹ����������
    if (B_VI_Test_Mode == 1)
    {
        //��ѹ����      
        if (U16_V_CNT != 0)
        {
            U16_V_OneCycleTime++;
            U16_V_TotalTimes++;
        }  
        if (U16_V_TotalTimes >= D_TIME1_V_OVERFLOW)
        {
            B_V_OVERFLOW = TRUE; 
            B_V_Last_OVERFLOW = B_V_OVERFLOW;
            //��״̬����,���¿�ʼ����
            U16_V_TotalTimes = 0;       //������Ĵ���
            U16_V_OneCycleTime = 0;
            U16_V_CNT = 0;              
            B_V_TestOneCycle_Mode = 0;   //��ʼ��Ϊ�����������ģʽ      
        }
        else if (U16_V_OneCycleTime == D_TIME1_100MS)
        {
          if (U16_V_CNT < 2)
          {
            // 100ms��ֻ��һ���жϣ�˵������>100ms,���õ����ڲ���ģʽ 
            B_V_TestOneCycle_Mode = 1;
          }
          else
          {
             // 100ms����2�λ������������壬˵������<100ms�����ü����������ģʽ
             B_V_TestOneCycle_Mode = 0;   
          }
        }
    }
    else
    {
        //��������   
        if (U16_I_CNT != 0)
        {
            U16_I_OneCycleTime++;
            U16_I_TotalTimes++;
        }  
        if (U16_I_TotalTimes >= D_TIME1_I_OVERFLOW)
        {
            B_I_OVERFLOW = TRUE; 
            B_I_Last_OVERFLOW = B_I_OVERFLOW;
            //��״̬����,���¿�ʼ����
            U16_I_TotalTimes = 0;       //������Ĵ���
            U16_I_OneCycleTime = 0;
            U16_I_CNT = 0;
            B_I_TestOneCycle_Mode = 0;   //��ʼ��Ϊ�����������ģʽ      
        }
        else if (U16_I_OneCycleTime == D_TIME1_100MS)
        {
          if (U16_I_CNT < 2)
          {
            // 100ms��ֻ��һ���жϣ�˵������>100ms,���õ����ڲ���ģʽ 
            B_I_TestOneCycle_Mode = 1;
          }
          else
          {
             // 100ms����2�λ������������壬˵������<100ms�����ü����������ģʽ
             B_I_TestOneCycle_Mode = 0;   
          }
        }
    }
      

//��ѹ����������ģʽ�л�  B_VI_Test_Mode:(1:��ѹ����ģʽ) (0:��������ģʽ) 
    U16_VI_Test_Times--;
    if (U16_VI_Test_Times == 0)
    {
        if (B_VI_Test_Mode == 1)
        {
            //תΪ��������ģʽ
            B_VI_Test_Mode = 0;
            IO_HLW8012_CF1_S = 0;
            U16_VI_Test_Times = D_TIME1_10S;
            
            //��״̬����
            U16_I_TotalTimes = 0;
            U16_I_OneCycleTime = 0;
            U16_I_CNT = 0;
            B_I_OVERFLOW = FALSE; 
        }
        else
        {
            //תΪ��ѹ����ģʽ
            B_VI_Test_Mode = 1;
            IO_HLW8012_CF1_S = 1;
            U16_VI_Test_Times = D_TIME1_1S;
            
            //��״̬����
            U16_V_TotalTimes = 0;
            U16_V_OneCycleTime = 0;
            U16_V_CNT = 0;
            B_V_OVERFLOW = FALSE; 
        }
    }
  
//����ɨ��,20mSһ��
	U8_KeyScanTimes++;
  	if (U8_KeyScanTimes > D_TIME1_20MS)
  	{
      		B_KeyScanEn = TRUE;
	  	U8_KeyScanTimes = 0;
  	}
    
// ÿ0.5S���ڷ���һ������
    U16_SendUart_Time++;
    if (U16_SendUart_Time == D_TIME1_500MS)
    {
        B_DIS_EN = TRUE;
        U16_SendUart_Time = 0;
    }

// Clear TIM1 INT FLAG   
   TIM1_SR1 = 0x00;       
}



/*-------------------------------------------- ���ʡ���ѹ���������� -------------------------------------------*/


*=====================================================
 * Function : void HLW8012_Measure_P(void)
 * Describe : 
 * Input    : none
 * Output   : none
 * Return   : none
 * Record   : 2014/04/14
=====================================================*/
void HLW8012_Measure_P(void)
{
    u32 a;
    u32 b;
    u32 u32_P_Period;
    
    if (B_P_Last_TestOneCycle_Mode == 1)
    {
       //�����ڲ���ģʽ
       b = U16_P_Last_OneCycleTime;
       b = b*1000;  //msת����us 
       u32_P_Period = b;   
    }
    else
    {
      //�����������ģʽ
      b = U16_P_Last_OneCycleTime;
      b = b*1000;
      u32_P_Period = b/(U16_P_Last_CNT-1);  
    }
    
    U32_P_CURRENT_PLUSEWIDTH_TIME = u32_P_Period;      // У��ʱȡU32_P_CURRENT_PLUSEWIDTH_TIME������Ϊ�ο�ֵ     
    a = U16_P_REF_Data * U32_P_REF_PLUSEWIDTH_TIME;        
    U16_AC_P = a/U32_P_CURRENT_PLUSEWIDTH_TIME;
    
    if (U16_AC_P == 0xffff)     //����ʱU32_P_CURRENT_PLUSEWIDTH_TIME = 0���������
    {
        U16_AC_P = 0; 
    }
    
    if (B_P_Last_OVERFLOW == TRUE)
    {
        U16_AC_P = 0;
    }
}
/*=====================================================
 * Function : void HLW8012_Measure_V(void)
 * Describe : 
 * Input    : none
 * Output   : none
 * Return   : none
 * Record   : 2014/04/14
=====================================================*/
void HLW8012_Measure_V(void)
{
    u32 a;
    u32 b;
    u32 u32_V_Period;
    
    if (U16_VI_Test_Times < D_TIME1_100MS)
    {
        if (B_V_Last_TestOneCycle_Mode == 1)
        {
            b = U16_V_Last_OneCycleTime;
            u32_V_Period = b * 1000;   //msת����us 
            U32_V_CURRENT_PLUSEWIDTH_TIME = u32_V_Period;  
        }
        else
        {
             b = U16_V_Last_OneCycleTime;
             b = b*1000;
             u32_V_Period = b/(U16_V_Last_CNT-1); 
             //u32_V_Period = b/U16_V_Last_CNT; 
             U32_V_CURRENT_PLUSEWIDTH_TIME = u32_V_Period;  
        }
    }
          
    a = U16_V_REF_Data * U32_V_REF_PLUSEWIDTH_TIME;
    U16_AC_V = a/U32_V_CURRENT_PLUSEWIDTH_TIME;
    
    if (U16_AC_V == 0xffff)     //����ʱU32_V_CURRENT_PLUSEWIDTH_TIME = 0���������
    {
        U16_AC_V = 0; 
    }
    
    if (B_V_Last_OVERFLOW == TRUE)
    {
        U16_AC_V = 0;
    }
    
    if (U16_AC_P == 0)
    {
        U16_AC_V = 0;
      
    }
}
/*=====================================================
 * Function : void HLW8012_Measure_I(void)
 * Describe : 
 * Input    : none
 * Output   : none
 * Return   : none
 * Record   : 2014/04/14
=====================================================*/
void HLW8012_Measure_I(void)
{
    u32 a;
    u32 b;
    u32 u32_I_Period;  
    
    if (U16_VI_Test_Times < D_TIME1_6S)
    {
        if (B_I_Last_TestOneCycle_Mode == 1)
        {

            b = U16_I_Last_OneCycleTime;
            u32_I_Period = b * 1000;   //msת����us 
            U32_I_CURRENT_PLUSEWIDTH_TIME = u32_I_Period; 
        }
        else
        {
             b = U16_I_Last_OneCycleTime;
             b = b*1000;
             u32_I_Period = b/(U16_I_Last_CNT-1); 
             //u32_I_Period = b/U16_I_Last_CNT;
             U32_I_CURRENT_PLUSEWIDTH_TIME = u32_I_Period; 
        }
    }
    
          
    a = U16_I_REF_Data * U32_I_REF_PLUSEWIDTH_TIME;
    U16_AC_I = a/U32_I_CURRENT_PLUSEWIDTH_TIME;
    
    
    if (U16_AC_I > 180)
    {    
       if (U16_AC_I != 0xffff)
       {
            NOP();
            NOP();
       }
    }
      
    if (U16_AC_P == 0)
    {
        U16_AC_I = 0;
      
    }
    
    if (U16_AC_I == 0xffff)     //����ʱU32_I_CURRENT_PLUSEWIDTH_TIME = 0���������
    {
        U16_AC_I = 0; 
    }
    
    if (B_I_OVERFLOW == TRUE)
    {
        U16_AC_I = 0;  
    }
}
/*=====================================================
 * Function : void HLW8012_Measure_COS(void)
 * Describe : 
 * Input    : none
 * Output   : none
 * Return   : none
 * Record   : 2014/04/14
=====================================================*/
void HLW8012_Measure_COS(void)
{
  u32 u32_P_Apparent;
  u32 a;
  u8 b;
  u32_P_Apparent = (u32)U16_AC_I*(u32)U16_AC_V;
  u32_P_Apparent = u32_P_Apparent/1000;
  a = U16_AC_P;
  a = a*100;
  
  b = (u8)(a/u32_P_Apparent);
  if (b > 100 )
    U8_AC_COS = 100; 		//������λ��ʱ��ɵĹ�������>1���������������ȡֵ1
  else
    U8_AC_COS = b;
}
/*=====================================================
 * Function : void HLW8012_Measure_E(void)
 * Describe : ÿ1�ȵ�洢һ��
 * Input    : none
 * Output   : none
 * Return   : none
 * Record   : 2014/04/14
=====================================================*/
void HLW8012_Measure_E(void)
{
  if (U32_AC_BACKUP_E < U32_AC_E)
  {
	U32_AC_BACKUP_E = U32_AC_E;
	//ÿ����0.01�ȵ���и��£������õ����ݴ���EEPROM
        //Updata_BackUp_E_EEPROM();
  }
}
/*=====================================================
 * Function : void HLW8012_Measure(void)
 * Describe : 
 * Input    : none
 * Output   : none
 * Return   : none
 * Record   : 2014/04/14
=====================================================*/
void HLW8012_Measure(void)
{
  HLW8012_Measure_P();
  HLW8012_Measure_V();
  HLW8012_Measure_I(); 
  HLW8012_Measure_COS();
  HLW8012_Measure_E();
}


/*-------------------------------------------- EEPROM -------------------------------------------*/

/*=====================================================
 * ��������: void Read_CalData_EEPROM(void)
 * ��������: 
 * �������:
 * �������: 
 * ��    ��: 
=====================================================*/
void Read_CalData_EEPROM(void)
{
    u8  u8_temp;
    
    u8_temp = EEPROM_Read_Byte(ADDR_CAL_FLAG);
   
    U32_P_REF_PLUSEWIDTH_TIME = EEPROM_Read_Word(ADDR_REF_P_PLUSEWIDTH_TIME);
    U32_V_REF_PLUSEWIDTH_TIME = EEPROM_Read_Word(ADDR_REF_V_PLUSEWIDTH_TIME); 
    U32_I_REF_PLUSEWIDTH_TIME = EEPROM_Read_Word(ADDR_REF_I_PLUSEWIDTH_TIME); 
    
    U16_REF_001_E_Pluse_CNT = EEPROM_Read_Inte(ADDR_REF_001_E);
    U32_AC_BACKUP_E = EEPROM_Read_Word(ADDR_AC_BACKUP_E);  
    U32_AC_E = U32_AC_BACKUP_E;
        
              
    if (u8_temp != 0x55)	//�ж�EEPROM���Ƿ����У��ֵ,��û�У��򽫲�������ΪĬ��ֵ
    {
      //����Ĭ��ֵ
      U16_P_REF_Data = 10000;		// 1000.0W
      U16_V_REF_Data = 2200;		// 220.0V
      U16_I_REF_Data = 4545;		// 4.545A
  
      //Ĭ������
      U32_P_REF_PLUSEWIDTH_TIME = 4975;     // 4975us
      U32_V_REF_PLUSEWIDTH_TIME = 1666;      // 1666us
      U32_I_REF_PLUSEWIDTH_TIME = 1666;      // 1666us
      U32_AC_BACKUP_E = 0;
      U32_AC_E = 0;
    }
}

/*=====================================================
 * ��������: void Write_CalData_EEPROM(void)
 * ��������: 
 * �������:
 * �������: 
 * ��    ��: 
=====================================================*/
void Write_CalData_EEPROM(void)
{

	EEPROM_Write_Word(ADDR_REF_P_PLUSEWIDTH_TIME,U32_P_CURRENT_PLUSEWIDTH_TIME);
	EEPROM_Write_Word(ADDR_REF_V_PLUSEWIDTH_TIME,U32_V_CURRENT_PLUSEWIDTH_TIME); 
	EEPROM_Write_Word(ADDR_REF_I_PLUSEWIDTH_TIME,U32_I_CURRENT_PLUSEWIDTH_TIME); 
	EEPROM_Write_Inte(ADDR_REF_001_E,U16_REF_001_E_Pluse_CNT);
	EEPROM_Write_Word(ADDR_AC_BACKUP_E,0x00); 
        
        EEPROM_Write_Byte(ADDR_CAL_FLAG,0x55); 
        
        U32_AC_BACKUP_E = 0;
        U32_AC_E = 0;
}