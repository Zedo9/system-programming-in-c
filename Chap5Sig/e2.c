#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int handle;

void handler(int signum)
{
  printf("No input recieved in 5 seconds, Operation aborted\n");
  close(handle);
}

int main(int argc, char **argv)
{
  char s[20];
  signal(SIGALRM, handler);
  alarm(5);
  printf("S=?\n");
  scanf("%s", s);
  alarm(0);
  handle = open("JUNK", O_WRONLY | O_CREAT);
  write(handle, s, strlen(s));
  close(handle);
}