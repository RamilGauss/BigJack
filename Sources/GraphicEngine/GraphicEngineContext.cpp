/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngineContext.h"
#include "ShaderFactory.h"
#include "ShaderPrefabs.h"

using namespace nsGraphicEngine;

void TGraphicEngineContext::Init(TGraphicEngine* pGE)
{
    mGE = pGE;

    mRenderableObjectShader = CreateRenderableObjectShader();

    mImGuiContext.Init(pGE->GetSdlWindow(), pGE->GetSdlCtx());
}
//--------------------------------------------------------------------------------------------
TGraphicEngineContext::~TGraphicEngineContext()
{

}
//--------------------------------------------------------------------------------------------
TShader* TGraphicEngineContext::CreateRenderableObjectShader()
{
    auto vertexShaderText = TShaderPrefabs::GetRenderObjectVertex();
    auto fragmentShaderText = TShaderPrefabs::GetRenderObjectFragment();

    std::list<nsGraphicEngine::TShaderFactory::TParams> params;

    params.push_back({ GL_VERTEX_SHADER, vertexShaderText });
    params.push_back({ GL_FRAGMENT_SHADER, fragmentShaderText });

    auto pShader = nsGraphicEngine::TShaderFactory::Create(params);

    return pShader;
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::Render()
{
    // Draw all renderable objects
    mRenderableObjectShader->MakeCurrentInConveyer();
    mRenderableObjectShader->SetInt("texture1", 0);

    for (auto& camera : mCameras) {

        auto winSize = camera->GetWindowSize();
        auto winPos = camera->GetWindowPosition();

        glViewport(winPos.x, winPos.y, winSize.x, winSize.y);

        glm::mat4 view = camera->GetMatrix();
        glm::mat4 projection = glm::perspective(glm::radians(camera->GetZoom()), winSize.x / winSize.y, 0.1f, 100.0f);
        mRenderableObjectShader->SetMat4("view", view);
        mRenderableObjectShader->SetMat4("projection", projection);

        for (auto& renderableObject : mRenderableObjects) {
            auto model = renderableObject->GetMatrix();
            mRenderableObjectShader->SetMat4("model", model);

            renderableObject->Draw();
        }
    }
    // Draw Gui
    if (mGuiCamera) {
        auto winSize = mGuiCamera->GetWindowSize();
        auto winPos = mGuiCamera->GetWindowPosition();

        mImGuiContext.Render(winSize.x, winSize.y);
    }
}
//--------------------------------------------------------------------------------------------
TCamera* TGraphicEngineContext::CreateCamera()
{
    auto pCamera = new TCamera();
    mCameras.push_back(pCamera);
    return pCamera;
}
//--------------------------------------------------------------------------------------------
TRenderableObject* TGraphicEngineContext::CreateRenderableObject()
{
    auto pObject = new TRenderableObject();
    mRenderableObjects.push_back(pObject);
    return pObject;
}
//--------------------------------------------------------------------------------------------
TLight* TGraphicEngineContext::CreateLight()
{
    return nullptr;
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::DestroyCamera(TCamera* pCamera)
{
    mCameras.remove(pCamera);
    delete pCamera;
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::DestroyRenderableObject(TRenderableObject* pRenderableObject)
{
    mRenderableObjects.remove(pRenderableObject);
    delete pRenderableObject;
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::DestroyLight(TLight* pLight)
{

}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::HandleEvents(const std::list<SDL_Event>& events, std::list<SDL_Event>& unusedEvents)
{
    if (mGuiCamera) {
        auto pos = mGuiCamera->GetWindowPosition();

        mImGuiContext.HandleEvents(events, unusedEvents, pos.x, pos.y);
    } else {
        unusedEvents = events;
    }
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::SetGuiCamera(TCamera* pCamera)
{
    mGuiCamera = pCamera;
}
//--------------------------------------------------------------------------------------------
TCamera* TGraphicEngineContext::GetGuiCamera() const
{
    return mGuiCamera;
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::AddRender(IRenderable* pRenderable)
{
    mImGuiContext.AddRender(pRenderable);
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::RemoveRender(IRenderable* pRenderable)
{
    mImGuiContext.RemoveRender(pRenderable);
}
//--------------------------------------------------------------------------------------------