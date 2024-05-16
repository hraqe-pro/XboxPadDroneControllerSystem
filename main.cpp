#include <winsock2.h>
#include <iostream>
#include <memory>
#include <vector>
#include <ws2tcpip.h>
#include "VectorManager.h"
#include "ServerUDP.h"
#include "XboxPadControllSystem.h"


int main()
{

    SUDP::ServerUDP server_udp;

    //XPC::XboxPadControllSystem->joystickDataCollector();
    XPC::XboxPadControllSystem xboxController;

    /*while(true)
    {
        xboxController.update();
        xboxController.printJoystickData();
    }*/




    return 0;
}
