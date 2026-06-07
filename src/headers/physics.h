#pragma once
#include "particle.h"
#include "settings.h"
#include "vector2.h"
class PhysicsHandler {
public:
  static void applySpeed(Particle *p);
  static void applyForce(Particle *p);
  static void updateForces(Particle *p1, Particle *p2);
};

inline void PhysicsHandler::applySpeed(Particle *p) {
  p->pos += p->speed * Variables::deltaTime;
}

inline void PhysicsHandler::applyForce(Particle *p) {
  float invWeight = 1.0f / p->weight;
  p->speed += p->force * invWeight;
}

inline void PhysicsHandler::updateForces(Particle *p1, Particle *p2) {
  float dist = vector2::getDistanceSquare(p1->pos, p2->pos);
  vector2 dir = vector2::getDirection(p1->pos, p2->pos);
  float force = Variables::GravityConst * ((p1->weight * p2->weight) / dist);

  p1->force = dir * (-force);
  p2->force = dir * force;
  int a = 5;
}
