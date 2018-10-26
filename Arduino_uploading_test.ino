#include <LedControl.h>

//The following three are for LED matrix with MAX7219
#define DIN 12
#define CS 10
#define CLK 11
//ledcontrol setup:
LedControl lc = LedControl(DIN, CLK, CS, 2);

void setup() {
  // put your setup code here, to run once:
  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);
  lc.shutdown(1, false);
  lc.setIntensity(1, 4);
  lc.clearDisplay(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i, j;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 8; j++) {
      lc.setRow(i, j, 255);
      delay(200);
      lc.setRow(i, j, 0);
      delay(200);
    }
  }
}
