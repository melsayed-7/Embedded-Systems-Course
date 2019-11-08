#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

// Data wire is plugged into port 4 on the Arduino
#define ONE_WIRE_BUS 4
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

int numberOfDevices; // Number of temperature devices found

DeviceAddress tempDeviceAddress; // We'll use this variable to store a found device address

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup(void) {
  
  // Start up the library
  sensors.begin();

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // Print a message to the LCD.
  lcd.setCursor(1,0);
  
  // Grab a count of devices on the wire
  numberOfDevices = sensors.getDeviceCount();
  
  // locate devices on the bus
  lcd.setCursor(1,0);
  lcd.print("Locating devices...");
  lcd.print("Found ");
  lcd.print(numberOfDevices, DEC);
  lcd.println(" devices.");
delay(1000);
  // Loop through each device, print out address
  for(int i=0;i<numberOfDevices; i++) {
    lcd.clear();
    lcd.setCursor(1,0);
    // Search the wire for address
    delay(50);
    if(sensors.getAddress(tempDeviceAddress, i)) {
      lcd.print("Found device ");
      lcd.print(i, DEC);
      lcd.print(" with address: ");
      printAddress(tempDeviceAddress);
      lcd.println();
    } else {
      lcd.print("Found ghost device at ");
      lcd.print(i, DEC);
      lcd.print(" but could not detect address. Check power and cabling");
    }
  }
}

void loop(void) { 
  lcd.clear();
  lcd.setCursor(1,0);
  sensors.requestTemperatures(); // Send the command to get temperatures
  
  // Loop through each device, print out temperature data
  for(int i=0;i<numberOfDevices; i++) {
    // Search the wire for address
    if(sensors.getAddress(tempDeviceAddress, i)){
    
    // Output the device ID
    lcd.print("Temperature for device: ");
    lcd.println(i,DEC);

    // Print the data
    float tempC = sensors.getTempC(tempDeviceAddress);
    lcd.print("Temp C: ");
    lcd.print(tempC);
    lcd.print(" Temp F: ");
    lcd.println(DallasTemperature::toFahrenheit(tempC)); // Converts tempC to Fahrenheit
    }   
  }
  delay(5000);
}

// function to print a device address
void printAddress(DeviceAddress deviceAddress) {
  for (uint8_t i = 0; i < 8; i++) {
    if (deviceAddress[i] < 16) lcd.print("0");
      lcd.print(deviceAddress[i], HEX);
  }
}
