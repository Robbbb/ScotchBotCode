
#include <Bounce2.h>


#define BUTTON_PIN 16
#define BUTTON_STRIP_GND_PIN 14


Bounce debouncer = Bounce();


// Instantiate a Bounce object
byte d=0xFF;

void setup() {

  // Setup the button with an internal pull-up :
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON_STRIP_GND_PIN, OUTPUT);
  digitalWrite(BUTTON_STRIP_GND_PIN, LOW);
  pinMode(13,OUTPUT);


  // After setting up the button, setup the Bounce instance :
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(20); // interval in ms


  delay(2000);
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("Both serial ports initialized...");

  //textmode...
  Serial1.write("!!!");
//  Serial1.println("?");
//  Serial1.write(d);
  Serial1.write(0x0D);


}



void loop() {

  // Update the Bounce instance :
  debouncer.update();
digitalWrite(13,HIGH);
  // Turn on or off the LED as determined by the state :
  if (  debouncer.fell() ) {
    Serial.println("Button Press detected");
    dispense(30);
    digitalWrite(13,LOW);
  }
}

void dispense(uint16_t ml) {
  //uint16_t ticks = int(ml*2.78F);
  //mySerial.print("Dispensing: ");
  //mySerial.print(ticks);
  //mySerial.println(" ticks");

  //header
  Serial1.write("tickdisp 11 135"); 
//  Serial1.println("tickdisp 83 66");// tickdisp <ticks> <speed>
  Serial1.write(0x0D);
  delay(500);
}


//From toher online guide
//byte d=0xFF;
//mySerial.println("!!!");
//mySerial.println("?");
//mySerial.write(d);







