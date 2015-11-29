/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB® Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC24FJ64GA004
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.24
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

#include "mcc_generated_files/mcc.h"
#include "app/miniature_head1.h"
#include "app/standard_head1.h"

/*
                         Main application
 */

unsigned int count1;
HEAD_SELECT head_select;
bool PRG_RST_Flag=0; 


int main(void) {
    // initialize the device
    //stepper1.Stepper=0b1111;
    SYSTEM_Initialize();

    if(HEAD_SELECT_1_GetValue() == 0) head_select=Minuature_Head1;
    else if(HEAD_SELECT_2_GetValue() == 0) head_select=Minuature_Head2;
    else if(HEAD_SELECT_3_GetValue() == 0) head_select=Standard_Head1;
    else if(HEAD_SELECT_4_GetValue() == 0) head_select=Standard_Head2;
    TMR_TOP_TRIG_SetHigh();
    TMR_BOT_TRIG_SetHigh();
    while (1)
    {  
//        if(PRG_RST_Flag == 0)
//        {
//            //SYSTEM_Initialize();
//            LATA = 0x011C;
//            LATB = 0x10;
//            LATC = 0x1C;
//
//    PRG_RST_Flag=1;
//            
//        }
//        else
//        {
            Time_Counter_Update();
            if(head_select==Minuature_Head1)
            {
                HEAD_SELECT_LED1_SetLow();
                HEAD_SELECT_LED2_SetHigh();
                HEAD_SELECT_LED3_SetHigh();
                HEAD_SELECT_LED4_SetHigh();
                Miniature_head1();
            }
            else if (head_select==Minuature_Head2)
            {
                HEAD_SELECT_LED1_SetHigh();
                HEAD_SELECT_LED2_SetLow();
                HEAD_SELECT_LED3_SetHigh();
                HEAD_SELECT_LED4_SetHigh();
                Miniature_head2();
            }
            else if (head_select==Standard_Head1)
            {
                HEAD_SELECT_LED1_SetHigh();
                HEAD_SELECT_LED2_SetHigh();
                HEAD_SELECT_LED3_SetLow();
                HEAD_SELECT_LED4_SetHigh();
                Standard_head1();
            }
            else if (head_select==Standard_Head2)
            {
                HEAD_SELECT_LED1_SetHigh();
                HEAD_SELECT_LED2_SetHigh();
                HEAD_SELECT_LED3_SetHigh();
                HEAD_SELECT_LED4_SetLow();
                Standard_head2();
            }
        //}
    }
}
/**
 End of File
 */