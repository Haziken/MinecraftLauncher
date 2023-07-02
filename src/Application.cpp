#include "Application.h"

Application::Application(const std::string &title)
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        std::cerr << "SDL_Init faled: " << SDL_GetError();
        exit(-1);
    }

    window = SDL_CreateWindow(title.c_str(), 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN);
    if(!window)
    {
        std::cerr << "SDL create window faled: " << SDL_GetError();
        exit(-1);
    }
    renderer = SDL_CreateRenderer(window, SDL_GetVideoDriver(-1), SDL_RENDERER_ACCELERATED);
    if(!renderer)
    {
        std::cerr << "SDL create renderer faled: " << SDL_GetError();
        exit(-1);
    }

    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_ShowWindow(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls

    ImGui::StyleColorsDark();
    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer3_Init(renderer);
}

Application::~Application()
{
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Application::Draw()
{
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    ImGui::ShowDemoWindow();

    

    ImGui::Render();
    SDL_SetRenderDrawColor(renderer, 69,69,69,255);
    SDL_RenderClear(renderer);
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData());
    SDL_RenderPresent(renderer);
}

void Application::Run()
{
    bool done = false;
    while(!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL3_ProcessEvent(&event);
            if (event.type == SDL_EVENT_QUIT)
                done = true;
            if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && event.window.windowID == SDL_GetWindowID(window))
                done = true;
        }
        Draw();
    }
}
