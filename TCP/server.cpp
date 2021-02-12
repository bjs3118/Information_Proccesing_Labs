// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <iostream>
#define PORT 8080 
int main(int argc, char const *argv[]) 
{ 
    int s, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    int hello = 69;
    // Creating socket file descriptor 
    if ((s = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        std::cerr << "socket failed" << '\n'; 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(s, (const sockaddr *)&address, sizeof(address))<0) 
    { 
        std::cerr << "bind failed" << '\n';  
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        std::cerr << ("listen") << '\n'; 
    } 
    
    uint32_t accumulator = 0;

    while(1) 
    {
        int client = accept(s, nullptr, nullptr)

        uint32_t payload;
        recv(client, &payload, 4, 0);

        accumulator += payload;

        cout << "New accumulator value = " << accumulator << endl;

        send(client, &accumulator, 4, 0);

        close(client);
    return 0; 
} 
