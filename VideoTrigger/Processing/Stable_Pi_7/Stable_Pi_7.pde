/**
Works on Pi3 with  GPU memory overclock to 512 and plugged in keyboard. Yaaay!
SEQUENCE_1-sm2.mp4 22mb with lots of key frames 852x490 px
 */

import gohai.glvideo.*;
GLMovie video1;

float fps = 24.0;
String clipNames[] = {"neutral", "cute", "dizzy", "hearts", "joyful", "sad", "smelling" };
float clipStarts[]= {0.1, 7.+( 3./fps), 10. +(2/fps), 15.+(3./fps), 18.+(4./fps), 21.+(8./fps), 26.+(7./fps)};
float clipEnds[] =  {6.+(20./fps), 9.+(16./fps), 14.+(22./fps), 18.0, 21.+(4./fps), 26.+(2./fps), 29.+(0.0/fps)};
float safeTrim = 0.1;
//String vidPath


//clipTriggers =[ -1,         -1,         0,            1,          2,           3,          4]

float loopPoint = 10.0;

void setup() {
  size(800, 480, P2D);
  //fullScreen(P2D);

  //video1 = new GLMovie(this, 
  //"/Users/robbgodshaw/Dropbox/Freelance/Freelance_2017/VICExDewars/AV Assets/Chaptered System/r2/SEQUENCE.mp4");
  ////GLVideo.MUTE);
  video1 = new GLMovie(this, 
    "/home/pi/Videos/SEQUENCE_1-sm2.mp4");
  //GLVideo.MUTE);
  video1.play();
}



void keyPressed() {
  switch(keyCode) {
  case '0':
    goTo(0);
    break;
  case '1':
    goTo(0);
    break;
  case '2':
    goTo(1);
    break;
  case '3':
    goTo(2);
    break;
  case '4':
    goTo(3);
    break;
  case '5':
    goTo(4);
    break;
  case '6':
    goTo(5);
    break;
  case '7':
    goTo(6);
    break;
  }
}

void goTo(int clipIndex) {
  float startPoint = clipStarts[clipIndex];
  loopPoint = clipEnds[clipIndex]-safeTrim;
  video1.jump(startPoint );
  print("clip number: ");
  print(clipIndex);
  print(" going to: ");
  print(clipNames[clipIndex]);
  print(" at ");
  print(startPoint);
  println(" seconds");
}
void draw() {
  background(0);
  if (video1.available()) {
    video1.read();
    float currentPos = video1.time();
    //if(millis()%3==1)println(currentPos);
    if (currentPos >loopPoint) {
      loopPoint = 10.0;
      goTo(0);
    }
  }

  image(video1, 0, 0, width, height);
}