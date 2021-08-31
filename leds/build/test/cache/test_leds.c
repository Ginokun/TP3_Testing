#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








uint16_t ledsVirtuales;



void setUp(void)

{

    Leds_Init(&ledsVirtuales);

}



void tearDown(void)

{

}







void test_LedsOffAfterCreate(void)

{

    ledsVirtuales = 0XFFFF;

    Leds_Init(&ledsVirtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0X0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_HEX16);

}







void test_TurnOnLed(void)

{



    const int led = 2;

    LedsTurnOn(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((LedsIndexToMask(led))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_HEX16);

}







void test_TurnOffLed(void)

{

    const int led = 2;

    LedsTurnOn(led);

    LedsTurnOff(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0X0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_HEX16);

}







void test_TurnOnOffLeds(void)

{



    const int led = 2;

    LedsTurnOn(led);

    LedsTurnOn(3);

    LedsTurnOff(3);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((LedsIndexToMask(led))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_HEX16);

}





void test_IsLedOn(void)

{

    const int led = 2;







    do {if ((IsLedOn(led))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(83)));}} while(0);

}
