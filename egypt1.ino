

#define LED 13
#define BUTTON 7
#define SERVO_TURN 9
#define SERVO_ARM 12 
#define B6 6
#define B8 8
//#define BUTTON2 4

//#include <Servo.h>
#include <VarSpeedServo.h>

VarSpeedServo s;//ターンテーブル
VarSpeedServo arm;//アーム

int start_vertical_angle = 90;
int start_turntable_angle = 45;
int basic_tap_depth = 9;
//int c = 90;
int w = 10;//basic rotate angle for turn table
int d = 900;//basic delay
int r = start_vertical_angle;
int arm_a = 33;

int turn = 15;

int val =  LOW;
int val2 = LOW;
int INs[14] = {LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW};

volatile int stopflag = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("start");
  attachInterrupt(0,stop_button_push,FALLING);
  
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(B6, INPUT);
  pinMode(B8, INPUT);
  //pinMode(BUTTON2, INPUT);
  digitalWrite(LED, LOW);

  s.attach(SERVO_TURN);
  arm.attach(SERVO_ARM);
  no_tap_wait();
  //  set_angle(start_turntable_angle);//start_vertical_angle);
  arm.write(arm_a);
  //  delay(200);

}

void loop() {
  //delay(200);

  INs[6] = digitalRead(B6);
  INs[8] = digitalRead(B8);    
  
  val = digitalRead(BUTTON);
  if(val == HIGH ){
    led13_tika(3);

    //set_angle(start_vertical_angle);
    for (int i = 0; i <= turn; i++) {
      proto2_sequence(i);
      
      if(stopflag == 1){
        Serial.println("stop button is pushed");
        stopflag = 0;
        set_angle(45);
        //goto labelfirst;
        break;
      }
    }
    
    return;
  }else if(INs[6] == HIGH){
    Serial.println("box open");
    stopflag = 0;
    tap_boxopen();
    delay(100);
  }else if(INs[8] == HIGH){
    Serial.println("battle continue");
    stopflag = 0;
    tap_battle_end_continue();
    delay(100);
  }else{
    char input = Serial.read();
    if (input != -1) {
      Serial.println("manual input");
      manual_input();
    }
  }

  stick_move();
  
}

void stop_button_push(){
  Serial.println("stop_button_push");
  stopflag = 1;

}

void led13_tika(int n){
//  Serial.println(n);
  for(int i=0;i<n;i++){
    digitalWrite(LED, HIGH);
    delay(50);
    digitalWrite(LED, LOW);
    delay(50);
    Serial.print(i);
  }
  Serial.println("Start program");

}
