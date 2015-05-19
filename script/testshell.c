#include <stdio.h>
#include <stdlib.h>

int status = 0; //exit stauts

int main(int argc, char **argv){
  char *name[] = {
    "/bin/bash",
    "-c",
    "ls | grep '.webm'",
    NULL
  };
  argv[0] = name[0];
  argv[1] = name[1];
  int pid = fork();
  if(!pid) execvp(name[0], argv);
  else{
    waitpid(pid, &status, 0);
    //TODO: zaženi bash script ki pogleda, ali se je ukaz končal z napako ali brez
    exit(status/128);
  }
  return status;
}
