#include "../include/initRealParticle.h"

int initRealParticle(const int charge, const double charge_unit, 
    const double mass, const double mass_unit,  
    struct particle_type *particle, char** msg) {
  
  strcpy(*msg, "");  
  strcat (*msg, __func__);    
    
  particle->charge = charge;
  
  if (mass <=0) {
    strcat (*msg, ": Wrong values of mass! Check if condition (mass > 0 ) carries out.");
    return -1;
  }
  particle->mass = mass;

  strcat (*msg, "\n\t\tOK!\tParticle has been initialized.");    
  return 0;
}
