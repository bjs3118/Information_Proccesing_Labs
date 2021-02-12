#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <iostream>

int main()
{
    int s = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in laddr{AF_INET, htons(4000), {0}};
    bind(s, (sockaddr*)&laddr, sizeof(laddr));

    listen(s, 16);

    uint32_t accumulator =0;
    while(1){
        int client = accept(s, nullptr, nullptr);

        uint32_t payload;
        recv(client, &payload, 4, 0);

        accumulator += payload;

        send(client, &accumulator, 4, 0);
        cout << "sent to client: " << accumulator << '\n'
        close(client);
    }

}