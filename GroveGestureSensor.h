#ifndef GroveGesture_H
#define GroveGesture_H

#include <Arduino.h>
#include <Grove.h>

typedef enum GroveGesture {
	NONE = 0, RIGHT, LEFT, UP, DOWN, FORWARD, BACKWARD, CLOCKWISE, COUNTER_CLOCKWISE, WAVE	
} GroveGesture;

class GroveGestureSensor {
	private:
		uint8_t _initializationErrorCode;
		
	public:
		GroveGestureSensor();
		virtual ~GroveGestureSensor() {};
		void initialize(GrovePin pins);
		boolean isInitialized();
		uint8_t getInitializationErrorCode();
		GroveGesture getGesture();
};

#endif