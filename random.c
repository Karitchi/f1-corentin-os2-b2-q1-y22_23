#include <stdlib.h>
#include "struct.h"

float getRandomNumber(sharedMemory *sharedMemory)
{
    srand(sharedMemory->seed);
    sharedMemory->seed++;
    return ((float)rand() / (float)(RAND_MAX)) * 10.0;
}
