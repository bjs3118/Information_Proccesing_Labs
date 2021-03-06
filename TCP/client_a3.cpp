#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <iostream>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    sockaddr_in saddr = {AF_INET, htons(4000), {0x4000a8c0}};

    while(1)
    {
        int s = socket(AF_INET, SOCK_STREAM, 0);

        connect(s, (sockaddr*)&saddr, sizeof(saddr));

        uint32_t value = 1;
        send(s, &value, 4, 0);

        uint32_t payload;
        recv(s, &payload, 4, 0);

        std::cout << "state = " << payload << '\n';

        close(s);
    }
}