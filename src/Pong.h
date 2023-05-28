#pragma once

#include "WindowManager.h"
#include "Paddle.h"
#include "Ball.h"
#include <string>

class Pong
{
private:
    int m_RightPlayerPoints;
    int m_LeftPlayerPoints;
    bool m_Reset;
    bool m_Keyboard;

    Pong() : m_RightPlayerPoints(0), m_LeftPlayerPoints(0), m_Reset(false), m_Keyboard(true) {}
    static auto PlayGame() -> void;
public:
    Pong(Pong const&) = delete;
    void operator=(Pong const&) = delete;

    static auto Run() -> void;

    static auto GiveRightPlayerAPoint() -> void { GetInstance().m_RightPlayerPoints++; }
    static auto GiveLeftPlayerAPoint() -> void { GetInstance().m_LeftPlayerPoints++; }
    static auto Reset(const bool state) -> void { GetInstance().m_Reset = state; }
    static auto SetKeyboard(const bool state) -> void { GetInstance().m_Keyboard = state; }

    static auto GetInstance() -> Pong& { static Pong instance; return instance; }
    static auto GetRightPlayerPoints() -> int { return GetInstance().m_RightPlayerPoints; }
    static auto GetLeftPlayerPoints() -> int { return GetInstance().m_LeftPlayerPoints; }
    static auto GetReset() -> bool { return GetInstance().m_Reset; }
    static auto GetKeyboard() -> bool { return GetInstance().m_Keyboard; }
};
