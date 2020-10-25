
void arm_tap_add(int add) {
  if(stopflag == 1){
    Serial.println("stop button is pushed");
    return;
  }
  
  int tap_w = 10 + add;
  arm_a -= tap_w;
  if (arm_a < 0) {
    arm_a = 0;
  }
  arm.write(arm_a, 50, true);
//  Serial.print("Arm angle:");
//  Serial.println(arm_a);
  delay(320);
  arm_a += tap_w;
  arm.write(arm_a );
  delay(d - 100);
  
  if(stopflag == 1){
    Serial.println("stop button is pushed");
    return;
  }
}

void arm_tap_5_long() {
  int tap_w = 10 + 9;
  arm_a -= tap_w;
  if (arm_a < 0) {
    arm_a = 0;
  }
  arm.write(arm_a, 40, true);
  delay(340);
  arm_a += tap_w;
  arm.write(arm_a, 100, true );
  delay(d);
}

void arm_tap_5() {
  int tap_w = 10 + 3;
  arm_a -= tap_w;
  if (arm_a < 0) {
    arm_a = 0;
  }
  arm.write(arm_a);
  delay(170);
  arm_a += tap_w;
  arm.write(arm_a );
  delay(d);
}

void arm_tap() {
  int tap_w = 10;
  arm_a -= tap_w;
  if (arm_a < 0) {
    arm_a = 0;
  }
  arm.write(arm_a);
  delay(150);
  arm_a += tap_w;
  arm.write(arm_a );
  delay(d);
}

void arm_down() {
  arm_a = arm_a - w;
  if (arm_a < 0) {
    arm_a = 0;
  }
  arm.write(arm_a);
  delay(d);
}

void arm_up() {
  arm_a = arm_a + w;
  if (arm_a > 180) {
    arm_a = 180;
  }
  arm.write(arm_a);
  delay(d);
}

void s_left() {
  r = r + w;
  if (r > 180) {
    r = 180;
  }
  set_angle(r);
}

void s_right() {
  r = r - w;
  if (r < 0) {
    r = 0;
  }
  set_angle(r);
}

void s_right_5() {
  r = r - w / 2;
  if (r < 0) {
    r = 0;
  }
  set_angle(r);
}

void s_wait() {
  set_angle(r);
}

void set_angle(int r) {
  if(stopflag == 1){
    Serial.println("stop button is pushed");
    return;
  }
  
  Serial.print("     Angle: ");
  Serial.println(r);
  s.write(r, 50, true);
  delay(d - 100);

  if(stopflag == 1){
    Serial.println("stop button is pushed");
    return;
  }
}

void stick_move() {
  int x = map( analogRead(1), 206, 799, -122, 122) - 4;// X 206 - 798  1023
  int y = map( analogRead(2), 203, 797, -122, 122) - 2;// Y 203 - 797
  
//  Serial.print("x:");
//  Serial.print(x, DEC);
//  Serial.print(" y:");
//  Serial.print(y, DEC);
//  Serial.println();

  int ca = s.read();
  if(x > 200){
    arm_tap_add(basic_tap_depth+2 );
  }else if( x > 20 || x < -20){
    if(x > 0){
        ca -= 1;
        if(ca < 1) ca = 0 ;
    }else if(x < 0){
        ca += 1;
        if (ca > 180) ca = 180 ;
    }
    s.write(ca, 10, true);

    delay(5);
  }
  int ca_arm = arm.read();
  if( y > 50 || y < -50){
    if(y < 0){
        ca_arm -= 1;
        if(ca_arm < 0) ca_arm = 0 ;
    }else if(y > 0){
        ca_arm += 1;
        if (ca_arm > 90) ca_arm = 90 ;
    }
    arm.write(ca_arm, 10, true);

    delay(5);
  }

  Serial.print("Arm-angle: ");
  Serial.print(ca_arm);
  Serial.print("   Table-angle: ");
  Serial.println(ca);
  

  
}
