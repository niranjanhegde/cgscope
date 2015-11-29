/* 
 * File:   standard_head1.c
 * Author: niru
 *
 * Created on 8 November, 2015, 11:34 AM
 */

#include "../mcc_generated_files/mcc.h"
#include "standard_head1.h"

STATES states_std_head1;
STD_HEAD_TIMERS std_head1_timer;

void Standard_head1(void)
{
    switch(states_std_head1)
    {
        case STEP1:
        {
            LED_OP1_SetHigh();      // led on
            SPIKE_COIL_LEFT_SetHigh();      //Tilt coil in this application
//            if(CARRAGE_UP_GetValue()== 0)       
//            {
                BOTTOM_COIL_SetHigh();      //Glass Hold in this application
                states_std_head1=STEP2;
//            }
            break;
        }
        case STEP2:
        {
            if(CARRAGE_UP_CONF_GetValue()== 0)  // button is used to confirm
            {
                states_std_head1=STEP3;
            }
            break;
           
        }
        case STEP3:
            
        {
            LED_OP1_SetLow();
            AIR_COIL_SetHigh();
            MAG_COIL_SetHigh();
            if(BUTTON_START_GetValue() == 0)
            {
                states_std_head1=STEP4;
            }
            break;
        }
        
        case STEP4:
        {
            PURGE_COIL_SetHigh();
            Timer_Soft_Delay_MS(250);
            PURGE_COIL_SetLow();
            SEAL_COIL_SetHigh();
            HEATER_BOT_SetLow();
            TMR2_LED_SetLow();                    //Heater bottom LED ON       
            std_head1_timer.std_timer1_start=1;
            states_std_head1= STEP5;
            break;
        }
        case STEP5:
        {
            if(std_head1_timer.std_timer1 == 14)
            {
                HEATER_TOP_SetLow();        // Heater Top On
                TMR1_LED_SetLow();          // Heater top LED ON
            }
            if(std_head1_timer.std_timer1 == 54)
            {
                HEATER_BOT_SetHigh();       // heater bottom off
                TMR2_LED_SetHigh();         //LED OFF
            }
            if(std_head1_timer.std_timer1 == 76)
            {
                SEAL_COIL_SetLow();         //Gas in this application
            }
            if(std_head1_timer.std_timer1 == 78)
            {
                MAG_COIL_SetLow();          
            }
            if(std_head1_timer.std_timer1 == 82)
            {
                SPIKE_COIL_LEFT_SetLow();     //GAP solenoid 
                SPIKE_COIL_RIGHT_SetHigh();   //GAP solenoid     
               
            }
            if(std_head1_timer.std_timer1 == 86)
            {
                HEATER_TOP_SetHigh();       // heater bottom off
                TMR1_LED_SetHigh();         //LED OFF
                
            }
            if(std_head1_timer.std_timer1 == 98)
            {
                AIR_COIL_SetLow();
                std_head1_timer.std_timer1_start=0;
                std_head1_timer.std_timer1=0; 
                states_std_head1 = STEP6;
            }

            break;
        }
        case STEP6:
        {

            COUNTER_SetHigh();
            Timer_Soft_Delay_MS(1000);
            COUNTER_SetLow();
            BOTTOM_COIL_SetLow();         //Glass Hold
            SPIKE_COIL_RIGHT_SetLow();
            states_std_head1 = STEP1;
            break;
        }
    }
}