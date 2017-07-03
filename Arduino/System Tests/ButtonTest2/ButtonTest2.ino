
/* 
 DESCRIPTION
 ====================
 Simple example of the Bounce library that switches the debug LED when 
 either of 2 buttons are pressed.
 */
 
// Include the Bounce2 library found here :
// https://github.com/thomasfredericks/Bounce2
#include <Bounce2.h>

#define BUTTON_PIN_1 18 //Buttons on the flexible numbered pad 1-4
#define BUTTON_PIN_2 17 //Buttons on the flexible numbered pad 1-4
#define BUTTON_PIN_3 20 //Buttons on the flexible numbered pad 1-4
#define BUTTON_PIN_4 19. //Buttons on the flexible numbered pad 1-4
#define BUTTON_PIN_5 5 // not used
#define BUTTON_PIN_6 7 //red inv logic
#define BUTTON_PIN_7 6 //left
#define BUTTON_PIN_8 4 //right
#define BUTTON_STRIP_GND_PIN 16

 #define DEBOUNCE_INTERVAL 5 //ms interval for debounce on buttons


#define LED_PIN 13

// Instantiate a Bounce object
Bounce debouncer1 = Bounce(); 
Bounce debouncer2 = Bounce(); 
Bounce debouncer3 = Bounce(); 
Bounce debouncer4 = Bounce(); 
Bounce debouncer5 = Bounce(); 
Bounce debouncer6 = Bounce(); 
Bounce debouncer7 = Bounce(); 
Bounce debouncer8 = Bounce(); 

void setup() {
  Serial.begin(9600);
  // Setup the first button with an internal pull-up :
buttonSetup();

  //Setup the LED :
  // pinMode(LED_PIN,OUTPUT);

}
void buttonSetup(){
  //set up all the buttons
   pinMode(BUTTON_PIN_1,INPUT_PULLUP);
   pinMode(BUTTON_PIN_2,INPUT_PULLUP);
   pinMode(BUTTON_PIN_3,INPUT_PULLUP);
   pinMode(BUTTON_PIN_4,INPUT_PULLUP);
   pinMode(BUTTON_PIN_5,INPUT_PULLUP);
   pinMode(BUTTON_PIN_6,INPUT_PULLUP);
   pinMode(BUTTON_PIN_7,INPUT_PULLUP);
   pinMode(BUTTON_PIN_8,INPUT_PULLUP);
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
  debouncer5.attach(BUTTON_PIN_5);
  debouncer5.interval(DEBOUNCE_INTERVAL); // interval in ms
  debouncer6.attach(BUTTON_PIN_6);
  debouncer6.interval(DEBOUNCE_INTERVAL); // interval in ms
  debouncer7.attach(BUTTON_PIN_7);
  debouncer7.interval(DEBOUNCE_INTERVAL); // interval in ms
  debouncer8.attach(BUTTON_PIN_8);
  debouncer8.interval(DEBOUNCE_INTERVAL); // interval in ms


}

void loop() {
updateButtons();

}
void updateButtons(){
  // Update the Bounce instances :
  debouncer1.update();
  debouncer2.update();
  debouncer3.update();
  debouncer4.update();
  // debouncer5.update();
  debouncer6.update();
  debouncer7.update();
  debouncer8.update();

  // Get the updated value :
  int buttonState1 = debouncer1.read();
  int buttonState2 = debouncer2.read();
  int buttonState3 = debouncer3.read();
  int buttonState4 = debouncer4.read();
  // int buttonState5 = debouncer5.read();
  int buttonStateRED = !bool(debouncer6.read());//Red button is NC so inverted logic
  int buttonStateLEFT = debouncer7.read();
  int buttonStateRIGHT = debouncer8.read();
  

Serial.println("ONE---\tTWO---\tTHREE\tFOUR--\tRed---2\tLeft--3\tRight-4");
Serial.print(buttonState1);
Serial.print("\t");
Serial.print(buttonState2);
Serial.print("\t");
Serial.print(buttonState3);
Serial.print("\t");
Serial.print(buttonState4);
Serial.print("\t");
// Serial.print(buttonState5);
// Serial.print("\t");
Serial.print(buttonStateRED);
Serial.print("\t");
Serial.print(buttonStateLEFT);
Serial.print("\t");
Serial.print(buttonStateRIGHT);
Serial.println(" ");
Serial.println(" ");
delay(50);

}


