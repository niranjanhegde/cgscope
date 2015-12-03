#include <xc.h>
#include "cn_int.h"
#include "../mcc_generated_files/mcc.h"


/******************************************************************************
 * CN INTERRUPT
 * This interrupt occures when change on input pin
 ******************************************************************************/

void CN_INTERRUPT_Initialize(void)
{
    TRISBbits.TRISB6|=1;
    CNEN2bits.CN24IE=1;  //RB1
    CNPU2bits.CN24PUE=0;
//    IPC4bits.CNIP=2;
    IFS1bits.CNIF=0;
    IEC1bits.CNIE=1;
}


/******************************************************************************
 * CN INTERRUPT
 * This interrupt occurs when change on input pin
 ******************************************************************************/

void __attribute__ ((__interrupt__, no_auto_psv)) _CNInterrupt(void)
{
    CN_InterruptFlagClear();
    asm("RESET");
}

/*
 *EOF
 */