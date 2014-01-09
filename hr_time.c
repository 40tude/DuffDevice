#include <windows.h>
#include "hr_time.h"

// CTRL + SHIFT + G to create auto documentation

// ----------------------------------------------------------------------------
static double LIToSecs(LARGE_INTEGER * L);   


// ----------------------------------------------------------------------------
/// HIFN Starts the timer passed as paramter
/// HIPAR timer/Pointer to the timer to be started
void StartTimer(HRWatch *timer) {
  QueryPerformanceCounter(&timer->start);
}

// ----------------------------------------------------------------------------
/// HIFN Starts the timer passed as paramter 
/// HIPAR timer/Pointer to the timer to be stopped 
void StopTimer(HRWatch *timer) {
  QueryPerformanceCounter(&timer->stop);
}

// ----------------------------------------------------------------------------
static double LIToSecs(LARGE_INTEGER *L) {
  
  LARGE_INTEGER frequency;
  
  QueryPerformanceFrequency( &frequency );
  return ((double)L->QuadPart /(double)frequency.QuadPart);
}

// ----------------------------------------------------------------------------
/// HIFN	For the timer passed as parameter returns the elapsed time between the StartTimer() and StopTimer() function calls.   
/// HIRET The elapsed time between the StartTimer() and StopTimer() function calls 
/// HIPAR timer/double - The timer for wich you wants to get the elapsed time
double GetElapsedTime(HRWatch *timer) {
  
  LARGE_INTEGER time;
  
  time.QuadPart = timer->stop.QuadPart - timer->start.QuadPart;
  return LIToSecs(&time) ;
}
