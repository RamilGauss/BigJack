/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include <list>

#include "Types.h"

#include "GraphicEngine.h"
#include "IRenderable.h"
#include "Camera.h"
#include "RenderableObject.h"
#include "Light.h"

namespace nsGraphicEngine
{
    class DllExport TGraphicEngineContext
    {
        Scene3D _scene;
        Magnum::SceneGraph::DrawableGroup3D _drawables;

        std::list<TCamera*> mCameras;

    public:
        void Init(nsGraphicEngine::TGraphicEngine* pGE);

        void Work();

        // GUI
        void AddRender(nsGraphicEngine::IRenderable* pRenderable);
        void RemoveRender(nsGraphicEngine::IRenderable* pRenderable);

        TCamera* CreateCamera();
        TRenderableObject* CreateRenderableObject();
        TLight* CreateLight();

        void DestroyCamera(TCamera* pCamera);
        void DestroyRenderableObject(TRenderableObject* pRenderableObject);
        void DestroyLight(TLight* pLight);

    private:
        nsGraphicEngine::TGraphicEngine* mGE = nullptr;
    };
}