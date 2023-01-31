#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void setup() {
  Serial.begin(115200);
  accel.begin();
}

void loop() {
  sensors_event_t event;
  accel.getEvent(&event);

  float x = event.acceleration.x;
  float y = event.acceleration.y;
  float z = event.acceleration.z;

  if (x > 2.0 && y < 0.5 && z < 0.5) {
    Serial.println("Gesture: Swipe Right");
  } else if (x < -2.0 && y < 0.5 && z < 0.5) {
    Serial.println("Gesture: Swipe Left");
  }

  delay(100);
}
