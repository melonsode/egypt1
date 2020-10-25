void proto2_sequence(int turn ) {

  Serial.print("turn: ");
  Serial.println(turn);

  if(turn == 4 || turn == 8  || turn > 11){
    Serial.println("delay 5s");  
    delay(5000);  
  }

  stopflag = 0;
  
  //sequence_batch('q');
  
  tap_attack();
  if(stopflag == 1) return;
  tap_card_r1();
  if(stopflag == 1) return;
  tap_card_r2();
  if(stopflag == 1) return;
  tap_card_r3();
  if(stopflag == 1) return;
  tap_card_r4();
  if(stopflag == 1) return;
  tap_card_r3();
  if(stopflag == 1) return;
  no_tap_wait();
  

//  sequence_batch('q');
  
  unsigned long now;
  now = millis();
  while (millis() - now < 20 * 1000) {
    
    if(stopflag == 1){
      Serial.println("stop button is pushed");
      return;
    }
    if (Serial.available() > 0) {
      char input = Serial.read();
      if (input == 'o') {
        Serial.println("break");
      }
    }
  }
}


void sequence_batch(char c) {
  if(stopflag == 1){
    Serial.println("stop button is pushed");
    return;
  }

  //  switch (Serial.read()){
  switch (c) {
    case 'g':
      s_right_5();
      break;
    case 'f':
      s_right();
      break;
    case 'd':
      s_left();
      break;
    case 'c':
      arm_down();
      break;
    case 'r':
      arm_up();
      break;
    case 's':
      arm_tap();
      break;
    case 'a':
      arm_tap_5();
      break;
    case 'z':
      arm_tap_5_long();
      break;
    case 'q':
      r = start_vertical_angle;
      set_angle(start_vertical_angle);
      break;
  }
  
//  int CdS = analogRead(0);
//  Serial.print("  CdS:");
//  Serial.println(CdS);
//  delay(100);
}
