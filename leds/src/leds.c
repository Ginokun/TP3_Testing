#include "leds.h"

#define ALL_LEDS_OFF_MASK 0X0000
#define ALL_LEDS_ON_MASK 0XFFFF
#define LEDS_INDEX_OFFSET 1
#define LEDS_STATE_ON 1

static uint16_t *puerto;

static uint16_t LedsIndexToMask(int led);

static uint16_t LedsIndexToMask(int led)
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

uint16_t IsLedOn(int led)
{
    return ((*puerto) & LedsIndexToMask(led));
}

void TurnOnAllLeds(){

    *puerto |= ALL_LEDS_ON_MASK;
}

void TurnOffAllLeds(){
    *puerto &= ALL_LEDS_OFF_MASK;
}