#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shi();
void ka();
void no();
void ko();
void ta();
void nn();

int count = 20;

int main(void)
{
  srand(time(NULL));
  shi();
  printf("\n");
  return 0;
}

void shi()
{
  if (count > 0)
  {
    printf("し");
    if (rand() & 1)
      ka();
    else
      ta();
  }
}

void ka()
{
  printf("か");
  no();
}

void no()
{
  printf("の");
  ko();
}

void ko()
{
  printf("こ");
  int v = rand() % 4;
  if (v == 0)
    shi();
  else if (v == 1)
    ko();
  else
    no();
}

void ta()
{
  printf("た");
  nn();
}

void nn()
{
  printf("ん");
  if (rand() & 1)
    ta();
  else
  {
    count--;
    printf("\n");
    shi();
  }
}