#include <ax12.h>
#include <BioloidController.h>
#include "poses.h"

BioloidController bioloid = BioloidController(1000000);

int flipFlop = 0;
void setup(){
  // stand up slowly
  Serial.begin(115200);
  delay(100);                    // recommended pause
  bioloid.loadPose(CENTER);
  bioloid.readPose();
  bioloid.interpolateSetup(5000);
  while(bioloid.interpolating > 0){
    bioloid.interpolateStep();
    delay(3);
  }
  delay(500);
  // start our walking
  bioloid.playSeq(r5_plu_smell);


}

void loop(){
  while(bioloid.playing){
//   bioloid.readPose();
//    int tempPos = bioloid.getCurPose(6);
//    if(tempPos <1){
//    Serial.println(tempPos);
//    }
    bioloid.play();
    ///TETTSTST
  }

    bioloid.playSeq(r5_plu_smell);

  
}


