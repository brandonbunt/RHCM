#include "Adafruit_MCP9601.h"

#define NUM_SENSORS 2
#define ThermA (0x60)  //ADR to ground - USED
#define ThermB (0x61)  //R2 2.2kΩ - USED
/*#define ThermC (0x62)  //R2  4.3kΩ 
#define ThermD (0x63)  //R2 7.5kΩ   
#define ThermE (0x64)  //R2 13kΩ  (13.3kΩ) 
#define ThermF (0x65)  //22k jumper closed
#define ThermG (0x66)  //43k jumper closed
#define ThermH (0x67)  //default */
#define R 0.0137 //m, 1" diameter. 0.5" radius
#define L 0.2667 //m, 10.5" Tall+
#define SURFACE_AREA 2*3.14159*R*L
#define Qin 7 //Watts

Adafruit_MCP9601 mcp[NUM_SENSORS];
const byte mcpADDR[NUM_SENSORS] = {ThermA, ThermB};

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(5); }
  Serial.println("...loading...");
  Serial.println("I2C Addresses Connecting...");

  for (byte s = 0; s < NUM_SENSORS; s++) {
    if (!mcp[s].begin(mcpADDR[s])) {
      Serial.print("Could not find 0x6");
      Serial.println(s, HEX);
      Serial.println("Please check wiring!");
      while (1)
        ;
    }
    Serial.print("Found 0x6");
    Serial.println(s, HEX);
    mcp[s].setThermocoupleType(MCP9600_TYPE_K);
    Serial.println("Thermocouple Type K");
  }
  delay(3000);
}

void loop() {
  Serial.print("$");
  Serial.print(millis());
  for (byte s = 0; s < NUM_SENSORS; s++) {
    Serial.print(",");
    Serial.print(mcp[s].readThermocouple(), 2);
  }
  int dT = mcp[0].readThermocouple()-mcp[1].readThermocouple();
  Serial.print(",");
  Serial.print((8)/(2*3.14159*L))*(log(1/0.5))*(1/dT); //Benchmark k-value calculation provided real time on serial monitor
  Serial.println("%");
  delay(100);
}
