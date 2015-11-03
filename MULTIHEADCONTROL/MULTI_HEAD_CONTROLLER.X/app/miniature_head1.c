 /* 
 * File:   miniature_control.h
 * Author: Niranjan Hegde
 *
 * Created on 17 October, 2015, 6:23 PM
 */

#include "miniature_head1.h"
#include "../mcc_generated_files/mcc.h"

STATES state_min_head1;
void Miniature_head1(void)
{
    switch(state_min_head1)
    {
        case STEP1:
        {
            LED_OP1_SetLow();
            BOTTOM_COIL_SetHigh();
            SPIKE_COIL_LEFT_SetHigh();
            SPIKE_COIL_RIGHT_SetHigh();
            TILT_COIL_SetHigh();
            if(BUTTON_START_GetValue()==0)
            {
                state_min_head1=STEP2;
            }
            break;
        }
        case STEP2:
        {
            LED_OP1_SetHigh();          //LED off
            PURGE_COIL_SetHigh();
            MAG_COIL_SetHigh();
            Timer_Soft_Delay_MS(250);   //Delay of 250ms
            PURGE_COIL_SetLow();
            SEAL_COIL_SetHigh();
            HEATER_TOP_SetHigh();
            TMR1_LED_SetLow();          //Time count LED On
            Timer_Soft_Delay_MS(10000);
            HEATER_TOP_SetLow();
            TMR1_LED_SetHigh();         //Time count LED off
            Timer_Soft_Delay_MS(1000);  //Cooling delay
            HEATER_BOT_SetHigh();
            TMR2_LED_SetLow();          //Time count LED On
            Timer_Soft_Delay_MS(10000);
            state_min_head1=STEP3;
            break;
        }
        case STEP3:
        {
            BOTTOM_COIL_SetLow();
            SPIKE_COIL_LEFT_SetLow();
            SPIKE_COIL_RIGHT_SetLow();
            TILT_COIL_SetLow();
            SEAL_COIL_SetLow();
            MAG_COIL_SetLow();
            TMR2_LED_SetHigh();         //Time count LED off
            Timer_Soft_Delay_MS(3000);
            state_min_head1=STEP4;
            break;
        }
        
        case STEP4:
        {
                HEATER_BOT_SetLow();
                Timer_Soft_Delay_MS(6000);      
                COUNTER_SetLow();       //Counter On
                Timer_Soft_Delay_MS(1000);      
                COUNTER_SetHigh();      //Counter Off
            state_min_head1=STEP1;
            break;
        }
    }
}
