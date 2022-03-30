/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Camera.h"

using namespace nsGraphicEngine;
using namespace Magnum;

TCamera::TCamera(nsGraphicEngine::Scene3D* scene3D)
{
    mObject = new Object3D(scene3D);

    mCamera3D = new SceneGraph::Camera3D(*mObject);
}
//---------------------------------------------------------------------------------------
TCamera::~TCamera()
{
    delete mObject;
    delete mCamera3D;
}
//---------------------------------------------------------------------------------------
Magnum::SceneGraph::Camera3D* TCamera::GetCamera3D()
{
    return mCamera3D;
}
//---------------------------------------------------------------------------------------
Object3D* TCamera::GetObject()
{
    return mObject;
}
//---------------------------------------------------------------------------------------