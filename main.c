#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int c=20;
char *s[]={"し","か","の","こ","た","ん"};

void f(int i){
  if(!c&&!i)return;
  printf("%s",s[i]);
  if(i==5){
    if(rand()&1)f(4);else{c--;printf("\n");f(0);}
    return;
  }
  if(i==3){
    int v=rand()%4;
    f(v<2?v==0?0:3:2);
    return;
  }
  f(i==0?rand()&1?1:4:i==1?2:i==2?3:5);
}

int main(){srand(time(0));f(0);return 0;}