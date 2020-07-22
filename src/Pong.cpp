#include "Pong.h"

auto Pong::PlayGame() -> void
{
	Paddle	rightPaddle(PaddleType::PLAYER);
	Paddle	leftPaddle(PaddleType::AI);
	Ball	ball;

	sf::Font consolas;
	consolas.loadFromFile("../src/Consolas.ttf");

	sf::Text rightPlayerScore;
	sf::Text leftPlayerScore;

	rightPlayerScore.setFont(consolas);
	rightPlayerScore.setCharacterSize(24);
	rightPlayerScore.setFillColor(sf::Color::White);
	rightPlayerScore.setStyle(sf::Text::Bold);
	rightPlayerScore.setPosition(WindowManager::MapPixelsToCoords(WindowManager::PercentsToPixelsX(55.f), WindowManager::PercentsToPixelsY(5.f)));

	leftPlayerScore.setFont(consolas);
	leftPlayerScore.setCharacterSize(24);
	leftPlayerScore.setFillColor(sf::Color::White);
	leftPlayerScore.setStyle(sf::Text::Bold);
	leftPlayerScore.setPosition(WindowManager::MapPixelsToCoords(WindowManager::PercentsToPixelsX(45.f), WindowManager::PercentsToPixelsY(5.f)));
	

	while (!GetReset())
	{
		while (WindowManager::PollEvent())
		{
			switch (WindowManager::GetEvent().type)
			{
			case sf::Event::EventType::Closed:
				WindowManager::CloseWindow();
				Reset(true);
				break;
			case sf::Event::EventType::KeyPressed:
				if (WindowManager::GetEvent().key.code == sf::Keyboard::Escape)
				{
					WindowManager::CloseWindow();
					Reset(true);
				}
				else
					Pong::SetKeyboard(true);
				break;
			case sf::Event::EventType::MouseMoved:
				Pong::SetKeyboard(false);
				break;
			}
		}

		rightPaddle.Update(ball);
		leftPaddle.Update(ball);
		ball.Update();

		rightPlayerScore.setString(std::to_string(GetRightPlayerPoints()));
		leftPlayerScore.setString(std::to_string(GetLeftPlayerPoints()));

		WindowManager::ClearWindow();

		WindowManager::GetWindow().draw(rightPlayerScore);
		WindowManager::GetWindow().draw(leftPlayerScore);
		rightPaddle.Render();
		leftPaddle.Render();
		ball.Render();

		WindowManager::DisplayWindow();
	}
}

auto Pong::Run() -> void
{
	WindowManager::Create(800, 600);

	while (WindowManager::IsWindowOpen())
	{
		switch (GetReset())
		{
		case true:
			Reset(false);
			break;
		case false:
			PlayGame();
			break;
		}
	}
}