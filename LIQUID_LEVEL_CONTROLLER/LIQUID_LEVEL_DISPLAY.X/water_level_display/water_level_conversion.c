/* 
 * File:   water_level_conversion.c
 * Author: niranjan
 *
 * Created on 6 December, 2015, 2:44 PM
 */

#include "water_level_conversion.h"
#include "../mcc_generated_files/mcc.h"
#define REF_VOLTAGE 50
#define ZERO_OFFSET 400
#define STEP_SIZE 35
uint16_t ReadWaterLevel(void)
{
    uint16_t adcValue=0;
    adcValue=ADC_GetConversion(WAT_LEVEL_AN);
    adcValue = (((((adcValue*REF_VOLTAGE)/1024))*100)+(((adcValue*REF_VOLTAGE)%1024)/10));
    return adcValue;
}

uint8_t WaterLevel_Lookup(uint16_t zeroSet, uint8_t stepLitre)
{
    uint16_t waterLevelRead=0;
    uint8_t waterLevelLookup=0;
    waterLevelRead=ReadWaterLevel();
    waterLevelRead = waterLevelRead - zeroSet;
    waterLevelLookup = waterLevelRead / stepLitre;
    return waterLevelLookup;
}