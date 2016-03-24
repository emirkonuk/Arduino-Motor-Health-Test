#define MOTOR1_EN_PIN 4
#define MOTOR1_STEP_PIN 3
#define MOTOR1_DIR_PIN 2
#define MOTOR2_EN_PIN 5
#define MOTOR2_STEP_PIN 6
#define MOTOR2_DIR_PIN 7
#define MOTOR3_EN_PIN 8
#define MOTOR3_STEP_PIN 9
#define MOTOR3_DIR_PIN 10
int temp;
void setup() { 
  pinMode(MOTOR1_DIR_PIN, OUTPUT);       // Motor Dir
  pinMode(MOTOR1_STEP_PIN, OUTPUT);     // Motor Step
  pinMode(MOTOR1_EN_PIN, OUTPUT);     // Motor On - Off
  digitalWrite(MOTOR1_EN_PIN, HIGH);     // Motor Off = LOW
  pinMode(MOTOR2_DIR_PIN, OUTPUT);       // Motor Dir
  pinMode(MOTOR2_STEP_PIN, OUTPUT);     // Motor Step
  pinMode(MOTOR2_EN_PIN, OUTPUT);     // Motor On - Off
  digitalWrite(MOTOR2_EN_PIN, HIGH);     // Motor Off = LOW
  pinMode(MOTOR3_DIR_PIN, OUTPUT);       // Motor Dir
  pinMode(MOTOR3_STEP_PIN, OUTPUT);     // Motor Step
  pinMode(MOTOR3_EN_PIN, OUTPUT);     // Motor On - Off
  digitalWrite(MOTOR3_EN_PIN, HIGH);     // Motor Off = LOW
  Serial.begin(9600);
}

void loop() {
   if (Serial.available()) { 
      temp = Serial.read();
 
      if (temp=='1')
      {
        digitalWrite(MOTOR1_EN_PIN, LOW);   // Motor On
        rotate1(1, 0.2);  //forward
        digitalWrite(MOTOR1_EN_PIN, HIGH);   // Motor Off
        //Serial.println("forward");
      }
      if (temp=='2'){
        digitalWrite(MOTOR1_EN_PIN, LOW);   // Motor On
        rotate1(-1, 0.2);   //reverse
        digitalWrite(MOTOR1_EN_PIN, HIGH);   // Motor Off
        //Serial.println("reverse");
      }
      if (temp=='3')
      {
        digitalWrite(MOTOR2_EN_PIN, LOW);   // Motor On
        rotate2(1, 0.2);  //forward
        digitalWrite(MOTOR2_EN_PIN, HIGH);   // Motor Off
        //Serial.println("forward");
      }
      if (temp=='4'){
        digitalWrite(MOTOR2_EN_PIN, LOW);   // Motor On
        rotate2(-1, 0.2);   //reverse
        digitalWrite(MOTOR2_EN_PIN, HIGH);   // Motor Off
        //Serial.println("reverse");
      }
      if (temp=='5')
      {
        digitalWrite(MOTOR3_EN_PIN, LOW);   // Motor On
        rotate3(1, 0.2);  //forward
        digitalWrite(MOTOR3_EN_PIN, HIGH);   // Motor Off
        //Serial.println("forward");
      }
      if (temp=='6'){
        digitalWrite(MOTOR3_EN_PIN, LOW);   // Motor On
        rotate3(-1, 0.2);   //reverse
        digitalWrite(MOTOR3_EN_PIN, HIGH);   // Motor Off
        //Serial.println("reverse");
      }
     delay(1000);   
  }
}


void rotate1(int steps, float speed){

  int dir = (steps > 0)? HIGH:LOW;
  steps = abs(steps);
  

  digitalWrite(MOTOR1_DIR_PIN,dir); 
  
  float usDelay = (1/speed) * 300;

  for(int i=0; i < steps; i++){
    digitalWrite(MOTOR1_STEP_PIN, HIGH);
    delayMicroseconds(usDelay); 

    digitalWrite(MOTOR1_STEP_PIN, LOW);
    delayMicroseconds(usDelay);
  }
  
} 
void rotate2(int steps, float speed){

  int dir = (steps > 0)? HIGH:LOW;
  steps = abs(steps);
  

  digitalWrite(MOTOR2_DIR_PIN,dir); 
  
  float usDelay = (1/speed) * 300;

  for(int i=0; i < steps; i++){
    digitalWrite(MOTOR2_STEP_PIN, HIGH);
    delayMicroseconds(usDelay); 

    digitalWrite(MOTOR2_STEP_PIN, LOW);
    delayMicroseconds(usDelay);
  }
  
}
void rotate3(int steps, float speed){

  int dir = (steps > 0)? HIGH:LOW;
  steps = abs(steps);
  

  digitalWrite(MOTOR3_DIR_PIN,dir); 
  
  float usDelay = (1/speed) * 300;

  for(int i=0; i < steps; i++){
    digitalWrite(MOTOR3_STEP_PIN, HIGH);
    delayMicroseconds(usDelay); 

    digitalWrite(MOTOR3_STEP_PIN, LOW);
    delayMicroseconds(usDelay);
  }
  
}