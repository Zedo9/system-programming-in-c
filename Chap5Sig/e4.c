#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void hi(int signum)
{
  printf("Hi!\n");
}

void bye(int signum)
{
  printf("Bye!\n");
}

int main()
{
  signal(SIGUSR1, hi);
  signal(SIGUSR2, bye);
  for (;;)
    ;
}