#pragma once

#include "WindowManager.h"
#include "Paddle.h"
#include "Ball.h"
#include <string>

class Pong
{
private:
	int																							m_RightPlayerPoints;
	int																							m_LeftPlayerPoints;
	bool																						m_Reset;
	bool																						m_Keyboard;

	Pong() : m_RightPlayerPoints(0), m_LeftPlayerPoints(0), m_Reset(false), m_Keyboard(true)	{}
	static auto PlayGame()																		-> void;
public:
	Pong(Pong const&) = delete;
	void operator=(Pong const&) = delete;

	static auto Run()																			-> void;

	inline static auto GiveRightPlayerAPoint()													-> void { GetInstance().m_RightPlayerPoints++; }
	inline static auto GiveLeftPlayerAPoint()													-> void { GetInstance().m_LeftPlayerPoints++; }
	inline static auto Reset(const bool state)													-> void { GetInstance().m_Reset = state; }
	inline static auto SetKeyboard(const bool state)											-> void { GetInstance().m_Keyboard = state; }

	inline static auto GetInstance()															-> Pong& { static Pong instance; return instance; }
	inline static auto GetRightPlayerPoints()													-> int { return GetInstance().m_RightPlayerPoints; }
	inline static auto GetLeftPlayerPoints()													-> int { return GetInstance().m_LeftPlayerPoints; }
	inline static auto GetReset()																-> bool { return GetInstance().m_Reset; }
	inline static auto GetKeyboard()															-> bool { return GetInstance().m_Keyboard; }
};