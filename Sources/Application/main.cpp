
#include "GraphicsSystem.h"
#include "LogicSystem.h"
#include "PostprocessingGameState.h"

#include "OgreSceneManager.h"
#include "OgreCamera.h"
#include "OgreRoot.h"
#include "OgreConfigFile.h"
#include "Compositor/OgreCompositorManager2.h"
#include "OgreWindow.h"
#include "OgreTimer.h"
#include "SdlInputHandler.h"

//Declares WinMain / main
#include "MainEntryPointHelper.h"
#include "System/Android/AndroidSystems.h"
#include "System/MainEntryPoints.h"

int WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR strCmdLine, INT nCmdShow)
{
    Demo::GameState* graphicsGameState = 0;
    Demo::GraphicsSystem* graphicsSystem = 0;
    Demo::GameState* logicGameState = 0;
    Demo::LogicSystem* logicSystem = 0;

    Demo::MainEntryPoints::createSystems(&graphicsGameState, &graphicsSystem,
        &logicGameState, &logicSystem);

    try {
        graphicsSystem->initialize("window");
        if (logicSystem)
            logicSystem->initialize();

        if (graphicsSystem->getQuit()) {
            if (logicSystem)
                logicSystem->deinitialize();
            graphicsSystem->deinitialize();

            Demo::MainEntryPoints::destroySystems(graphicsGameState, graphicsSystem,
                logicGameState, logicSystem);

            return 0; //User cancelled config
        }

        Ogre::Window* renderWindow = graphicsSystem->getRenderWindow();

        graphicsSystem->createScene01();
        if (logicSystem)
            logicSystem->createScene01();

        graphicsSystem->createScene02();
        if (logicSystem)
            logicSystem->createScene02();

#if OGRE_USE_SDL2
        //Do this after creating the scene for easier the debugging (the mouse doesn't hide itself)
        Demo::SdlInputHandler* inputHandler = graphicsSystem->getInputHandler();
        inputHandler->setGrabMousePointer(true);
        inputHandler->setMouseVisible(false);
        inputHandler->setMouseRelative(true);
#endif

        Ogre::Timer timer;
        Ogre::uint64 startTime = timer.getMicroseconds();
        double accumulator = Demo::MainEntryPoints::Frametime();

        double timeSinceLast = 1.0 / 60.0;

        while (!graphicsSystem->getQuit()) {
            while (accumulator >= Demo::MainEntryPoints::Frametime() && logicSystem) {
                logicSystem->beginFrameParallel();
                logicSystem->update(static_cast<float>(Demo::MainEntryPoints::Frametime()));
                logicSystem->finishFrameParallel();

                logicSystem->finishFrame();
                graphicsSystem->finishFrame();

                accumulator -= Demo::MainEntryPoints::Frametime();
            }

            graphicsSystem->beginFrameParallel();
            graphicsSystem->update(static_cast<float>(timeSinceLast));
            graphicsSystem->finishFrameParallel();
            if (!logicSystem)
                graphicsSystem->finishFrame();

            if (!renderWindow->isVisible()) {
                //Don't burn CPU cycles unnecessary when we're minimized.
                Ogre::Threads::Sleep(500);
            }

            Ogre::uint64 endTime = timer.getMicroseconds();
            timeSinceLast = (endTime - startTime) / 1000000.0;
            timeSinceLast = std::min(1.0, timeSinceLast); //Prevent from going haywire.
            accumulator += timeSinceLast;
            startTime = endTime;
        }

        graphicsSystem->destroyScene();
        if (logicSystem) {
            logicSystem->destroyScene();
            logicSystem->deinitialize();
        }
        graphicsSystem->deinitialize();

        Demo::MainEntryPoints::destroySystems(graphicsGameState, graphicsSystem,
            logicGameState, logicSystem);
    } catch (Ogre::Exception& e) {
        Demo::MainEntryPoints::destroySystems(graphicsGameState, graphicsSystem,
            logicGameState, logicSystem);
        throw e;
    } catch (...) {
        Demo::MainEntryPoints::destroySystems(graphicsGameState, graphicsSystem,
            logicGameState, logicSystem);
    }
}
