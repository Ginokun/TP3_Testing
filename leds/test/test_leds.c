/*
Cuando se inicializa el controlador, todos los leds deben estar apagados.
Prender un led.
Apagar un led.
Determinar si un led esta prendido.
Determinar si un led esta apagado.
Prender todos los leds en una sola operación.
Apagar todos los leds en una sola operación.
Ver si los indices corresponden con los leds.
Secuencia del primero al ultimo.
Prender un led sin afectar al resto.
Valores de borde para los parametros.
Verificar que funcione con lógica positiva.
Valores invalidos para los parametros.
*/





#include "unity.h"
#include "leds.h"

void setUp(void)
{
}

void teatDown(void)
{
}

/*Cuando se inicializa el controlador, todos los leds deben quedar apagados*/

void test_LedsOffAfterCreate(void)
{
    uint16_t puerto = 0xFFFF;
    Leds_Init(&puerto);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto);
}