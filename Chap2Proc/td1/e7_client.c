#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    char *clientToServer = "/tmp/fifoquest";
    char *serverToClient = "/tmp/fiforep";
    int serverToClientRead, clientToServerWrite;
    int dataSent, dataRecieved;
    dataSent = 5;
    clientToServerWrite = open(clientToServer, O_WRONLY);
    serverToClientRead = open(serverToClient, O_RDONLY);
    printf("\nCLIENT : Sending data=%d", dataSent);
    write(clientToServerWrite, &dataSent, 4);
    printf("\nCLIENT : Reading reponse");
    read(serverToClientRead, &dataRecieved, 4);
    printf("\nCLIENT : Data Recieved : %d", dataRecieved);
    close(clientToServerWrite);
    close(serverToClientRead);
    return 0;
}