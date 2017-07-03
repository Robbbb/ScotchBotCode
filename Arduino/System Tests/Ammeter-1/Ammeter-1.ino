/*
 Fading

 This example shows how to fade an LED using the analogWrite() function.

 The circuit:
 * LED attached from digital pin 9 to ground.

 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://www.arduino.cc/en/Tutorial/Fading

 This example code is in the public domain.

 */


int ledPin = 9;    // LED connected to digital pin 9

void setup() {
  // nothing happens in setup
}

int maxx = 165;
int minn = 0;
int speeed = 190;
void loop() {
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= maxx; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(speeed);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = maxx ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(speeed);
  }
  analogWrite(ledPin, map(100,0,500,minn,maxx));
  delay(speeed*10);
    analogWrite(ledPin, map(200,0,500,minn,maxx));
  delay(speeed*10);
    analogWrite(ledPin, map(300,0,500,minn,maxx));
  delay(speeed*10);
    analogWrite(ledPin, map(400,0,500,minn,maxx));
  delay(speeed*10);
      analogWrite(ledPin, map(500,0,500,minn,maxx));
  delay(speeed*10);
}


