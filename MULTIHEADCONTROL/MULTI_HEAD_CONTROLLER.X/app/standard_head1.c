/* 
 * File:   standard_head1.c
 * Author: niru
 *
 * Created on 8 November, 2015, 11:34 AM
 */

#include "../mcc_generated_files/mcc.h"
#include "standard_head1.h"

STATES states_std_head1;
STD_HEAD_TIMERS std_head_timer;

void Standard_head1(void)
{
    switch(states_std_head1)
    {
        case STEP1:
        {
            LED_OP1_SetHigh();      // led on
            SPIKE_COIL_LEFT_SetHigh();      //Tilt coil in this application
            BOTTOM_COIL_SetHigh();      //Glass Hold in this application
            if(CARRAGE_UP_CONF_GetValue()== 0)  // button is used to confirm
            {
                states_std_head1=STEP2;
            }
            break;
        }
        case STEP2:
        {
            LED_OP1_SetLow();
            AIR_COIL_SetHigh();
            MAG_COIL_SetHigh();
            if(BUTTON_START_GetValue() == 0)
            {
                states_std_head1=STEP3;
            }
            break;
        }
        case STEP3:
        {
            PURGE_COIL_SetHigh();
            Timer_Soft_Delay_MS(250);
            PURGE_COIL_SetLow();
            SEAL_COIL_SetHigh();
            HEATER_BOT_SetLow();
            TMR2_LED_SetLow();                    //Heater bott0om LED ON 
            TMR_TOP_TRIG_SetLow();      // External Timer pulse
            Timer_Soft_Delay_MS(500);
            TMR_TOP_TRIG_SetHigh();     // External Timer pulse
            Timer_Soft_Delay_MS(500);
            states_std_head1=STEP4;
            break;
        }
        case STEP4:
        {
            if(TMR_TOP_ELAPS_GetValue() == 1)
            {
                std_head_timer.std_timer1_start=1;

                TMR_BOT_TRIG_SetLow();     // External Timer pulse
                Timer_Soft_Delay_MS(500);
                TMR_BOT_TRIG_SetHigh();     // External Timer pulse

                HEATER_TOP_SetLow();        // Heater Top On
                TMR1_LED_SetLow();          // Heater top LED ON

                states_std_head1=STEP5;
            }
            break;
        }
        case STEP5:
        {
            if(std_head_timer.std_timer1 == 40)
            {
                HEATER_BOT_SetHigh();       // heater bottom off
                TMR2_LED_SetHigh();         //LED OFF
            }
            if(std_head_timer.std_timer1 == 62)
            {
                SEAL_COIL_SetLow();         //Gas in this application
            }
            if(std_head_timer.std_timer1 == 64)
            {
                MAG_COIL_SetLow();          
            }
            if(std_head_timer.std_timer1 == 68)
            {
                SPIKE_COIL_LEFT_SetLow();     //GAP solenoid 
                SPIKE_COIL_RIGHT_SetHigh();   //GAP solenoid     
                states_std_head1 = STEP6;
            }
            break;
        }
        case STEP6:
        {
            if(TMR_BOT_ELAPS_GetValue() == 1)
            {
                HEATER_TOP_SetHigh();       // heater bottom off
                TMR1_LED_SetHigh();         //LED OFF
                std_head_timer.std_timer2_start=1;
                states_std_head1=STEP7;
            }
            break;
        }
        case STEP7:
        {
            if(std_head_timer.std_timer2==13)
            {
                AIR_COIL_SetLow();
                std_head_timer.std_timer1=0;
                std_head_timer.std_timer2=0;
                std_head_timer.std_timer1_start=0;
                std_head_timer.std_timer2_start=0;
                
                COUNTER_SetHigh();
                Timer_Soft_Delay_MS(1000);
                COUNTER_SetLow();
                BOTTOM_COIL_SetLow();         //Glass Hold
                SPIKE_COIL_RIGHT_SetLow();
            }
            break;
        }
    }
}