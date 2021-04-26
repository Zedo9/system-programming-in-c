#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int handle;

void handler(int signum)
{
  printf("Signal SIGINT recieved\n");
  exit(0);
}

int main()
{
  struct sigaction action;
  action.sa_handler = handler;
  sigaction(SIGINT, &action, NULL);
  pause();
  exit(0);
}