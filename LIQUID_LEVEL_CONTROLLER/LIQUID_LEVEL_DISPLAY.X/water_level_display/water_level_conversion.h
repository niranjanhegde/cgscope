/* 
 * File:   water_level_conversion.h
 * Author: niranjan
 *
 * Created on 6 December, 2015, 2:44 PM
 */

#ifndef WATER_LEVEL_CONVERSION_H
#define	WATER_LEVEL_CONVERSION_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "../mcc_generated_files/mcc.h"
    
    
    uint8_t WaterLevel_Lookup(uint16_t zeroSet, uint8_t stepLitre);
    uint16_t ReadWaterLevel(void);
    


#ifdef	__cplusplus
}
#endif

#endif	/* WATER_LEVEL_CONVERSION_H */

