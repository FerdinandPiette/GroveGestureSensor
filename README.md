# GroveGestureSensor
Gesture Sensor Library for Arduino Uno + Grove shield.
[Link to the tested grove module](http://wiki.seeed.cc/Grove-Gesture_v1.0/).

## Example 

```c++
#include <GroveGestureSensor.h>

GroveGestureSensor gestureSensor(GROVE_I2C);

void setup() {
  Serial.begin(9600);
  gestureSensor.initialize();
  if(!gestureSensor.isInitialized()) {
    Serial.print("GroveGestureSensor initialization error :");
    Serial.println(gestureSensor.getInitializationErrorCode());
  }
}

void loop() {
  GroveGesture gesture = gestureSensor.getGesture();
  if(GroveGesture::RIGHT == gesture) {
    Serial.println("Right");
  } else if(GroveGesture::LEFT == gesture) {
    Serial.println("Left");
  } else if(GroveGesture::UP == gesture) {
    Serial.println("Up");
  } else if(GroveGesture::DOWN == gesture) {
    Serial.println("Down");
  } else if(GroveGesture::FORWARD == gesture) {
    Serial.println("Forward");
  } else if(GroveGesture::BACKWARD == gesture) {
    Serial.println("Backward");
  } else if(GroveGesture::CLOCKWISE == gesture) {
    Serial.println("Clockwise");
  } else if(GroveGesture::COUNTER_CLOCKWISE == gesture) {
    Serial.println("Counter clockwise");
  } else if(GroveGesture::WAVE == gesture) {
    Serial.println("Wave");
  }
  delay(100);
}
```

## Documentation
### `GroveGestureSensor(GrovePin pins)`
parameters: pins - must be GrovePin::GROVE_I2C

### `void initialize()`
Initialize the sensor before using it.

### `boolean isInitialized()`
Return `true` if the sensor is initialized - `false` otherwise

### `uint8_t getInitializationErrorCode()`
Return the error code after the initialization failure.
- 0 : The sensor is correctly initialized
- 0xFE : The `initialize` method was not called yet
- For the other error code, check the source code (TODO)

### `GroveGesture getGesture()`
Return the detected gesture :
- GroveGesture::NONE : No gesture detected
- GroveGesture::LEFT
- GroveGesture::RIGHT
- GroveGesture::UP
- GroveGesture::DOWN
- GroveGesture::FORWARD
- GroveGesture::BACKWARD
- GroveGesture::CLOCKWISE
- GroveGesture::COUNTER_CLOCKWISE
- GroveGesture::WAVE
