//
// Created by Dave on 2/22/17.
//

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    int clientSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    // create the socket
    // 1. Internet Domain
    // 2. Stream Socket
    // 3. Default protocol (TCP is this example)
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    // configure settings of the server address struct
    // address family = Internet
    serverAddr.sin_family = AF_INET;

    // set port number
    serverAddr.sin_port = htons(7891);

    // set ip on local host
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // set all bits of the padding field to 0
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    // connect the socket to the server using the address struct
    addr_size = sizeof serverAddr;
    connect(clientSocket, (struct sockaddr *) & serverAddr, addr_size);

    // read the message from the server into the buffer
    recv(clientSocket, buffer, 1024, 0);

    // print the received message
    printf("Data received: %s", buffer);

    return 0;
}