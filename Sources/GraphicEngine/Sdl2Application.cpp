/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Sdl2Application.h"

using namespace nsGraphicEngine;

bool TSdl2Application::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return false;
    }

    auto windowFlag = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    std::string title = "";
    int x = 0;
    int y = 0;
    int width = 800;
    int height = 600;
    mWindow = SDL_CreateWindow(title.c_str(), x, y, width, height, windowFlag);

    auto rendererFlag = SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE;
    mRenderer = SDL_CreateRenderer(mWindow, -1, rendererFlag);

    if (mRenderer == nullptr) {
        return false;
    }

    // Create a OpenGL context on SDL2
    mCtx = SDL_GL_CreateContext(mWindow);

    // Load GL extensions using glad
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        return false;
    }

    glEnable(GL_DEPTH_TEST);

    return true;
}
//-------------------------------------------------------------------------------
void TSdl2Application::SetTitle(const std::string& title)
{
    SDL_SetWindowTitle(mWindow, title.c_str());
}
//-------------------------------------------------------------------------------
void TSdl2Application::SetSize(int width, int height)
{
    SDL_SetWindowSize(mWindow, width, height);
}
//-------------------------------------------------------------------------------
void TSdl2Application::SetPosition(int x, int y)
{
    SDL_SetWindowPosition(mWindow, x, y);
}
//-------------------------------------------------------------------------------
const std::string TSdl2Application::GetTitle()
{
    return SDL_GetWindowTitle(mWindow);
}
//-------------------------------------------------------------------------------
int TSdl2Application::GetWidth() const
{
    int w, h;
    SDL_GetWindowSize(mWindow, &w, &h);
    return w;
}
//-------------------------------------------------------------------------------
int TSdl2Application::GetHeight() const
{
    int w, h;
    SDL_GetWindowSize(mWindow, &w, &h);
    return h;
}
//-------------------------------------------------------------------------------
int TSdl2Application::GetX() const
{
    int x, y;
    SDL_GetWindowPosition(mWindow, &x, &y);
    return x;
}
//-------------------------------------------------------------------------------
int TSdl2Application::GetY() const
{
    int x, y;
    SDL_GetWindowPosition(mWindow, &x, &y);
    return y;
}
//-------------------------------------------------------------------------------
bool TSdl2Application::Work()
{
    SDL_Event event;
    while (true) {
        auto pollResult = SDL_PollEvent(&event);

        if (event.type == SDL_QUIT) {
            return false;
        }

        HandleEvent(event);

        if (pollResult == 0) {
            break;
        }
    }

    Render();

    SDL_GL_SwapWindow(mWindow);
    return true;
}
//-------------------------------------------------------------------------------
void TSdl2Application::Done()
{
    // Destroy everything to not leak memory.
    SDL_GL_DeleteContext(mCtx);
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);

    SDL_Quit();
}
//-------------------------------------------------------------------------------
const std::string TSdl2Application::GetLastError() const
{
    return SDL_GetError();
}
//-------------------------------------------------------------------------------
