/* 
 * File:   standard_head1.h
 * Author: niru
 *
 * Created on 8 November, 2015, 11:34 AM
 */

#ifndef STANDARD_HEAD1_H
#define	STANDARD_HEAD1_H

#ifdef	__cplusplus
extern "C" {
#endif

//    typedef enum
//    {
//        STEP1=0,
//        STEP2,
//        STEP3,
//        STEP4,
//        STEP5,        
//    }STATES3;
    
    typedef struct
    {
        unsigned std_timer1_start:1;
        unsigned std_timer2_start:1;
        char std_timer1;
        char std_timer2;
    }STD_HEAD_TIMERS;

    void Standard_head1(void);


#ifdef	__cplusplus
}
#endif

#endif	/* STANDARD_HEAD1_H */

