
#include "unity.h"
#include "leds.h"

#define LED_ON_FIRST   2       //numero del led a testear si enciende.
#define LED_ON_FIRST_MASK   0x0002  //mascara correspondiente al segundo led encendido y los demás apagados.
#define LED_ON_SECOND   3       //numero del led a testear si enciende.
#define LED_ON_SECOND_MASK   0x0004  //mascara correspondiente al segundo led encendido y los demás apagados.
#define ALL_LEDS_OFF_MASK 0X0000    //mascara para apagar todos los leds.
#define ALL_LEDS_ON_MASK 0XFFFF     //mascara para encender todos los leds.

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
    TEST_ASSERT_EQUAL_HEX16(LED_ON_FIRST_MASK, ledsVirtuales);
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

void test_TurnOnOffLed(void)
{

    const int led = LED_ON_FIRST;
    LedsTurnOn(led);
    LedsTurnOn(LED_ON_SECOND);
    LedsTurnOff(LED_ON_SECOND);

    TEST_ASSERT_EQUAL_HEX16(LED_ON_FIRST_MASK, ledsVirtuales);
}

/*Ver si un led se encuentra prendido*/
void test_IsLedOn(void)
{
    const int led = LED_ON_FIRST;

    LedsTurnOn(led);

    TEST_ASSERT_TRUE(IsLedOn(led));
}

/*Ver si un led se encuentra apagado*/
void test_IsLedOff(void)
{
    const int led = LED_ON_FIRST;

    LedsTurnOn(led);
    LedsTurnOff(led);

    TEST_ASSERT_TRUE(!IsLedOn(led));
}

/*Encender todos los leds*/

void test_TurnOnAllLeds(void)
{
    TurnOnAllLeds();

    TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_ON_MASK, ledsVirtuales);
}

/*Apagar todos los leds*/

void test_TurnOffAllLeds(void)
{
    TurnOnAllLeds();
    TurnOffAllLeds();

    TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF_MASK, ledsVirtuales);
}