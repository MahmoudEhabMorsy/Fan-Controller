/*
 * Fan_Controller.c
 * Description:controls a fan according to the temperature sensed
 *  Created on: Oct 6, 2022
 *      Author: Mahmoud Ehab
 */
#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include"DcMotor.h"
#define FAN_0_SPEED    0
#define FAN_25_SPEED   25
#define FAN_50_SPEED   50
#define FAN_75_SPEED   75
#define FAN_100_SPEED  100
int main(void) {
	uint8 temp;
	ADC_ConfigType ADC_Config = { AVCC_2, F_CPU_8 };
	LCD_init(); /* initialize LCD driver */
	ADC_init(&ADC_Config); /* initialize ADC driver */
	DcMotor_init();/*initialize DC Motor*/
	/* Display this string "FAN is " only once on LCD at the first row */
	LCD_displayString("FAN is ");
	/* Display this string "Temp =   C" only once on LCD at the second row */
	LCD_displayStringRowColumn(1, 0, "Temp =    C");

	while (1) {

		temp = LM35_getTemperature();

		/* Display the temperature value every time at same position */
		LCD_moveCursor(1, 7);
		if (temp >= 100) {
			LCD_intgerToString(temp);
		} else {
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		/*Display the fan state every time at the same position*/
		LCD_moveCursor(0, 7);
		if (temp < 30) {
			DcMotor_Rotate(STOP, FAN_0_SPEED);
			LCD_displayString("OFF");

		} else if ((temp >= 30) && (temp < 60)) {
			DcMotor_Rotate(CW, FAN_25_SPEED);
			LCD_displayString("ON ");
		} else if ((temp >= 60) && (temp < 90)) {
			DcMotor_Rotate(CW, FAN_50_SPEED);
			LCD_displayString("ON ");
		} else if ((temp >= 90) && (temp < 120)) {
			DcMotor_Rotate(CW, FAN_75_SPEED);
			LCD_displayString("ON ");
		} else {
			DcMotor_Rotate(CW, FAN_100_SPEED);
			LCD_displayString("ON ");
		}
	}
}

