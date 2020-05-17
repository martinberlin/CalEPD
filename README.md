![CalEPD Logo](/assets/CalEPD-logo.svg)

The plan is to build from scratch an EPaper Display library with font support. Prepared to be used as an ESP-IDF component only for ESP32 / ESP32S2 SoCs as a target.
This repository will act for now as a placeholder, to plan the architecture, discuss ideas and document the progress.


## The masterplan

**CalEPD component** will be focused in EPD displays >= 400*300 px 
(It won't support the smaller types for now)
Architecture wise having the SPI header in a way that can be implemented using IDF SPI or Arduino-esp32 SPI classes.
The goal is to learn in this process what each model needs to receive in order to update. To document it.
Please check our [first issue](https://github.com/martinberlin/CalEPD/issues/1) to add your testing displays and let us know if you have some time to test or participate in the creation of this component.

![CalEPD Logo](/assets/CalEPD_flow.svg)

## History

In the beginning of May 2020 I had the idea to make GxEPD work as an ESP-IDF component. After starting with [GxEPD-SPI](https://github.com/martinberlin/GxEPD-config-spi), that was created initially to make the [SPI GPIOs configurable](https://github.com/martinberlin/GxEPD-config-spi/tree/ini_spi#about-this-fork), I realized after a week of updates and frustration that it was simply not the best road to take. 
The C++ classes and inheritance was simply not working as is with Cmake and [ESP-IDF v4.0](https://github.com/espressif/esp-idf/tree/release/v4.0).
So I decided to abort it, make up my mind, and start with a clear mission. Coding a component that starts from scratch instead of refactoring a big class. 
Using the factory examples provided by Good Display and Waveshare as a base and coding in top of this a very small footprint component just to support bigger displays. 
The mission is to have a component that compiles with latest versions of CMake and does not need to use in any way Arduino components for SPI. It needs to work independantly of espressif-32 arduino.
[SPI-communication](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/spi_master.html) does not need anything else than base classes and the idea is to keep in CalEPD the smallest footprint as possible, so you don't have to compile 22 epaper classes, to use just one in your embedded project.


I expect that this is not my personal project but a component that can be forked and where other people with more experience than me can contribute and even make their own versions. 
Only in some months we will see if this was a good idea or just a dream that goes into nowhere land.
