/* Project #2
   EGRE245 Fall 2017
   Tin Vu */
#include <stdio.h>
int main(void) {
  float ra,t1,t2,rd;

    
  printf("Proj #2 - Tin Vu\n");
  printf("\n");
  printf("Acceleration rate (in m/s/s): ");
    scanf("%f",&ra);
  printf("Acceleration time (in minutes): ");
    scanf("%f",&t1);
  printf("Time until brakes were applied (in minutes): ");
    scanf("%f",&t2);
  printf("Deceleration rate (in m/s/s): ");
    scanf("%f",&rd);
  printf("\n");
  printf("- the train accelerated from rest at a rate of %1.2f m/s/s ",ra);
  printf("for %1.2f mins\n",t1);
  printf("- it traveled for %1.2f mins total until it applied its brakes\n",t2);
  printf("- it then decelerated at a rate of %1.2f m/s/s until it was at rest\n",rd);
  printf("\n");
  printf("Total distance traveled: %1.3f km\n", (((ra*t1*60*t1*60)/2 + (ra*t1*60)*(t2*60-t1*60)+(ra*t1*60*ra*t1*60)/(2*rd))/1000));
return 0; 
}