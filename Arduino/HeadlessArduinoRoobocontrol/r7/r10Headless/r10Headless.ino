#include <ax12.h>
#include <BioloidController.h>
// #include <Bounce2.h> //debounce for button
#include "poses.h"

BioloidController bioloid = BioloidController(1000000);


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

#define DEBOUNCE_INTERVAL 20 //ms to wait before listening to button press

//Our Global finite state machine control variable
uint8_t fsm_state = SLEEP_ON_BOOT;
uint8_t next_fsm_state = SLEEP_ON_BOOT;



//sure do wish the debounce library worked....
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
  buttonSetup();
  beep();
  beep();
  beep();
  beep();
  beep();
  delay(500);

  delay(100);  // recommended pause
  bioloid.loadPose(CENTER);
  bioloid.readPose();
  bioloid.interpolateSetup(5000);
  while(bioloid.interpolating > 0){
    bioloid.interpolateStep();
    delay(3);
  }
  // bioloid.playSeq(toFill);

  // bioloid.playSeq(r5_plu_smell);


}

void loop(){
  while(bioloid.playing){
    updateButtons();
    bioloid.play();
  }
  updateButtons();

  switch (fsm_state)
  {
    case SLEEP_ON_BOOT:
      // zzzzz();
      break;
    case FILL_CUP:
      if(!bioloid.playing){
      bioloid.playSeq(toFill);}
      break;
    case SLEEP_FULL:
      break;
    case SMELL_AND_DUMP:
        if(!bioloid.playing){
        bioloid.playSeq(toPour);}
      break;
    case SLEEP_DUMPED:
          // zzzzz();
      break;
    case DANCE_EMPTY:
        if(!bioloid.playing){
        bioloid.playSeq(Dance);}
      break;
    case SLEEP_DANCED:
      break;
    case SLEEP_FOR_BOX:
        if(!bioloid.playing){
// zzzzz();

        bioloid.playSeq(sleep);}
      break;
    default:
      break;

  }



}


void zzzzz() {
  bioloid.loadPose(CENTER);
  bioloid.readPose();
  bioloid.interpolateSetup(5000);
  while(bioloid.interpolating > 0){
    bioloid.interpolateStep();
    delay(3);
  }
}


void buttonSetup() {

  pinMode(FILL_BUTTON_1, INPUT);
  digitalWrite( FILL_BUTTON_1 ,HIGH);
  pinMode(POUR_BUTTON_2, INPUT);
  digitalWrite( POUR_BUTTON_2 ,HIGH);
  pinMode(DANCE_BUTTON_3, INPUT);
  digitalWrite(  DANCE_BUTTON_3,HIGH);
  pinMode(BOX_ZZZ_BUTTON_4, INPUT);
  digitalWrite( BOX_ZZZ_BUTTON_4 ,HIGH);

}

void updateButtons() {

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

beep();
      fsm_state = FILL_CUP;
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
      beep();
      beep();
      fsm_state = SMELL_AND_DUMP;

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
      beep();
      beep();
      beep();
        fsm_state = DANCE_EMPTY;

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


void beep() {
  noTone(BUZZER_PIN);
  // play a note on pin 6 for 200 ms:
  tone(BUZZER_PIN, 440, 200);
  delay(200);
}


