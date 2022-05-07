/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include <list>

#include "GraphicEngine.h"
#include "IRenderable.h"
#include "Camera.h"
#include "RenderableObject.h"
#include "Light.h"
#include "ImGuiContext.h"

namespace nsGraphicEngine
{
    class DllExport TGraphicEngineContext
    {
        std::list<TCamera*> mCameras;
        std::list<TRenderableObject*> mRenderableObjects;

        TImGuiContext mImGuiContext;

        TShader* mRenderableObjectShader = nullptr;
        TShader* mGuiShader = nullptr;

        TGraphicEngine* mGE = nullptr;
    public:
        virtual ~TGraphicEngineContext();

        void Init(TGraphicEngine* pGE);

        void Work();

        // GUI
        void AddRender(IRenderable* pRenderable);
        void RemoveRender(IRenderable* pRenderable);

        TCamera* CreateCamera();
        TRenderableObject* CreateRenderableObject();
        TLight* CreateLight();

        void DestroyCamera(TCamera* pCamera);
        void DestroyRenderableObject(TRenderableObject* pRenderableObject);
        void DestroyLight(TLight* pLight);

    private:

        TShader* CreateRenderableObjectShader();
    };
}