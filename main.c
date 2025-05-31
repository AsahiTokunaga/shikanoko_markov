#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  shi();
  return 0;
}

void shi()
{
  printf("し");
  if(rand() & 1)
    ka();
  else
    ta();
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
  int v = rand() % 3;
  if(v == 0)
    no();
  else if (v == 1)
    ko();
  else
    shi();
}

void ta()
{
  printf("た");
  nn();
}

void nn()
{
  printf("ん");
  shi();
}