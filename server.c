#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define PORT 8080
#define BUFFER_SIZE 1024

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    int server_socket , client_socket;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE] = {0};
    const char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello from C server!</h1>";


    if(WSAStartup(MAKEWORD(2,2), &wsa) != 0){
        printf("Winsock initialization failed. Error Code : %d", WSAGetLastError());
        return 1;
    }



    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(server_socket == INVALID_SOCKET){
        printf("Could not create socket: %d\n", WSAGetLastError());
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_address,sizeof(server_address))){
        printf("Bind failed, Error Code : %d", WSAGetLastError());
        return 1;
    }

    listen(server_socket,1);

    printf("Server is running on port %d\n", PORT);

    client_socket = accept(server_socket, NULL, NULL);
    if(client_socket == INVALID_SOCKET) {
        printf("Accept failed. Error Code :%d", WSAGetLastError());
        return 1;
    }

    send(client_socket, response, strlen(response),0);

    closesocket(client_socket);

    WSACleanup();

    return 0;
}


