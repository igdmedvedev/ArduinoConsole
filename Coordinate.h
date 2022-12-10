#pragma once
template <class T> class Coordinate {
  private:
    T x, y;
  public:
    Coordinate() {}
    Coordinate(T, T);
    Coordinate(const Coordinate&);
    T getX();
    T getY();
    void setX(T);
    void setY(T);
    void setXY(T, T);

    bool operator==(const Coordinate&);
    bool operator!=(const Coordinate&);

    Coordinate operator=(const Coordinate&);
    Coordinate operator+(const Coordinate&);
    Coordinate operator-(const Coordinate&);
};

template <class T> Coordinate<T>::Coordinate(T x, T y) {
  this->x = x;
  this->y = y;
}
template <class T> Coordinate<T>::Coordinate(const Coordinate& crd) {
  x = crd.x;
  y = crd.y;
}
template <class T> T Coordinate<T>::getX() {
  return x;
}
template <class T> T Coordinate<T>::getY() {
  return y;
}
template <class T> void Coordinate<T>::setX(T x) {
  this->x = x;
}
template <class T> void Coordinate<T>::setY(T y) {
  this->y = y;
}
template <class T> void Coordinate<T>::setXY(T x, T y) {
  this->x = x;
  this->y = y;
}

template <class T> bool Coordinate<T>::operator==(const Coordinate& obj) {
  return x == obj.x && y == obj.y;
}
template <class T> bool Coordinate<T>::operator!=(const Coordinate& obj) {
  return !(x == obj.x && y == obj.y);
}

template <class T> Coordinate<T> Coordinate<T>::operator=(const Coordinate& obj) {
  setXY(obj.x, obj.y);
}

template <class T> Coordinate<T> Coordinate<T>::operator+(const Coordinate& obj) {
  return Coordinate<T>(x + obj.x, y + obj.y);
}
template <class T> Coordinate<T> Coordinate<T>::operator-(const Coordinate& obj) {
  return Coordinate<T>(x - obj.x, y - obj.y);
}
