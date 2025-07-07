/*#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int classe= 2;
  printf("Vou criar um processo na classe %d.\n", classe);

  int pid = fork(classe); 

  if(pid == 0) {
    // Código do processo filho
    printf("Sou o filho, PID = %d\n", getpid());
    while(1){
      printf("Comendo cpu com um loop!\n");
    }
  } else if(pid > 0) {
    // Código do processo pai
    printf("Sou o pai, criei filho PID = %d\n", pid);
  } else {
    printf("fork falhou!\n");
  }

  exit(0);
}
*/

#include "kernel/types.h"
#include "user/user.h"

int main() {
  int pid = getpid();
  int count = 0;
  while (1) {
    printf("PID %d classe X executando. Count = %d\n", pid, count++);
    sleep(1); // ou yield();
  }
  exit(0);
}
