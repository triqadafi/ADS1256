# ADS1256
Arduino Library for Texas Instrument ADS1256, working with Arduino IDE 1.8.5, Arduino UNO 

# Installation
As any arduino library (import library)

# Wiring
## ADS1256 Board (BLACK VERSION) - Arduino UNO Board
- 5V          -     5V
- GND         -     GND
- SCLK        -     pin 13 (SCK)
- DIN         -     pin 11 (MOSI)
- DOUT        -     pin 12 (MISO)
- **RESET       -     pin 8**
- DRDY        -     pin 9
- CS          -     pin 10
- POWN        -      5V


# Examples
Single_Ended
## Pin Configuration
- AIN1 index 1
- AIN2 index 2
- AIN3 index 3
- AIN4 index 4
- AIN5 index 5
- AIN6 index 6
- AIN7 index 7
- AIN8 index 0

Differential (negative and positive input may different)
- AIN1 and AIN2 index 2,3
- AIN3 and AIN4 index 4,5
- AIN5 and AIN6 index 6,7
- AIN7 and AIN8 index 0,1

# Functions

ADS1256 adc(clockSpeed in Mhz, VREF in volt): Class Constructor: 

adc.sendCommand(SDATAC): Send SDATAC to stop reading contionus data, so we can send other command

adc.waitDRDY(): Waits for the data ready flag (ADC conversion ended and ready to be read)

adc.setChannel(x): Sets the channels to be read in next reading cycle, configured in "single end" (reads between the "x" input AINx and ground GND)
  
adc.setChannel(i,j): Sets the channels to be read in next reading cycle, configured in "differential mode", first argument (i) is the positive input and second argument (j) is negative input to ADC. As stated in device datasheet any combination (i,j) (between 0 and 7) is possible but it's recomended to use adjacent inputs (0 and 1, 2 and 3, etc) 

adc.readRegister(reg): Returns value of the register "reg" 

adc.readCurrentChannel(): Returns the value of the current reading stored in ADC

# Notice: Working as 14/2/2020
use BLACK VERSION board

# Timing Diagram
datasheet page 9

# Data Settling Time
datasheet page 20-22