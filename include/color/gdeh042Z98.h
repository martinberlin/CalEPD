// 4.2 b/w/red
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "esp_system.h"
#include <stdint.h>
#include <math.h>
#include "sdkconfig.h"
#include "esp_log.h"
#include <string>
#include <epd.h>
#include <Adafruit_GFX.h>
#include <epdspi.h>
#include <gdew_colors.h>
#include <esp_timer.h>

// Controller: SSD1683 // https://www.good-display.cn/companyfile/585.html

#define GDEH042Z98_WIDTH 400
#define GDEH042Z98_HEIGHT 300
#define GDEH042Z98_BUFFER_SIZE (uint32_t(GDEH042Z98_WIDTH) * uint32_t(GDEH042Z98_HEIGHT) / 8)

#define GDEH042Z98_8PIX_BLACK 0x00
#define GDEH042Z98_8PIX_WHITE 0xFF
#define GDEH042Z98_8PIX_RED 0xFF
#define GDEH042Z98_8PIX_RED_WHITE 0x00

class Gdeh042Z98 : public Epd
{
  public:

    Gdeh042Z98(EpdSpi& IO);
    uint8_t colors_supported = 3;
    
    // EPD tests 
    void init(bool debug = false);
    void drawPixel(int16_t x, int16_t y, uint16_t color);  // Override GFX own drawPixel method
    
    void fillScreen(uint16_t color);
    void update();

  private:
    EpdSpi& IO;

    uint8_t _black_buffer[GDEH042Z98_BUFFER_SIZE];
    uint8_t _red_buffer[GDEH042Z98_BUFFER_SIZE];

    bool _initial = true;
    void _wakeUp();
    void _sleep();
    void _waitBusy(const char* message);
    void _rotate(uint16_t& x, uint16_t& y, uint16_t& w, uint16_t& h);

    static const epd_init_4 epd_resolution;
};