#pragma once
#include "Stick.h"
#include "Coordinate.h"

class Racket {
private:
  int y;
public:
  const static int R_WIDTH = 4, R_HEIGHT = 16;
  Racket(int = R_WIDTH / 2);
  int getY() { return y; }
  void move(Direction);
};

Racket::Racket(int y) {
  this->y = y;
}
void Racket::move(Direction direction) {
  switch(direction) {
    case UP:
      y -= 2; 
      break;
    case DOWN:
      y += 2;
      break;
  }
}
