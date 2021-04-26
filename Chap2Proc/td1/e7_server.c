#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    char *clientToServer = "/tmp/fifoquest";
    char *serverToClient = "/tmp/fiforep";
    int serverToClientWrite, clientToServerRead;
    int dataSent, dataRecieved;
    mkfifo(clientToServer, 0606);
    mkfifo(serverToClient, 0606);
    clientToServerRead = open(clientToServer, O_RDONLY);
    serverToClientWrite = open(serverToClient, O_WRONLY);
    read(clientToServerRead, &dataRecieved, 4);
    printf("\nSERVER : Data Recieved : %d", dataRecieved);
    dataSent = dataRecieved * 2;
    printf("\nSERVER : Sending Data=%d", dataSent);
    write(serverToClientWrite, &dataSent, 4);
    close(clientToServerRead);
    close(serverToClientWrite);
    return 0;
}