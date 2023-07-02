#pragma once

#include <string>
#include <iostream>

#include <SDL3/SDL.h>
#include <imgui.h>

#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include "portable-file-dialogs.h"

class Application
{
public:
    Application(const std::string& title);

    ~Application();

    void Draw();
    void Run();

    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;
private:
};