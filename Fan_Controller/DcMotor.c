/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: DcMotor.c
 *
 * Description: source file for the ATmega32 DC Motor driver
 *
 * Author: Mahmoud Ehab
 *
 *******************************************************************************/

#include"DcMotor.h"
#include"gpio.h"
#include"PWM0.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * Stop the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_init(void) {
	/*
	 * Configure PB0&PB1 as o/p Pin
	 */
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
	/*
	 *Stop Motor at the beginning by setting PB0&PB1 to LOW
	 */
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
}

/*
 * Description :
 * The function responsible for rotating the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed) {
	switch (state) {
	case CW:/*Motor spin in clock-wise*/
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);
		break;
	case ACW:/*Motor spin in anti-clock-wise*/
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		break;
	case STOP:/*Motor stop spinning*/
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		break;
	}
	PWM_Timer0_Start(speed);/*insert the speed of the motor*/
}

