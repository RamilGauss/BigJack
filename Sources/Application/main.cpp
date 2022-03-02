#include <SDL_main.h>

#include "GraphicEngine.h"

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


    while (true) {

        auto workResult = ge.Work();
        if (!workResult) {
            break;
        }

    }

    return 0;
}

