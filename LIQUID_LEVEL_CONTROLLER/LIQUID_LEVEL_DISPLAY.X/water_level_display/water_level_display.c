/* 
 * File:   water_level_display.c
 * Author: niranjan
 *
 * Created on 6 December, 2015, 5:39 PM
 */

#include "water_level_display.h"
#include "../mcc_generated_files/mcc.h"

WL_Data wlData;


void WaterLevelDisplay_StateMachine(void)
{
    switch(wlData.states)
    {
        case INITIALIZE:
        {
            wlData.zero_offset = 400;
            wlData.liter_per_step = 8;
            wlData.lookup=0;
            wlData.states=LEVEL_DISPLAY;
           break; 
        }
        case LEVEL_DISPLAY:
        {
            wlData.lookup=WaterLevel_Lookup(wlData.zero_offset, wlData.liter_per_step);
            if((wlData.lookup > 0) && (wlData.lookup < 201))
            {
                Display_value(WaterLevelLookup[wlData.lookup]);
            }
            else
            {
                Display_value(0);
            }
            break;
        }
        case IDLE:
        {
            break;
        }
    }
    
}