
#include <Bounce2.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

#define BUTTON_PIN 18
#define BUTTON_STRIP_GND_PIN 16


Bounce debouncer = Bounce();


// Instantiate a Bounce object


void setup() {

  // Setup the button with an internal pull-up :
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON_STRIP_GND_PIN, OUTPUT);
  digitalWrite(BUTTON_STRIP_GND_PIN, LOW);


  // After setting up the button, setup the Bounce instance :
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(20); // interval in ms


delay(100);
  Serial.begin(9600);
  delay(100);
  mySerial.begin(9600);
  Serial.println("Both serial ports initialized...");

  //textmode...
  mySerial.write("!!!");
  mySerial.write(0x0D);


}



void loop() {


  // Update the Bounce instance :
  debouncer.update();

  // Get the updated value :
  int value = debouncer.read();

  // Turn on or off the LED as determined by the state :
  if (  debouncer.fell()  ) {
    Serial.println("Button Press detected");

    dispense(30);


  }

}

void dispense(uint16_t ml) {
  //uint16_t ticks = int(ml*2.78F);
  //mySerial.print("Dispensing: ");
  //mySerial.print(ticks);
  //mySerial.println(" ticks");

  //header
  mySerial.write("tickdisp 83 66");// tickdisp <ticks> <speed>

  mySerial.write(0x0D); 
  delay(500);
}

/*
  Software serial multple serial test

  Receives from the hardware serial, sends to software serial.
  Receives from software serial, sends to hardware serial.

  The circuit:
   RX is digital pin 10 (connect to TX of other device)
   TX is digital pin 11 (connect to RX of other device)

  Note:
  Not all pins on the Mega and Mega 2560 support change interrupts,
  so only the following can be used for RX:
  10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

  Not all pins on the Leonardo support change interrupts,
  so only the following can be used for RX:
  8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

  created back in the mists of time
  modified 25 May 2012
  by Tom Igoe
  based on Mikal Hart's example

  This example code is in the public domain.

*/

//From toher online guide
//byte d=0xFF;
//mySerial.println("!!!");
//mySerial.println("?");
//mySerial.write(d);







