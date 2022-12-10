#pragma once
#include "Snake.h"
#include "Stick.h"
#include "Visualization.h"

Direction changeDir(Direction tmpDir, Direction nowDir) {
  if (stick.isRightPressed() && nowDir != LEFT) {
    return RIGHT;
  }
  else if (stick.isLeftPressed() && nowDir != RIGHT) {
    return LEFT;
  }
  else if (stick.isDownPressed() && nowDir != UP) {
    return DOWN;
  }
  else if (stick.isUpPressed() && nowDir != DOWN) {
    return UP;
  }
  return tmpDir;
}
void snakeGame() {
  Snake snake;
  unsigned long lastTime = millis();
  bool game = true;
  Direction tmpDir = DOWN, nowDir = DOWN;
  Coordinate<int> food((int)rand() % 16, (int)rand % 8);
  int score = 0;
  
  while (game) {
    tmpDir = changeDir(tmpDir, nowDir);
    if (millis() - lastTime > 250) {
      lastTime = millis();
      
      visualizationSnake(&snake, food);

      nowDir = tmpDir;
      if (snake.getHeadCoord() == food) {
        score++;
        food.setX((int)rand() % 16);
        food.setY((int)rand() % 8);
        SnakeCell* tmp = snake.getTail();
        while(tmp != NULL) {
          if (tmp->getCoordinate() == food) {
            food.setX((int)rand() % 16);
            food.setY((int)rand() % 8);
            tmp = snake.getTail();
          }
          tmp = tmp->getNext();
        }
        
        snake.move(nowDir, true);
      }
      else {
        snake.move(nowDir, false);
      }

      SnakeCell* tmp = snake.getTail();
      while(tmp->getNext() != NULL) {
        if (tmp->getCoordinate() == snake.getHeadCoord()) {
          game = false;
        }
        tmp = tmp->getNext();
      }
    }
  }
  
  while (true) {
    gameOverSnake(score);
    if(stick.isSWPressed()) {
      break;
    }
  }
}
