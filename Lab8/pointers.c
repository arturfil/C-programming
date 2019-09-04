#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef int *intPoint;
typedef int intArray[5];
typedef intPoint pointerArray[5];
#define LENGTH 5

void initialize(intArray iA, pointerArray pA) {
  srand(getpid());
  int i, j;

  for (i = 0; i < LENGTH; i++) {
    iA[i] = rand();
  }

  for (j = 0; j < LENGTH; j++) {
    pA[j] = &iA[j];
  }
}

void printInt(intArray iA) {
  int i;

  for (i = 0; i < LENGTH; i++) {
    printf(" %d : %d\n", i, iA[i]);
  }
}

void printPoint(pointerArray pA) {
  int i;
  
  for (i = 0; i < LENGTH; i++) {
    printf(" %d : %d\n", i, *pA[i]);
  }
}

void sortInt(intArray iA) {
  int j;
  int phase = 1;
  int temp;

  while (phase == 1) {
    phase = 0;

    for (j = 0; j < LENGTH - 1; j++) {
      
      if (*(iA + j) > *(iA + (j + 1))) {
        temp = *(iA + j);
        *(iA + j) = *(iA + (j + 1));
        *(iA + (j + 1)) = temp;
        phase = 1;
      }
    }
  }
}

void sortPoints(pointerArray pA) {
  int i;
  int phase = 1;
  intPoint temp;

  while (phase == 1) {
    phase = 0;

    for (i = 0; i < LENGTH - 1; i++) {

      if (*pA[i] > *pA[i + 1]) {
        temp = pA[i];
        pA[i] = pA[i + 1];
        pA[i + 1] = temp;
        phase = 1;
      }
    }
  }
}

int main() {

  intArray integers;
  pointerArray points;

  initialize(integers, points);
  printf("---- Initialized array of integers ----\n");
  printInt(integers);
  printf("---- Sorted array of pointers ----\n");
  
  sortPoints(points);
  printPoint(points);
  
  printf("---- Sorted array of integers ----\n");
  sortInt(integers);
  printInt(integers);
  
  printf("---- Array of pointers ----\n");
  printPoint(points);

  return (EXIT_SUCCESS);
}

