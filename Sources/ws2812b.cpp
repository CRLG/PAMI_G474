#include "ws2812b.h"
#include "RessourcesHardware.h"

WS2812b::WS2812b()
{
}

// _______________________________________________
void WS2812b::send_buffer_dma()
{
    // TODO : a implementer dans la classe fille
    HAL_UART_Transmit_DMA(&UART_HDL_WS2812, m_led_ws2812b_dma_buffer, LED_DMA_BUFFER_SIZE);
}

// _______________________________________________
unsigned int WS2812b::getNumberOfLed()
{
    return NB_OF_LEDS;
}

// _______________________________________________
unsigned char *WS2812b::getDmaBuffer()
{
    return m_led_ws2812b_dma_buffer;
}

// _______________________________________________
WS2812UartBase::tWS2812BPattern *WS2812b::getPatternBuffer()
{
    return m_led_ws2812b;
}

