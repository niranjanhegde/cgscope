/* 
 * File:   drv_74hc595.h
 * Author: Niranjan Hegde
 *
 * Created on 23 November, 2015, 4:58 PM
 */

#ifndef DRV_74HC595_H
#define	DRV_74HC595_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>
  
#define MASK(j) (1<<j)

    void Display_value(uint16_t value);
    void Display_put(char *dig);
    void GetStringReverse(char *str, char*buff);
    void Display_clear(void);
    void Display_check(void);

#ifdef	__cplusplus
}
#endif

#endif	/* DRV_74HC595_H */

