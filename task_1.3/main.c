#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LENGHT_STRING 100
#define MAX_ARGUMENT 100


int main() {
  char stroka[MAX_LENGHT_STRING];
  char *arg[MAX_ARGUMENT] = {0};
  int count = 0;
  char *sep;
  pid_t pid;
  int rv;

  while (1) {
    printf(">>: \n");
    fgets(stroka, sizeof(stroka), stdin);
    stroka[strlen(stroka + 1)] = '\0';

    sep = strtok(stroka, " ");

    while (sep != NULL) {
      arg[count++] = sep;
      sep = strtok(NULL, " ");
    }

    switch (pid = fork()) {
    case -1:
      perror("fork");
      exit(EXIT_FAILURE);
    case 0:
      printf("child: PID - %d\n", getpid());
      execv(arg[0], arg);
      exit(EXIT_SUCCESS);
    default:
      printf("Parent: PID - %d\n", getpid());
      wait(&rv);
      printf("Parent: RETURN STATUS FOR child - %d\n", WEXITSTATUS(rv));
    }
  }
  return 0;
}