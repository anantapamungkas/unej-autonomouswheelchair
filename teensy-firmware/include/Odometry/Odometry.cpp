#include "Odometry.h"

Odometry::Odometry(int dia, int resA, int resB) {
  wheelDia = dia;
  encResA = resA;
  encResB = resB;
}

void Odometry::readCoordinate(int wheelPosA, int wheelPosB) {
  Da = PI * wheelDia * (wheelPosA / encResA);
  Db = PI * wheelDia * (wheelPosB / encResB);

  diffA = Da - prevA;
  prevA = Da;
  diffB = Db - prevB;
  prevB = Db;

  Ax = diffA * (cos(radians(wheelAngleA)));
  Ay = diffA * (sin(radians(wheelAngleA)));
  Bx = diffB * (cos(radians(wheelAngleB)));
  By = diffB * (sin(radians(wheelAngleB)));

  this->posX = this->posX + (Ax + Bx);
  this->posY= this->posY + (Ay + By);
}