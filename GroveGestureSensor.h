#ifndef GroveGesture_H
#define GroveGesture_H

#include <Arduino.h>
#include "../Grove/Grove.h"

typedef enum GroveGesture {
	NONE = 0, RIGHT, LEFT, UP, DOWN, FORWARD, BACKWARD, CLOCKWISE, COUNTER_CLOCKWISE, WAVE	
} GroveGesture;

class GroveGestureSensor {
	private:
		uint8_t _initializationErrorCode;
		
	public:
		GroveGestureSensor(GrovePin pins);
		virtual ~GroveGestureSensor() {};
		void initialize();
		boolean isInitialized();
		uint8_t getInitializationErrorCode();
		GroveGesture getGesture();
};

#endif