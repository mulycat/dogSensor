/*
  Check nano for PIR compatibility
*/
int PIR7pin = 7;
int PIR11pin = 11;
int dogatD7 = 0;
int dogatD11 = 0;
int pinSpeaker = 2
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(12, HIGH);//power up PIR 11
  pinMode(10, LOW); //provide gnd for PIR 11
  pinMode(PIR11pin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIR7pin,INPUT);
  Serial.begin(9600);
}
// the loop function runs over and over again forever
void loop() {
  dogatD7 = digitalRead(PIR7pin);
  dogatD11 = digitalRead(PIR11pin);
  if (dogatD7 == 0) {
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  }
  else {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      
       for (int i=30; i <= 1955; i = i*1.05){
          tone(pinSpeaker, i , 100);
          delay(2);
        } 
  }
  delay(4000);                       // wait for a second
}

void playTone(long duration, int freq) {
    duration *= 1000;
    int period = (1.0 / freq) * 1000000;
    long elapsed_time = 0;
    while (elapsed_time < duration) {
        digitalWrite(pinSpeaker,HIGH);
        delayMicroseconds(period / 2);
        digitalWrite(pinSpeaker, LOW);
        delayMicroseconds(period / 2);
        elapsed_time += (period);
    }

// Serial.print("Off. onTime was ");
   // Serial.println(onTime);
   // Serial.println(dogatD8);
   // onTime = 0;
   //onTime = onTime + 1;

   /* if (onTime == 0){
        Serial.print("Dog at D7 ");
      }
      */
