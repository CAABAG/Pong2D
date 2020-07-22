#include "Paddle.h"
#include "WindowManager.h"

Paddle::Paddle(const PaddleType type) : m_TypeOfPaddle(type), m_BaseSpeed(6.f), m_MinSpeed(1.f)
{
	m_Rectangle.setSize({WindowManager::PercentsToPixelsX(2.f), WindowManager::PercentsToPixelsY(10.f)});
	m_Rectangle.setOrigin(m_Rectangle.getGlobalBounds().width / 2, m_Rectangle.getGlobalBounds().height / 2);
	m_Rectangle.setFillColor(sf::Color::White);

	switch (m_TypeOfPaddle)
	{
	case PaddleType::PLAYER:
		m_Rectangle.setPosition(WindowManager::MapPixelsToCoords(WindowManager::PercentsToPixelsX(95.f), WindowManager::PercentsToPixelsY(50.f)));
		break;
	case PaddleType::AI:
		m_Rectangle.setPosition(WindowManager::MapPixelsToCoords(WindowManager::PercentsToPixelsX(5.f), WindowManager::PercentsToPixelsY(50.f)));
		break;
	}
}

auto Paddle::Update(Ball& ball) -> void
{
	if (WindowManager::MapXPixelsToCoords(m_Rectangle.getPosition().x) + m_Rectangle.getSize().x / 2 > WindowManager::MapXPixelsToCoords(ball.GetCircle().getPosition().x) &&
		WindowManager::MapXPixelsToCoords(m_Rectangle.getPosition().x) - m_Rectangle.getSize().x / 2 < WindowManager::MapXPixelsToCoords(ball.GetCircle().getPosition().x) &&
		WindowManager::MapYPixelsToCoords(m_Rectangle.getPosition().y) + m_Rectangle.getSize().y / 2 > WindowManager::MapYPixelsToCoords(ball.GetCircle().getPosition().y) &&
		WindowManager::MapYPixelsToCoords(m_Rectangle.getPosition().y) - m_Rectangle.getSize().y / 2 < WindowManager::MapYPixelsToCoords(ball.GetCircle().getPosition().y))
	{
		if ((WindowManager::MapYPixelsToCoords(m_Rectangle.getGlobalBounds().top) + m_Rectangle.getSize().y * 0.33f) > WindowManager::MapYPixelsToCoords(ball.GetPosition().y))
			ball.SetYDir(BallDirectionY::NEG);
		else if ((WindowManager::MapYPixelsToCoords(m_Rectangle.getGlobalBounds().top) + m_Rectangle.getSize().y * 0.66f) < WindowManager::MapYPixelsToCoords(ball.GetPosition().y))
			ball.SetYDir(BallDirectionY::POS);

		switch (m_TypeOfPaddle)
		{
		case PaddleType::PLAYER:
			ball.SetXDir(BallDirectionX::NEG);
			break;
		case PaddleType::AI:
			ball.SetXDir(BallDirectionX::POS);
			break;
		}

		ball.IncreaseSpeed();
	}

	switch (m_TypeOfPaddle)
	{
	case PaddleType::PLAYER:
		if (Pong::GetKeyboard())
		{
			if (WindowManager::GetEvent().type == sf::Event::EventType::KeyPressed)
			{
				switch (WindowManager::GetEvent().key.code)
				{
				case sf::Keyboard::Up:
					m_Rectangle.move(0.f, -m_BaseSpeed);
					break;
				case sf::Keyboard::Down:
					m_Rectangle.move(0.f, m_BaseSpeed);
					break;
				}
			}
		}
		else
		{
			sf::Vector2i mousePixelPos = sf::Mouse::getPosition(WindowManager::GetWindow());
			sf::Vector2f mouseCoordPos = WindowManager::GetWindow().mapPixelToCoords(mousePixelPos);

			if (mouseCoordPos.y > WindowManager::MapYPixelsToCoords(m_Rectangle.getPosition().y))
			{
				if (mouseCoordPos.y - WindowManager::MapYPixelsToCoords(m_Rectangle.getPosition().y) < 7.f)
					m_Rectangle.move(0.f, m_MinSpeed);
				else
					m_Rectangle.move(0.f, m_BaseSpeed);
			}
			else if (mouseCoordPos.y < WindowManager::MapYPixelsToCoords(m_Rectangle.getPosition().y))
			{
				if (WindowManager::MapYPixelsToCoords(m_Rectangle.getPosition().y) - mouseCoordPos.y < 7.f)
					m_Rectangle.move(0.f, -m_MinSpeed);
				else
					m_Rectangle.move(0.f, -m_BaseSpeed);
			}
		}
		break;
	case PaddleType::AI:
		if (WindowManager::MapYPixelsToCoords(ball.GetPosition().y) > WindowManager::MapYPixelsToCoords(m_Rectangle.getPosition().y))
		{
			if (WindowManager::MapYPixelsToCoords(ball.GetPosition().y) - WindowManager::MapYPixelsToCoords(m_Rectangle.getPosition().y) < 7.f)
				m_Rectangle.move(0.f, m_MinSpeed);
			else
				m_Rectangle.move(0.f, m_BaseSpeed);
		}
		else if (WindowManager::MapYPixelsToCoords(ball.GetPosition().y) < WindowManager::MapYPixelsToCoords(m_Rectangle.getPosition().y))
		{
			if (WindowManager::MapYPixelsToCoords(m_Rectangle.getPosition().y) - WindowManager::MapYPixelsToCoords(ball.GetPosition().y) < 7.f)
				m_Rectangle.move(0.f, -m_MinSpeed);
			else
				m_Rectangle.move(0.f, -m_BaseSpeed);
		}
		break;
	}
}