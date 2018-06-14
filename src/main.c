
#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio_interface.h"


static void MX_GPIO_Init(void);

int main(void)
{
  HAL_Init();

  //SystemClock_Config();
  enable_gpio_clock(GPIO_CLOCK_C);
  configure_gpio_pin(GPIO_PORT_C,14,0x01);
  MX_GPIO_Init();
  while (1)
  {
	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	  delay_ms(50);
  }

}



static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;


  __HAL_RCC_GPIOA_CLK_ENABLE();


  /*Configure GPIO pin :PC13
   */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

