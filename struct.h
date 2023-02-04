#ifndef STRUCT
#define STRUCT

typedef struct
{
    int randomSeed;
    int childIdSeed;
    int carsLeft;
    struct car
    {
        float sectors[3];
        float lapTime;
        float totalTime;
        int carId;
    } cars[20];
} sharedMemory;

#endif