  
  #include <LiquidCrystal.h>
  #include <HX711_ADC.h>
  #if defined(ESP8266)|| defined(ESP32) || defined(AVR)
  #include <EEPROM.h>
  #endif
  
    LiquidCrystal lcd(13, 12, 10, 9, 8, 7);
    
    //pins:
    #define siren 2 
    #define Gas A0
    #define Alert 3
    const int HX711_dout = 4; //mcu > HX711 dout pin
    const int HX711_sck = 5; //mcu > HX711 sck pin
    long count=0;
    float val;
    int sample=0;
    float xValue=0;
  
    //HX711 constructor:
    HX711_ADC LoadCell(HX711_dout, HX711_sck);
    
    const int calVal_eepromAdress = 0;
    unsigned long t = 0;
    
void setup() 
    {
        Serial.begin(57600); delay(10);
       pinMode(Alert,OUTPUT);
       pinMode(Gas,INPUT);
       pinMode(siren,OUTPUT);

        lcd.begin(16,2);
        lcd.print("     LPG");
        lcd.setCursor(0,1);
        lcd.print("   Monitor");
        delay(2000);
  
      Serial.println();
      Serial.println("Starting...");
    
        LoadCell.begin();
        //LoadCell.setReverseOutput();          //uncomment to turn a negative output value to positive
        float calibrationValue;               // calibration value (see example file "Calibration.ino")
        calibrationValue = 222.28; // uncomment this if you want to set the calibration value in the sketch
      
        unsigned long stabilizingtime = 8000; // preciscion right after power-up can be improved by adding a few seconds of stabilizing time
        boolean _tare = true; //set this to false if you don't want tare to be performed in the next step
        LoadCell.start(stabilizingtime, _tare);
        if (LoadCell.getTareTimeoutFlag()) {
          Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
          while (1);
        }
        else 
        {
          LoadCell.setCalFactor(calibrationValue); // set calibration value (float)
          Serial.println("Startup is complete");
        }
  
        lcd.clear();
        lcd.print("Put Weight.");
        delay(100);

    //    calibrate();
    
  }

  void loop() 
  {
      
    static boolean newDataReady = 0;
    const int serialPrintInterval = 0; //increase value to slow down serial print activity
     
   if (LoadCell.update()) newDataReady = true;

        xValue=LoadCell.getData();
   /*
    // Gas Leakage Detection ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
             int Gas_Val=analogRead(Gas);
            
           // Checking Gas leakage
              if(Gas_Val > 80)  // Threshold value for gas leakage.
               {
                  
                  Serial.print(" Gas value: ");
                  Serial.println(Gas_Val);
                  delay(100);
                  digitalWrite(Alert,HIGH);
                  digitalWrite(siren,HIGH); // LED Blinks
                  delay(600);
                  digitalWrite(siren,LOW);
                  delay(600);

                
               //  lcd.setCursor(0,0);
               //  lcd.print("Gas");
               //  lcd.setCursor(0,8);
               //  lcd.print("Leak..."); 
          
              }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    */
    // check for new data/start next conversion:
   
    
    // get smoothed value from the dataset:
    if (newDataReady) 
    {
    
        lcd.setCursor(0,0);
        lcd.print("Weight:");
        lcd.setCursor(0,4);
        lcd.print(xValue);

     if(xValue<360)
     {
      lcd.setCursor(0,0);
      lcd.print("Refill:");
      digitalWrite(siren,HIGH);   // Led Light turns ON. 
     }
     else
     {
      digitalWrite(siren,LOW);
     
     }
    }
else
{
  lcd.print("No Weight");
}
    
  }
