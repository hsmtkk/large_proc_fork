#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  int megaBytes = atoi(argv[1]);
  size_t size = megaBytes * 1024 * 1024;
  char *ptr = malloc(size);
  if(ptr == NULL){
    printf("Error; memory allocation\n");
    exit(1);
  }
  printf("OK; memory allocation\n");

  int i;
  for(i=0 ; i<size ; i++){
    ptr[i] = rand();
  } 

  pid_t pid = fork();
  if(pid == -1){
    // failed
    perror("");
    printf("Error; fork\n");
    exit(1);
  } else if(pid == 0){
    // child
    char *path = "/bin/hostname";
    char *args[] = {"hostname", NULL};
    int exitCode = execv(path, args);
    if(exitCode < 0){
      printf("Error; execv\n");
    }
  } else {
    // parent
    printf("OK; fork\n");
    int status;
    pid_t exitPID = wait(&status);
    if(exitPID < 0){
      printf("Error; child exit\n");
    } else {
      printf("OK; child exit\n");
    }
  }
  return 0;
}

