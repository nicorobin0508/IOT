int potPin=2;
int ledPin=13;
int val=10;
void setup()
{
pinMode(ledPin, OUTPUT);
}
void loop()
{
val = analogRead(potPin);
digitalWrite(ledPin, HIGH);
delay(val); // Wait for 1000 millisecond(s)
digitalWrite(ledPin, LOW);
delay(val); // Wait for 1000 millisecond(s)
}
