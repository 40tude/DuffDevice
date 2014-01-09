#include <string.h>
#include <stdio.h>
#include "hr_time.h"

#define COUNT 10025

// ----------------------------------------------------------------------------
static void send(short* to, short* from, const int count);

// ----------------------------------------------------------------------------
int main(){
  
  static short  to[COUNT];
  static short  from[COUNT];
  HRWatch       WDuff, WMcpy;  
  
  for(int i=0; i<COUNT; i++){
    from[i] = (short)i;
  }
  
  StartTimer(&WDuff);     
    send(to, from, COUNT);
  StopTimer(&WDuff);  
  printf("Calc timing Duff device : %f (sec.)\n", GetElapsedTime(&WDuff));   
  
  StartTimer(&WMcpy);   
    memcpy(to, from, COUNT*sizeof(short));
  StopTimer(&WMcpy);  
  printf("Calc timing mem copy    : %f (sec.)\n", GetElapsedTime(&WMcpy));   
  
  getchar();
}

// ----------------------------------------------------------------------------
static void send(short *to, short *from, const int count){
        
  int n = (count + 7) / 8;
  switch(count % 8) {
    case 0:   do {     *to++ = *from++;
    case 7:            *to++ = *from++;
    case 6:            *to++ = *from++;
    case 5:            *to++ = *from++;
    case 4:            *to++ = *from++;
    case 3:            *to++ = *from++;
    case 2:            *to++ = *from++;
    case 1:            *to++ = *from++;
              } while(--n > 0);
  }
  return;
}
