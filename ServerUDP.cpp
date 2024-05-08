//
// Created by f on 5/2/2024.
//
#include <winsock2.h>
#include <iostream>
#include <memory>
#include <vector>
#include <ws2tcpip.h>
#include "VectorManager.h"
#include "ServerUDP.h"

#include <queue>

namespace SUDP
{

    ServerUDP::ServerUDP()
    {

        WSADATA wsaData;

        WORD wVersionRequested = MAKEWORD(2, 2);
        int wsaerr = WSAStartup(wVersionRequested, &wsaData);
        //here we initialize WINSOCK

        SOCKET serverSocket = INVALID_SOCKET;
        serverSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        //here we create SOCKET
        std::unique_ptr<sockaddr_in> service(new sockaddr_in);
        //service(std::make_unique<sockaddr_in>()){}
        //ervice->sin_family = AF_INET;
        //ervice->sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
        char str[INET_ADDRSTRLEN];
        inet_pton(AF_INET, "127.0.0.1", &(service->sin_addr));
        inet_ntop(AF_INET, &(service->sin_addr), str, INET_ADDRSTRLEN);
        service->sin_port = htons(8888);
        std::cout << "ip" << str << std::endl;

        std::queue<std::vector<int>> queueToSendData;
        std::vector<int> vec1 = {1, 2, 3};
        std::vector<int> vec2 = {4, 5, 6};
        //queue2D.push(vec1);
        //queue2D.push(vec2);




    }
} // SUDP