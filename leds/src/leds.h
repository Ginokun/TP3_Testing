#ifndef _LEDS_H_
#define _LEDS_H_

#include <stdint.h>

#define ALL_LEDS_OFF_MASK 0X0000
#define ALL_LEDS_ON_MASK 0XFFFF
#define LEDS_INDEX_OFFSET 1
#define LEDS_STATE_ON 1

void Leds_Init(uint16_t *puerto);

void LedsTurnOn(int led);

void LedsTurnOff(int led);

void IsLedOn(int led);

#endif