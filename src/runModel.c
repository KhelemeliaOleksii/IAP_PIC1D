#include <stdio.h>
#include "../include/runModel.h"

void RunModel () {
    int age;
    fprintf(stdout, "Hello\n");
    printf("Enter your age\n");
    scanf("%d", &age);
    fprintf(stdout, "You are %d years old!", age);
}