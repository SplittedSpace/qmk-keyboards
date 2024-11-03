#pragma once

#include_next <mcuconf.h>

#undef STM32_SERIAL_USE_USART1
#define STM32_SERIAL_USE_USART1 TRUE

#undef STM32_I2C_USE_DMA
#define STM32_I2C_USE_DMA FALSE

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 FALSE

#undef STM32_PWM_USE_TIM2
#define STM32_PWM_USE_TIM2 TRUE
#undef STM32_PWM_USE_TIM3
#define STM32_PWM_USE_TIM3 FALSE
#undef STM32_ST_USE_TIMER
#define STM32_ST_USE_TIMER 3

#undef STM32_PWM_USE_ADVANCED
#define STM32_PWM_USE_ADVANCED FALSE

#undef STM32_SPI_USE_SPI1
#define STM32_SPI_USE_SPI1 FALSE