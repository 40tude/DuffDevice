#include <windows.h>

typedef struct {
    LARGE_INTEGER start;
    LARGE_INTEGER stop;
}HRWatch;

void StartTimer(HRWatch *timer);
void StopTimer(HRWatch *timer);
double GetElapsedTime(HRWatch *timer);
