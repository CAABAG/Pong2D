#include "Ball.h"

Ball::Ball() : m_XDir(BallDirectionX::NEG), m_YDir(BallDirectionY::NEUT), m_Speed(3.f)
{
	m_Circle.setRadius(WindowManager::PercentsToPixelsY(0.5f));
	m_Circle.setOrigin(m_Circle.getRadius(), m_Circle.getRadius());
	m_Circle.setPosition(WindowManager::MapPixelsToCoords(WindowManager::PercentsToPixelsX(50.f), WindowManager::PercentsToPixelsY(50.f)));
}

auto Ball::Update() -> void
{
	if (0.f > WindowManager::MapYPixelsToCoords(m_Circle.getPosition().y - m_Circle.getRadius()))
	{
		m_YDir = BallDirectionY::POS;
		IncreaseSpeed();
	}
	else if (WindowManager::GetWindow().getSize().y < WindowManager::MapYPixelsToCoords(m_Circle.getPosition().y + m_Circle.getRadius()))
	{
		m_YDir = BallDirectionY::NEG;
		IncreaseSpeed();
	}
	
	if (0.f > WindowManager::MapXPixelsToCoords(m_Circle.getPosition().x - m_Circle.getRadius()))
	{
		Pong::GiveRightPlayerAPoint();
		Pong::Reset(true);
	}
	else if (WindowManager::GetWindow().getSize().x < WindowManager::MapXPixelsToCoords(m_Circle.getPosition().x + m_Circle.getRadius()))
	{
		Pong::GiveLeftPlayerAPoint();
		Pong::Reset(true);
	}

	m_Speed = m_Speed > 6.5f ? 6.5f : m_Speed;

	switch (m_XDir)
	{
	case BallDirectionX::POS:
		switch (m_YDir)
		{
		case BallDirectionY::POS:
			m_Circle.move(m_Speed, m_Speed);
			break;
		case BallDirectionY::NEG:
			m_Circle.move(m_Speed, -m_Speed);
			break;
		case BallDirectionY::NEUT:
			m_Circle.move(m_Speed, 0.f);
			break;
		}
		break;
	case BallDirectionX::NEG:
		switch (m_YDir)
		{
		case BallDirectionY::POS:
			m_Circle.move(-m_Speed, m_Speed);
			break;
		case BallDirectionY::NEG:
			m_Circle.move(-m_Speed, -m_Speed);
			break;
		case BallDirectionY::NEUT:
			m_Circle.move(-m_Speed, 0.f);
			break;
		}
		break;
	}
}
