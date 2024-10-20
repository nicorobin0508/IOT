
const int LEDR = 9; 
const int LEDG = 10; 
const int LEDB = 11; 

void setup() {
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}

void loop() {
  int r = random(0, 256); 
  int g = random(0, 256); 
  int b = random(0, 256); 

  analogWrite(LEDR, r);
  analogWrite(LEDG, g);
  analogWrite(LEDB, b);
  
  delay(1000);
}
