


void tap_attack(){
//  r -= 17; // s
  r = 83;
  set_angle(r);
  //sequence_batch('z');//z:arm_tap_5_long
  arm_tap_add(basic_tap_depth+2 );

}

void tap_card_r1(){
  r = 84;
  set_angle(r);
  //sequence_batch('z');//z:arm_tap_5_long
  arm_tap_add(basic_tap_depth +1 );
}

void tap_card_r2(){
  r = 103;
  set_angle(r);
  //sequence_batch('z');//z:arm_tap_5_long
  arm_tap_add(basic_tap_depth +1 );
}

void tap_card_r3(){
  r = 124;
  set_angle(r);
  //sequence_batch('z');//z:arm_tap_5_long
  arm_tap_add(basic_tap_depth+1 );
}

void tap_card_r4(){
  r = 142;
  set_angle(r);
  //sequence_batch('z');//z:arm_tap_5_long
  arm_tap_add(basic_tap_depth+2  );
}

void no_tap_wait(){
  r = 40;
  set_angle(r);

}
