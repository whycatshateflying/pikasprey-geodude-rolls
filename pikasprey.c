#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // By rolling the 4 sided die and keeping track of all the highest, not just ones, we can simulate 4 times as many
    int maxes[4] = {0, 0, 0, 0};

    int roll = 0;
    // Seed the prng function
    srandom(time(NULL));

    long startTime = time(NULL);

    // Attempt N times (or 1000000000/4, one for each chance)
    int N = 250000000;
    for (int j = 0; j < N; j++)
    {
        int current[4] = {0, 0, 0, 0};
        // Roll 231 times
        for (int i = 0; i < 231; i++)
        {
            roll = random()%4;
            current[roll]++;
        }

        // Check for a new maximum for each number
        for (int i = 0; i < 4; i++)
        {
            if (current[i] > maxes[i])
                maxes[i] = current[i];
        }
    }
    long endTime = time(NULL);
    // I'm too lazy to find a way to get millisecond precision :/
    printf("Max rolled: 1: %i, 2: %i, 3: %i, 4: %i\nTime start: %li\nTime end: %li\nTime difference (seconds): %li\n", maxes[0], maxes[1], maxes[2], maxes[3], startTime, endTime, (endTime-startTime));
}
