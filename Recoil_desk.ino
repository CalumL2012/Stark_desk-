int DeskUp = 7;
int DeskDown = 6;
#define LIGHTSENSORPIN A6
String Test = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(DeskUp, OUTPUT);
  pinMode(DeskDown, OUTPUT);
  pinMode(LIGHTSENSORPIN, INPUT);
}

void loop() {
  int lightValue = analogRead(LIGHTSENSORPIN);
  //Read light level (0-1023)
  Serial.print("Raw Value:");
  Serial.println(lightValue);

  if (lightValue < 5) {
    digitalWrite(DeskUp, HIGH);
    delay(30);
    digitalWrite(DeskUp, LOW);
    delay(30);
    digitalWrite(DeskUp, HIGH);
    delay(30);
    digitalWrite(DeskUp, LOW);
    delay(30);
    digitalWrite(DeskDown, HIGH);
    delay(30);
    digitalWrite(DeskDown, LOW);
    delay(30);
    digitalWrite(DeskDown, HIGH);
    delay(30);
    digitalWrite(DeskDown, LOW);
    delay(30);
  }
  if (Serial.available() > 0) {
    Test = Serial.readStringUntil('\n');
    Test.trim();
  }

  if (Test == "Test") {
    digitalWrite(DeskUp, HIGH);
    delay(30);
    digitalWrite(DeskUp, LOW);
    delay(30);
    digitalWrite(DeskUp, HIGH);
    delay(30);
    digitalWrite(DeskUp, LOW);
    delay(30);
    digitalWrite(DeskDown, HIGH);
    delay(30);
    digitalWrite(DeskDown, LOW);
    delay(30);
    digitalWrite(DeskDown, HIGH);
    delay(30);
    digitalWrite(DeskDown, LOW);
    delay(30);
  } else if (Test == "end") {
    digitalWrite(DeskUp, LOW);
    digitalWrite(DeskDown, LOW);
  }
}