/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include <list>

#include <OgreCamera.h>
#include <OgreSceneManager.h>

#include "GraphicEngine_Ogre_ImGui.h"

namespace nsTornadoEngine
{
    class DllExport TGraphicEngineContext
    {
    public:
        Ogre::SceneManager* mSceneManager = nullptr;

        std::list<Ogre::Camera*> cameras;


        void Init(nsGraphicEngine::TGraphicEngine_Ogre_ImGui* pGE);

        // GUI
        void AddRender(nsGraphicEngine::IRenderable* pRenderable);
        void RemoveRender(nsGraphicEngine::IRenderable* pRenderable);

    private:
        nsGraphicEngine::TGraphicEngine_Ogre_ImGui* mGE = nullptr;
    };
}