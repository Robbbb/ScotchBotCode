#include <ax12.h>
#include <BioloidController.h>
// #include <Bounce2.h> //debounce for button
#include "poses.h"

BioloidController bioloid = BioloidController(1000000);

 
#define ASLEEP_ON_BOOT  0
#define FILL_CUP  1
#define ASLEEP_FULL  2
#define SMELL_AND_DUMP  3
#define ASLEEP_DUMPED  4
#define DANCING_A  5
#define ASLEEP_DANCED_A  6
#define DANCING_B  7
#define ASLEEP_DANCED_B 8


//pin numbers for buttons
#define FILL_BUTTON_1    2
#define POUR_BUTTON_2    3
#define DANCE_BUTTON_3   4
#define BOX_ZZZ_BUTTON_4 5

#define BUZZER_PIN 7

#define BUTTON_GND 9

#define DEBOUNCE_INTERVAL 20 //ms to wait before listening to button press

//Our Global finite state machine control variable
uint8_t fsm_state = ASLEEP_ON_BOOT;
uint8_t next_fsm_state = ASLEEP_ON_BOOT;


//sure do wish the debounce library worked....
int fillButtonState ;
int fillButtonStatePrev = HIGH ;
long fillButtonLastDebounceTime = 0;

int pourButtonState;
int pourButtonStatePrev = HIGH ;
long pourButtonLastDebounceTime = 0;

int danceButtonState;
int danceButtonStatePrev = HIGH ;
long danceButtonLastDebounceTime = 0;

int zzzButtonState;
int zzzButtonStatePrev = HIGH ;
long zzzButtonLastDebounceTime = 0;


void setup(){
  buttonSetup();

  delay(100);  // recommended pause
  bioloid.loadPose(CENTER);
  bioloid.readPose();
  bioloid.interpolateSetup(5000);
  while(bioloid.interpolating > 0){
    bioloid.interpolateStep();
    delay(3);
  }

  beep();
  delay(1000);
  beep();
  delay(1000);


}

void loop(){
  while(bioloid.playing){
    updateButtons();
    bioloid.play();
  }
  updateButtons();

  switch (fsm_state)
  {
  case ASLEEP_ON_BOOT:
    break;
  case FILL_CUP:
    if(!bioloid.playing){
      bioloid.playSeq(toFill);
      fsm_state= ASLEEP_FULL;
    }
    break;
  case ASLEEP_FULL:
  
    break;
  case SMELL_AND_DUMP:
    if(!bioloid.playing){
      bioloid.playSeq(toPour);
    }
    fsm_state= ASLEEP_DUMPED;
    break;
  case ASLEEP_DUMPED:
    break;
  case DANCING_A:
    if(!bioloid.playing){
      bioloid.playSeq(dance_a);
      fsm_state= ASLEEP_DANCED_A;
    }
    break;
  case ASLEEP_DANCED_A:
    break;
  case DANCING_B:
    if(!bioloid.playing){
      bioloid.playSeq(dance_b);
      fsm_state= ASLEEP_DANCED_B
    ;
    }
    break;
  case ASLEEP_DANCED_B
:
    break;
  default:
    break;

  }



}


// void zzzzz() {
//   bioloid.loadPose(CENTER);
//   bioloid.readPose();
//   bioloid.interpolateSetup(5000);
//   while(bioloid.interpolating > 0){
//     bioloid.interpolateStep();
//     delay(3);
//   }
// }


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

int fillButtonReading = digitalRead(FILL_BUTTON_1);
int pourButtonReading = digitalRead(POUR_BUTTON_2);
int danceButtonReading = digitalRead(DANCE_BUTTON_3);
int zzzButtonReading = digitalRead(BOX_ZZZ_BUTTON_4);


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
      fsm_state = DANCING_A;

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
      fsm_state = DANCING_B;
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
  delay(400);
}



