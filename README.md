# WS2812B LED Strip Driver
Driver for controlling addressable WS2812B LED's strips/tapes by PWM modulation.

### Features
- Changing color of every single diode in RGB format(8bit per color)
- Wave generation for given width

### How to use?
After coping/moving driver files into your project, it is necessary to set few things  
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
![](/img/ws2812b_datasheet_timings2.png)  
![](/img/ws2812b_datasheet_timings1.png)  

**Initialization**

In your main program file, firstly you have to declare led tape structure variable. It will contain inforamtions about every sigle diode in strip, length, timings etc.    
`ws2812bLedStruct myOwnLedTape;`  

Then run function which will properly initialize previously created structure with values, create buffers of certain size etc.  
`ws2812bLedStructInit(&myOwnLedTape);`  

**Setting colors**
