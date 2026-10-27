#define UB_DEB_TIME 10      // дебаунс (до 255)
#define UB_HOLD_TIME 600    // время до перехода в состояние "удержание"
#define UB_STEP_TIME 400    // время до перехода в состояние "импульсное удержание"
#define UB_STEP_PRD 200     // период импульсов
#define UB_CLICK_TIME 500   // ожидание кликов

#include <uEncoder.h>
#include <uButton.h>

#define L1 12  // LED
#define L2 13

#define E1_S1 2  // ENCODER 1, PIN S1
#define E1_S2 3
#define E1_K 4
#define E2_S1 5
#define E2_S2 6
#define E2_K 7
#define E3_S1 8
#define E3_S2 9

#define B1 10  // BUTTON
#define B2 11
#define B3 A0
#define B4 A1
#define B5 A2
#define B6 A3

//---------------------------------------------------------------------------------------------------------
// костыль

#define E3_K A3

//===================================================================================================================================================

#define OK_START_PC = "======PC OK START======"
#define OK_END_PC = "=======PC OK END======="

#define L1_ON_PC = "L1_ON"
#define L1_OFF_PC = "L1_OFF"
#define L2_ON_PC = "L2_ON"
#define L2_OFF_PC = "L2_OFF"

//---------------------------------------------------------------------------------------------------------

#define OK_ARDU = "::::::::ARDU OK::::::::"

#define ENCODER1_R_ARDU "E1_R"
#define ENCODER1_L_ARDU "E1_L"
// #define ENCODER1_C_ARDU = "E1_C" // CLick
#define ENCODER2_R_ARDU "E2_R"
#define ENCODER2_L_ARDU "E2_L"
#define ENCODER3_R_ARDU "E3_R"
#define ENCODER3_L_ARDU "E3_L"

#define BUTTON1_C_ARDU "B1_C"  // Click
#define BUTTON2_C_ARDU "B2_C"
#define BUTTON3_C_ARDU "B3_C"
#define BUTTON4_C_ARDU "B4_C"
#define BUTTON5_C_ARDU "B5_C"
#define BUTTON6_C_ARDU "B6_C"

//===================================================================================================================================================

uEncoder e1(E1_S1, E1_S2, E1_K);
uEncoder e2(E2_S1, E2_S2, E2_K);
uEncoder e3(E3_S1, E3_S2, E3_K);

uButton b1(B1);
uButton b2(B2);
uButton b3(B3);
uButton b4(B4);
uButton b5(B5);
uButton b6(B6);

//===================================================================================================================================================

void setup() {
  Serial.begin(9600);

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
}

void loop() {
  e1.tick();
  e2.tick();
  e3.tick();

  b1.tick();
  b2.tick();
  b3.tick();
  b4.tick();
  b5.tick();
  b6.tick();

  //---------------------------------------------------------------------------------------------------------

  if (e1.right()) {
    Serial.println(ENCODER1_R_ARDU);
  } else if (e1.left()) {
    Serial.println(ENCODER1_L_ARDU);
  }

  // if (e2.right()) {
  //   Serial.println(ENCODER2_R_ARDU);
  // } else if (e2.left()) {
  //   Serial.println(ENCODER2_L_ARDU);
  // }

  // if (e3.right()) {
  //   Serial.println(ENCODER3_R_ARDU);
  // } else if (e3.left()) {
  //   Serial.println(ENCODER3_L_ARDU);
  // }

  //---------------------------------------------------------------------------------------------------------

  if (b1.click()){
    Serial.println(BUTTON1_C_ARDU);
  }
  
  if (b2.click()){
    Serial.println(BUTTON2_C_ARDU);
  }

  if (b3.click()){
    Serial.println(BUTTON3_C_ARDU);
  }

  if (b4.click()){
    Serial.println(BUTTON4_C_ARDU);
  }

  if (b5.click()){
    Serial.println(BUTTON5_C_ARDU);
  }

  if (b6.click()){
    Serial.println(BUTTON6_C_ARDU);
  }
}
