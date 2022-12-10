#pragma once
#include "U8glib.h"
#include "Bitmaps.h"
#include "Snake.h"
#include "Pong.h"

#define WIDTH 128
#define HEIGHT 64
#define BALL_PONG_R 3

U8GLIB_SSD1306_128X64 u8g(13, 11, 10, 9, 7); // SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RES = 7

void menuPage1(int gameLineX, int gameLineY) {
  u8g.firstPage();
  do {
    u8g.drawFrame(gameLineX * 32, gameLineY * 32, 32, 32);
    u8g.drawBitmapP(0, 0, 4, 32, SNAKE_MENU_32x32);
    u8g.drawBitmapP(32, 0, 4, 32, PONG_MENU_32x32);
    /*u8g.drawBox(0, 6 * 4, 3 * 4, 4);
    u8g.drawBox(2 * 4, 5 * 4, 2 * 4, 4);
    u8g.drawBox(3 * 4, 4 * 4, 3 * 4, 4);
    u8g.drawBox(7 * 4 - 1, 4 * 4 + 1, 3, 3);*/
  } while (u8g.nextPage());
}

void visualizationSnake(Snake* snake, Coordinate<int> food) {
  const int cellSize = 8;
  u8g.firstPage();
  do {
    u8g.drawBox(food.getX() * cellSize + cellSize / 4, food.getY() * cellSize + cellSize / 4, cellSize / 2, cellSize / 2);
    SnakeCell* tmp = snake->getTail();
    while (tmp != NULL) {
      u8g.drawBox(tmp->getX() * cellSize, tmp->getY() * cellSize, cellSize, cellSize);
      tmp = tmp->getNext();
    }
  } while (u8g.nextPage());
}
void gameOverSnake(int score) {
  char str[] = "Your score: ";
  char scoreStr[] = " ";
  itoa(score, scoreStr, 10);
  strcat(str, scoreStr);
  
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr( 0, 22, "Game over");
    u8g.drawStr( 0, 50, str);
  } while (u8g.nextPage());
}

void visualizationPong(Racket player, Racket enemy, Coordinate<float> ball) {
  u8g.firstPage();
  do {
    u8g.drawBox(0, player.getY(), Racket::R_WIDTH, Racket::R_HEIGHT);
    u8g.drawBox(WIDTH - Racket::R_WIDTH, enemy.getY(), Racket::R_WIDTH, Racket::R_HEIGHT);
    u8g.drawFilledEllipse((int)ball.getX(), (int)ball.getY(), BALL_PONG_R, BALL_PONG_R, U8G_DRAW_ALL);
  } while (u8g.nextPage());
}
void gameOverPong(bool playerWon, int* score) {
  char str[] = " ";
  char scoreStr[] = " ";
  
  itoa(score[0], str, 10);
  strcat(str, " : ");
  
  itoa(score[1], scoreStr, 10);
  strcat(str, scoreStr);
  
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr( 44, 32, str);
  } while (u8g.nextPage());
  
}
