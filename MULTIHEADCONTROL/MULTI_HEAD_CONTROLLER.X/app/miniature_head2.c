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
            LED_OP1_SetHigh();
            BOTTOM_COIL_SetHigh();
            SPIKE_COIL_LEFT_SetHigh();
            SPIKE_COIL_RIGHT_SetHigh();
            TILT_COIL_SetHigh();
            if(BUTTON_START_GetValue()==0)
            {
                state_min_head2=STEP2;
            }
            break;
        }
        case STEP2:
        {
            LED_OP1_SetLow();           //LED off
            PURGE_COIL_SetHigh();       //Purge coil on
            MAG_COIL_SetHigh();         // Magnetic coil on
            Timer_Soft_Delay_MS(250);   //Delay of 250 Ms
            PURGE_COIL_SetLow();        // Purge coil off
            SEAL_COIL_SetHigh();        // Seal coil on
            HEATER_TOP_SetLow();        // Heater Top SSR On
            TMR1_LED_SetLow();          //Time count LED On
            TMR_TOP_TRIG_SetLow();      // External Timer pulse
            Timer_Soft_Delay_MS(500);
            TMR_TOP_TRIG_SetHigh();     // External Timer pulse
            Timer_Soft_Delay_MS(500);
            state_min_head2=STEP3;
            break;
        }
        case STEP3:
        {
            if(TMR_TOP_ELAPS_GetValue() == 1)
            {
                state_min_head2=STEP4;
            }
            break;
        }
        case STEP4:
        {
            
            //Timer_Soft_Delay_MS(8000);  // Heater top on time
            HEATER_TOP_SetHigh();       // Heater TOP SSR OFF
            TMR1_LED_SetHigh();         //Time count LED off
            Timer_Soft_Delay_MS(1000);  //Cooling delay
            HEATER_BOT_SetLow();        // Bottom heater on
            TMR2_LED_SetLow();          //Time count LED On
            TMR_BOT_TRIG_SetLow();     // External Timer pulse
            Timer_Soft_Delay_MS(500);
            TMR_BOT_TRIG_SetHigh();     // External Timer pulse
            Timer_Soft_Delay_MS(500);
            StepperMotor_Reverse();
            state_min_head2=STEP5;
            break;
        }
        case STEP5:
        {
            if(TMR_BOT_ELAPS_GetValue() == 1)
            {
                state_min_head2=STEP6;
            }
            break;
        }
        case STEP6:
        {
            BOTTOM_COIL_SetLow();       // Bottom coil off
            
            SEAL_COIL_SetLow();         // seal coil off
            SPIKE_COIL_LEFT_SetLow();   // spike coil left off         
            SPIKE_COIL_RIGHT_SetLow();  // spike coil right off
            TILT_COIL_SetLow();         // tilt coil off            
            MAG_COIL_SetLow();          // mag coil off
            Timer_Soft_Delay_MS(1);  // 
           // StepperMotor_Reverse();
           // Timer_Soft_Delay_MS(1);
            state_min_head2=STEP7;
            break;
        }
        
        case STEP7:
        {
            HEATER_BOT_SetHigh();    // Heater bottom off
            TMR2_LED_SetHigh();      //Time count LED off
            Timer_Soft_Delay_MS(6000);      
            COUNTER_SetHigh();        //Counter On
            Timer_Soft_Delay_MS(1000);      
            COUNTER_SetLow();        //Counter Off
            StepperMotor_Forward();
            state_min_head2=STEP1;
            break;
        }
    }
}

