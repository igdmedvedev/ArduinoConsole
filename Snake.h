#pragma once
#include "Stick.h"
#include "Coordinate.h"
#include <time.h>
#include <stdlib.h>

class SnakeCell {
  private:
    Coordinate<int> coordinate;
    SnakeCell* next;
  public:
    SnakeCell(int x, int y, SnakeCell* next) {
      coordinate.setXY(x, y);
      this->next = next;
    }
    int getX() { return coordinate.getX(); }
    int getY() { return coordinate.getY(); }
    Coordinate<int> getCoordinate() { return coordinate; }
    void setNext(SnakeCell* next) { this->next = next; }
    SnakeCell* getNext() { return next; }
};

class Snake {
  private:
    SnakeCell* head;
    SnakeCell* tail;
  public:
    Snake();
    ~Snake();
    void move(Direction, bool);
    SnakeCell* getTail() { return tail; }
    Coordinate<int> getHeadCoord() { return head->getCoordinate(); }
    Coordinate<int> getTailCoord() { return tail->getCoordinate(); }
};

Snake::Snake() {
  head = new SnakeCell(0, 1, NULL);
  tail = new SnakeCell(0, 0, head);
}
Snake::~Snake() {
  SnakeCell* tmp = tail->getNext();
  while (tmp != NULL) {
    delete tail;
    tail = tmp;
    tmp = tmp->getNext();
  }
}
void Snake::move(Direction directionHead, bool addCell) {
  SnakeCell* tmp;
  switch (directionHead) {
    case UP:
      tmp = new SnakeCell(head->getX(), ((unsigned int)head->getY() - 1) % 8, NULL);
      break;
    case RIGHT:
      tmp = new SnakeCell(((unsigned int)head->getX() + 1) % 16, head->getY(), NULL);
      break;
    case DOWN:
      tmp = new SnakeCell(head->getX(), ((unsigned int)head->getY() + 1) % 8, NULL);
      break;
    case LEFT:
      tmp = new SnakeCell(((unsigned int)head->getX() - 1) % 16, head->getY(), NULL);
      break;
  }
  head->setNext(tmp);
  head = tmp;

  if (!addCell) {
    tmp = tail;
    tail = tail->getNext();
    delete tmp;
  }
}
