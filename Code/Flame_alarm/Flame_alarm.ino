const int speakerPin = 13; //buzzer to arduino pin 9
const int lowrange = 2000;   
const int highrange = 4000; 
const int triggeredLED = 2; // LED connected to Pin7
const int inputPin = A0; // LDR connected to A0

void setup()
{
    Serial.begin(9600);
    pinMode(triggeredLED, OUTPUT);
    pinMode(inputPin,INPUT);
}

void loop()
{
 int  reading = analogRead(inputPin);
 Serial.println(reading);
 if(reading < 40) 
 {  
   for(int j = 1; j <= 10 ; j++)
   {
       for (int i = lowrange; i <= highrange; i++)
     {
      tone (speakerPin, i, 250);
     }
   
    for (int i = highrange; i >= lowrange; i--)
     {
      tone (speakerPin, i, 250);
     }
    digitalWrite(triggeredLED, HIGH);
    delay(50);
    digitalWrite(triggeredLED, LOW);
    delay (50);
   }
 }
}
