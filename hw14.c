#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

static void sighandler(int signo) {
  if(signo == SIGINT) {
    int fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    
    char msg[50];
    strncpy(msg, "Program exited due to SIGINT.");
    write(fd, msg, sizeof(msg));
    
    close(fd);
    exit(0);
  }
  else if(signo == SIGUSR1) {
    printf("PPID: %d\n", getppid());
  }
}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  
  while(1) {
    printf("PID: %d\n", getpid());
    sleep(1);
  }

  return 0;
}
