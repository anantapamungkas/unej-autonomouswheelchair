#ifndef ODOMETRY_H
#define ODOMETRY_H

#include <Arduino.h>

class Odometry {
public:
  double posX;
  double posY;
  int wheelAngleA;
  int wheelAngleB;

  Odometry(int dia, int resA, int resB);
  void readCoordinate(int wheelPosA, int wheelPosB);

private:
  double wheelDia;
  double encResA;
  double encResB;

  int Da;
  int Db;
  int diffA;
  int diffB;
  int prevA;
  int prevB;
  double Ax;
  double Ay;
  double Bx;
  double By;
};

#endif