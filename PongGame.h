#pragma once
#include "Pong.h"
#include "Stick.h"
#include "Visualization.h"
#include <math.h>
#include <stdlib.h>

bool playerLose(Racket player, Coordinate<float> ball) {
  return ball.getX() <  BALL_PONG_R + Racket::R_WIDTH && (ball.getY() > player.getY() + Racket::R_HEIGHT || player.getY() > ball.getY());
}
bool enemyLose(Racket enemy, Coordinate<float> ball) {
  return ball.getX() + BALL_PONG_R >= WIDTH - Racket::R_WIDTH && (ball.getY() > enemy.getY() + Racket::R_HEIGHT || enemy.getY() > ball.getY());
}

void ricochet(Coordinate<float> ball, Coordinate<float>* ballSpeed, Racket player, Racket enemy) {
  if (ball.getY() <= BALL_PONG_R || ball.getY() >= HEIGHT - BALL_PONG_R) {
    ballSpeed->setY(-ballSpeed->getY());
  }
  if(ball.getX() + BALL_PONG_R >= WIDTH - Racket::R_WIDTH && enemy.getY() + Racket::R_HEIGHT > ball.getY() && ball.getY() > enemy.getY()) {
    ballSpeed->setX(-ballSpeed->getX());
  }
  if (ball.getX() <  BALL_PONG_R + Racket::R_WIDTH && player.getY() + Racket::R_HEIGHT > ball.getY() && ball.getY() > player.getY()) {
    ballSpeed->setX(-ballSpeed->getX());
  }
}

Racket enemyMove(Racket enemy, Coordinate<float> ball, unsigned long* speedEnemy) {
  if (millis() - *speedEnemy > 50) {
      *speedEnemy = millis();

      if ((int)ball.getY() + 1 > enemy.getY() + Racket::R_HEIGHT / 2 && enemy.getY() + Racket::R_HEIGHT < HEIGHT) {
        enemy.move(DOWN);
      }
      if ((int)ball.getY() < enemy.getY() + Racket::R_HEIGHT / 2 && enemy.getY() > 0){
        enemy.move(UP);
      }
  }
  return enemy;
}

void pongGame() {
  bool playerWon;
  int score[2] = { 0, 0 };
  
  while(true) {
    Racket player;
    Racket enemy;
    Coordinate<float> ball(20, rand() % 20 + 30);
    float a = M_PI / 4;
    Coordinate<float> ballSpeed(tan(a), 1 / tan(a));
    unsigned long speedGame = millis(), speedEnemy = millis();
    while (true) {
      if(stick.isSWPressed()) {
        return;
      }
      stick.readY();
      if (stick.getY() < 360 && player.getY() > 0) {
          player.move(UP);
      }
      else if (stick.getY() > 660 && player.getY() + Racket::R_HEIGHT < HEIGHT) {
          player.move(DOWN);
      }
      
      if (millis() - speedGame > 10) {
        speedGame = millis();
        
        ball = ball + ballSpeed;
        ricochet(ball, &ballSpeed, player, enemy);
        enemy = enemyMove(enemy, ball, &speedEnemy);
        
        if (playerLose(player, ball)) {
          playerWon = false;
          score[1]++;
          break;
        }
        else if (enemyLose(enemy, ball)) {
          playerWon = true;
          score[0]++;
          break;
        }
      }
      visualizationPong(player, enemy, ball);
    }
    
    gameOverPong(playerWon, score);
    delay(1500);
  }
}
