import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import gohai.glvideo.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class StableOSX_7 extends PApplet {

/**
 *  On Raspberry Pi: increase your GPU memory, to avoid
 *  OpenGL error 1285 at top endDraw(): out of memory
 */


GLMovie video1;
GLMovie video2;

float fps = 24.0f;
String clipNames[] = {"neutral", "cute", "dizzy", "hearts", "joyful", "sad", "smelling" };
float clipStarts[]= {0.1f, 7.f+( 3.f/fps), 10.f +(2/fps), 15.f+(3.f/fps), 18.f+(4.f/fps), 21.f+(8.f/fps), 26.f+(7.f/fps)};
float clipEnds[] =  {6.f+(20.f/fps), 9.f+(16.f/fps), 14.f+(22.f/fps), 18.0f, 21.f+(4.f/fps), 26.f+(2.f/fps), 29.f+(0.0f/fps)};
float safeTrim = 0.1f;
//String vidPath


//clipTriggers =[ -1,         -1,         0,            1,          2,           3,          4]

float loopPoint = 10.0f;

public void setup() {
  //size(800, 480, P2D);
  
  
  //video1 = new GLMovie(this, 
  //"/Users/robbgodshaw/Dropbox/Freelance/Freelance_2017/VICExDewars/AV Assets/Chaptered System/r2/SEQUENCE.mp4");
  ////GLVideo.MUTE);
    video1 = new GLMovie(this, 
  "/home/pi/Videos/SEQUENCE.mp4");
  //GLVideo.MUTE);
  video1.play();
}



public void keyPressed() {
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

public void goTo(int clipIndex) {
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
public void draw() {
  background(0);
  if (video1.available()) {
    video1.read();
    float currentPos = video1.time();
    //if(millis()%3==1)println(currentPos);
    if (currentPos >loopPoint) {
      loopPoint = 10.0f;
      goTo(0);
    }
  }

  image(video1, 0, 0, width, height);
}
  public void settings() {  fullScreen(P2D); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "StableOSX_7" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
