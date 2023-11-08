/*
 * main.c
 *
 *  Created on: Oct 3, 2023
 *      Author: Lenovo
 */

#include <avr/delay.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include "../MCAL/DIO-DRIVER/DIO_MCAL_Interface.h"
#include "../MCAL/TMR-DRIVER/TMR_MCAL_Interface.h"

#include "../HAL/LCD-DRIVER/LCD_HAL_Interface.h"
#include "../HAL/SEGMENT_DRIVER/SEG_HAL_Interface.h"
#include "../HAL/KPD_DRIVER/KPD_HAL_Interface.h"

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

int main() {
	DIO_SetPortDirection(DIO_PORTA, DIO_OUTPUT);
	DIO_SetPortDirection(DIO_PORTA, DIO_OUTPUT);
	DIO_Init();
	LCD_Init();
	KPD_Init();
	SEG_Init(DIO_PORTC);

	f32 operands[10];
	u8 operators[10];
	u8 operandcount = 0;
	u8 operatorcount = 0;
	f32 result = 0;
	u8 x;
	u8 div_flag = 0;
	LCD_SendCommand(CLR_DISP);
	while (1) {
		x = KPD_GetKey();
		if (x != 0b11111111) {

			if (x >= '0' && x <= '9') {
				LCD_SendChar(x);
				operands[operandcount] = operands[operandcount] * 10
						+ (x - '0');
			}
			if (x == '/' || x == '*' || x == '-' || x == '+') {
				LCD_SendChar(x);
				operators[operatorcount] = x;
				operandcount++;
				operatorcount++;
			}

			if (x == '=') {
				LCD_SendChar(x);
				result = operands[0];
				u8 operatorIndex = 0;
				for (u8 i = 1; i <= operandcount; i++) {

					switch (operators[operatorIndex]) {
					case '/':
						if (operands[i] == 0) {
							LCD_SendCommand(CLR_DISP);
							LCD_SendString("Error: Division by zero", 0);
							_delay_ms(1000);
							LCD_SendCommand(CLR_DISP);
							LCD_SendString("Press C to clear",0);

							operandcount = 0;
							operatorcount = 0;
							for (u8 i = 0; i < 10; i++) {
								operands[i] = 0;
								operators[i] = 0;
							}
							result = 0;

							div_flag = 0;

							// Clear display and reset LCD
							_delay_ms(1000);
							LCD_SendCommand(CLR_DISP);
							LCD_SendString("press C",0);
						}
						result /= operands[i];
						div_flag = 1;
						break;
					case '*':
						result *= operands[i];
						break;
					case '-':
						result -= operands[i];
						break;
					case '+':
						result += operands[i];
						break;
					default:
						break;
					}
					operatorIndex++;
				}
				while (div_flag == 1) {
					LCD_SendCommand(CLR_DISP);
					LCD_SendFloatNumber(result, 2);
					div_flag = 0;

					break;
				}
				if (div_flag == 0) {
					LCD_SendCommand(CLR_DISP);
					LCD_SendFloatNumber(result, 2);
				}
//
			}

			if (x == 'c') {
				operandcount = 0;
				operatorcount = 0;
				for (u8 i = 0; i < 10; i++) {
					operands[i] = 0;
					operators[i] = 0;
				}
				result = 0;

				div_flag = 0;

				// Clear display and reset LCD
				LCD_SendCommand(CLR_DISP);
			}
		}

	}
	return 0;
}

