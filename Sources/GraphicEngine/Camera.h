/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "Types.h"

#include <Magnum/SceneGraph/Camera.h>

namespace nsGraphicEngine
{
    class DllExport TCamera
    {
        Magnum::SceneGraph::Camera3D* mCamera3D = nullptr;

        Object3D* mObject = nullptr;

    public:

        TCamera(nsGraphicEngine::Scene3D* scene3D);

        virtual ~TCamera();

        Magnum::SceneGraph::Camera3D* GetCamera3D();

        Object3D* GetObject();
    };
}
