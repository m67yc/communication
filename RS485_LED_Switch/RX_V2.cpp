#define ledPin 13

bool read = 0;
String message = "";
char m[100];

void setup() {

  Serial.begin(9600);
  Serial3.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  while (Serial3.available() > 0) {
    char receivedVal = Serial3.read();

    if (read == 1) {

      if (receivedVal == '>') {

        for(int i = 0;i <= time;i++){
          Serial3.write(m[i]);
          Serial.print(m[i]);
        }
        
        Serial.print("    ");
        Serial.print(message);

        Serial.println();
        
        message = "";
        read = 0;
        break;
      }

      message += receivedVal;
      m[time] = receivedVal;
      time++;
    }

    if (receivedVal == '<') {
      read = 1;
    }
  }
}