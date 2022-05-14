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
#include "KeyMouseEventHandler.h"

namespace nsGraphicEngine
{
    class DllExport TSdl2Application
    {
        SDL_GLContext mCtx;
        SDL_Renderer* mRenderer = nullptr;
        SDL_Window* mWindow = nullptr;

        TKeyMouseEventHandler mKeyMouseEventHandler;
        TKeyMouseEventContainer mKeyMouseEventContainer;
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

        bool GenerateInputEvents();
        void Draw();

        void Done();
        const std::string GetLastError() const;

        const TKeyMouseEventContainer* GetKeyMouseContainer() const;

        SDL_GLContext GetSdlCtx() const;
        SDL_Window* GetSdlWindow() const;
    protected:
        virtual void ApplyInputEventsToGui(const std::list<SDL_Event>& events, 
            std::list<SDL_Event>& unusedEvents) = 0;

        virtual void Render() = 0;

    };
}