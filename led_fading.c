#include "debug.h"

void GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD , ENABLE); // Enable clock for GPIOD
// Configure GPIOD Pin 6 as a 50 MHz push-pull output
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; 
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

        
// Gradually increase the LED "on" time (simulate LED brightening)
        for(int i=0;i<=1500;i++){
        GPIO_WriteBit(GPIOD, GPIO_Pin_6, SET);
        Delay_Us(i);
        GPIO_WriteBit(GPIOD, GPIO_Pin_6, RESET);
        Delay_Us(1500-i);}
// Gradually decrease the LED "on" time (simulate LED dimming)
        for(int i=1500;i>=0;i--){
        GPIO_WriteBit(GPIOD, GPIO_Pin_6, SET);
        Delay_Us(i);
        GPIO_WriteBit(GPIOD, GPIO_Pin_6, RESET);
        Delay_Us(1500-i);}
    }
}
