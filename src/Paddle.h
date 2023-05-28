#pragma once

#include "SFML/Graphics.hpp"
#include "Ball.h"

class Ball;

enum class PaddleType
{
    PLAYER,
    AI
};

class Paddle
{
public:
    Paddle(const PaddleType type);

    void Update(Ball& ball, const sf::Event& event);
    void Render() { WindowManager::GetWindow().draw(m_Rectangle); }

private:
    sf::RectangleShape m_Rectangle;
    PaddleType m_TypeOfPaddle;
    float m_BaseSpeed;
    float m_MinSpeed;
};
