
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char getGroup(double partialpressure){
  //partialpressure = 0.2;
  int groupnumber = floor(partialpressure * 10.0)+65;
  if(groupnumber >90) return '!';

  char g = (char)groupnumber;

  return g;
}

void printMax(double partialpressure){
  if(partialpressure >= 1.4){
    printf("\n\nExceeds maximal O2 pressure\t: %s\n","true");
  }
  else{
    printf("\n\nExceeds maximal O2 pressure\t: %s\n","false");
  }

  if(partialpressure >= 1.6){
    printf("Exceeds contingency O2 pressure\t: %s\n","true");
  }
  else{
    printf("Exceeds contingency O2 pressure\t: %s\n","false");
  }
}


int main(void){
  int depth;
  int oxygen;

  printf("\nEnter depth and percentage O2\t: " );

  scanf(" %d %d",&depth,&oxygen);

  double constant = 33.0;
  double ambientpressure = (depth / constant) + 1;

  printf("\nAmbient pressure\t\t: %f \n",ambientpressure);

  double partialpressure = oxygen / 100.0 * ambientpressure;

  printf("O2 pressure\t\t\t: %f \n",partialpressure);

  char group = getGroup(partialpressure);

  printf("O2 group\t\t\t: %c \n",group);

  printMax(partialpressure);

  return(EXIT_SUCCESS);
}
