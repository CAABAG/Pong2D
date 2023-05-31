#include "Pong.h"

void Pong::InitializeScoreLabel(const sf::Font& font, sf::Text& label, double xCoord, double yCoord)
{
    label.setFont(font);
    label.setCharacterSize(24);
    label.setFillColor(sf::Color::White);
    label.setStyle(sf::Text::Bold);
    label.setPosition(WindowManager::MapPixelsToCoords(WindowManager::PercentsToPixelsX(xCoord), WindowManager::PercentsToPixelsY(yCoord)));
}

void Pong::PlayGame()
{
    Paddle rightPaddle(PaddleType::PLAYER);
    Paddle leftPaddle(PaddleType::AI);
    Ball ball;

    sf::Text rightPlayerScore;
    sf::Text leftPlayerScore;

    sf::Font consolas;
    consolas.loadFromFile("../src/Consolas.ttf");

    Pong::InitializeScoreLabel(consolas, rightPlayerScore, 55., 5.);
    Pong::InitializeScoreLabel(consolas, leftPlayerScore, 45., 5.);

    while (!GetReset())
    {
        sf::Event event;
        while (WindowManager::GetWindow().pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::EventType::Closed:
                WindowManager::CloseWindow();
                Reset(true);
                break;
            case sf::Event::EventType::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
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

        rightPaddle.Update(ball, event);
        leftPaddle.Update(ball, event);
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

void Pong::Run()
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
