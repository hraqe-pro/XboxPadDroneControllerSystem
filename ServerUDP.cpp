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
    void ServerUDP::send_to_client(SOCKET serverSocket, sockaddr_in *clientService, XPC::JoysticksData *data) //cos z tym trzeba zrobic, to dopiero szkic w którym kierunku mamy iść
    {
        sendto(serverSocket, reinterpret_cast<char*>(data), sizeof(XPC::JoysticksData), 0, (sockaddr*)clientService, sizeof(sockaddr_in));
    }

    ServerUDP::ServerUDP()
    {
        service = std::make_unique<sockaddr_in>();
        data = std::make_unique<XPC::JoysticksData>();
        sockadress_structure_ptr = std::make_unique<sockaddr>();
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) !=0)
        {
            std::cerr << "winsock not initialized" << std::endl;
            exit(1);
        }else{std::cout<<"winsock initialized" << std::endl;}
        //here we initialize WINSOCK

        auto serverSocket = INVALID_SOCKET;

        if((serverSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==INVALID_SOCKET)
        {
            std::cerr << "socket not created" << std::endl;
            closesocket(serverSocket);
            WSACleanup();
            exit(1);
        }else{std::cout << "socket created" << std::endl;}


        //here we create SOCKET

        char str[INET_ADDRSTRLEN];
        inet_pton(AF_INET, "127.0.0.1:50425", &(service->sin_addr));
        inet_ntop(AF_INET, &(service->sin_addr), str, INET_ADDRSTRLEN);
        service->sin_port = htons(50425);
        std::cout << "ip" << str << std::endl;
        //server_udp.send_to_client(serverSocket, &clientService, *data);


        if (bind(serverSocket, sockadress_structure_ptr.get(), sizeof(sockaddr_in)) == SOCKET_ERROR)
        {
            std::cerr << "bind failed" << std::endl;
            closesocket(serverSocket);
            WSACleanup();
            exit(1);
        }
        std::cout << "server is listening" << std::endl;

    }

    //void ServerUDP::send_to_client(SOCKET serverSocket, sockaddr_in *clientService, XPC::JoysticksData *data)
    //{

      //  sendto(serverSocket, reinterpret_cast<char*>(data), sizeof(XPC::JoysticksData), 0, (sockaddr*)clientService, sizeof(sockaddr_in));
    //}

    //std::unique_ptr<sockaddr_in> ServerUDP::create_socket() {return nullptr;}
} // SUDP*