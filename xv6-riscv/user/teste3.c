#include "kernel/types.h"
#include "user/user.h"

#define N 4

int child[N];

// Função que apenas consome tempo
void waste_time(){
  volatile unsigned long long i;
  printf("start (pid %d)\n", getpid());
  for (i = 0; i < 3000000000ULL; ++i);
  printf("stop (pid %d)\n", getpid());
}

int
main(int argc, char *argv[])
{
  int n, pid;
  for(n = 0; n < N; n++){
    pid = fork(n); // <- AQUI usamos fork com a classe (0 a 3)
    if(pid == 0) {
      waste_time();
      exit(0);
    }
    else child[n] = pid;
  }

  for(n = 0; n < N; n++){
    pid = wait(0);
    printf("Child pid = %d finished!\n", pid);
  }
  return 0;
}
