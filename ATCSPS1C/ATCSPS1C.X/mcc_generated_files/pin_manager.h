/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB® Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC16F1503
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X v2.35 or v3.00
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SENSOR2 aliases
#define SENSOR2_TRIS               TRISA4
#define SENSOR2_LAT                LATA4
#define SENSOR2_PORT               RA4
#define SENSOR2_WPU                WPUA4
#define SENSOR2_ANS                ANSA4
#define SENSOR2_SetHigh()    do { LATA4 = 1; } while(0)
#define SENSOR2_SetLow()   do { LATA4 = 0; } while(0)
#define SENSOR2_Toggle()   do { LATA4 = ~LATA4; } while(0)
#define SENSOR2_GetValue()         RA4
#define SENSOR2_SetDigitalInput()    do { TRISA4 = 1; } while(0)
#define SENSOR2_SetDigitalOutput()   do { TRISA4 = 0; } while(0)

#define SENSOR2_SetPullup()    do { WPUA4 = 1; } while(0)
#define SENSOR2_ResetPullup()   do { WPUA4 = 0; } while(0)
#define SENSOR2_SetAnalogMode()   do { ANSA4 = 1; } while(0)
#define SENSOR2_SetDigitalMode()   do { ANSA4 = 0; } while(0)
// get/set SENSOR1 aliases
#define SENSOR1_TRIS               TRISA5
#define SENSOR1_LAT                LATA5
#define SENSOR1_PORT               RA5
#define SENSOR1_WPU                WPUA5
#define SENSOR1_SetHigh()    do { LATA5 = 1; } while(0)
#define SENSOR1_SetLow()   do { LATA5 = 0; } while(0)
#define SENSOR1_Toggle()   do { LATA5 = ~LATA5; } while(0)
#define SENSOR1_GetValue()         RA5
#define SENSOR1_SetDigitalInput()    do { TRISA5 = 1; } while(0)
#define SENSOR1_SetDigitalOutput()   do { TRISA5 = 0; } while(0)

#define SENSOR1_SetPullup()    do { WPUA5 = 1; } while(0)
#define SENSOR1_ResetPullup()   do { WPUA5 = 0; } while(0)
// get/set OUTPUT aliases
#define OUTPUT_TRIS               TRISC1
#define OUTPUT_LAT                LATC1
#define OUTPUT_PORT               RC1
#define OUTPUT_ANS                ANSC1
#define OUTPUT_SetHigh()    do { LATC1 = 1; } while(0)
#define OUTPUT_SetLow()   do { LATC1 = 0; } while(0)
#define OUTPUT_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define OUTPUT_GetValue()         RC1
#define OUTPUT_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define OUTPUT_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

#define OUTPUT_SetAnalogMode()   do { ANSC1 = 1; } while(0)
#define OUTPUT_SetDigitalMode()   do { ANSC1 = 0; } while(0)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
 */