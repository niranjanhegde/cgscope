/* 
 * File:   miniature_control.h
 * Author: Niranjan Hegde
 *
 * Created on 17 October, 2015, 6:23 PM
 */

#ifndef MINIATURE_CONTROL_H
#define	MINIATURE_CONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef enum
    {
        STEP1=0,
        STEP2,
        STEP3,
        STEP4,
    }STATES;

    void Miniature_Sequence1(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MINIATURE_CONTROL_H */

