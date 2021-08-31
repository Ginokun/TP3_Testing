#include "leds.h"

static uint16_t *puerto;

uint16_t LedsIndexToMask(int led)
{

    return (LEDS_STATE_ON << (led - LEDS_INDEX_OFFSET));
}

void Leds_Init(uint16_t *direccion)
{
    puerto = direccion;
    *direccion = ALL_LEDS_OFF_MASK;
}

void LedsTurnOn(int led)
{
    *puerto |= LedsIndexToMask(led);
}

void LedsTurnOff(int led)
{
    *puerto &= ~LedsIndexToMask(led);
}

void IsLedOn(int led)
{
    return ((*puerto) & LedsIndexToMask(led));
}
