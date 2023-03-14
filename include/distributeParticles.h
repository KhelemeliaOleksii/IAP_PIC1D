#ifndef DISTRIBUTEPARTICLES_H
  #define DISTRIBUTEPARTICLES_H

    int distribute1DVelocityUniform(int particle_number, double beam_velocity, double** particle_velocity, char**description);  int distributeCoordUniform(int particle_number, double** particle_coord, char**function_name);
    int distribute1DCoordUniform(int particle_number, double start, double end, double** particle_coord, char**description);
#endif // DISTRIBUTEPARTICLES_H

