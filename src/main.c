#include <stdio.h>
#include "../include/initSystem.h"
#include "../include/initSuperParticles.h"

int main () {
    printf("hello\n");

    // to initialize SYSTEM
    initSystem(0);

    initSuperParticles();

    // to initialize LAYOUT of experiment
    //initLayout();

    // to initialize PARTICLE initial condition 
    // - positions
    // - velocities
    //initParticles();

    // to initialize ELECTRO-MAGNETICS FIELDS
    // - eletric fieds E
    // - magnetic fields B
    //initFields();

    // to carry out PERFORMING
    // use initial condition to start calculatiion
    // perform();

    return 0;
}