#include "kernel/types.h"
#include "user/user.h"

void criar_processo(int classe) {
  int pid = fork(classe);
  if (pid == 0) {
    // Processo filho
    while (1) {
      printf("PID %d (classe %d) executando...\n", getpid(), classe);
    }
    exit(0); // Nunca chega aqui
  }
}

int main() {
  printf("Criando processos em diferentes classes\n");

  criar_processo(0); // Prioridade alta
  criar_processo(1);
  criar_processo(2);
  criar_processo(3); // Prioridade baixa

  sleep(5); // Deixa o pai vivo um pouco
  exit(0);
}
