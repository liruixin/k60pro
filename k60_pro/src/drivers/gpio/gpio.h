  #ifndef  __GPIO_H__   
  #define  __GPIO_H__   
    
  typedef  enum  PORTx   // �˿ں궨��    
  {   
    PORTA,   
    PORTB,   
    PORTC,   
    PORTD,   
     PORTE     
   }PORTx;   
     
   typedef  enum  IO    //����ܽŷ���   
   {   
     _I=0u,         // ����ܽ����뷽��    
     GPO=1u          //����ܽ��������    
   }IO;   
     
   #define  HIGH   1u    
   #define  LOW    0u    
     
   extern  volatile  struct  GPIO_MemMap *GPIOx[5];    
   extern  volatile struct   PORT_MemMap *PORTX[5];    
      
   void     gpio_init   (PORTx, u8 n,IO,u8  data);     //��ʼ�� gpio      
   void     gpio_set    (PORTx,   u8 n,       u8 data);    //��������״̬
     
   #endif