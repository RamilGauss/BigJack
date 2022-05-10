/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include <SDL2/SDL.h>
#include <glad/glad.h>

#include "TypeDef.h"

namespace nsGraphicEngine
{
    class DllExport TSdl2Application
    {
        SDL_GLContext mCtx;
        SDL_Renderer* mRenderer = nullptr;
        SDL_Window* mWindow = nullptr;
    public:
        virtual ~TSdl2Application() {}

        bool Init();

        void SetTitle(const std::string& title);
        void SetSize(int width, int height);
        void SetPosition(int x, int y);

        const std::string GetTitle();
        int GetWidth() const;
        int GetHeight() const;

        int GetX() const;
        int GetY() const;

        bool Work();

        void Done();
        const std::string GetLastError() const;
    protected:
        virtual void HandleEvent(const SDL_Event& event) = 0;
        virtual void Render() = 0;
    };
}