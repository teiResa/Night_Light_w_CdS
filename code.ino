int ledPin = 9;       //LED will be on pin ~9

void setup() {
  Serial.begin(9600);     //initialises serial communication (for debugging)
  pinMode(ledPin, OUTPUT);    //sets ledPin as OUTPUT

  //the PinMode statement may be redundant... but I'll leave it.

}

void loop() {
  int sensorRead = analogRead(A0);    //reads photosensor
  Serial.println(sensorRead);     //prints to Serial Monitor


  //map input of sensorRead range (400 - 1000) to the LED's range (0 - 255)
  int brightness = map(sensorRead, 400, 1000, 0, 255);


  // if sensorRead is over X, brightness = 0; else brightness = 255
  if (sensorRead < 150) {
    brightness = 255;
      //set LED's brightness to value 0 - 255
      analogWrite(ledPin, brightness);
      delay(30);      //delays for 30ms
  } else {
    brightness = 0;
      analogWrite(ledPin, brightness);
      delay(30);      //delays for 30ms
  }


}
