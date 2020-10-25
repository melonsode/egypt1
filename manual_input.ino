
void manual_input(){

  while(char c = Serial.read()){
    switch (c) {
      case '1':
        tap_card_r1();
        break;
      case '2':
        tap_card_r2();
        break;
      case '3':
        tap_card_r3();
        break;
      case '4':
        tap_card_r4();
        break;
      case 'a':
        tap_attack();
        break;
      case 'q':
        break;
      case 'b':
        tap_boxopen();
        break;
      case 'c':
        tap_battle_end_continue();
        break;
    }
    if(c == 'q'){
      Serial.println("END manual input");
      return;
    }
  }

}


void tap_boxopen(){
  r = 142;
  set_angle(r);
  
  int box_max = 30 * 2 + 5;
  for(int i=0;i< box_max ;i++){
    
    //sequence_batch('z');//z:arm_tap_5_long
    int add = 9;
    int tap_w = 10 + add;
    arm_a -= tap_w;
    if (arm_a < 0) {
      arm_a = 0;
    }
    arm.write(arm_a, 40, true);
    delay(100);
    arm_a += tap_w;
    arm.write(arm_a );
    delay(800);

    if(stopflag == 1){
      Serial.println("stop button is pushed");
      s.write(start_turntable_angle, 30, true);
      break;
    }
  }
  s.write(start_turntable_angle, 30, true);
  
}

void tap_battle_end_continue(){

  sequence_batch('q');
  
  tap_card_r2();
  if(stopflag == 1) return;
  tap_card_r2();
  if(stopflag == 1) return;
  tap_attack();
  no_tap_wait();
//  r = 85;
//  set_angle(r);
  //sequence_batch('z');//z:arm_tap_5_long
//  arm_tap_add(11 );

  
  unsigned long now;
  now = millis();
  while (millis() - now < 10 * 1000) {
    if(stopflag == 1){
      Serial.println("stop button is pushed");
      s.write(start_turntable_angle, 10, true);
      return;
    }
  }

}
