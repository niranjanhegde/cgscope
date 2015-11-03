/* 
 * File:   stepper_motor.h
 * Author: Niranjan Hegde
 *
 * Created on 16 October, 2015, 12:24 PM
 */
#include "stepper_motor.h"
#include "../mcc_generated_files/mcc.h"
int i=0;
STEPPER stepper1;   
void StepperMotor_Forward(void)
{
    
    for(i=0; i<10; i++)
    {
        stepper1.Stepper=0b0110;
        StepperMotor_OP_update();
        Timer_Soft_Delay_MS(50);

        stepper1.Stepper=0b1010;
        StepperMotor_OP_update();
        Timer_Soft_Delay_MS(50);

        stepper1.Stepper=0b1001;
        StepperMotor_OP_update();
        Timer_Soft_Delay_MS(50);

        stepper1.Stepper=0b0101;
        StepperMotor_OP_update();
        Timer_Soft_Delay_MS(50);
    }
}

void StepperMotor_Reverse(void)
{
    for(i=0; i<10; i++)
    {
        stepper1.Stepper=0b0101;
        StepperMotor_OP_update();
        Timer_Soft_Delay_MS(50);

        stepper1.Stepper=0b1001;
        StepperMotor_OP_update();
        Timer_Soft_Delay_MS(50);

        stepper1.Stepper=0b1010;
        StepperMotor_OP_update();
        Timer_Soft_Delay_MS(50);

        stepper1.Stepper=0b0110;
        StepperMotor_OP_update();
        Timer_Soft_Delay_MS(50);
    }
}

void StepperMotor_OP_update(void)
{
    STEP_A = stepper1.motors.STEPA;
    STEP_A_BAR = stepper1.motors.STEPA_BAR;
    STEP_B = stepper1.motors.STEPB;
    STEP_B_BAR = stepper1.motors.STEPB_BAR;
}