#include "struct.h"

float getLapTime(sharedMemory *sharedMemory, int childId)
{
    float lapTime = 0;
    for (int i = 0; i < 3; i++)
    {
        lapTime += sharedMemory->cars[childId].sectors[i];
    }
    return lapTime;
}