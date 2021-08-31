/*
Cuando se inicializa el controlador, todos los leds deben estar apagados.  <----------
Prender un led. <----------
Apagar un led.  <----------
    Determinar si un led esta prendido.
    Determinar si un led esta apagado.
    Prender todos los leds en una sola operación.
    Apagar todos los leds en una sola operación.
Ver si los indices corresponden con los leds.
Secuencia del primero al ultimo.
Prender un led sin afectar al resto.    <----------
Valores de borde para los parametros. /NOT/
Verificar que funcione con lógica positiva.
Valores invalidos para los parametros.
*/

#include "unity.h"
#include "leds.h"

#define LED_ON_FIRST   2       //numero del led a testear si enciende.
#define LED_ON_SECOND   3       //numero del led a testear si enciende.

uint16_t ledsVirtuales;

void setUp(void)
{
    Leds_Init(&ledsVirtuales);
}

void tearDown(void)
{
}

/*Cuando se inicializa el controlador, todos los leds deben quedar apagados*/

void test_LedsOffAfterCreate(void)
{
    ledsVirtuales = ALL_LEDS_ON_MASK;
    Leds_Init(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF_MASK , ledsVirtuales);
}

/*Prender un led*/

void test_TurnOnLed(void)
{

    const int led = LED_ON_FIRST;
    LedsTurnOn(led);
    TEST_ASSERT_EQUAL_HEX16(LedsIndexToMask(led), ledsVirtuales);
}

/*Apagar un led*/

void test_TurnOffLed(void)
{
    const int led = LED_ON_FIRST;
    LedsTurnOn(led);
    LedsTurnOff(led);
    TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF_MASK, ledsVirtuales);
}

/*Prender un led sin afectar al resto*/

void test_TurnOnOffLeds(void)
{

    const int led = LED_ON_FIRST;
    LedsTurnOn(led);
    LedsTurnOn(LED_ON_SECOND);
    LedsTurnOff(LED_ON_SECOND);

    TEST_ASSERT_EQUAL_HEX16(LedsIndexToMask(led), ledsVirtuales);
}

/*Ver si un led se encuentra prendido*/
void test_IsLedOn(void)
{
    const int led = LED_ON_FIRST;

    LedsTurnOn(led);

    TEST_ASSERT_TRUE(IsLedOn(led));
}

