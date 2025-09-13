int led = 13;
int light = 0;
int val = 0;
void setup(){
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}
void loop () {
  val = analogRead(light);
  Serial.print(val);
  if (val<700) digitalWrite(led,LOW);
  else digitalWrite(led, HIGH);
  delay(200);
}
