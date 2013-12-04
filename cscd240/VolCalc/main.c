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
int menu();
void eval(float radius);

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

    //convert to gallons
    leftover = leftover*0.0043290;
    printf("|%-5d\t | %-5.2f\t |\n", height, leftover);

  }
  printf("+------------------------+\n");

}
int menu() {
 
  int choice;

  printf("1.  Create Chart for tank\n");
  printf("2.  Calc volume currently in tank\n");
  printf("3.  quit\n");

  scanf("%d", &choice);
  return choice;


}
void eval(float radius) {
  
  float fullVol = PI * pow(radius, 2) * TANKLEN; 
  float height;
  float answer;

  printf("Enter height: ");
  scanf("%f", &height);

  if(height < radius) {
    answer = method1(height, radius);
  }
  else {
    answer = method2(height, radius);
  }

  answer = answer * 0.0043290; //convert
  fullVol = fullVol * 0.0043290; //convert
  printf("-----------------------------------------------------\n");
  printf("There is currently %.2f gallons of liquid in the tank\n", answer);
  printf("%.2f gallons left before full\n", fullVol - answer);
  printf("-----------------------------------------------------\n");

}
int main( void ) {
  
  int choice;
  float height, radius, answer;

  radius = (float)MAXCAP/2;

  // createChart(radius);

  do {

    choice = menu();

    switch(choice) {

    case 1:
      createChart(radius);
      break;
    case 2:
      eval(radius);
      break;
    case 3:
      printf("exiting...\n");
    default:
      printf("Invalid input");
    }

  }while(choice != 3);
  

  return 0;

}
