/*
 * gpio_interface.c
 *
 *  Created on: Jun 13, 2018
 *      Author: bichar4
 */

#include "gpio_interface.h"
#include "stm32f1xx_hal.h"

__IO uint32_t uwTICK;

void configure_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number, uint8_t pin_mode){

	if(pin_number < 8){
		GPIOX->ConfigRegLow = ( GPIOX->ConfigRegLow & ( ~ ( 1<< pin_number ) ) ) | (pin_mode << pin_number );

	}
	else{
		pin_number = pin_number - 8;
		GPIOX->ConfigRegLow = ( GPIOX->ConfigRegLow & ( ~ ( 1<< pin_number ) ) ) | (pin_mode << pin_number );
	}
}

uint8_t read_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number){

	return( ( GPIOX->InputDataReg >> pin_number ) & 0x01 );
}

void write_gpio_pin(GPIORegister_structure *GPIOX, uint8_t pin_number, uint8_t output_value){

	GPIOX->OutputDatareg = ( GPIOX->OutputDatareg & ( ~ ( 1<<pin_number ) ) ) | ( output_value << pin_number );
}

void enable_gpio_clock(uint8_t GPIO_PORT_Number){

    RCC->APB2ENR |= ( 1 << ( GPIO_PORT_Number + 2) );
}

__weak void delay_ms(uint32_t Delay)
{
  uint32_t tickstart = getTick();
  uint32_t wait = Delay;

  /* Add a freq to guarantee minimum wait */
  if (wait < 0xFFFFFFFFU)
  {
    wait += (uint32_t)(1U);
  }

  while ((getTick() - tickstart) < wait)
  {
  }
}
uint32_t  getTick(){
	return uwTICK;
}

void incTick(){
	uwTICK+=1U;
}


