//
// Created by f on 5/2/2024.
//
#include <windows.h>
#include <XInput.h>
#include <vector>
#include "XboxPadControllSystem.h"
#include <memory>
#include <cstring>

namespace XPC
{
    /*
    void addToVector(std::pmr::vector<T>& vec, const T& value)
    {
        vec.emplace_back(value);
    }*/

    XboxPadControllSystem::XboxPadControllSystem() :
    //joystickDataCollector(std::make_unique<std::vector<SHORT>>()),
    joysticks_data_(std::make_unique<JoysticksData>()){}
    //state(std::make_unique<XINPUT_STATE>()){}
    //template<typename T>

    /*void XboxPadControllSystem::addToVector(std::vector<T>& vec, const T& value)
    {
        vec.emplace_back(value);
        //vec.push_back(value);
    }*/

    void XboxPadControllSystem::update() {
        XINPUT_STATE state;
        //ZeroMemory(state.get(), sizeof(XINPUT_STATE));
        ZeroMemory(&state, sizeof(XINPUT_STATE));
        DWORD result = XInputGetState(0, &state);
        if(result == ERROR_SUCCESS)
        {
            std::cout << "pad online" << std::endl;
            joysticks_data_->LEFTJOX = state.Gamepad.sThumbLX;
            joysticks_data_->LEFTJOY = state.Gamepad.sThumbLY;
            joysticks_data_->RIGHTJOX = state.Gamepad.sThumbRX;
            joysticks_data_->RIGHTJOY = state.Gamepad.sThumbRY;
            //SHORT leftJoyX = state->Gamepad.sThumbLX;
            //SHORT leftJoyY = state->Gamepad.sThumbLY;
            //addToVector(*joystickDataCollector, leftJoyX);
            //addToVector(*joystickDataCollector, leftJoyY);
        }else{std::cout << "pad offline" << std::endl;}
    }
    void XboxPadControllSystem::printJoystickData() {
        {
            if(joysticks_data_->LEFTJOX && joysticks_data_->LEFTJOY && joysticks_data_->RIGHTJOX && joysticks_data_->RIGHTJOY)
            {
                std::system("cls");
                std::cout << joysticks_data_->LEFTJOX<< "||" << joysticks_data_->LEFTJOY << "||"<< joysticks_data_->RIGHTJOX << "||" << joysticks_data_->RIGHTJOY << std::endl;
            }else{std::cout << "vector ptr is null pointer" << std::endl;}
        }
    }
}




//XPC::XboxPadControllSystem::~XboxPadControllSystem() {}





    /* Zapytaj o stan kontrolera dla gracza o indeksie 0
auto state = gamePad->GetState(0);
    // Jeśli kontroler jest podłączony
    if (state.IsConnected()) {
        // Pobierz pozycje drążków analogowych
        float posXLeft = state.thumbSticks.leftX;
        float posYLeft = state.thumbSticks.leftY;
        float posXRight = state.thumbSticks.rightX;
        float posYRight = state.thumbSticks.rightY;
        // Wydrukuj pozycje drążków analogowych
        std::cout << "Lewy drążek: (" << posXLeft << ", " << posYLeft << ")\n";
        std::cout << "Prawy drążek: (" << posXRight << ", " << posYRight << ")\n";
    }*/
 // XPC