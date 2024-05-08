//
// Created by f on 5/2/2024.
//

#ifndef XBOXPADCONTROLLSYSTEM_H
#define XBOXPADCONTROLLSYSTEM_H
#include "VectorManager.h"
#include <windows.h>
#include <XInput.h>
#include <vector>
#include "XboxPadControllSystem.h"
#include <memory>
#include <cstring>

namespace XPC
{
struct JoysticksData
{
    SHORT LEFTJOX;
    SHORT LEFTJOY;
    SHORT RIGHTJOX;
    SHORT RIGHTJOY;
};
class XboxPadControllSystem
{
    std::unique_ptr<JoysticksData> joysticks_data_;

public:
    XboxPadControllSystem();
    //~XboxPadControllSystem();

    void update();
    //template<typename T>

    //void addToVector(std::vector<T>& vec, const T& value);
    void printJoystickData();


private:
    //std::unique_ptr<std::vector<SHORT>> joystickDataCollector;
    //std::unique_ptr<XINPUT_STATE> state;
};

} // XPC

#endif //XBOXPADCONTROLLSYSTEM_H
