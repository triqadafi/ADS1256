// Arudino Sample Code to use ADS1256 library
// Reads 4 differential channels
// Written by Adien Akhmad, August 2015
// Modfified Jan 2019 by Axel Sepulveda for ATMEGA328
// Modfified Feb 2020 by @triqadafi for ARDUINO UNO and using BLACK VERSION ADS1256

#include <ADS1256.h>
#include <SPI.h>

// Initialize ADS1256 object
#define BOARD_CLOCK 7.68 // crystal frequency used on ADS1256
#define VREF 2.5 // voltage reference
ADS1256 adc(BOARD_CLOCK, VREF);

void setup()
{
  Serial.begin(9600);

  // start the ADS1256 with data rate of 15 SPS
  // other data rates: 
  // ADS1256_DRATE_30000SPS
  // ADS1256_DRATE_15000SPS
  // ADS1256_DRATE_7500SPS
  // ADS1256_DRATE_3750SPS
  // ADS1256_DRATE_2000SPS
  // ADS1256_DRATE_1000SPS
  // ADS1256_DRATE_500SPS
  // ADS1256_DRATE_100SPS
  // ADS1256_DRATE_60SPS
  // ADS1256_DRATE_50SPS
  // ADS1256_DRATE_30SPS
  // ADS1256_DRATE_25SPS
  // ADS1256_DRATE_15SPS
  // ADS1256_DRATE_10SPS
  // ADS1256_DRATE_5SPS
  // ADS1256_DRATE_2_5SPS
  // 
  // NOTE : Data Rate vary depending on crystal frequency. Data rates listed below assumes the crystal frequency is 7.68Mhz
  //        for other frequency consult the datasheet.
  //Posible Gains 
  //ADS1256_GAIN_1 
  //ADS1256_GAIN_2 
  //ADS1256_GAIN_4 
  //ADS1256_GAIN_8 
  //ADS1256_GAIN_16 
  //ADS1256_GAIN_32 
  //ADS1256_GAIN_64 
  Serial.println("Starting ADC");
  adc.begin(ADS1256_DRATE_15SPS,ADS1256_GAIN_1, false);
  Serial.println("LOOP!");
}

void loop()
{ 

  // Efficient Input Cycling
  // to learn further, read on datasheet page 21, figure 19 : Cycling the ADS1256 Input Multiplexer
  adc.waitDRDY(); // wait for DRDY to go low before changing multiplexer register
  adc.setChannel(2,3);   // Set the MUX for differential between ch2 and 3 
  float sensor1 = adc.readCurrentChannel();

  adc.waitDRDY();
  adc.setChannel(4,5);
  float sensor2 = adc.readCurrentChannel();

  adc.waitDRDY();
  adc.setChannel(6,7);
  float sensor3 = adc.readCurrentChannel();

  adc.waitDRDY();
  adc.setChannel(0,1);
  float sensor4 = adc.readCurrentChannel();

  //print the result.
  Serial.print(sensor1,10);
  Serial.print("\t");
  Serial.print(sensor2,10);
  Serial.print("\t");
  Serial.print(sensor3,10);
  Serial.print("\t");
  Serial.println(sensor4,10);
}

