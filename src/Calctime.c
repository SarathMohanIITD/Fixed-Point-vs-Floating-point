#include<time.h>

double calctime(double start , double stop)
{
  return (double)(stop-start) / CLOCKS_PER_SEC;  
}

