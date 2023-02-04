#include <unistd.h>
#include <stdio.h>
#include <sys/shm.h>
#include "struct.h"
#include <stdlib.h>

void generateChilds(int *pId, int *childId)
{
    for (int i = 0; i < 20; i++)
    {
        *pId = fork();

        if (!*pId)
        {
            *childId = i;
            break;
        }
    }
}

void *createSharedMemory(void *sharedMemory, const int KEY)
{
    size_t shmId;
    shmId = shmget(KEY, sizeof(*sharedMemory), IPC_CREAT | 0666);
    return shmat(shmId, NULL, 0);
}

int selectRace(void)
{

    int selectedRace;
    int timeLeft;

    printf("Essai 1 : 1\n");
    printf("Essai 2 : 2\n");
    printf("Essai 3 : 3\n");
    printf("\n");
    // printf("Qualification 1 : 4\n");
    // printf("Qualification 2 : 5\n");
    // printf("Qualification 3 : 6\n");
    // printf("\n");
    // printf("Course : 7\n");
    // printf("\n");
    printf("Quitter : 0\n");
    printf("\n");
    printf("Choix: ");
    scanf("%d", &selectedRace);

    switch (selectedRace)
    {
    case 0:
        exit(0);
        break;
    case 1:
        timeLeft = 3600;
        break;

    case 2:
        timeLeft = 3600;
        break;

    case 3:
        timeLeft = 3600;
        break;
    }
    return timeLeft;
}

void display(sharedMemory *sharedMemory)
{
    system("clear");
    printf("| position | car number | sector 1 | sector 2 | sector 3 | lap time | total time |\n");
    for (int i = 0; i < 20; i++)
    {
        printf("[  %2d  ][  %2.2f  ][  %2.2f  ][  %3.2f  ][  %3.2f  ][  %4.2f  ]\n",
               i + 1,
               sharedMemory->cars[i].sectors[0],
               sharedMemory->cars[i].sectors[1],
               sharedMemory->cars[i].sectors[2],
               sharedMemory->cars[i].lapTime,
               sharedMemory->cars[i].totalTime);
    }
}
