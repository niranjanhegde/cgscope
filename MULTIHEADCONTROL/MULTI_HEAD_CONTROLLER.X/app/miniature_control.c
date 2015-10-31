 /* 
 * File:   miniature_control.h
 * Author: Niranjan Hegde
 *
 * Created on 17 October, 2015, 6:23 PM
 */

#include "miniature_control.h"
#include "../mcc_generated_files/mcc.h"

STATES states;
void Miniature_Sequence1(void)
{
    switch(states)
    {
        case STEP1:
        {
            TILT_TOP_COIL_SetHigh();
            TILT_BOT_COIL_SetHigh();
            LED_OP1_SetHigh();
            if(BUTTON_START_GetValue())
            {
                states=STEP2;
            }
            break;
        }
        case STEP2:
        {
            MAG_COIL_SetHigh();
            PURGE_COIL_SetHigh();
            LED_OP1_SetLow();
            Timer_Soft_Delay_MS(250);
            HEATER_TOP_SetHigh();
            EXT_TMR1_TRIG_SetHigh();
            Timer_Soft_Delay_MS(10);
            states=STEP3;
            break;
        }
        case STEP3:
        {
            if(EXT_TMR1_OV_GetValue()==0)
            {
                EXT_TMR1_TRIG_SetLow();
                TILT_TOP_COIL_SetLow();
                TILT_BOT_COIL_SetLow();
                MAG_COIL_SetLow();
                PURGE_COIL_SetLow();
                HEATER_TOP_SetLow();
                HEATER_BOT_SetHigh();
                Timer_Soft_Delay_MS(4500);
                HEATER_BOT_SetLow();
                EXT_TMR2_TRIG_SetHigh();
                states=STEP4;
            }
            break;
        }
        
        case STEP4:
        {
            StepperMotorCOntrol();
            states=STEP1;
            break;
        }
    }
}
