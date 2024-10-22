#include "sl_sleeptimer.h"

#ifdef SL_CATALOG_SIMPLE_LED_PRESENT
#include "sl_simple_led_instances.h"
// LED Indication
#ifdef SL_CATALOG_SIMPLE_LED_LED0_PRESENT
#define ACTIVITY_LED sl_led_led0 // BOARDLED0
#endif                           // SL_CATALOG_SIMPLE_LED_LED0_PRESENT
#ifdef SL_CATALOG_SIMPLE_LED_LED1_PRESENT
#define COMMISSIONING_STATE_LED sl_led_led1 // BOARDLED1
#else
#define COMMISSIONING_STATE_LED sl_led_led0 // BOARDLED0
#endif

#define BOARD_LED_ON(led) sl_led_turn_on(&led)
#define BOARD_LED_OFF(led) sl_led_turn_off(&led)

#else
#define BOARD_LED_ON(led)
#define BOARD_LED_OFF(led)

#endif // SL_CATALOG_SIMPLE_LED_PRESENT

static sl_sleeptimer_timer_handle_t led_blink_timer_handle;

static void ledBlinkCallback(sl_sleeptimer_timer_handle_t *handle, void *contextData);

    void startLedBlinking(uint32_t interval_ms)
{
    sl_sleeptimer_start_periodic_timer_ms(&led_blink_timer_handle,
                                          interval_ms,
                                          ledBlinkCallback,
                                          NULL,
                                          0,
                                          0);
}

static void ledBlinkCallback(sl_sleeptimer_timer_handle_t *handle, void *contextData)
{
    (void)handle;      // Marquer la variable comme inutilisée
    (void)contextData; // Marquer la variable comme inutilisée
    static bool led_on = false;

    if (led_on)
    {
        BOARD_LED_OFF(ACTIVITY_LED);
    }
    else
    {
        BOARD_LED_ON(ACTIVITY_LED);
    }

    led_on = !led_on;
}