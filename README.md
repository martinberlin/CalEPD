![CalEPD Logo](/assets/CalEPD-logo.svg)

**CalEPD is an ESP-IDF C++ component to drive epaper displays with ESP32 / ESP32S2**

## Requirements

CalEPD needs also [Adafruit-GFX-Library-ESP-IDF](https://github.com/martinberlin/Adafruit-GFX-Library-ESP-IDF) as a component since it's uses the GFX magic to provide fonts and geometrical functions to your pixel Buffer.
To check how an existing project uses it check [CALE-IDF dependencies](https://github.com/martinberlin/cale-idf/network/dependencies) and the [components folder](https://github.com/martinberlin/cale-idf/tree/master/components).

![CalEPD Classmap](/assets/CalEPD_flow.svg)

This is the newest additon, the Touch class, so you can make user interfaces on the ESP32
![CalEPD with Touch Classmap](/assets/CalEPD_touch.svg)

## Menuconfig

In "Display configuration" you can customize the GPIOs for your Firmware

![Display configuration](/assets/menuconfig-display.png)

## The masterplan

**CalEPD component** will be focused in EPD displays >= 400x300 px. It supports 3 smaller Epds, since I had some TTGOs epapers at home, check the 2.13" and 2.7" Epd classes.

The goal is to learn in this process what each model needs to receive in order to update. To document it and test it openly sharing the results and learning from our mistakes.
Check our [first issue](https://github.com/martinberlin/CalEPD/issues/1) to add your testing displays and let us know if you have some time to test or participate in the creation of this component.
Please that there is no intention to port this library to Arduino-Espressif32 since I want to keep the SPI communication as low level as possible and in my opinion, that is possible only using ESP-IDF since there are much more settings to play with. 

## Implementing this library as a C++ component

Please note that due to the object oriented nature of this library C++ is used. That forces the developers implementing this library to use C++ as well as the main program. Please refer to [cale-idf repository](https://github.com/martinberlin/cale-idf) to see a demo of how this library is implemented on a C++ Firmware and check the demos provided.

## Achievements

In some models of epaper this component was about 20% faster than GxEPD. CalEPD is designed to have the smallest footprint as possible and standard C++ with the minimum overhead as possible.
Please check our [Wiki page with the supported eink display](https://github.com/martinberlin/cale-idf/wiki), discover some benchmarks between different versions, and get specific information about your epaper display.

## How to test it right away

This component development is taking place in the [CALE-IDF repository](https://github.com/martinberlin/cale-idf). So simply clone it or download it. And then use the idf toolchain: 

    idf.py set-target esp32 OR esp32s2
    idf.py menuconfig
    idf.py flash console

Make sure to set the right GPIOs that connect your epaper module with your esp32 board. 

## Want a new epaper module?

I'm slowly adding new epapers every time a new one comes to the office. But I cannot possibly have all the existing models in the world, so if you follow the way it's done, and you have a reference library that works it's not hard to make a new class. 
Now if you don't have the time and you want to have it added to this component I can do it for you. But in exchange I need to receive the epaper display per post, otherwise it's impossible to test and get it working the right way. Just add a git issue here with all the details you have about the model.

## Author

Martin [Fasani](https://fasani.de) - PHP Engineer, C++ and electronic maker - **Contact:** martin at luckycloud.de
My C++ OOP skills are still being perfectioned, so if you see things that could be done better, your pull request is more than welcome.

## History

In the beginning of May 2020 I had the idea to make GxEPD work as an ESP-IDF component. After starting with [GxEPD-SPI](https://github.com/martinberlin/GxEPD-config-spi), that was created initially to make the [SPI GPIOs configurable](https://github.com/martinberlin/GxEPD-config-spi/tree/ini_spi#about-this-fork), I realized after a week of updates and frustration that it was simply not the best road to take. 
The C++ classes and inheritance was simply not working as is with Cmake and [ESP-IDF v4.0](https://github.com/espressif/esp-idf/tree/release/v4.0).
So I decided to abort it, make up my mind, and start with a clear mission. Coding a component that starts from scratch instead of refactoring a big class. 
Using the factory examples provided by Good Display and Waveshare as a base and coding in top of this a very small footprint component just to support bigger displays. 
The mission is to have a component that compiles with latest versions of CMake and does not need to use in any way Arduino components for SPI. It needs to work independantly of espressif-32 arduino.
[SPI-communication](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/spi_master.html) does not need anything else than base classes and the idea is to keep in CalEPD the smallest footprint as possible, so you don't have to compile 22 epaper classes, to use just one in your embedded project.
