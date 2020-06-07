![CalEPD Logo](/assets/CalEPD-logo.svg)

**CalEPD is an ESP-IDF component to drive epaper displays with ESP32 / ESP32S2**

## Requirements

CalEPD needs also [Adafruit-GFX-Library-ESP-IDF](https://github.com/martinberlin/Adafruit-GFX-Library-ESP-IDF) as a component since it's uses the GFX magic to provide fonts and geometrical functions to your pixel Buffer.
To check how an existing project uses it check [CALE-IDF dependencies](https://github.com/martinberlin/cale-idf/network/dependencies) and the [components folder](https://github.com/martinberlin/cale-idf/tree/master/components).

## A bit of history

The plan is to build from scratch an EPaper Display library with font support. Prepared to be used as an ESP-IDF component only for ESP32 / ESP32S2 SoCs as a target.
This repository will act for now as a placeholder, to plan the architecture, discuss ideas and document the progress.

Please note that this component development is being done first in [cale-idf repository](https://github.com/martinberlin/cale-idf) and this CalEPD will be a component in cale-idf. Like this is possible to test and develop fast without updating this submodule all the time. 

In CALE-IDF you will find also a daily updated [Wiki with last news and a comprehensive list of Epaper displays supported](https://github.com/martinberlin/cale-idf/wiki).
Just follow the **cale-idf** or this one to be notified about the development status.


## The masterplan

**CalEPD component** will be focused in EPD displays >= 400x300 px 
(It won't support the smaller types for now) -> Update: Since I had a small 2.7" from TTGO in my office I also added it but it's the exception to the rule.

The goal is to learn in this process what each model needs to receive in order to update. To document it and test it openly sharing the results and learning from our mistakes.
Please check our [first issue](https://github.com/martinberlin/CalEPD/issues/1) to add your testing displays and let us know if you have some time to test or participate in the creation of this component.

![CalEPD Classmap](/assets/CalEPD_flow.svg)
*Note that the classmap is outdated current one looks simply like:*

    Epd Abstract <- extends Adafruit GFX
      ↑    
      Gets EspSPI (IO) class injected
      ↑
      YourModel.h class implements Epd adding your display CMDs for IO

## Author

Martin [Fasani](https://fasani.de) - C++ intermediate level, still learning OOP and reading every week. Big fan of [Espressif System on a Chip devices](https://www.espressif.com/en/support/documents/technical-documents)
Not a C++ Jedi master, so excuse me if there are obvious errors for you, and please send a pull request if you know how to make it better. 
Please do not fork this repository just to make a copy of it. If you really need it then do it but change the name, so it represents what your changes will affect, or do it with the intention to make this library better. I dislike seeing hundreds of forks of existing libraries when only 1% of them brough something better to the project. 

## History

In the beginning of May 2020 I had the idea to make GxEPD work as an ESP-IDF component. After starting with [GxEPD-SPI](https://github.com/martinberlin/GxEPD-config-spi), that was created initially to make the [SPI GPIOs configurable](https://github.com/martinberlin/GxEPD-config-spi/tree/ini_spi#about-this-fork), I realized after a week of updates and frustration that it was simply not the best road to take. 
The C++ classes and inheritance was simply not working as is with Cmake and [ESP-IDF v4.0](https://github.com/espressif/esp-idf/tree/release/v4.0).
So I decided to abort it, make up my mind, and start with a clear mission. Coding a component that starts from scratch instead of refactoring a big class. 
Using the factory examples provided by Good Display and Waveshare as a base and coding in top of this a very small footprint component just to support bigger displays. 
The mission is to have a component that compiles with latest versions of CMake and does not need to use in any way Arduino components for SPI. It needs to work independantly of espressif-32 arduino.
[SPI-communication](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/spi_master.html) does not need anything else than base classes and the idea is to keep in CalEPD the smallest footprint as possible, so you don't have to compile 22 epaper classes, to use just one in your embedded project.


I expect that this is not my personal project but a component that have external contributions where other people with more experience than me can contribute and even make their own versions.
