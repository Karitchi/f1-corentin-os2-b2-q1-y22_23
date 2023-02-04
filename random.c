#include <stdlib.h>
#include "struct.h"

float getRandomNumber(sharedMemory *sharedMemory)
{
    srand(sharedMemory->randomSeed);
    sharedMemory->randomSeed++;
    return ((float)rand() / (float)(RAND_MAX)) * 10.0;
}
