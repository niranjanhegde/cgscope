/* 
 * File:   miniature_head2.c
 * Author: Niranjan Hegde
 *
 * Created on 3 November, 2015, 10:19 PM
 */

#include "miniature_head2.h"
#include "../mcc_generated_files/mcc.h"

STATES state_min_head2;
void Miniature_head2(void)
{
    switch(state_min_head2)
    {
        case STEP1:
        {
            LED_OP1_SetLow();
            BOTTOM_COIL_SetHigh();
            SPIKE_COIL_LEFT_SetHigh();
            SPIKE_COIL_RIGHT_SetHigh();
            TILT_COIL_SetHigh();
            StepperMotor_Forward();
            state_min_head2=STEP2;
            break;
        }
        case STEP2:
        {
            if(BUTTON_START_GetValue()==0)
            {
                state_min_head2=STEP3;
            }
            break;
        }
        case STEP3:
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
            state_min_head2=STEP4;
            break;
        }
        case STEP4:
        {
            BOTTOM_COIL_SetLow();
            SPIKE_COIL_LEFT_SetLow();
            SPIKE_COIL_RIGHT_SetLow();
            TILT_COIL_SetLow();
            SEAL_COIL_SetLow();
            MAG_COIL_SetLow();
            StepperMotor_Reverse();
            TMR2_LED_SetHigh();         //Time count LED off
            Timer_Soft_Delay_MS(3000);
            state_min_head2=STEP5;
            break;
        }
        
        case STEP5:
        {
                HEATER_BOT_SetLow();
                Timer_Soft_Delay_MS(6000);      
                COUNTER_SetLow();       //Counter On
                Timer_Soft_Delay_MS(1000);      
                COUNTER_SetHigh();      //Counter Off
            state_min_head2=STEP1;
            break;
        }
    }
}

