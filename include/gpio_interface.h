/*
 * gpio_interface.h
 *
 *  Created on: Jun 13, 2018
 *      Author: bichar4
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


#include "port_struct.h"
#include "stm32f1xx_hal.h"



void configure_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number, uint8_t pin_mode);

uint8_t read_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number);

void write_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number, uint8_t output_value);

void enable_gpio_clock(uint8_t GPIO_PORT_Number);

__weak void delay_ms(uint32_t Delay);

void incTick();
uint32_t  getTick();

#endif /* GPIO_INTERFACE_H_ */
