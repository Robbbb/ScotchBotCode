byte d=0xFF;

void setup() {


Serial1.begin(9600);

delay(100);

Serial1.println("!!!");

Serial1.println("?");

Serial1.write(d);
delay(500);

}

void loop(){

Serial1.write(" tickdisp 50 255\n\r"); // tickdisp <ticks> <speed>

delay(500);

}
