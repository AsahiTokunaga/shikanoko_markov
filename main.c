#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/random.h>

int c=0;
char *s[]={"し","か","の","こ","た","ん"};

unsigned int get_seed() {
  unsigned int seed;
  ssize_t result;
  result=getrandom(&seed,sizeof(seed),0);
  if(result<0){
    perror("getrandom failed, using time() instead\n");
    seed=(unsigned int)time(0);
  }
  return seed;
}

void f(int i){
  if(!c&&!i)return;
  printf("%s",s[i]);
  if(i==5){
    if(rand()&1)f(4);else{printf("\n");}
    return;
  }
  if(i==3){
    int v=rand()%4;
    f(v<2?v==0?0:3:2);
    return;
  }
  f(i==0?rand()&1?1:4:i==1?2:i==2?3:5);
}

int main(int argc, char** argv){
  if(argc<2){
    printf("Frequency not found. (e.g. ./main 10)\n");
    return 1;
  }
  srand(get_seed());
  c=atoi(argv[1]);
  while(c>0){
    f(0);c--;
  }
  return 0;
}