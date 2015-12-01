/* 
 * File:   drv_74hc595.c
 * Author: Niranjan Hegde
 *
 * Created on 23 November, 2015, 4:58 PM
 */

#include "drv_74hc595.h"
#include "../mcc_generated_files/mcc.h"
uint8_t dot=0;
void Display_value(uint16_t value)
{
    uint8_t i=0;
    uint16_t number = value;    
    char myBuffer[6]={'\0'};
    char numChar[6]={'\0'};
    itoa(myBuffer, number, 10);
    GetStringReverse(myBuffer, numChar);
    Display_put('0');                   //put 0 after dot
    dot=1;
    for(i=0; i<5; i++)                  //put for 5 displays
    {
        if(numChar[i]!= '\0')           
        {
            Display_put(numChar[i]);    //if number present put to display
        }
        else
        {
            Display_put(NULL);          //if no number off the remaining display
        }
    }
    STCP_SetHigh();                     //Latch toggle to put display
    STCP_SetLow();       
}
void Display_put(char* dig)
{
    char digit = (char)dig;            //digit as local
    if(digit == NULL)
    {
        digit = 0;                      //if null select display_segment[0]
    }
    else
    {
        digit -= 47;                    //subtract ascii value to select array
    }
    /*display segment sequences*/
    const uint8_t const display_segment[]={0b00000000,0b01101111,0b00001010,0b01110110,0b01011110,0b00011011,0b01011101,0b01111101,0b00001110,0b01111111,0b01011111};
    uint8_t i=0;
    SHCP_SetLow();                      //clock
    STCP_SetLow();
    for(i=0; i<8; i++)
    {
        DS_PORT = ((display_segment[digit] & MASK(i))==0)?0:1; //On or Off
        SHCP_SetHigh();                 //clock
        SHCP_SetLow();
    }
}

void GetStringReverse(char *str, char*buff)
{
    //uint8_t j=0;
    int i=0;
    char *sptr;
    char *rptr;
    rptr=buff;
    sptr=str;
    while(*sptr)
    {
        sptr++;
        i++;
    }
    while(i>0)
    {
        sptr--;
        *rptr=*sptr;
        rptr++;
        --i;
    }
    *rptr='\0';
}