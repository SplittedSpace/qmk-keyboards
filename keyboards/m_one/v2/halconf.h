#pragma once

#define HAL_USE_SERIAL  FALSE
#define HAL_USE_PWM     FALSE
#define HAL_USE_I2C     FALSE
#define HAL_USE_SPI     FALSE
#define SPI_USE_WAIT    FALSE
#define SPI_SELECT_MODE SPI_SELECT_MODE_PAD

#include_next <halconf.h>