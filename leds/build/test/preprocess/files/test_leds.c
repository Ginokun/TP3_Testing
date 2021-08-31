#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void setUp(void)

{

}



void teatDown(void)

{

}







void test_LedsOffAfterCreate(void)

{

    uint16_t puerto = 0xFFFF;

    Leds_Init(&puerto);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto)), (

   ((void *)0)

   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_HEX16);

}
