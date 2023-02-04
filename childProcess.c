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

float findBestLap(sharedMemory *sharedMemory, int childId)
{
    if (sharedMemory->cars[childId].bestLap > sharedMemory->cars[childId].lapTime)
    {
        sharedMemory->cars[childId].bestLap = sharedMemory->cars[childId].lapTime;
    }
    return sharedMemory->cars[childId].bestLap;
}