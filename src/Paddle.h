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
private:
    sf::RectangleShape m_Rectangle;
    PaddleType m_TypeOfPaddle;
    float m_BaseSpeed;
    float m_MinSpeed;

public:
    Paddle(const PaddleType type);

    auto Update(Ball& ball, const sf::Event& event) -> void;
    inline auto Render() -> void { WindowManager::GetWindow().draw(m_Rectangle); }
};
