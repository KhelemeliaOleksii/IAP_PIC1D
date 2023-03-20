#include "../include/initSuperParticles.h"
#include "../include/constants.h"
#include "../include/distributeParticles.h"
#include <stdio.h>

int initSuperParticles()
{
  // array to a description of velocity distribution function
  char vdf_description[200];
  char *ptr_dvfd = vdf_description;
  // array to a description of coord distribution function
  char cdf_description[200];
  char *ptr_dcfd = cdf_description;
  // array to particles coord
  double particles_coord[(int)SUPERPRTCL_NMBR];
  // array to particles velocity
  double particles_velocity[(int)SUPERPRTCL_NMBR];

  // Length of plasma
  double length_total = CELLS * LENGTH_MESH;
  double plasma_borders[2] = {0, length_total};
  // Real particles (rp) all
  // double rp_all = DENSITY_FIRST * length_total;

  // Real particles per SuperParticle
  // double rp_per_sp = rp_all / SUPERPRTCL_NMBR;

  // Charge of SuperParticlse
  // double charge_sp = CHARGE_FIRST * rp_per_sp * ELEM_CHARGE;

  // Mass of SuperParticle
  // double mass_sp = ELECTRON_MASS * rp_per_sp;
  

  // fprintf(stdout, "Plasma length is %e m\n", length_total);
  // fprintf(stdout, "Number of all real particles is %e\n", rp_all);
  // fprintf(stdout, "Real particles per a SuperPArticle are %e \n", rp_per_sp);
  // fprintf(stdout, "Charge of a SuperParticle is %e C\n", charge_sp);
  // fprintf(stdout, "Mass of a SuperParticle is %e kg\n", mass_sp);
  // fprintf(stdout, "Plasma borders %e<->%e meters\n", plasma_borders[0], plasma_borders[1]);
  // fflush(stdout);
  
  initParticlesVelocity(SUPERPRTCL_NMBR, VELOCITY_FIRST, 
      VELOCITY_FIRST, VELOCITY_FIRST, 0,
      distribute1DVelocityUniform, particles_velocity, &ptr_dvfd);
  for (int i = 0; i < SUPERPRTCL_NMBR; i++)
  {
    printf("V[%d] = %f\t", i, particles_velocity[i]);
    if (i%3 == 0) {
      printf("\n");
    }
  }
  
  printf("%s", ptr_dvfd);

  initParticlesCoord(SUPERPRTCL_NMBR, 0, 
          plasma_borders[0], plasma_borders[1], 0, 
          distribute1DCoordUniform,
          particles_coord, &ptr_dcfd);

  for (int i = 0; i < SUPERPRTCL_NMBR; i++)
  {
    printf("x[%d] = %f\t", i, particles_coord[i]);
    if (i%3 == 0) {
      printf("\n");
    }
  }
  
  printf("%s", ptr_dcfd);

  return 0;
}

int initParticlesVelocity(int particle_number, double beam_velocity, 
          double min_velocity, double max_velocity, double velocity_spread, 
          int distribute_function(int particle_number, double beam_velocity, 
            double min_velocity, double max_velocity, double velocity_spread, 
            double* particles_velocity, char**description),
          double *particles_velocity, char **df_description){
            
  distribute_function(particle_number, beam_velocity, 
    beam_velocity, beam_velocity, velocity_spread, 
    particles_velocity, df_description);

  return 0;
}
    
int initParticlesCoord(int particle_number, double beam_position, 
          double min_coord, double max_coord, double coord_spread, 
          int distribute_function(int particle_number, double beam_position, 
            double min_coord, double max_coord, double coord_spread, 
            double* particles_coord, char**description),
          double *particles_coord, char **df_description){

  distribute_function(particle_number, beam_position, 
            min_coord, max_coord, coord_spread, 
            particles_coord, df_description);

  return 0;
}

int test (int size, int *src_array) {
  int i;
  for (i=0; i< size; i++) {
    src_array[i] = i;
  }
  return 0;
}

int testString (int size, char **msg) {
  *msg = "Test is OK!";
  return 0;
}

