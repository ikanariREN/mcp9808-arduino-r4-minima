#include "mcp9808.h"


//Constructor
MCP9808::MCP9808(){}

bool MCP9808::isDetected(void)
{
	int id = 0;
	char data[256] ={0};
	Wire.beginTransmission(MCP9808_SLAVE_ADD); // transmit to device 0x18 (24)
	Wire.write(MCP9808_REG_DEV_ID);
	Wire.endTransmission();
	Wire.requestFrom(MCP9808_SLAVE_ADD, 2);
	if (2 <= Wire.available()) { // if two bytes were received

		id = Wire.read();  // receive high byte (overwrites previous reading)

		id = id << 8;    // shift high byte to be high 8 bits

		id |= Wire.read(); // receive low byte as lower 8 bits
	}
	if(id == 1024){
		this->id = id;
		return true;
	}
	return false;	
} 

void MCP9808::begin(void)
{
  Wire.begin();
}

void MCP9808::getRawTemp(void)
{ 
	uint16_t temperature;
	Wire.beginTransmission(MCP9808_SLAVE_ADD); // transmit to device 0x18 (24)
	Wire.write(MCP9808_REG_TEMP);
	Wire.endTransmission();
	delay(100);
	Wire.requestFrom(MCP9808_SLAVE_ADD, 2);
	if (2 <= Wire.available()) { // if two bytes were received
		temperature = Wire.read();  // receive high byte (overwrites previous reading)
		temperature = temperature << 8;
		temperature |= Wire.read();
		this->rawTemp = temperature;
	}
}

void MCP9808::calculateFloatTemp(void)
{
	float floatTemp = 0.0;
	getRawTemp();
	floatTemp = (this->rawTemp & 0x0FFF);
	floatTemp = floatTemp/16.0;
	if(floatTemp < 0.0){ //case temperature is negative
		floatTemp = floatTemp - 256.0;
	}
	this->temperature = floatTemp;
}

float MCP9808::getFloatTemp()
{
  return this->temperature;
}

int MCP9808::getMCP9808id(void)
{
  return this->id;
}

void MCP9808::setSleepMode(uint16_t cmd)
{
  cmd = 0x100;
	uint16_t buffToSend[2] ={MCP9808_REG_CFG,cmd}; //cmd=0x100;
	Wire.beginTransmission(MCP9808_SLAVE_ADD);
	Wire.write((uint8_t*)buffToSend,4);
	Wire.endTransmission();	
}

void MCP9808::setWakeUpMode(uint16_t cmd)
{
  cmd = 0x0000;
	uint16_t buffToSend[2] ={MCP9808_REG_CFG,cmd}; //cmd=0x0000;
	Wire.beginTransmission(MCP9808_SLAVE_ADD);
	Wire.write((uint8_t*)buffToSend,4);
	Wire.endTransmission();
}

//Destructor
MCP9808::~MCP9808(){}
