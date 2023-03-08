#include "../include/initSuperParticles.h"
#include "../include/constants.h"
#include "../include/distributeParticles.h"
#include <stdio.h>

int initSuperParticles () {
  // array to a name of velocity distribution function
  char dvf_description[200];
  // array to a name of coord distribution function
  char dcf_description[200];
  // array to an array of particles coord
  double particles_coord[(int)SUPERPRTCL_NMBR];
  // array to an array of particles velocity
  double particles_velocity[(int)SUPERPRTCL_NMBR];
  
  // Length of plasma
  double length_total = CELLS * LENGTH_MESH; 

  double plasma_borders[2] = {0, length_total};
  // Real particles (rp) all
  double rp_all = DENSITY_FIRST * length_total;

  // Real particles per SuperParticle
  double rp_per_sp = rp_all / SUPERPRTCL_NMBR;

  // Charge of SuperParticlse
  double charge_sp = CHARGE_FIRST * rp_per_sp * ELEM_CHARGE;

  // Mass of SuperParticle
  double mass_sp = ELECTRON_MASS * rp_per_sp;
  fprintf(stdout, "Plasma length is %e m\n", length_total);
  fprintf(stdout, "Number of all real particles is %e\n", rp_all);
  fprintf(stdout, "Real particles per a SuperPArticle are %e \n", rp_per_sp);
  fprintf(stdout, "Charge of a SuperParticle is %e C\n", charge_sp);
  fprintf(stdout, "Mass of a SuperParticle is %e kg\n", mass_sp);
  fprintf(stdout, "Plasma borders %e<->%e\n", plasma_borders[0], plasma_borders[1]);
  fflush(stdout);
  

  //initParticlesPosition(SUPERPRTCL_NMBR, plasma_borders, distribute1DCoordUniform, &particles_coord, &dcf_description);
  //initParticlesVelocity(SUPERPRTCL_NMBR, VELOCITY_FIRST, distribute1DVelocityUniform, &particles_velocity, &dvf_description);
  return 0;
}

int initParticlesPosition(int particle_number, double **borders, int distribute_function(int, double, double, double**, char**), double **particle_position, char **function_description) {
  double start = borders[0][0];
  double end = borders[0][1];

  distribute_function(particle_number, start, end, &particle_position, &function_description);

  return 0;
} 

int initParticlesVelocity(int particle_number, double beam_velocity, int distribute_function(int, double, double**, char**), double **particle_velocity, char **function_description) {
  distribute_function(particle_number, beam_velocity, particle_velocity, function_description);
  return 0;
} 
