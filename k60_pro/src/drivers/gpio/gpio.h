  #ifndef  __GPIO_H__   
  #define  __GPIO_H__   
    
  typedef  enum  PORTx   // 端口宏定义    
  {   
    PORTA,   
    PORTB,   
    PORTC,   
    PORTD,   
     PORTE     
   }PORTx;   
     
   typedef  enum  IO    //定义管脚方向   
   {   
     _I=0u,         // 定义管脚输入方向    
     GPO=1u          //定义管脚输出方向    
   }IO;   
     
   #define  HIGH   1u    
   #define  LOW    0u    
     
   extern  volatile  struct  GPIO_MemMap *GPIOx[5];    
   extern  volatile struct   PORT_MemMap *PORTX[5];    
      
   void     gpio_init   (PORTx, u8 n,IO,u8  data);     //初始化 gpio      
   void     gpio_set    (PORTx,   u8 n,       u8 data);    //设置引脚状态
     
   #endif