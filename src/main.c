#include <stdio.h>
#include "runModel.h"
#include "initSystem.h"
#include "initSuperParticles.h"
int main () {
    printf("hello\n");

    initSystem(0);

    initSuperParticles();

    // to initialize SYSTEM
    //initSystem()

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