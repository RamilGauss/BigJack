/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngineContext.h"

#include <OgreOverlaySystem.h>
#include <OgreOverlayManager.h>

#include <OgreMeshManager.h>
#include <OgreMeshManager2.h>
#include <OgreMesh.h>
#include <OgreMesh2.h>

using namespace nsTornadoEngine;

void TGraphicEngineContext::Init(nsGraphicEngine::TGraphicEngine_Ogre_ImGui* pGE)
{
    mGE = pGE;

    
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::AddRender(nsGraphicEngine::IRenderable* pRenderable)
{

}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::RemoveRender(nsGraphicEngine::IRenderable* pRenderable)
{

}
//--------------------------------------------------------------------------------------------
