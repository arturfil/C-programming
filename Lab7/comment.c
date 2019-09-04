#include<stdio.h>

void parseInput(int c);
void parseComment(int c);

int main(void)
{
    int c,d;

    printf("/* Extract Comment */ \n");

    while ((c = getchar()) != EOF)
        parseInput(c);

    return 0;
}

void parseInput (int c) {
  int d = getchar();
  if (c == '/' && d == '*') {
    parseComment(getchar());
  }
  else if (c == '"') {
    int f;
    while ((f = getchar()) != '"') {
    }
    parseInput(d);
  }
  else {
    parseInput(d);
  }
}

void parseComment (int c) {
    int d = getchar();

    if (c != '*' && d != '/') {
      putchar(c);
      parseComment(d);
    }
    else {
      printf("\n");
      parseInput(getchar());
    }
}

