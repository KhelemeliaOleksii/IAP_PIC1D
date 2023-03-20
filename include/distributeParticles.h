#ifndef DISTRIBUTEPARTICLES_H
  #define DISTRIBUTEPARTICLES_H

    int distribute1DVelocityUniform(int particle_number, double beam_velocity, 
        double min_velocity, double max_velocity, double spread, 
        double* particle_velocity, char**description);
  
    int distribute1DCoordUniform(int particle_number, double beam_position, 
        double min_coord, double max_coord, double spread, 
        double* particles_coord, char**description);    

#endif // DISTRIBUTEPARTICLES_H

