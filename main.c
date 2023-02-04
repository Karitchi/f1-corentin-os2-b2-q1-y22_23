#include <math.h>
#include "mainProcess.c"
#include "childProcess.c"
#include "random.c"
// #include "struct.c"

void main(void)
{
    int pId, timeOfRace;
    const int KEY = 666;
    sharedMemory *sharedMemory;

    sharedMemory = createSharedMemory(sharedMemory, KEY);

    sharedMemory->carsLeft = 20;
    sharedMemory->childIdSeed = 0;
    sharedMemory->randomSeed = 0;

    timeOfRace = selectRace();

    pId = generateChilds();

    // if child process
    if (!pId)
    {
        float timeLeft = timeOfRace;
        int childId;
        int carIds[20] = {44, 63, 1, 11, 55, 16, 4, 3, 14, 31, 10, 22, 5, 18, 6, 23, 77, 24, 47, 9};

        childId = assingChildId(sharedMemory);
        sharedMemory->cars[childId].carId = assignCarId(carIds, childId);

        sharedMemory->cars[childId].totalTime = 0;
        sharedMemory->cars[childId].bestLap = INFINITY;

        while (timeLeft > 0)
        {
            sharedMemory->cars[childId].sectors[0] = getRandomNumber(sharedMemory) + 35;
            sharedMemory->cars[childId].sectors[1] = getRandomNumber(sharedMemory) + 35;
            sharedMemory->cars[childId].sectors[2] = getRandomNumber(sharedMemory) + 35;

            sharedMemory->cars[childId].lapTime = getLapTime(sharedMemory, childId);
            sharedMemory->cars[childId].totalTime += sharedMemory->cars[childId].lapTime;

            sharedMemory->cars[childId].bestLap = findBestLap(sharedMemory, childId);

            timeLeft = timeLeft - sharedMemory->cars[childId].lapTime;
            sleep(1);
        }
        sharedMemory->carsLeft--;
    }
    // if main process
    if (pId)
    {
        int ranking[20][2];
        while (sharedMemory->carsLeft > 0)
        {
            // todo ranking
            // rankCarsOnBestLap(sharedMemory);
            // printf("ranking %d", ranking[1][1]);
            display(sharedMemory);
            sleep(1);
        }
    }
}
