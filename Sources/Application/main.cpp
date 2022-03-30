/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <SDL_main.h>

#include "GraphicEngine.h"
#include "GraphicEngineContext.h"

int main(int argc, char** argv)
{
    nsGraphicEngine::TGraphicEngine ge(argc, argv);

    using Conf = Magnum::Platform::Sdl2Application::Configuration;

    Conf configuration;
    configuration.setTitle("MMO-Framework");
    configuration.setSize({800, 600});
    configuration.addWindowFlags(Conf::WindowFlag::Resizable);
    configuration.addWindowFlags(Conf::WindowFlag::OpenGL);

    auto initResult = ge.Init(configuration);
    if (initResult == false) {
        return 1;
    }

    auto pCtx = ge.CreateContext();

    auto pCamera = pCtx->CreateCamera();
    auto pLight = pCtx->CreateLight();
    auto pObject = pCtx->CreateRenderableObject();


    while (true) {

        auto workResult = ge.Work();
        if (!workResult) {
            break;
        }

    }

    return 0;
}

