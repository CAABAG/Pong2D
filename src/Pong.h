#pragma once

#include "WindowManager.h"
#include "Paddle.h"
#include "Ball.h"
#include <string>

class Pong
{
public:
    Pong(Pong const&) = delete;
    void operator=(Pong const&) = delete;

    static void Run();

    static void GiveRightPlayerAPoint() { GetInstance().m_RightPlayerPoints++; }
    static void GiveLeftPlayerAPoint() { GetInstance().m_LeftPlayerPoints++; }
    static void Reset(const bool state) { GetInstance().m_Reset = state; }
    static void SetKeyboard(const bool state) { GetInstance().m_Keyboard = state; }

    static Pong& GetInstance() { static Pong instance; return instance; }
    static int GetRightPlayerPoints() { return GetInstance().m_RightPlayerPoints; }
    static int GetLeftPlayerPoints() { return GetInstance().m_LeftPlayerPoints; }
    static bool GetReset() { return GetInstance().m_Reset; }
    static bool GetKeyboard() { return GetInstance().m_Keyboard; }

private:
    Pong() : m_RightPlayerPoints(0), m_LeftPlayerPoints(0), m_Reset(false), m_Keyboard(true) {}
    static void PlayGame();

    int m_RightPlayerPoints;
    int m_LeftPlayerPoints;
    bool m_Reset;
    bool m_Keyboard;
};
