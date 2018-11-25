/*
 * Particle.h
 *
 *  Created on: Nov. 6, 2018
 *      Author: keeganjebb
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace ksj {

struct Particle {

//Break encapsulation for efficiency. Also why this is a struct and not a class
  double x;
  double y;

private:
  double speed;
  double direction;

public:
  Particle ();
  virtual
  ~Particle ();
  void update(int interval);

private:
  void init();

};

} /* namespace ksj */

#endif /* PARTICLE_H_ */
