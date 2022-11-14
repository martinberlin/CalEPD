![CalEPD Logo](/assets/CalEPD-logo.svg)

**CalEPD is an ESP-IDF C++ component to drive epaper displays with ESP32 / ESP32S2**

IMPORTANT NEWS: IDF v. 5 support is already on the way. Please switch to **develop** branch to test it, even if you are using 4.4 version, so you can help us to debug it and be safe when it merges.
[Pull request to merge idf_v5 into master here](https://github.com/martinberlin/CalEPD/pull/8)

## Requirements

* Espressif IDF framework **v. 4.3**
* An SPI epaper. Check [the Wiki](https://github.com/martinberlin/cale-idf/wiki) for supported models
* In order to use the parallel epaper displays it needs EPDiy library as a submodule. I prepared a fork that can be directly used as a component:

    git submodule add https://github.com/martinberlin/epdiy-rotation.git components/epd_driver

CalEPD needs also [Adafruit-GFX-Library-ESP-IDF](https://github.com/martinberlin/Adafruit-GFX-Library-ESP-IDF) as a component since it's uses the GFX magic to provide fonts and geometrical functions to your pixel Buffer.
To check how an existing project uses it check [CALE-IDF dependencies](https://github.com/martinberlin/cale-idf/network/dependencies) and the [components folder](https://github.com/martinberlin/cale-idf/tree/master/components).
Please check the [paralell examples in Cale-idf](https://github.com/martinberlin/cale-idf/tree/master/main/demos/parallel) project to get a grasp of how they work together with the EPDiy integration. 

### VSCODE and Platformio ★

In the repository [cale-platformio](https://github.com/martinberlin/cale-platformio) you can have a quick start skeleton to use this component CalEPD and Adafruit-GFX together, along with optional FocalTech touch I2C. Please be aware that there are some corrections to do until we figure out what is the best way to do it. Read those in the WiKi and please give a **★ to the cale-platformio** repository if you find it useful.

### Touch models

In latest CalEPD releases we included two classes that are touch aware. Touch models marked with a T suffix are disabled by default, uncomment in case of requirement in the CMakeLists.txt file:

```
set(srcs 
   #"models/gdew027w3T.cpp"
   #"models/parallel/ED047TC1touch.cpp"
)
```

**Instantiation of touch**

For more in-deep use cases check the Cale-idf examples

```c
// Add the Focal Tech class for Goodisplay 2.7 inch epaper
#include <FT6X36.h>
#include <gdew027w3T.h>
// INTGPIO is touch interrupt, goes low when it detects a touch, which coordinates are read by I2C
FT6X36 ts(CONFIG_TOUCH_INT);
EpdSpi io;
// Inject both IO and Touch to the display class in the constructor parameters
Gdew027w3T display(io, ts);
```

## Fork policy

**Please do not Fork this repository to bookmark it**. For that use the ★ Star button. Acceptable forks fall in this three categories:

1. You found a bug and want to suggest a merge request. Then Fork it!
2. You will contribute adding a new epaper model that does exist.
3. You will use CaEPD as a base to create something new. But in that case it would be nice to let us know first!

All other users that fork this without falling in this categories and without any kind of advice to us will be blocked and will not be able to interact with the further Cale releases. Forking is not bookmarking!

We don't like having copies of this without any reason. It is just a bad practice, makes things confusing, and makes absolutely no sense. This repository is not going to dissapear or be deleted by any means so you can use it with confidence.
Forking this in order to make updates that fit your particular project is alright, as long as you update the readme and state what are the intentions to do so.

## Classmap 

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

## Touch integration

Starting on v1.0 we added a touch component that is integrated as a test in the [Model gdew027w3T.h](https://github.com/martinberlin/cale-idf/wiki/Model-gdew027w3T.h-(Touch)) 
Please check the WiKi to get the wiring details and thinking behind building this component. 
https://github.com/martinberlin/FT6X36-IDF


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
