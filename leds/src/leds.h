#ifndef _LEDS_H_
#define _LEDS_H_

#include <stdint.h>

void Leds_Init(uint16_t *puerto);

void LedsTurnOn(int led);

void LedsTurnOff(int led);

uint16_t IsLedOn(int led);

uint16_t LedsIndexToMask(int led);

void TurnOnAllLeds();

void TurnOffAllLeds();

#endif