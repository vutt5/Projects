/* Project #3
   EGRE245 Fall 2017
   Tin Vu */




#include <stdio.h>
#include <math.h>

int main (void){

float c, h, x,d0, d1, d2, d3, d4, d5, d6,l0, l1, l2, l3, l4, l5, interval ;
float l01,l02,l03,l04; 
float l11 , l12 , l13 , l14;
float l21 , l22 , l23 , l24;   
   
   
printf("Proj. #3 - Tin Vu\n");
printf("\n");
printf("power of lamps (in watts)? ");
scanf("%f", &c);
printf("height of lamp (in meters)? ");
scanf("%f", &h);
printf("distance apart (in meters)? ");
scanf("%f", &x); 
    
    interval = (x*3)/5;
    d1 = interval * 1;
    d2 = interval * 2;
    d3 = interval * 3;
    d4 = interval * 4;
    d5 = interval * 5;
    
   
    
printf("\n");
printf("power: %.2f watts\n",c);
printf("height: %.2f meters\n", h);
printf("distance apart: %.2f meters\n", x);
    
printf("\n");
    
printf("total distance: %.2f meters\n", x*3);
printf("interval: %.2f meters\n", (x*3)/5);
printf("  d       L\n");
printf(" ------  -------\n");

    
   // illumination of the 0 and 5th interval
    
        l01 = ((c * h) / sqrt(powf ((pow(h,2) + powf(d0,2)), 3))); 
        l02 = ((c * h) / sqrt(pow ((pow(h,2) + pow(x,2)), 3))) ;
        l03 = ((c * h) / sqrt(pow ((pow(h,2) + pow((x*2),2)), 3)));
        l04 = ((c * h) / sqrt(pow ((pow(h,2) + pow((x*3),2)), 3)))  ;
   
    l0 = l5 = l01 + l02 + l03 + l04;
    
    // illumination of the 1st and 4th intervals
     
        l11 = (c * h) / pow ((pow(h,2) + pow(interval,2)), 1.5); 
        l12 = (c * h) / pow ((pow(h,2) + pow((x - interval),2)), 1.5); 
        l13 = (c * h) / pow ((pow(h,2) + pow(2*x - interval,2)), 1.5);
        l14 = (c * h) / pow ((pow(h,2) + pow(3*x - interval,2)), 1.5) ;
     l1 = l4 = l11 + l12 + l13 + l14; 
    
    // illumination of the 2nd and 3rdth intervals 
    
        l21 = (c * h) / pow ((pow(h,2) + pow((2* interval),2)), 1.5);
        l22 = (c * h) / pow ((pow(h,2) + pow((2* interval - x ),2)), 1.5); 
        l23 = (c * h) / pow ((pow(h,2) + pow(((2*x) - 2*interval),2)), 1.5); 
        l24 = (c * h) / pow ((pow(h,2) + pow((3 * interval),2)), 1.5) ;
    l2 = l3 = l21 + l22 + l23 + l24;
    
    printf("%6.2f   %1.5f\n", d0, l0);
    printf("%6.2f   %1.5f\n", d1, l1);
    printf("%6.2f   %1.5f\n", d2, l2);
    printf("%6.2f   %1.5f\n", d3, l3);
    printf("%6.2f   %1.5f\n", d4, l4);
    printf("%6.2f   %1.5f\n", d5, l5);
    
    
    
    return 0;

}
//
//
//    !!------x-----!!            !!            !!          !  
//    !!            !!            !!            !!          !              
//    !!            !!            !!            !!          !  
//    !!            !!            !!            !!          !  
//    !!            !!            !!            !!      height of lamps: h      
//    !!            !!            !!            !!          !  
//    !!            !!            !!            !!          !  
//    !!            !!            !!            !!          !            
//    ^-------^--------^--------^-------^--------^          !
//   |interval|interval|interval|interval|interval|
//
//    |--------total distance (4*x)--------------|
//










