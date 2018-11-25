//============================================================================
// Name        : Particle_Explosion.cpp
// Author      : KJ
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace ksj;

int main() {

  srand(time(NULL));

  Screen screen;

  if (!screen.init()) {
      cout << "Failed to initialize" << endl;
  }

  Swarm swarm;

  while(true) {

      int elapsed = SDL_GetTicks();

      swarm.update(elapsed);

      unsigned char red = (1 + sin(elapsed * 0.0001)) * 128; //Unsigned char makes sure no overflow from 256
      unsigned char green = (1 + cos(elapsed * 0.0002)) * 128;
      unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

      const Particle * const pParticles = swarm.getParticles();

      for (int i = 0; i < Swarm::NUM_PARTICLES; i++) {
          Particle particle = pParticles[i];

          int x = particle.x * (Screen::SCREEN_WIDTH - 1);
          int y = particle.y * (Screen::SCREEN_WIDTH - 1) - Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2; //Same sized space as x, just translated to be centred

          screen.setPixel(x, y, red, green, blue);
      }

      screen.boxBlur();

      screen.update();

      if (!screen.processEvents()) {
          break;
      }

  }

  screen.close();

  cout << "Program Exiting" << endl;

  return 0;
}
