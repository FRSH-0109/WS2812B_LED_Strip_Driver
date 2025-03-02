# WS2812B LED Strip Driver
Driver for controlling addressable WS2812B LED's strips/tapes by PWM modulation.

---

### Features
- Changing color of every single diode in RGB format (8bit per color)
- Wave generation for given width
- Clearing whole strip at once

---

### How to use?
After coping/moving driver files into your project, it is necessary to set few things  

---

**Defines**

Set proper length of your strip at LED_AMOUNT define in driver header file  
`#define LED_AMOUNT 30`

Set proper length of your LED's reset time(check at your LED's datasheet) at RESET_BYTES_AMOUNT define in driver header file.  
72 means that reset signal would be 72 * PWM cycle time long, for 72 it is exactly as long as data send for setting 3 diodes colors.  
`#define RESET_BYTES_AMOUNT 72`

Set values which represents fulfillment of PWM cycle. For example, in my project, PWM cycle would be counting from 0 to 80(It is hardly connected to frequency of timer in used hardware, we want to achieve PWM cycle period as close to 1.25us). Timer counting from 0 to 80 will change state on output pin on compare match with given value.  

To get logical '1' message, we have to set value of 52, it will be interpreted as about 65% high state and 35% low state.  
`#define PWM_VALUE_ONE 52`  

In the other hand, the '0' message shuold be about 35% high state and 65% low state. Value of proper define is set to 27, because 27/80 equals nearly 35%  
`#define PWM_VALUE_ZERO 27`  
![ws2812b_datasheet_timings2](https://user-images.githubusercontent.com/64641846/154581395-1a60bd15-9316-49a1-be32-470fcfc55683.png)  
![ws2812b_datasheet_timings1](https://user-images.githubusercontent.com/64641846/154581408-8d147a29-fb50-44b4-95d6-6ab387e725e2.png)  

---

**Initialization**

In your main program file, firstly you have to declare led tape structure variable. It will contain inforamtions about every sigle diode in strip, length, timings etc.    
`ws2812bLedStruct myOwnLedTape;`  

Then run function which will properly initialize previously created structure with values, create buffers of certain size etc.  
`ws2812bLedStructInit(&myOwnLedTape);`  

---

**Setting colors**

Diodes colors setting is done by calling function showed below, it takes address of Led Strip structure, index of diode values to be edited and rgb parameters in 8bit range. 
`ws2812bSetRGB(&myOwnLedTape, index, red, green, blue);`

---

**Clearing strip**

All diodes in the strip can be cleared by calling: 
`ws2812bClearAll(&myOwnLedTape);`

---

**Clearing strip**

Clearing whole strip at once can be done by calling:
`ws2812bWave(&myOwnLedTape, width, red, green, blue);`

---

**Converting RGB values into data to be send**

Converting RGB values into binary data ready to be send is achieved by calling function below. Best way is to call it only once, just before transmission.
`ws2812bGetBytesArray(&myOwnLedTape)`

---

**Example of implementation strip**

Implementation of this library on STM32 microcontroller is showed in public project avaiable on my github profil:
[STM32_WS2812B_Example](https://github.com/FRSH-0109/STM32_WS2812B_Example)

---