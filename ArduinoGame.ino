#include "Menu.h"
#include <stdlib.h>
#include <time.h>

void setup() {
  Serial.begin(9600);
  pinMode(PIN_SW, INPUT_PULLUP);
  pinMode(PIN_X, INPUT);
  pinMode(PIN_Y, INPUT);
  srand(time(NULL));
}

Menu mainMenu;
void loop() {
  mainMenu.start();
}
