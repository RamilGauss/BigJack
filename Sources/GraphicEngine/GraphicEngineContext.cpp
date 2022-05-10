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

void TGraphicEngineContext::Init(nsGraphicEngine::TGraphicEngine* pGE)
{
    mGE = pGE;

    mRenderableObjectShader = CreateRenderableObjectShader();
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
void TGraphicEngineContext::Work()
{
    const auto SCR_WIDTH = mGE->GetWidth();
    const auto SCR_HEIGHT = mGE->GetHeight();

    mRenderableObjectShader->MakeCurrentInConveyer();

    mRenderableObjectShader->SetInt("texture1", 1);

    for (auto& camera : mCameras) {
        glm::mat4 view = camera->GetViewMatrix();
        glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        mRenderableObjectShader->SetMat4("view", view);
        mRenderableObjectShader->SetMat4("projection", projection);

        for (auto& renderableObject : mRenderableObjects) {
            auto& model = renderableObject->GetMatrix();
            mRenderableObjectShader->SetMat4("model", model);

            renderableObject->Draw();
        }
    }

    // Draw all renderable objects
    //mRenderableObjectShader
    //camera glViewport(10, 10, SCR_WIDTH - 10, SCR_HEIGHT - 10);

    // Draw Gui
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
