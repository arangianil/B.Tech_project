#include <TinyGPS++.h>
TinyGPSPlus gps;
String LAT = "13.630108";
String LON = "79.408439";
#define motor_pin1 4
#define motor_pin2 5
#define motor_pin3 6
#define motor_pin4 7
#define Switch1 9
#define Switch2 10
#define Switch3 11
#define Switch4 12
#define buzzer 2


void setup()
{
  Serial.begin(9600);
  pinMode(Switch1, INPUT_PULLUP);
  pinMode(Switch2, INPUT_PULLUP);
  pinMode(Switch3, INPUT_PULLUP);
  pinMode(Switch4, INPUT_PULLUP);
  pinMode(motor_pin1, OUTPUT);
  pinMode(motor_pin2, OUTPUT);
  pinMode(motor_pin3, OUTPUT);
  pinMode(motor_pin4, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(motor_pin1, LOW);
  digitalWrite(motor_pin2, LOW);
  digitalWrite(motor_pin3, LOW);
  digitalWrite(motor_pin4, LOW);
  digitalWrite(buzzer, LOW);

}
void loop()
{
    smartDelay(1000);
    String LAT = String(gps.location.lat(), 6);
    String LON = String(gps.location.lng(), 6);
    Serial.print("LATITUDE = ");
    Serial.println(LAT);
    delay(1000);
    Serial.print("LONGITUDE = ");
    Serial.println(LON);
    delay(1000);
    if (millis() > 5000 && gps.charsProcessed() < 10)
      Serial.println(F("No GPS data received: check wiring"));
      
    int Switchstate1 = digitalRead(Switch1);
    Serial.print("Switchstate1:");
    Serial.println(Switchstate1);
    
    int Switchstate2 = digitalRead(Switch2);
    Serial.print("Switchstate2:");
    Serial.println(Switchstate2);

    int Switchstate3 = digitalRead(Switch3);
    Serial.print("Switchstate3:");
    Serial.println(Switchstate3);

    int Switchstate4 = digitalRead(Switch4);
    Serial.print("Switchstate4:");
    Serial.println(Switchstate4);

   if(Switchstate1 == 0)
    {
    Serial.println("forward");
    digitalWrite(motor_pin1, HIGH);
    digitalWrite(motor_pin2, LOW);
    digitalWrite(motor_pin3, HIGH);
    digitalWrite(motor_pin4, LOW);
    
      if(LAT >"13.630104" || LON >"79.408432")
      {
        Serial.println("stop");
        digitalWrite(buzzer, HIGH);
        Serial.println("BACK");
        digitalWrite(buzzer, HIGH);
        digitalWrite(motor_pin1, HIGH);
        digitalWrite(motor_pin2, LOW);
        digitalWrite(motor_pin3, LOW);
        digitalWrite(motor_pin4, HIGH);
        delay(3000);
        digitalWrite(motor_pin1, HIGH);
        digitalWrite(motor_pin2, LOW);
        digitalWrite(motor_pin3, HIGH);
        digitalWrite(motor_pin4, LOW);
        delay(5000);
        digitalWrite(motor_pin1, LOW);
        digitalWrite(motor_pin2, LOW);
        digitalWrite(motor_pin3, LOW);
        digitalWrite(motor_pin4, LOW);
        send_msg();
        delay(8000);
      }
    }
    else if (Switchstate2 == 0)
    {
      Serial.println("backward");
      digitalWrite(motor_pin1, LOW);
      digitalWrite(motor_pin2, HIGH);
      digitalWrite(motor_pin3, LOW);
      digitalWrite(motor_pin4, HIGH);

      if(LAT >"13.630104" || LON >"79.408432")
      {
        Serial.println("stop");
        digitalWrite(buzzer, HIGH);
        Serial.println("BACK");
        digitalWrite(buzzer, HIGH);
        digitalWrite(motor_pin1, HIGH);
        digitalWrite(motor_pin2, LOW);
        digitalWrite(motor_pin3, LOW);
        digitalWrite(motor_pin4, HIGH);
        delay(3000);
        digitalWrite(motor_pin1, HIGH);
        digitalWrite(motor_pin2, LOW);
        digitalWrite(motor_pin3, HIGH);
        digitalWrite(motor_pin4, LOW);
        delay(5000);
        digitalWrite(motor_pin1, LOW);
        digitalWrite(motor_pin2, LOW);
        digitalWrite(motor_pin3, LOW);
        digitalWrite(motor_pin4, LOW);
        send_msg();
        delay(8000);

      }

    }
    
    else if (Switchstate3 == 0)
    {
      Serial.println("right");
      digitalWrite(motor_pin1, HIGH);
      digitalWrite(motor_pin2, LOW);
      digitalWrite(motor_pin3, LOW);
      digitalWrite(motor_pin4, LOW);
      delay(1000);
      digitalWrite(motor_pin1, HIGH);
      digitalWrite(motor_pin2, LOW);
      digitalWrite(motor_pin3, HIGH);
      digitalWrite(motor_pin4, LOW);
      
      
      if(LAT >"13.630104" || LON >"79.408432")
      {
        Serial.println("stop");
        digitalWrite(buzzer, HIGH);
        Serial.println("BACK");
        digitalWrite(buzzer, HIGH);
        digitalWrite(motor_pin1, HIGH);
        digitalWrite(motor_pin2, LOW);
        digitalWrite(motor_pin3, LOW);
        digitalWrite(motor_pin4, HIGH);
        delay(3000);
        digitalWrite(motor_pin1, HIGH);
        digitalWrite(motor_pin2, LOW);
        digitalWrite(motor_pin3, HIGH);
        digitalWrite(motor_pin4, LOW);
        delay(5000);
        digitalWrite(motor_pin1, LOW);
        digitalWrite(motor_pin2, LOW);
        digitalWrite(motor_pin3, LOW);
        digitalWrite(motor_pin4, LOW);
        send_msg();
        delay(8000);
      }
    }

     else if (Switchstate4 == 0)
    {
      Serial.println("left");
      digitalWrite(motor_pin1, LOW);
      digitalWrite(motor_pin2, LOW);
      digitalWrite(motor_pin3, HIGH);
      digitalWrite(motor_pin4, LOW);
      delay(1000);
      digitalWrite(motor_pin1, HIGH);
      digitalWrite(motor_pin2, LOW);
      digitalWrite(motor_pin3, HIGH);
      digitalWrite(motor_pin4, LOW);
      
      
      if(LAT >"13.630104" || LON >"79.408432")
      {
        Serial.println("BACK");
        digitalWrite(buzzer, HIGH);
        digitalWrite(motor_pin1, HIGH);
        digitalWrite(motor_pin2, LOW);
        digitalWrite(motor_pin3, LOW);
        digitalWrite(motor_pin4, HIGH);
        delay(3000);
        digitalWrite(motor_pin1, HIGH);
        digitalWrite(motor_pin2, LOW);
        digitalWrite(motor_pin3, HIGH);
        digitalWrite(motor_pin4, LOW);
        delay(5000);
        digitalWrite(motor_pin1, LOW);
        digitalWrite(motor_pin2, LOW);
        digitalWrite(motor_pin3, LOW);
        digitalWrite(motor_pin4, LOW);
        send_msg();
        delay(8000);

      }
    }
    else
    {
      digitalWrite(buzzer, LOW);
      digitalWrite(motor_pin1, LOW);
      digitalWrite(motor_pin2, LOW);
      digitalWrite(motor_pin3, LOW);
      digitalWrite(motor_pin4, LOW);
    }
}

void send_msg() 
{
  Serial.println("MESSAGE SEND");      
  Serial.println("AT+CMGF=1");
  delay(1000);
  Serial.println("AT+CMGS=\"+917286819827\"\r");
  delay(1000);
  Serial.println("BORDER CROSSED ALERT"); 
  delay(1000);
  Serial.print("https://maps.google.com/maps?q=");
  Serial.print(gps.location.lat(), 6);
  Serial.print(",");
  Serial.print(gps.location.lng(), 6);
  delay(1000);
  Serial.println((char)26);
  delay(1000);
}

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do
  {
    while (Serial.available())
      gps.encode(Serial.read());
  } while (millis() - start < ms);
}
