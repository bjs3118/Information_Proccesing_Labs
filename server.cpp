// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <iostream>
#define PORT 8080 
int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    int hello = 69;
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        std::cerr << "socket failed" << '\n'; 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
       std::cerr << ("setsockopt") << '\n';
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        std::cerr << "bind failed" << '\n';  
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        std::cerr << ("listen") << '\n'; 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        std::cerr << "accept" << '\n'; 
    } 
    valread = read( new_socket , buffer, 1024); 

    std::cerr << buffer << '\n'; 
    send(new_socket , hello , strlen(hello) , 0 ); 

    std::cout << "Hello message sent" << '\n' ; 
    return 0; 
} 
