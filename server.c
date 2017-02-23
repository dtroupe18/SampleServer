/* Sample Server Code */

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main() {

    int welcomeSocket, newSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;

    // create the socket
    // 1. Internet Domain
    // 2. Stream Socket
    // 3. Default protocol (TCP is this example)
    welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);

    // configure settings of the server address struct
    // address family = Internet
    serverAddr.sin_family = AF_INET;

    // set port number
    serverAddr.sin_port = htons(7891);

    // set ip on local host
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // set all bits of the padding field to 0
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    // bind the address struct to the socket
    bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    // listen to the socket - 5 connections max
    if (listen(welcomeSocket, 5) == 0) {
        printf("Listening.....\n");
    }
    else {
        printf("Error!\n");
    }

    // accept call creates a new socket for the incoming connection
    addr_size = sizeof serverStorage;
    newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);

    // send a message to the socket of the incoming connection
    strcpy(buffer, "Hello World\n");
    send(newSocket, buffer, 13, 0);

    return 0;
}