#pragma once
#define PIN_X A2
#define PIN_Y A1
#define PIN_SW 3

enum Direction { UP = 0, RIGHT, DOWN, LEFT, ZERO };

class Stick {
  private:
    bool sw;
    int oX, oY;
    unsigned long lastTime;
    bool flagHold, flagPress;
  public:
    Stick() {
      sw = false;
      oX = oY = 512;
      flagHold = flagPress = false;
      lastTime = millis();
    }

    void readX() { oX = analogRead(PIN_X); }
    int getX() { return oX; }

    void readY() { oY = analogRead(PIN_Y); }
    int getY() { return oY; }

    void readSW() { sw = !digitalRead(PIN_SW); }
    bool getSW() { return sw; }

    void readAll() {
      readX();
      readY();
      readSW();
    }

    bool isUpPressed(unsigned int = 100);
    bool isRightPressed(unsigned int = 100);
    bool isDownPressed(unsigned int = 100);
    bool isLeftPressed(unsigned int = 100);
    bool isSWPressed(unsigned int = 100);

    bool isUpHold(unsigned int = 400);
    bool isRightHold(unsigned int = 400);
    bool isDownHold(unsigned int = 400);
    bool isLeftHold(unsigned int = 400);
    bool isSWHold(unsigned int = 400);
};

bool Stick::isUpPressed(unsigned int timing) {
  readY();
  bool returnFlag = false;
  if (getY() < 150 && !flagPress && millis() - lastTime > timing){
    returnFlag = true;
    flagHold = flagPress = true;
    lastTime = millis();
  }
  if(getY() > 150 && flagPress && millis() - lastTime > timing) {
    flagHold = flagPress = false;
    lastTime = millis();
  }
  return returnFlag;
}
bool Stick::isUpHold(unsigned int timing) {
  readY();
  bool returnFlag = false;
  if(getY() < 50 && flagHold && millis() - lastTime > timing) {
    returnFlag = true;
    lastTime = millis();
  }
  if(getY() > 50 && flagHold && millis() - lastTime > timing) {
    flagHold = false;
    lastTime = millis();
  }
  return returnFlag;
}

bool Stick::isRightPressed(unsigned int timing) {
  readX();
  bool returnFlag = false;
  if (getX() > 970 && !flagPress && millis() - lastTime > timing){
    returnFlag = true;
    flagHold = flagPress = true;
    lastTime = millis();
  }
  if(getX() < 970 && flagPress && millis() - lastTime > timing) {
    flagHold = flagPress = false;
    lastTime = millis();
  }
  return returnFlag;
}
bool Stick::isRightHold(unsigned int timing) {
  readX();
  bool returnFlag = false;
  if(getX() > 970 && flagHold && millis() - lastTime > timing) {
    returnFlag = true;
    lastTime = millis();
  }
  if(getX() < 970 && flagHold && millis() - lastTime > timing) {
    flagHold = false;
    lastTime = millis();
  }
  return returnFlag;
}

bool Stick::isDownPressed(unsigned int timing) {
  readY();
  bool returnFlag = false;
  if (getY() > 970 && !flagPress && millis() - lastTime > timing){
    returnFlag = true;
    flagHold = flagPress = true;
    lastTime = millis();
  }
  if(getY() < 970 && flagPress && millis() - lastTime > timing) {
    flagHold = flagPress = false;
    lastTime = millis();
  }
  return returnFlag;
}
bool Stick::isDownHold(unsigned int timing) {
  readY();
  bool returnFlag = false;
  if(getY() > 970 && flagHold && millis() - lastTime > timing) {
    returnFlag = true;
    lastTime = millis();
  }
  if(getY() < 970 && flagHold && millis() - lastTime > timing) {
    flagHold = false;
    lastTime = millis();
  }
  return returnFlag;
}

bool Stick::isLeftPressed(unsigned int timing) {
  readX();
  bool returnFlag = false;
  if (getX() < 50 && !flagPress && millis() - lastTime > timing){
    returnFlag = true;
    flagHold = flagPress = true;
    lastTime = millis();
  }
  if(getX() > 50 && flagPress && millis() - lastTime > timing) {
    flagHold = flagPress = false;
    lastTime = millis();
  }
  return returnFlag;
}
bool Stick::isLeftHold(unsigned int timing) {
  readX();
  bool returnFlag = false;
  if(getX() < 50 && flagHold && millis() - lastTime > timing) {
    returnFlag = true;
    lastTime = millis();
  }
  if(getX() > 50 && flagHold && millis() - lastTime > timing) {
    flagHold = false;
    lastTime = millis();
  }
  return returnFlag;
}

bool Stick::isSWPressed(unsigned int timing) {
  readSW();
  bool returnFlag = false;
  if (getSW() && !flagPress && millis() - lastTime > timing){
    returnFlag = true;
    flagHold = flagPress = true;
    lastTime = millis();
  }
  if(!getSW() && flagPress && millis() - lastTime > timing) {
    flagHold = flagPress = false;
    lastTime = millis();
  }
  return returnFlag;
}
bool Stick::isSWHold(unsigned int timing) {
  readSW();
  bool returnFlag = false;
  if(getSW() && flagHold && millis() - lastTime > timing) {
    returnFlag = true;
    lastTime = millis();
  }
  if(!getSW() && flagHold && millis() - lastTime > timing) {
    flagHold = false;
    lastTime = millis();
  }
  return returnFlag;
}


Stick stick;
