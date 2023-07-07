#include "mcp9808.h"
#include "SoftwareSerial.h"

#define RX_PIN 10
#define TX_PIN 11


MCP9808 mcp9808; //object of class MCP9808
SoftwareSerial mcp9808Serial (RX_PIN, TX_PIN);
char tx_data[256] = {0}; //store tx messages

void setup()
{
  mcp9808.begin();               //Join I2C bus
  pinMode(RX_PIN,INPUT);         //Set RX input
  pinMode(TX_PIN,OUTPUT);        //Set TX output
  mcp9808Serial.begin(9600);     //Set baudrate
  while(!mcp9808.isDetected()){  //Check if sensor is detected
    
  } 
  /*Print sensor's MAN ID*/
  sprintf(tx_data,"MCP9808 detected,sensor id is 0x%x \r\n",mcp9808.getMCP9808id());
  mcp9808Serial.print(tx_data);
}

void loop()
{  
  delay(100);
  /*Calculate float temperature*/
  mcp9808.calculateFloatTemp();
  
  /*Clear tx buffer*/
  memset(tx_data,0,sizeof(tx_data));
  
  /*Print temperature data*/
  mcp9808Serial.print("Measured temperature is:");
  mcp9808Serial.println(mcp9808.getFloatTemp(),2);
  delay(2000);
  
}