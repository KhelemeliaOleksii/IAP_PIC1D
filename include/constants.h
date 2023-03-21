#ifndef CONSTANTS_H
    #define CONSTANTS_H
        /////////////////////////
        // Procedure constants //
        /////////////////////////
        // No. of particles
        #define SUPERPRTCLS 1e3
        // Sys. length (or number of cells)
        #define MESHCELLS 100
        // Mesh length (or length of a cell)
        #define MESHCELL_LENGTH 1.0e-3 // m (meters)
        // Max no. of timestaps
        #define TIME_MAX 500
        // No. of iteractions in poisson solver
        #define ITRCTN_MAX 10000
        //convergence factor for poisson solver
        #define EPS 1e-6
        // Volume Density of particles #1 per meters to the third power
        #define DENSITY_FIRST 1e6 // m^3 (meters in power of three)
        // Particle #1 Beam velocity
        #define VELOCITY_FIRST 1.0e8 // m/s (meters per second) 
        // Charge of the first beam particle
        #define CHARGE_FIRST -1  
        // Border of physical system start
        #define BORDER_XMIN .0 // m (meters)
        // Border of physical system end
        #define BORDER_XMAX 0.1 // m (meters)
        ////////////////////
        // Math constants //
        ////////////////////
        #define PI 3.14159275

        ///////////////////////
        // Physics constants //
        ///////////////////////
        #define VEL_LIGHT 2.99792458e8 // m/s (meters per second)
        #define ELEM_CHARGE 1.60217663e-19 // C(coulombs)
        #define ELECTRON_MASS 9.1093837e-31 // kg(kilogramms) 

        ///////////////////////////
        // Performing constants  //
        ///////////////////////////
        #define FUNC_NAME_LENGTH = 200
#endif // CONSTANTS_H