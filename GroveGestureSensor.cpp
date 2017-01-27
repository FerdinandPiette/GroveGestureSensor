#include "GroveGestureSensor.h"
#include "paj7620.h"

GroveGestureSensor::GroveGestureSensor(GrovePin pins) {
	this->_initializationErrorCode = 0xFE;
}

void GroveGestureSensor::initialize() {	
	this->_initializationErrorCode = paj7620Init();
}

boolean GroveGestureSensor::isInitialized() {
	return 0 == this->_initializationErrorCode;
}

uint8_t GroveGestureSensor::getInitializationErrorCode() {
	return this->_initializationErrorCode;
}

GroveGesture GroveGestureSensor::getGesture() {
	uint8_t data = 0, data1 = 0;
	GroveGesture gesture = NONE;
	paj7620ReadReg(0x43, 1, &data);
	paj7620ReadReg(0x44, 1, &data1);
	
	if(data1) { gesture = GroveGesture::WAVE; }
	else {
		switch(data) {
			case GES_RIGHT_FLAG: 
				gesture = GroveGesture::RIGHT;
				break;
			case GES_LEFT_FLAG: 
				gesture = GroveGesture::LEFT;
				break;
			case GES_UP_FLAG: 
				gesture = GroveGesture::UP;
				break;
			case GES_DOWN_FLAG: 
				gesture = GroveGesture::DOWN;
				break;
			case GES_FORWARD_FLAG: 
				gesture = GroveGesture::FORWARD;
				break;
			case GES_BACKWARD_FLAG: 
				gesture = GroveGesture::BACKWARD;
				break;
			case GES_CLOCKWISE_FLAG: 
				gesture = GroveGesture::CLOCKWISE;
				break;
			case GES_COUNT_CLOCKWISE_FLAG: 
				gesture = GroveGesture::COUNTER_CLOCKWISE;
				break;
		}
	}
	/*if(0 != data || 0 != data1) {
		Serial.print(data);
		Serial.print(" - ");
		Serial.println(data1);
	}*/
	/*if (!paj7620ReadReg(0x43, 1, &data)) {
		switch (data) {
			case GES_RIGHT_FLAG:
				delay(GES_ENTRY_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_FORWARD_FLAG) {
					gesture = FORWARD;
					delay(GES_QUIT_TIME);
				} else if(data == GES_BACKWARD_FLAG) {
					gesture = BACKWARD;
					delay(GES_QUIT_TIME);
				} else {
					gesture = RIGHT;
				}          
			break;
			case GES_LEFT_FLAG: 
				delay(GES_ENTRY_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_FORWARD_FLAG) {
					gesture = FORWARD;
					delay(GES_QUIT_TIME);
				} else if(data == GES_BACKWARD_FLAG) {
					gesture = BACKWARD;
					delay(GES_QUIT_TIME);
				} else {
					gesture = LEFT;
				}
				break;
			case GES_UP_FLAG:
				delay(GES_ENTRY_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_FORWARD_FLAG) {
					gesture = FORWARD;
					delay(GES_QUIT_TIME);
				} else if(data == GES_BACKWARD_FLAG) {
					gesture = BACKWARD;
					delay(GES_QUIT_TIME);
				} else {
					gesture = UP;
				}          
				break;
			case GES_DOWN_FLAG:
				delay(GES_ENTRY_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_FORWARD_FLAG) {
					gesture = FORWARD;
					delay(GES_QUIT_TIME);
				} else if(data == GES_BACKWARD_FLAG) {
					gesture = BACKWARD;
					delay(GES_QUIT_TIME);
				} else {
					gesture = DOWN;
				}          
				break;
			case GES_FORWARD_FLAG:
				gesture = FORWARD;
				delay(GES_QUIT_TIME);
				break;
			case GES_BACKWARD_FLAG:     
				gesture = BACKWARD;
				delay(GES_QUIT_TIME);
				break;
			case GES_CLOCKWISE_FLAG:
				gesture = CLOCKWISE;
				break;
			case GES_COUNT_CLOCKWISE_FLAG:
				gesture = COUNT_CLOCKWISE;
				break;  
			default:
				paj7620ReadReg(0x44, 1, &data1);
				if (data1 == GES_WAVE_FLAG) {
					gesture = WAVE;
				}
		}
	}*/
	
	/*if(NONE != gesture) {
		this->_gestureBuffer[this->_gestureBufferIndex++] = gesture;
	}*/
	return gesture;
}