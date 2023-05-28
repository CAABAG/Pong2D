#pragma once

#include <SFML/Graphics.hpp>

class WindowManager
{
public:
    WindowManager(WindowManager const&) = delete;
    void operator=(WindowManager const&) = delete;

    static void Create(int width, int height) { GetWindow().create(sf::VideoMode(width, height), "Pong2D"); GetWindow().setVerticalSyncEnabled(true); }
    static void CloseWindow() { GetWindow().close(); }
    static void DisplayWindow() { GetWindow().display(); }
    static void ClearWindow() { GetWindow().clear(sf::Color::Black); }
    static float PercentsToPixelsX(float percents) { return GetWindow().getSize().x * percents / 100.f; }
    static float PercentsToPixelsY(float percents) { return GetWindow().getSize().y * percents / 100.f; }
    static sf::Vector2f MapPixelsToCoords(float x, float y) { return GetWindow().mapPixelToCoords({ static_cast<int>(x), static_cast<int>(y) }); }
    static float MapXPixelsToCoords(float x) { return GetWindow().mapPixelToCoords({ static_cast<int>(x), 0 }).x; }
    static float MapYPixelsToCoords(float y) { return GetWindow().mapPixelToCoords({ 0, static_cast<int>(y) }).y; }

    static WindowManager& GetInstance() { static WindowManager instance; return instance; }
    static bool IsWindowOpen() { return GetWindow().isOpen(); }
    static sf::RenderWindow& GetWindow() { return GetInstance().m_Window; }

private:
    WindowManager() {}

    sf::RenderWindow m_Window;
    sf::Event m_Event;
};
