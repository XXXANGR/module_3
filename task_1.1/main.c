#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void print_value_arg(int argc, char *argv[]){
    for(int i = 0; i < argc; i++){
        printf("argv[%d]: %s\n", i, argv[i]);        
    }
}

int main(int argc, char *argv[]) {
  pid_t pid;
  int rv;

  switch (pid = fork()) {
    case -1:
        perror("fork");
        exit(EXIT_FAILURE);
    case 0:
        printf("CHILD: PID - %d\n", getpid());
        printf("CHILD: PPID - %d\n", getppid());
        print_value_arg(argc,argv);
        exit(EXIT_SUCCESS);

    default:
        printf("PARENT: PID - %d\n", getpid());
        printf("PARENT: CHILD PID - %d\n", pid);
        print_value_arg(argc,argv);
        wait(&rv);
        printf("PARENT: RETURN STATUS FOR CHILD - %d\n", WEXITSTATUS(rv));
  }
  exit(EXIT_SUCCESS);
}