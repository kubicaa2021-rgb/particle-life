#pragma once
#include "particle.h"
#include "settings.h"
class PhysicsHandler {
public:
  static void applySpeed(Particle *p);
  static void applyForce(Particle *p);
};

inline void PhysicsHandler::applySpeed(Particle *p) {
  p->pos += p->speed * Settings::deltaTime;
}

inline void PhysicsHandler::applyForce(Particle *p) {
  float invWeight = 1.0f / p->weight;
  p->speed += p->force * invWeight * Settings::deltaTime;
}
