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
public:
    Ball();

    void Update();

    void Render() { WindowManager::GetWindow().draw(m_Circle); }

    void SetXDir(const BallDirectionX newDir) { m_XDir = newDir; }
    void SetYDir(const BallDirectionY newDir) { m_YDir = newDir; }
    void IncreaseSpeed() { m_Speed += m_Speed * 0.1f; }

    sf::Vector2f GetPosition() { return m_Circle.getPosition(); }
    sf::CircleShape GetCircle() { return m_Circle; }
    BallDirectionY& GetYDir() { return m_YDir; }

private:
    sf::CircleShape m_Circle;
    BallDirectionX  m_XDir;
    BallDirectionY  m_YDir;
    float m_Speed;
};
