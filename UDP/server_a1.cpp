#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <iostream>

int main()
{
    int s = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in laddr{AF_INET, htons(4000), {INADDR_ANY}};
    bind(s, (const sockaddr*)&laddr, sizeof(laddr));

    uint32_t state = 0;

    while(1)
    {
        sockaddr_in raddr;
        socklen_t raddr_len=sizeof(raddr);
        uint32_t val;
        recvfrom(s, &val, sizeof(val), 0, (sockaddr*)&raddr, &raddr_len);

        state += val;

        sendto(s, &state, sizeof(state), 0, (const sockaddr*)&raddr, raddr_len);

    }


}