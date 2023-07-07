#ifndef  MCP9808_H_
#define MCP9808_H_

#include "Arduino.h"
#include "Wire.h"
#include <stdint.h>
#include <stdbool.h>

/*---MCP9808 registers---*/

#define MCP9808_REG_RFU               0x00
#define MCP9808_REG_CFG               0x01
#define MCP9808_REG_ALERT_TEMP_UPPER  0x02
#define MCP9808_REG_ALERT_TEMP_LOWER  0x03
#define MCP9808_REG_CRIT_TEMP         0x04
#define MCP9808_REG_TEMP              0x05
#define MCP9808_REG_MAN_ID            0x06
#define MCP9808_REG_DEV_ID            0x07
#define MCP9808_REG_RES               0x08

/*--MCP9808 slave address--*/
#define MCP9808_SLAVE_ADD 24

/*--Class MCP9808--*/
class MCP9808{
	private:
		int id = 0;
		uint16_t rawTemp = 0;
		float temperature = 0.0;
	public:
		MCP9808();
		void begin(void);
		bool isDetected(void);
		void getRawTemp(void);
		void calculateFloatTemp(void);
		void setSleepMode(uint16_t cmd);
		void setWakeUpMode(uint16_t cmd);
		float getFloatTemp(void);
		int getMCP9808id(void);
		~MCP9808();


};

#endif
