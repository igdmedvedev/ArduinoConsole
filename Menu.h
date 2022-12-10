#pragma once
#include "SnakeGame.h"
#include "PongGame.h"
#include "Stick.h"
#include "Visualization.h"
#include "Coordinate.h"

class Menu {
private:
  Coordinate<int> gameLine;
  unsigned long timer;
  bool flagPress, flagHold;
public:
  Menu() {
    gameLine.setXY(0, 0);
  }
  void start() {
    if(stick.isUpPressed() || stick.isUpHold()) {
      gameLine.setY((unsigned int)(gameLine.getY() - 1) % 2);
    }
    if(stick.isRightPressed() || stick.isRightHold()) {
      gameLine.setX((unsigned int)(gameLine.getX() + 1) % 4);
    }
    if(stick.isDownPressed() || stick.isDownHold()) {
      gameLine.setY((unsigned int)(gameLine.getY() + 1) % 2);
    }
    if(stick.isLeftPressed() || stick.isLeftHold()) {
      gameLine.setX((unsigned int)(gameLine.getX() - 1) % 4);
    }
    if(stick.isSWPressed()) {
      if (gameLine.getX() == 0 && gameLine.getY() == 0) {
        snakeGame();
      }
      if (gameLine.getX() == 1 && gameLine.getY() == 0) {
        pongGame();
      }
    }
    
    menuPage1(gameLine.getX(), gameLine.getY());
  }
};
