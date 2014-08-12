#include "common.h"  
#include "gpio.h"
#include "lptmr.h"  // 延时 
  /**********************************************************************  
  *                                  野火嵌入式开发工作室  
  *                                    GPIO 实验简单测试  
  *  实验说明：野火 GPIO 实验，利用 LED 来显示电平高低  
  *  
  *  实验操作：无   
  *  
   *  实验效果：LED0 每隔 500ms  
   *  
   *  实验目的：明白如何设置 IO 口电平  
   *  
   *  修改时间：2012-2 -28      已测试  
   *  
   *  备     注：野火 Kinetis 开发板的 LED0~3 ，分别接 PTD15~PTD12 ，低电平点亮  
   *************************************************************************/
 
   void  main(void)          
   {   
       gpio_init(PORTA,17,GPO,HIGH);//初始化 PTD15：输出高电平 ,即 初始化 LED0，灭
       while(1)   
       {        
            gpio_set(PORTA,17,LOW);    //设置 PTD15 输出 低电平 ,  即 LED0 亮    
            time_delay_ms(500);         //延时 500ms    
            gpio_set(PORTA,17,HIGH);   //设置 PTD15 输出 高电平 ,  即 LED0 灭    
            time_delay_ms(500);         //延时 500ms             
       }    
   }