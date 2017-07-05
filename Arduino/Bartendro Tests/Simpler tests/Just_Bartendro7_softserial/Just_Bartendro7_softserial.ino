#include <SoftwareSerial.h>
#include <Bounce2.h>

#define LED_PIN 13
#define BUTTON_PIN_1 5
#define BUTTON_PIN_2 4
#define BUTTON_PIN_3 7
#define BUTTON_PIN_4 6
#define BUTTON_STRIP_GND_PIN 3
#define BARTENDRO_SPEEED 200

#define DEBOUNCE_INTERVAL 20

SoftwareSerial mySerial(10, 11); // RX, TX

Bounce debouncer1 = Bounce();
Bounce debouncer2 = Bounce();
Bounce debouncer3 = Bounce();
Bounce debouncer4 = Bounce();


void setup() {
  // pinMode(LED_PIN, OUTPUT); // for LED use
buttonSetup();
  // delay(50);
  Serial.begin(9600);
  // while (!Serial) ; // wait for Arduino Serial Monitor to open
  mySerial.begin(9600);
  Serial.print("Both serial ports initialized...");

  //textmode...
  mySerial.write("!!!");
  mySerial.write(0x0D);
  Serial.println("bartendro initialized");


}
void buttonSetup(){

  // Setup the buttons with an internal pull-up :
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(BUTTON_PIN_3, INPUT_PULLUP);
  pinMode(BUTTON_PIN_4, INPUT_PULLUP);
  //Set the ground pin low for the button strip
  pinMode(BUTTON_STRIP_GND_PIN, OUTPUT);
  digitalWrite(BUTTON_STRIP_GND_PIN, LOW);



  // After setting up the button, setup the Bounce instance :
  debouncer1.attach(BUTTON_PIN_1);
  debouncer1.interval(DEBOUNCE_INTERVAL); // interval in ms
  debouncer2.attach(BUTTON_PIN_2);
  debouncer2.interval(DEBOUNCE_INTERVAL); // interval in ms
  debouncer3.attach(BUTTON_PIN_3);
  debouncer3.interval(DEBOUNCE_INTERVAL); // interval in ms
  debouncer4.attach(BUTTON_PIN_4);
  debouncer4.interval(DEBOUNCE_INTERVAL); // interval in ms



}
void updateButtons(){
    debouncer1.update();
  debouncer2.update();
    debouncer3.update();
  debouncer4.update();
  
}

void loop() {
updateButtons();

  if ( debouncer1.fell() ) {
    Serial.println("Button 1 Press detected");
    dispense(30);
  }
  else if (  debouncer2.fell() ) {
    Serial.println("Button 2 Press detected");
    undispense();
  }
  else if (  debouncer3.read() ==LOW) {
    Serial.println("Button 3 Press detected");
    primeTube();
  }
  else if (  debouncer4.read() ==LOW ) {
    Serial.println("Button 4 Press detected");
    unprimeTube();
  }
}

void undispense() {
unpump();
  mySerial.write("tickdisp 55 255");
  //  Serial1.println("tickdisp 83 66");// tickdisp <ticks> <speed>
  mySerial.write(0x0D);


}

void dispense(uint16_t ml) {
  //uint16_t ticks = int(ml*2.78F);
  //mySerial.print("Dispensing: ");
  //mySerial.print(ticks);
  //mySerial.println(" ticks");
pump();
  //header
  mySerial.write("tickdisp 44 255");
  //  Serial1.println("tickdisp 83 66");// tickdisp <ticks> <speed>
  mySerial.write(0x0D);
  delay(100);
}

void pump(){
  mySerial.write("forwards");
  mySerial.write(0x0D);
}

void unpump(){
  mySerial.write("backwards");
  mySerial.write(0x0D);
}

void unprimeTube(){
  unpump();
  mySerial.write("timedisp 500");
  mySerial.write(0x0D);
  delay(25);
}

void primeTube(){
  pump();
  mySerial.write("timedisp 500");
  mySerial.write(0x0D);
  delay(25);

}




