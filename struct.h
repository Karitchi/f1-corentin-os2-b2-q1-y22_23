#ifndef STRUCT
#define STRUCT

typedef struct
{
    int seed;
    int carsLeft;
    struct car
    {
        float sectors[3];
        float lapTime;
        float totalTime;
    } cars[20];
} sharedMemory;

#endif