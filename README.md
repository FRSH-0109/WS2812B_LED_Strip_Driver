# WS2812B LED Strip Driver
Drivers for controlling addressable WS2812B LED's strips/tapes

### Features
- Changing color of every single diode in RGB format(8bit per color)
- Wave generation for certain width

### How to use?
**Defines**  
Set proper length of your strip at LED_AMOUNT define in driver header file  
`#define LED_AMOUNT 30`

Set proper length of your LED's reset time(check at your LED's datasheet) at RESET_BYTES_AMOUNT define in driver header file.  
72 means that reset signal would be 72 * PWM cycle time long, for 72 it is exactly as long as data send for setting 3 diodes colors.  
`#define RESET_BYTES_AMOUNT 72`

Set value which will be as logical 1 for diodes at PWM_VALUE_ONE define in driver header file  
`#define PWM_VALUE_ONE 52`

![](/img/ws2812b_datasheet_timings1.png)  
![](/img/ws2812b_datasheet_timings2.png)

#define PWM_VALUE_ZERO 27
