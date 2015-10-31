/* 
 * File:   time_counter.h
 * Author: MSB
 *
 * Created on October 9, 2015, 9:53 PM
 */

#ifndef TIME_COUNTER_H
#define	TIME_COUNTER_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <xc.h>

        
    /***************************************************************************
    * @Summary
        Set the desired timer with count.
    * @Description
        This routine is used to set the desired software timer with the delay 
        count required. There are three software timers 0,1,2 and the delay 
        is passed as parameter. Given delay value is decremented with the one 
        of the hardware timer interrupt. This timer is considered to be in 
        mili seconds. So the hardware timer should be set to give interrupt of 
        1ms. and values are decremented in that interrupt routine.
    * @Preconditions
        Hardware timer should be set to give a interrupt of 1ms.
    * @Param
        timer to be set- 0,1,2
        delay value    - in ms
    * @Returns
       none
    * @Example
       Timer_Soft_Start(1,100);
     while(condition)
     {
        //To do 
        if(HAL_TimerDone)
                    break;
     }
     
     **************************************************************************/
    void Timer_Soft_Start(unsigned char Timer, unsigned int Count);
    
/*******************************************************************************
 ******************************************************************************/  

    /***************************************************************************
    * @Summary
        Set the desired timer with count.
    * @Description
        This routine is used to check the desired software timer has experied 
        the delay time. Given delay value is decremented with the one 
        of the hardware timer interrupt. This timer is considered to be in 
        mili seconds. So the hardware timer should be set to give interrupt of 
        1ms. and values are decremented in that interrupt routine.
    * @Preconditions
        Hardware timer should be set to give a interrupt of 1ms.
    * @Param
        timer to be check- 0,1,2
        
    * @Returns
        Delay expired- true
        Delay not expired- false
    * @Example
       Timer_Soft_Start(1,100);
     while(condition)
     {
        //To do 
        if(Timer_Soft_Done)
                    break;
     }
     
     **************************************************************************/
    unsigned char Timer_Soft_Done(unsigned char Timer);
    
/*******************************************************************************
 ******************************************************************************/  

    /***************************************************************************
    * @Summary
        Delay loop which waits for the desired delay.
    * @Description
        This routine is used to wait for the given delay time.
        Given delay value is decremented with the one of the hardware timer 
        interrupt. This timer is considered to be in mili seconds. So the 
        hardware timer should be set to give interrupt of 1ms. and values 
        are decremented in that interrupt routine.
    * @Preconditions
        Hardware timer should be set to give a interrupt of 1ms.
    * @Param
        delay time- in miliseconds
        
    * @Returns
        None
    * @Example
       HAL_TimerDelay(100);
     **************************************************************************/
    void Timer_Soft_Delay_MS(unsigned int NumMilliseconds);
    
/*******************************************************************************
 ******************************************************************************/ 

    void Time_Counter_Update(void);

#ifdef	__cplusplus
}
#endif

#endif	/* TIME_COUNTER_H */

