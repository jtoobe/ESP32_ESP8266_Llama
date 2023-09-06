/*
 * Para usar con el Sensor de llama KY-026
 */


// para ESP8266
int Buzzer = 4;           //    (D2)
int Llama_analog = 0;    //     (A0)
int Llama_digital = 5;   //     (D1)

// Para ESP32
//int Buzzer = 32;        
//int Llama_analog = 4;    
//int Llama_digital = 2;    

void setup() {
  Serial.begin(115200);
  pinMode(Buzzer, OUTPUT);      
  pinMode(Llama_digital, INPUT);
}

void loop() {
  int LlamaSensorAnalog = analogRead(Llama_analog);
  int LlamaSensorDigital = digitalRead(Llama_digital);

  Serial.print("Llama Sensor: ");
  Serial.print(LlamaSensorAnalog);
  Serial.print("\t");
  Serial.print("Llama Digital: ");
  Serial.print(LlamaSensorDigital);
  Serial.print("\t");
  Serial.print("\t");
  
  if (LlamaSensorAnalog < 1000) {
    Serial.println("Llama !!!");
    digitalWrite (Buzzer, HIGH) ; //Suena Buzzer
    delay(1000);
    digitalWrite (Buzzer, LOW) ;  //Silencio
  }
  else {
    Serial.println("No hay llama");
  }
  delay(100);
}
