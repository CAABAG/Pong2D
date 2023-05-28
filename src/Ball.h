#pragma once

#include "SFML/Graphics.hpp"
#include "WindowManager.h"
#include "Pong.h"

enum class BallDirectionY
{
    POS,
    NEG,
    NEUT
};

enum class BallDirectionX
{
    POS,
    NEG
};

class Ball
{
private:
    sf::CircleShape m_Circle;
    BallDirectionX  m_XDir;
    BallDirectionY  m_YDir;

    float m_Speed;
public:
    Ball();

    auto Update() -> void;

    auto Render() -> void { WindowManager::GetWindow().draw(m_Circle); }

    auto SetXDir(const BallDirectionX newDir) -> void { m_XDir = newDir; }
    auto SetYDir(const BallDirectionY newDir) -> void { m_YDir = newDir; }
    auto IncreaseSpeed() -> void { m_Speed += m_Speed * 0.1f; }

    auto GetPosition() -> sf::Vector2f { return m_Circle.getPosition(); }
    auto GetCircle() -> sf::CircleShape { return m_Circle; }
    auto GetYDir() -> BallDirectionY& { return m_YDir; }
};
