/* 
 * File:   cn_int.h
 * Author: Niranjan
 *
 * Created on 12 May, 2015, 8:16 PM
 */

#ifndef CN_INT_H
#define	CN_INT_H

#include <xc.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define CN_InterruptFlagClear()       (IFS1bits.CNIF = 0)

    /*@Summary: 
     *  This function Initializes Change Notification Interrupt on Pin RA0
     *@Description:
     *  Initialize the port pin RA0 as Change Notification Interrupt by setting
     *  according registers.
     *@Parameters:
     *  None.
     *@Returns:
     *  None. 
     *@Function:
     *  void CN_INTERRUPT_Initialize(void);
     */
    void CN_INTERRUPT_Initialize(void);

#ifdef	__cplusplus
}
#endif

#endif	/* CN_INT_H */

