
#define SLEEP_ON_BOOT  0
#define FILL_CUP  1
#define SLEEP_FULL  2
#define SMELL_AND_DUMP  3
#define SLEEP_DUMPED  4
#define DANCE_EMPTY  5
#define SLEEP_DANCED  6
#define SLEEP_FOR_BOX  7


//pin numbers for buttons
#define FILL_BUTTON_1    2
#define POUR_BUTTON_2    3
#define DANCE_BUTTON_3   4
#define BOX_ZZZ_BUTTON_4 5

#define BUZZER_PIN 7

#define BUTTON_GND 9

#define DEBOUNCE_INTERVAL 15 //ms to wait before listening to button press

//Our Global finite state machine control variable
uint8_t fsm_state = SLEEP_ON_BOOT;

//Button objects
// Bounce fillButton = Bounce();
// Bounce pourButton = Bounce();
// Bounce danceButton = Bounce();
// Bounce zzzButton = Bounce();


int fillButtonState = HIGH ;
int fillButtonStatePrev = HIGH ;
int fillButtonReading = HIGH ;
long fillButtonLastDebounceTime = 0;

int pourButtonState = HIGH ;
int pourButtonStatePrev = HIGH ;
int pourButtonReading = HIGH ;
long pourButtonLastDebounceTime = 0;

int danceButtonState = HIGH ;
int danceButtonStatePrev = HIGH ;
int danceButtonReading = HIGH ;
long danceButtonLastDebounceTime = 0;

int zzzButtonState = HIGH ;
int zzzButtonStatePrev = HIGH ;
int zzzButtonReading = HIGH ;
long zzzButtonLastDebounceTime = 0;


void setup(){
  Serial.begin(115200);
  buttonSetup();


}

void loop(){
  //timer state machine
  updateButtons();
}



void updateButtons() {

  // fillButton.update();
  // pourButton.update();
  // danceButton.update();
  // zzzButton.update();

  fillButtonReading = digitalRead(FILL_BUTTON_1);
  pourButtonReading = digitalRead(POUR_BUTTON_2);
  danceButtonReading = digitalRead(DANCE_BUTTON_3);
  zzzButtonReading = digitalRead(BOX_ZZZ_BUTTON_4);

  if (fillButtonReading != fillButtonStatePrev) {// reset the debouncing timer
    fillButtonLastDebounceTime = millis();
  } 
  if ((millis() - fillButtonLastDebounceTime) > DEBOUNCE_INTERVAL) {
    fillButtonState = fillButtonReading;
    if (fillButtonState == LOW){
      ////FILLL!!
      Serial.println("FILL");
      fsm_state = FILL_CUP;
      beep();
    }

  }
  fillButtonStatePrev = fillButtonReading;

  if (pourButtonReading != pourButtonStatePrev) {// reset the debouncing timer
    pourButtonLastDebounceTime = millis();
  } 
  if ((millis() - pourButtonLastDebounceTime) > DEBOUNCE_INTERVAL) {
    ////pourL!!
    pourButtonState =pourButtonReading; 
    if (pourButtonState == LOW)
    {
      Serial.println("POUR");
      fsm_state = SMELL_AND_DUMP;
      beep();
      beep(); 
    }
  }
  pourButtonStatePrev = pourButtonReading;


  if (danceButtonReading != danceButtonStatePrev) {// reset the debouncing timer
    danceButtonLastDebounceTime = millis();
  } 
  if ((millis() - danceButtonLastDebounceTime) > DEBOUNCE_INTERVAL) {
    danceButtonState =danceButtonReading;
    if (danceButtonState == LOW)    {

        ////DNACE!!
        Serial.println("DANCE");

        fsm_state = DANCE_EMPTY;
    beep();
    beep();
    beep();
  }
  }
  danceButtonStatePrev = danceButtonReading;

  if (zzzButtonReading != zzzButtonStatePrev) {// reset the debouncing timer
    zzzButtonLastDebounceTime = millis();
  } 
  if ((millis() - zzzButtonLastDebounceTime) > DEBOUNCE_INTERVAL) {
    zzzButtonState =zzzButtonReading;
    if (zzzButtonState == LOW)
    {
    ////zzzz!!
        Serial.println("ZZZZ");
        fsm_state = SLEEP_FOR_BOX;
    beep();
    beep();
    beep();
    beep();
  }
  }
  zzzButtonStatePrev = zzzButtonReading;


}

void buttonSetup() {

  // Setup the buttons with an internal pull-up :
  // pinMode(FILL_BUTTON_1, INPUT_PULLUP);
  // pinMode(POUR_BUTTON_2, INPUT_PULLUP);
  // pinMode(DANCE_BUTTON_3, INPUT_PULLUP);
  // pinMode(BOX_ZZZ_BUTTON_4, INPUT_PULLUP);

  pinMode(FILL_BUTTON_1, INPUT);
  digitalWrite( FILL_BUTTON_1 ,HIGH);
  pinMode(POUR_BUTTON_2, INPUT);
  digitalWrite( POUR_BUTTON_2 ,HIGH);
  pinMode(DANCE_BUTTON_3, INPUT);
  digitalWrite(  DANCE_BUTTON_3,HIGH);
  pinMode(BOX_ZZZ_BUTTON_4, INPUT);
  digitalWrite( BOX_ZZZ_BUTTON_4 ,HIGH);


  // After setting up the button, setup the Bounce instance :
  // fillButton.attach(FILL_BUTTON_1);
  // fillButton.interval(DEBOUNCE_INTERVAL); // interval in ms
  // pourButton.attach(POUR_BUTTON_2);
  // pourButton.interval(DEBOUNCE_INTERVAL); // interval in ms
  // danceButton.attach(DANCE_BUTTON_3);
  // danceButton.interval(DEBOUNCE_INTERVAL); // interval in ms
  // zzzButton.attach(BOX_ZZZ_BUTTON_4);
  // zzzButton.interval(DEBOUNCE_INTERVAL); // interval in ms

}

void beep() {
  noTone(BUZZER_PIN);
  // play a note on pin 6 for 200 ms:
  tone(BUZZER_PIN, 440, 200);
  delay(400);
  noTone(BUZZER_PIN);
}


