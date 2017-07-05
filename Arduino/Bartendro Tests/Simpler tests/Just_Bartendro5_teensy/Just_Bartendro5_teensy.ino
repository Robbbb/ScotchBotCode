
#include <Bounce2.h>

#define BUTTON_PIN_2 15
#define BUTTON_PIN 16
#define BUTTON_STRIP_GND_PIN 14


Bounce debouncer = Bounce();
Bounce debouncer2 = Bounce();


// Instantiate a Bounce object
byte d = 0xFF;

void setup() {

  // Setup the button with an internal pull-up :
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(BUTTON_STRIP_GND_PIN, OUTPUT);
  digitalWrite(BUTTON_STRIP_GND_PIN, LOW);
  pinMode(13, OUTPUT);


  // After setting up the button, setup the Bounce instance :
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(20); // interval in ms
  debouncer2.attach(BUTTON_PIN_2);
  debouncer2.interval(20); // interval in ms


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
  // debouncer.update();
    debouncer.update();
  debouncer2.update();
  digitalWrite(13, HIGH);
  // Turn on or off the LED as determined by the state :

  if (  debouncer.fell() ) {
    Serial.println("Button Press detected");
    dispense(30);
  }
  else if (  debouncer2.fell() ) {
    Serial.println("Button 2 Press detected");
    undispense();
  }
}
void undispense() {
  Serial1.write("backwards");
  Serial1.write(0x0D);
    delay(29);


  Serial1.write("tickdisp 55 135");
  //  Serial1.println("tickdisp 83 66");// tickdisp <ticks> <speed>
  Serial1.write(0x0D);
    delay(29);

  Serial1.write("forwards");
  Serial1.write(0x0D);
      delay(29);


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
  delay(100);
}


//From toher online guide
//byte d=0xFF;
//mySerial.println("!!!");
//mySerial.println("?");
//mySerial.write(d);







