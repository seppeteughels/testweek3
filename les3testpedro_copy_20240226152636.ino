/* This code is to use with Adafruit BMP280           (Metric)
 * It  measures both temperature and pressure and it displays them on the Serial monitor  with the altitude
 * It's a modified version of the Adafruit example code
  * Refer to www.surtrtech.com or SurtrTech Youtube channel
 */

#include  <Adafruit_BMP280.h>
const int lm35_pin = A3;
Adafruit_BMP280 bmp; // I2C Interface

void setup()  {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));

  if  (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor,  check wiring!"));
    while (1);
  }

  /* Default settings from datasheet.  */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500);  /* Standby time. */
}

void loop() {
    Serial.print(F("Temperature outside  = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

   

    

    Serial.println();
    delay(2000);
 int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);	/* Read Temperature */
  temp_val = (temp_adc_val * 4.88);	/* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10);	/* LM35 gives output of 10mv/°C */
  Serial.print("Temperature inside = ");
  Serial.print(temp_val);
  Serial.print(" Degree Celsius\n");
  delay(1000);
}
