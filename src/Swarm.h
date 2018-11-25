/*
 * Swarm.h
 *
 *  Created on: Nov. 6, 2018
 *      Author: keeganjebb
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace ksj {

class Swarm {

public:
  const static int NUM_PARTICLES = 5000;

private:
  Particle * m_pParticles;
  int lastTime;

public:
  Swarm ();
  virtual
  ~Swarm ();

  const Particle * const getParticles() {return m_pParticles;}
  void update(int elapsed);
};

} /* namespace ksj */

#endif /* SWARM_H_ */
