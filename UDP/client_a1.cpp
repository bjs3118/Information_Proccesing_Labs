#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <iostream>

int main()
{
    int s = socket(AF_INET, SOCK_DGRAM, 0);

    uint32_t addr = 0x4000a8c0;
    sockaddr_in saddr = {AF_INET, htons(4000), {addr}};

    while(1)
    {
        uint32_t val = 1;
        sendto(s, &val, sizeof(val), 0, (sockaddr*)&saddr, sizeof(saddr));

        uint32_t state;
        recvfrom(s, &state, sizeof(state), 0, nullptr, nullptr);

        std::cout << "State = " << state << '\n';
    }

}