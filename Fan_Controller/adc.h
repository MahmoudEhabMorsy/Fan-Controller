/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Mahmoud Ehab
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
/*
 * AREF:Internal Vref is turned off (External Vref)
 * AVCC:Internal Vref=5V
 * AVCC_2:Internal Vref=2.56V
 * */
typedef enum {
	AREF=0, AVCC=1, AVCC_2 = 3
} ADC_ReferenceVoltage;

typedef enum {
	F_CPU_2, F_CPU_4 = 2, F_CPU_8=3, F_CPU_16, F_CPU_32, F_CPU_64, F_CPU_128
} ADC_Prescaler;
typedef struct {
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
} ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
