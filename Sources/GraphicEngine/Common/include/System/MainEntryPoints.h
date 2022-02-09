
#pragma once

#include "TypeDef.h"

#include "OgrePrerequisites.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PLATFORM_WINRT
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#define NOMINMAX
#include <windows.h>
#endif

namespace Demo
{
    class GameState;
    class GraphicsSystem;
    class LogicSystem;
}

namespace Demo
{
    class DllExport MainEntryPoints
    {
    public:
        static void createSystems(GameState** outGraphicsGameState, GraphicsSystem** outGraphicsSystem);

        /// Destroys the systems created via createSystems. Implementation should check for null pointers.
        static void destroySystems(GameState* graphicsGameState, GraphicsSystem* graphicsSystem);

        static const char* getWindowTitle(void);

        /// Time in seconds a frame should last in fixed timestep (e.g. to simulate
        /// physics at 60hz; set it to Frametime = 1 / 60.0). The default is 60hz
        static double Frametime();
        static void SetFrametime(double value);

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
        static INT WINAPI mainAppSingleThreaded(HINSTANCE hInst, HINSTANCE hPrevInstance,
            LPSTR strCmdLine, INT nCmdShow);
#else
        static int mainAppSingleThreaded(int argc, const char* argv[]);
#endif
    };
}

