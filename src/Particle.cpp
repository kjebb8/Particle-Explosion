/*
 * Particle.cpp
 *
 *  Created on: Nov. 6, 2018
 *      Author: keeganjebb
 */

#include "Particle.h"
#include <math.h>
#include <stdlib.h>

namespace ksj {

Particle::Particle () {
  init();
}

Particle::~Particle () {
  // TODO Auto-generated destructor stub
}


void Particle::init() {

  x = 0.5;
  y = 0.5;
  direction = (2 * M_PI * rand())/RAND_MAX;
  speed = (0.04 * rand())/RAND_MAX;
  speed *= speed;
}


void Particle::update(int interval) {

  direction += 0.0003 * interval;

  double xSpeed = speed * cos(direction);
  double ySpeed = speed * sin(direction);

  x += xSpeed * interval;
  y += ySpeed * interval;

  if (x < 0.0 || x > 1.0 || y < 0.0 || y > 1.0) {
      init();
  }

  if (rand() < RAND_MAX/100) {
      init(); //randomly reinit particles
  }

}


} /* namespace ksj */
