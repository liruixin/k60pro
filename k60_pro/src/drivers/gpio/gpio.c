   #include "common.h"   
   #include "gpio.h"          
     
     
   volatile struct GPIO_MemMap  *GPIOx[5]={PTA_BASE_PTR,PTB_BASE_PTR,PTC_BASE_PTR,PTD_BASE_PTR,PTE_BASE_PTR}; //定义五个指针数组保存  GPIOx  的地址   
   volatile struct PORT_MemMap  *PORTX[5]={PORTA_BASE_PTR,PORTB_BASE_PTR,PORTC_BASE_PTR,PORTD_BASE_PTR,PORTE_BASE_PTR};   
     
   /***********************************************************************
   *                                  野火嵌入式开发工作室  
   *    
   *  函数名称：gpio_init  
   *  功能说明：初始化 gpio    
   *  参数说明：PORTx         端口号（PORTA,PORTB,PORTC,PORTD,PORTE）  
   *              n             端口引脚   
   *              IO            引脚方向,0=输入,1=输出  
   *              data          输出初始状态,0= 低电平,1=高电平 （对输入无效）  
   *  函数返回：无  
   *  修改时间：2012-1 -15    已测试  
   *  备     注：  
   ***********************************************************************/
   void gpio_init (PORTx portx,  u8 n,IO cfg,u8  data)   
   {   
       ASSERT(  (n < 32u)   && (data <  2u)  );//使用断言检查输入、电平 是否为 1bit
 PORT_PCR_REG(PORTX[portx],n)=(0|PORT_PCR_MUX(1));     
          
       //端口方向控制输入还是输出     
       if(cfg == GPO) //output    
       {    
            GPIO_PDDR_REG(GPIOx[portx]) |=  (1<<n);       //端口方向为输出   
            if(data ==  1)//output   
            {   
                 GPIO_PDOR_REG(GPIOx[portx]) |=  (1<<n); // 对端口输出控制，输出为 1
            }   
       else  
            {   
                 GPIO_PDOR_REG(GPIOx[portx]) &=  ~(1<<n);// 对端口输出控制，输出为 0
            }   
       }      
       else  
            GPIO_PDDR_REG(GPIOx[portx]) &=  ~(1<<n);         //端口方向为输入    
   }   
     
   /***********************************************************************
   *                                  野火嵌入式开发工作室  
   *    
   *  函数名称：gpio_set  
   *  功能说明：设置引脚状态   
   *  参数说明：PORTx         端口号（PORTA,PORTB,PORTC,PORTD,PORTE）  
   *              n             端口引脚   
   *              data          输出初始状态,0= 低电平,1=高电平  
   *  函数返回：无  
   *  修改时间：2012-1 -16    已测试  
   *  备     注：  
   ***********************************************************************/
   void gpio_set (PORTx portx,  u8 n,  u8 data)    
   {   
       ASSERT(  (n < 32u)   && (data <  2u)  );//使用断言检查输入、电平 是否为 1bit
          
       if(data  == 1)                              
           GPIO_PDOR_REG(GPIOx[portx]) |=  (1<<n);       //输出高电平    
       else  
          GPIO_PDOR_REG(GPIOx[portx]) &=  ~(1<<n);      //出去低电平    
   }