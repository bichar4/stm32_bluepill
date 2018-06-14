#ifndef __PORT_STRUCT__
#define __PORT_STRUCT__
//just for test
#include<stdint.h>
#include<main.h>

//Base address of GPIO PORT Register
#define GPIOA_BASE_ADDRESS 0x40010800
#define GPIOB_BASE_ADDRESS 0x40010C00
#define GPIOC_BASE_ADDRESS 0x40011000
#define GPIOD_BASE_ADDRESS 0x40011400
#define GPIOE_BASE_ADDRESS 0x40011800


//GPIO Register Structure 
typedef struct{
   volatile uint32_t ConfigRegLow;
   volatile uint32_t ConfigRegHigh;
   volatile uint32_t InputDataReg;
   volatile uint32_t OutputDatareg;
   volatile uint32_t BitSetResetReg;
   volatile uint32_t BitResetReg;
   volatile uint32_t LockConfigReg;
}GPIORegister_structure;


//Base address of Register related to Ports

#define GPIO_PORT_A ( (GPIORegister_structure *) GPIOA_BASE_ADDRESS )
#define GPIO_PORT_B ( (GPIORegister_structure *) GPIOB_BASE_ADDRESS )
#define GPIO_PORT_C ( (GPIORegister_structure *) GPIOC_BASE_ADDRESS )
#define GPIO_PORT_D ( (GPIORegister_structure *) GPIOD_BASE_ADDRESS )
#define GPIO_PORT_E ( (GPIORegister_structure *) GPIOE_BASE_ADDRESS )

//GPIO CLOCK
#define GPIO_CLOCK_A 0
#define GPIO_CLOCK_B 1
#define GPIO_CLOCK_C 2

#endif

