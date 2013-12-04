/**
 *Volume Calculator
 *Calculates the volume of liquid in a cylendrical tank
 *
 *Created By Josh Harshman on 12/3/2013
 *All Rights Reserved 12/3/2013
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXCAP 95
#define TANKLEN 395
#define PI 3.14159

float method1(float height, float radius);
float method2(float height, float radius);
void createChart(float radius);

//Method 1 is for height < radius
float method1(float height, float radius) {

  float areaSector;
  float areaTriangle;

  areaSector = pow(radius, 2) * acos((radius-height)/radius);
  areaTriangle = (radius-height) * sqrt(2*radius*height - pow(height, 2));

  return TANKLEN * (areaSector - areaTriangle);

}
//Method 2 is for height >= radius
float method2(float height, float radius) {

  float areaSector;
  float areaTriangle;

  areaSector = pow(radius, 2) * acos((height - radius)/radius);
  areaTriangle = (height - radius) * sqrt(2*radius*height - pow(height, 2));

  return TANKLEN * ((PI * pow(radius, 2)) - (areaSector - areaTriangle));

}
void createChart(float radius) {

  int height;
  float fluid, leftover;
  float fullVol = PI*pow(radius,2) * TANKLEN;

  printf("Reading\t | Remaining\n");
  for(height = 0; height <= MAXCAP; height++) {
    //

    //print header for chart
    //printf("Reading\t | Remaining\n");
    printf("+------------------------+\n");
    if(height < radius) {
      //do by method 1
      fluid = method1(height, radius);
      leftover = fullVol - fluid;
    }
    else {
      //do by method 2
      fluid = method2(height, radius);
      leftover = fullVol - fluid;
    }

    printf("|%-5d\t | %-.2f\t |\n", height, leftover);

  }

}
int main( void ) {

  float height, radius, answer;

  radius = (float)MAXCAP/2;

  createChart(radius);
  
  printf("Enter height of fluid: ");
  scanf("%f", &height);
  
  if(height < radius) {
    //execute method 1
    answer = method1(height, radius);
  }
  else {
    //execute method 2
    answer = method2(height, radius);
  }

  printf("%.2f\n", answer);
  
  return 0;

}
