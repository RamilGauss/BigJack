#include <windows.h>


#include "GraphicEngine_Ogre_ImGui.h"

int WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR strCmdLine, INT nCmdShow)
{
    nsGraphicEngine::TGraphicEngine_Ogre_ImGui ge;

    auto initResult = ge.Init("", "");
    if (initResult == false) {
        return 1;
    }
    ge.Load();

    //bool isLoaded = false;
    //int counter = 0;

    while (!ge.IsNeedQuit()) {

        //if (!isLoaded && counter == 1000) {
        //    isLoaded = true;
        //}

        ge.Work();

        //counter++;
    }

    ge.Done();
    return 0;
}