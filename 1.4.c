//cup is dual core, only get to 50% cpu usage.
#include <Windows.h>
#include <stdlib.h>
#include <math.h>

const double SPLIT = 0.02;//SPLIT*COUNT should be 2
const int COUNT = 100;
const int INTERVAL = 200;

int main(void)
{
    unsigned long busySpan[COUNT];
    unsigned long idleSpan[COUNT];
    unsigned long startTime;
    int half = INTERVAL/2;
    double radian = 0.0;
    int i;

    for (i=0; i<COUNT; i++)
    {
        busySpan[i] = (unsigned long)(half + (sin(radian*M_PI) * half));
        idleSpan[i] = INTERVAL - busySpan[i];
        radian += SPLIT;
    }

    i=0;
    while (1)
    {
        i %= COUNT;
        startTime = GetTickCount();
        while (GetTickCount() - startTime <= busySpan[i]);

        Sleep(idleSpan[i]);
        i++;
    }
    return 0;
}