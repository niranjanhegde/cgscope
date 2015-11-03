/* 
 * File:   stepper_motor.h
 * Author: Niranjan Hegde
 *
 * Created on 16 October, 2015, 12:24 PM
 */

#ifndef STEPPER_MOTOR_H
#define	STEPPER_MOTOR_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <xc.h>

    typedef union
    {
        unsigned int Stepper;
        struct
        {
            unsigned int STEPA:1;
            unsigned int STEPA_BAR:1;
            unsigned int STEPB:1;
            unsigned int STEPB_BAR:1;
        }motors;
    }STEPPER;

    void StepperMotor_Forward(void);
    void StepperMotor_Reverse(void);
    void StepperMotor_OP_update(void);


#ifdef	__cplusplus
}
#endif

#endif	/* STEPPER_MOTOR_H */

