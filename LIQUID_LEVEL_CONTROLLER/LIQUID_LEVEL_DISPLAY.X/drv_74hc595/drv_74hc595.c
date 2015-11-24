/* 
 * File:   drv_74hc595.c
 * Author: Niranjan Hegde
 *
 * Created on 23 November, 2015, 4:58 PM
 */

#include "drv_74hc595.h"
#include "../mcc_generated_files/mcc.h"

void Display_value(unsigned int value)
{
    unsigned int num=value;
    uint8_t i=0;
    long power=1;
    uint8_t power_count=0;
    if(num == 0 || num == 1)
    {
        uint8_t digit = num;
        Display_put(digit);
    }
    else
    {
        while(num > power)  
        {
            power*=10;
            ++power_count;
        }
        if((num % power)!=0) {power/=10;}
        else{
            ++power_count;
        }

        while(num != 0)
        {
             int digit = num/power;
             Display_put(digit);
             if(digit != 0) num = num-digit*power;
             if(power != 1) power/=10;
             //if((num % power)==0)++power_count;
             --power_count;
        }
        if(power_count>1)
        {
            for(i=0; i<power_count; i++)
            {
                Display_put(0);
            }
        }
    }
    STCP_SetHigh();
    STCP_SetLow();
}
void Display_put(uint8_t dig)
{
    uint8_t display_segment[]={0b11111100,0b01100000,0b11011010,0b11110010,0b01100110,0b10110110,0b10111110,0b11100000,0b11111110,0b11110110};
    int i=0;
    SHCP_SetLow();
    STCP_SetLow();
    for(i=0; i<8; i++)
    {
        DS_PORT = ((display_segment[dig] & MASK(i))==0)?0:1;
        SHCP_SetHigh();
        SHCP_SetLow();
    }
//    STCP_SetHigh();
//    STCP_SetLow();
}