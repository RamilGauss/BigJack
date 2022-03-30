/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngineContext.h"

using namespace nsGraphicEngine;

void TGraphicEngineContext::Init(nsGraphicEngine::TGraphicEngine* pGE)
{
    mGE = pGE;
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::Work()
{
    for (auto& camera : mCameras) {
        //camera->draw(_drawables);
    }
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
TCamera* TGraphicEngineContext::CreateCamera()
{
    auto pCamera = new TCamera(&_scene);

    //(_cameraObject = new Object3D(&_scene))
    //    ->translate(Vector3::zAxis(3.0f));
    //(_camera = new SceneGraph::Camera3D(*_cameraObject))
    //    ->setAspectRatioPolicy(SceneGraph::AspectRatioPolicy::Extend)
    //    .setProjectionMatrix(Matrix4::perspectiveProjection(55.0_degf, 1.0f, 0.001f, 100.0f))
    //    .setViewport(GL::defaultFramebuffer.viewport().size());

    return pCamera;
}
//--------------------------------------------------------------------------------------------
TRenderableObject* TGraphicEngineContext::CreateRenderableObject()
{
    return nullptr;
}
//--------------------------------------------------------------------------------------------
TLight* TGraphicEngineContext::CreateLight()
{
    return nullptr;
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::DestroyCamera(TCamera* pCamera)
{

}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::DestroyRenderableObject(TRenderableObject* pRenderableObject)
{

}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::DestroyLight(TLight* pLight)
{

}
//--------------------------------------------------------------------------------------------
