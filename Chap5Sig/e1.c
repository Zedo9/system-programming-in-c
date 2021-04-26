#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int n;

void handler(int signum)
{
  printf("Expiration of %d seconds...\n", n);
  fflush(stdout);
  exit(0);
}

int main(int argc, char **argv)
{
  signal(SIGALRM, handler);
  n = atoi(*(argv + 1));
  alarm(n);
  while (1)
    ;
}