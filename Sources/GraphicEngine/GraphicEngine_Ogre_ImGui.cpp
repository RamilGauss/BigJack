/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine_Ogre_ImGui.h"
#include "IRenderable.h"


#include "OgreArchiveManager.h"
#include "OgreCamera.h"
#include "OgreConfigFile.h"
#include "OgreRoot.h"
#include "OgreWindow.h"

#include "OgreHlmsManager.h"
#include "OgreHlmsPbs.h"
#include "OgreHlmsUnlit.h"

#include "Compositor/OgreCompositorManager2.h"

#include "OgreWindowEventUtilities.h"

#include "OgreSceneManager.h"
#include "OgreCamera.h"
#include "OgreRoot.h"
#include "OgreConfigFile.h"
#include "Compositor/OgreCompositorManager2.h"
#include "OgreWindow.h"
#include "OgreTimer.h"
#include "SdlInputHandler.h"

//Declares WinMain / main
#include "System/Android/AndroidSystems.h"
#include "System/MainEntryPoints.h"


using namespace nsGraphicEngine;

//---------------------------------------------------------------------
TGraphicEngine_Ogre_ImGui::TGraphicEngine_Ogre_ImGui()
{

}
//---------------------------------------------------------------------
TGraphicEngine_Ogre_ImGui::~TGraphicEngine_Ogre_ImGui()
{

}
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::Init(const std::string& pathPluginCfg, const std::string& pathOgreCfg)
{
    mPathPluginCfg = pathPluginCfg;
    mPathOgreCfg = pathOgreCfg;

    Demo::MainEntryPoints::createSystems(&mGraphicsGameState, &mGraphicsSystem);

    try {
        mGraphicsSystem->initialize("window");

        if (mGraphicsSystem->getQuit()) {
            mGraphicsSystem->deinitialize();

            Demo::MainEntryPoints::destroySystems(mGraphicsGameState, mGraphicsSystem);
            return false; //User cancelled config
        }

        //Do this after creating the scene for easier the debugging (the mouse doesn't hide itself)
        Demo::SdlInputHandler* inputHandler = mGraphicsSystem->getInputHandler();
        inputHandler->setGrabMousePointer(true);
        inputHandler->setMouseVisible(false);
        inputHandler->setMouseRelative(true);
    } catch (Ogre::Exception& e) {
        Demo::MainEntryPoints::destroySystems(mGraphicsGameState, mGraphicsSystem);
        throw e;
    } catch (...) {
        Demo::MainEntryPoints::destroySystems(mGraphicsGameState, mGraphicsSystem);
    }

    return true;
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::AddResource(const std::string& name, const std::string& type)
{
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, type);
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::Load()
{
    mGraphicsSystem->createScene01();
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::Work()
{
    Ogre::Window* renderWindow = mGraphicsSystem->getRenderWindow();

    Ogre::Timer timer;
    Ogre::uint64 startTime = timer.getMicroseconds();
    double accumulator = Demo::MainEntryPoints::Frametime();

    double timeSinceLast = 1.0 / 60.0;

    mGraphicsSystem->beginFrameParallel();
    mGraphicsSystem->update(static_cast<float>(timeSinceLast));
    mGraphicsSystem->finishFrameParallel();
    mGraphicsSystem->finishFrame();

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
//---------------------------------------------------------------------
bool TGraphicEngine_Ogre_ImGui::IsNeedQuit()
{
    return mGraphicsSystem->getQuit();
}
//---------------------------------------------------------------------
void TGraphicEngine_Ogre_ImGui::Done()
{
    mGraphicsSystem->destroyScene();
    mGraphicsSystem->deinitialize();

    Demo::MainEntryPoints::destroySystems(mGraphicsGameState, mGraphicsSystem);
}
//---------------------------------------------------------------------
Ogre::Root* TGraphicEngine_Ogre_ImGui::GetRoot()
{
    return mGraphicsSystem->getRoot();
}
//---------------------------------------------------------------------
Ogre::Window* TGraphicEngine_Ogre_ImGui::GetWindow()
{
    return mGraphicsSystem->getRenderWindow();
}
//---------------------------------------------------------------------
