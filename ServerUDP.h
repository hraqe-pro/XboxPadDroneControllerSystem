//
// Created by f on 5/2/2024.
//

#ifndef SERVERUDP_H
#define SERVERUDP_H
#include "ServerUDP.h"
#include <winsock2.h>
#include <iostream>
#include <memory>
#include <vector>
#include <ws2tcpip.h>
#include "VectorManager.h"
#include "XboxPadControllSystem.h"


namespace SUDP
{

    class ServerUDP
    {
    public:
        void send_to_client(SOCKET serverSocket, sockaddr_in* clientService, XPC::JoysticksData* data);



        ServerUDP();
        //static std::unique_ptr<sockaddr_in> create_socket();
        int clientService;
        std::unique_ptr<sockaddr_in> service;
        std::unique_ptr<sockaddr> sockadress_structure_ptr;
        std::unique_ptr<XPC::JoysticksData> data;
        //auto service = std::make_unique<sockaddr_in>();
        //static void send_to_client(SOCKET serverSocket, sockaddr_in* clientService, XPC::JoysticksData* data);
        //auto clientService = std::make_unique<sockaddr_in>();
        //std::__detail::__unique_ptr_t<XPC::JoysticksData> data = std::make_unique<XPC::JoysticksData>();
    };

    inline SUDP::ServerUDP server_udp;

} // SUDP

#endif //SERVERUDP_H
