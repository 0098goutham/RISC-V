// led on and off based on time delay, using the VSDSQUADRON MINI

#include "debug.h"

void GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0}; // Initialize a structure to configure GPIO settings.

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD , ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; // Pin 6 of GPIOD is selected
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(GPIOD, &GPIO_InitStructure);  
    }
    
    
int main(void){

    SystemCoreClockUpdate();
    Delay_Init();
    GPIO_Config();
    SystemInit();

    while(1){
        
        GPIO_WriteBit(GPIOD, GPIO_Pin_6, SET);
        Delay_Ms(1000); // Change the time delay
        GPIO_WriteBit(GPIOD, GPIO_Pin_6, RESET);
        Delay_Ms(1000); // Change the time delay
    }
}
