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

namespace nsTornadoEngine
{
    class DllExport TGraphicEngineContext
    {
    public:
        void Init(nsGraphicEngine::TGraphicEngine* pGE);

        // GUI
        void AddRender(nsGraphicEngine::IRenderable* pRenderable);
        void RemoveRender(nsGraphicEngine::IRenderable* pRenderable);

    private:
        nsGraphicEngine::TGraphicEngine* mGE = nullptr;
    };
}