   #include "common.h"   
   #include "gpio.h"          
     
     
   volatile struct GPIO_MemMap  *GPIOx[5]={PTA_BASE_PTR,PTB_BASE_PTR,PTC_BASE_PTR,PTD_BASE_PTR,PTE_BASE_PTR}; //�������ָ�����鱣��  GPIOx  �ĵ�ַ   
   volatile struct PORT_MemMap  *PORTX[5]={PORTA_BASE_PTR,PORTB_BASE_PTR,PORTC_BASE_PTR,PORTD_BASE_PTR,PORTE_BASE_PTR};   
     
   /***********************************************************************
   *                                  Ұ��Ƕ��ʽ����������  
   *    
   *  �������ƣ�gpio_init  
   *  ����˵������ʼ�� gpio    
   *  ����˵����PORTx         �˿ںţ�PORTA,PORTB,PORTC,PORTD,PORTE��  
   *              n             �˿�����   
   *              IO            ���ŷ���,0=����,1=���  
   *              data          �����ʼ״̬,0= �͵�ƽ,1=�ߵ�ƽ ����������Ч��  
   *  �������أ���  
   *  �޸�ʱ�䣺2012-1 -15    �Ѳ���  
   *  ��     ע��  
   ***********************************************************************/
   void gpio_init (PORTx portx,  u8 n,IO cfg,u8  data)   
   {   
       ASSERT(  (n < 32u)   && (data <  2u)  );//ʹ�ö��Լ�����롢��ƽ �Ƿ�Ϊ 1bit
 PORT_PCR_REG(PORTX[portx],n)=(0|PORT_PCR_MUX(1));     
          
       //�˿ڷ���������뻹�����     
       if(cfg == GPO) //output    
       {    
            GPIO_PDDR_REG(GPIOx[portx]) |=  (1<<n);       //�˿ڷ���Ϊ���   
            if(data ==  1)//output   
            {   
                 GPIO_PDOR_REG(GPIOx[portx]) |=  (1<<n); // �Զ˿�������ƣ����Ϊ 1
            }   
       else  
            {   
                 GPIO_PDOR_REG(GPIOx[portx]) &=  ~(1<<n);// �Զ˿�������ƣ����Ϊ 0
            }   
       }      
       else  
            GPIO_PDDR_REG(GPIOx[portx]) &=  ~(1<<n);         //�˿ڷ���Ϊ����    
   }   
     
   /***********************************************************************
   *                                  Ұ��Ƕ��ʽ����������  
   *    
   *  �������ƣ�gpio_set  
   *  ����˵������������״̬   
   *  ����˵����PORTx         �˿ںţ�PORTA,PORTB,PORTC,PORTD,PORTE��  
   *              n             �˿�����   
   *              data          �����ʼ״̬,0= �͵�ƽ,1=�ߵ�ƽ  
   *  �������أ���  
   *  �޸�ʱ�䣺2012-1 -16    �Ѳ���  
   *  ��     ע��  
   ***********************************************************************/
   void gpio_set (PORTx portx,  u8 n,  u8 data)    
   {   
       ASSERT(  (n < 32u)   && (data <  2u)  );//ʹ�ö��Լ�����롢��ƽ �Ƿ�Ϊ 1bit
          
       if(data  == 1)                              
           GPIO_PDOR_REG(GPIOx[portx]) |=  (1<<n);       //����ߵ�ƽ    
       else  
          GPIO_PDOR_REG(GPIOx[portx]) &=  ~(1<<n);      //��ȥ�͵�ƽ    
   }