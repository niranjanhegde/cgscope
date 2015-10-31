/* 
 * File:   time_counter.c
 * Author: MSB
 *
 * Created on October 9, 2015, 9:53 PM
 */


#include "mcc.h"

    volatile unsigned int msec;
    volatile unsigned int TickCount[3] = {0, 0, 0};      //Keep track of three software timers
    unsigned int sec,min;
    extern unsigned int count1;
    
void Time_Counter_Update(void)
{
    if(msec > 999)
    {
        msec=0;
        sec++;
        count1++;
    }
    if(sec > 59)
    {
        sec=0;
        min++;
    }
    if(min > 59)
    {
        min=0;
    }
    if(count1 > 50)
    {
        count1=0;
    }
}

//**********************************************************************************************************************
// Start one of the software timers

void Timer_Soft_Start(unsigned char Timer, unsigned int Count)
{
    TickCount[Timer] = Count;               //SelectTimer and load the count down time;
}

//**********************************************************************************************************************
// Check if one of the software software timers has timed out

unsigned char Timer_Soft_Done(unsigned char Timer)
{
    if(TickCount[Timer] == 0)               //Check if counted down to zero
        return true;                        //then return true
    return false;                           //else return false
}

//**********************************************************************************************************************
// Simple delay for n milliseconds

void Timer_Soft_Delay_MS(unsigned int NumMilliseconds)
{
    unsigned int mili=NumMilliseconds;
    Timer_Soft_Start(2, mili);         //Start software timer 2
    while(!Timer_Soft_Done(2));                   //and wait for it to count down
}