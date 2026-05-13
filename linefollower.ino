// Pins
#define sensorRight 2
#define sensorLeft 3
 

 // Inputs Definition
#define IN4 5
#define IN3 6 
#define IN2 7
#define IN1 8

// speed
#define ENA 9 
#define ENB 10







 // Medium Speed
int speedMotor = 130; 

void setup() {
  pinMode(sensorRight, INPUT);
  pinMode(sensorLeft, INPUT);


  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);


  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  stopMotors();
}

void loop() {
  int right = digitalRead(sensorRight);
  int left = digitalRead(sensorLeft);


  if (right == 0 && left == 0) {
    moveForward();
  } 

  else if (right == 0 && left == 1) {
    turnLeft();
  } 
  else if (right == 1 && left == 0) {
    turnRight();
  } 

  else {
    stopMotors();
    delay(100);

    turnRightInPlace();
    delay(300);

    moveForward();

  }
}


// Movement Functions

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speedMotor);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speedMotor);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speedMotor - 30);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speedMotor);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speedMotor);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, speedMotor - 30);
}

void turnRightInPlace() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speedMotor);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speedMotor);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}
