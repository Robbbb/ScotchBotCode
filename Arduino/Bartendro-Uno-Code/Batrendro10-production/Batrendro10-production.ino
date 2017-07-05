#include <SoftwareSerial.h>
#include <Bounce2.h>

#define FILL_BUTTON_PIN 3
#define PRIME_BUTTON_PIN 7
#define PURGE_BUTTON_PIN 6

#define BARTENDRO_SPEEED 255 ///not used cuz we lazy

#define AMMETER_DUTY_MAX 130 //5V with 4.7k ohm resisitor
#define AMMETER_DUTY_MIN 0
#define AMMETER_DISPLAY_MAX 500
#define AMMETER_PIN 9

#define DEBOUNCE_INTERVAL 20

SoftwareSerial bartendroSerial(10, 11); // RX, TX

Bounce fillDebounce = Bounce();
Bounce primeDebounce = Bounce();
Bounce purgeDebounce = Bounce();

//////DRINK STUFFF

 //// // ticks = mL * 2.78.   ///FORMULA FOR ML TO TICKS

  int delayBetweenLurches = 1333;
  int ticksPerLurch = 9;
  int lurchPerDrink = 10;

  int ammeterTimeOut = 30000;

////////

long lastFillTime;


void setup() {
  buttonSetup();
  Serial.begin(9600);
  bartendroSerial.begin(9600);
  Serial.print("Both serial ports initialized...");
  bartendroSetup();

}
void bartendroSetup() {
  //textmode...
  bartendroSerial.write("!!!");
  bartendroSerial.write(0x0D);
  Serial.println("bartendro initialized");
}
void buttonSetup() {

  // Setup the buttons with an internal pull-up :
  pinMode(FILL_BUTTON_PIN, INPUT_PULLUP);
  pinMode(PRIME_BUTTON_PIN, INPUT_PULLUP);
  pinMode(PURGE_BUTTON_PIN, INPUT_PULLUP);
  //Set the ground pin low for the button strip



  // After setting up the button, setup the Bounce instance :
  fillDebounce.attach(FILL_BUTTON_PIN);
  fillDebounce.interval(DEBOUNCE_INTERVAL); // interval in ms
  primeDebounce.attach(PRIME_BUTTON_PIN);
  primeDebounce.interval(DEBOUNCE_INTERVAL); // interval in ms
  purgeDebounce.attach(PURGE_BUTTON_PIN);
  purgeDebounce.interval(DEBOUNCE_INTERVAL); // interval in ms



}
void updateButtons() {
  fillDebounce.update();
  primeDebounce.update();
  purgeDebounce.update();

}

void loop() {
  updateButtons();
   if ( fillDebounce.fell() ) { ///ACTIVE HIGH (Normally closed button)
    Serial.println("Button 2 Press detected (fillDebounce)");
    showDrink();
  }
  else if ( primeDebounce.read() == LOW) { //ACTIVE LOW
    Serial.println("Button 3 Press detected(primeDebounce)");
    primeTube();
  }
  else if ( purgeDebounce.read() == LOW ) {
    Serial.println("Button 4 Press detected(purgeDebounce)");
    unprimeTube();
  }

  
  if (millis()>(ammeterTimeOut+lastFillTime))
  {
    ammeterGoTo(0);
  }
}

void showDrink() {
  pump();
  int ammeterSweepPerLurch = 350 / lurchPerDrink;
  for (int tickCount = 0; tickCount < lurchPerDrink; ++tickCount)
  {
    bartendroSerial.write("tickdisp 9 255");//One 'tick' is 1/4 turn of the trilobe thing
    bartendroSerial.write(0x0D);
    ammeterGoTo(tickCount * ammeterSweepPerLurch);
    delay(delayBetweenLurches);
  }
  lastFillTime = millis();

}

void pump() {
  bartendroSerial.write("forwards");
  bartendroSerial.write(0x0D);
}

void unpump() {
  bartendroSerial.write("backwards");
  bartendroSerial.write(0x0D);
}

void unprimeTube() {
  unpump();
  bartendroSerial.write("timedisp 100");
  bartendroSerial.write(0x0D);
  delay(100);
}

void primeTube() {
  pump();
  bartendroSerial.write("timedisp 100");
  bartendroSerial.write(0x0D);
  delay(100);

}

void ammeterGoTo(int target) {
  analogWrite(AMMETER_PIN, map(target, 0, AMMETER_DISPLAY_MAX, AMMETER_DUTY_MIN, AMMETER_DUTY_MAX));
}

