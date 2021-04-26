#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void handler(int signum)
{
  pid_t child_pid;
  child_pid = wait(NULL);
  printf("Child %d finished execution\n", child_pid);
}

void main()
{
  struct sigaction action;
  action.sa_handler = handler;
  sigaction(SIGCHLD, &action, NULL);
  if (fork() == 0)
  {
    printf("Child process PID %d, suspending...\n", getpid());
    sleep(2);
    exit(0);
  }
  printf("Current Process PID %d\n", getpid());
  printf("Waiting for child process to finish\n");
  pause();
}