#include <stdio.h>
#include <stdlib.h>

int main(void) {
  float side;
  float length;
  float roos;

  printf("Enter length of the side of the square of land (in kilometers)\t: ");
  scanf("%f",&side);

  printf("Enter length of roads running through the square (in kilometers)\t: ");
  scanf("%f",&length);

  printf("Enter number of kangaroos living in that square\t\t: ");
  scanf("%f",&roos);

  float width;
  float constant;

  width = 10.0 / 1000.0;
  constant = 1.47;

  float square  = side * side;
  float density = roos / square;

  float area = length * width;

  float kills = density * area * constant;

  printf("Expected number of kills is\t: %f\n",kills);

  return(EXIT_SUCCESS);
}
