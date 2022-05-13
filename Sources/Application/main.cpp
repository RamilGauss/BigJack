/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <SDL_main.h>

#include "GraphicEngine.h"
#include "GraphicEngineContext.h"

#include "TextureFactory.h"
#include "ShaderFactory.h"
#include "MeshFactory.h"

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace nsGraphicEngine;

TMesh* CreateCube()
{
    auto pMesh = nsGraphicEngine::TMeshFactory::CreateEmpty();

    pMesh->AddPoint({ -0.5f, -0.5f, -0.5f,  0.0f, 0.0f });
    pMesh->AddPoint({  0.5f, -0.5f, -0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({  0.5f,  0.5f, -0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({  0.5f,  0.5f, -0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({ -0.5f,  0.5f, -0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({ -0.5f, -0.5f, -0.5f,  0.0f, 0.0f });

    pMesh->AddPoint({ -0.5f, -0.5f,  0.5f,  0.0f, 0.0f });
    pMesh->AddPoint({  0.5f, -0.5f,  0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({  0.5f,  0.5f,  0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({  0.5f,  0.5f,  0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({ -0.5f,  0.5f,  0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({ -0.5f, -0.5f,  0.5f,  0.0f, 0.0f });

    pMesh->AddPoint({ -0.5f,  0.5f,  0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({ -0.5f,  0.5f, -0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({ -0.5f, -0.5f, -0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({ -0.5f, -0.5f, -0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({ -0.5f, -0.5f,  0.5f,  0.0f, 0.0f });
    pMesh->AddPoint({ -0.5f,  0.5f,  0.5f,  1.0f, 0.0f });

    pMesh->AddPoint({  0.5f,  0.5f,  0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({  0.5f,  0.5f, -0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({  0.5f, -0.5f, -0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({  0.5f, -0.5f, -0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({  0.5f, -0.5f,  0.5f,  0.0f, 0.0f });
    pMesh->AddPoint({  0.5f,  0.5f,  0.5f,  1.0f, 0.0f });

    pMesh->AddPoint({ -0.5f, -0.5f, -0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({  0.5f, -0.5f, -0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({  0.5f, -0.5f,  0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({  0.5f, -0.5f,  0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({ -0.5f, -0.5f,  0.5f,  0.0f, 0.0f });
    pMesh->AddPoint({ -0.5f, -0.5f, -0.5f,  0.0f, 1.0f });

    pMesh->AddPoint({ -0.5f,  0.5f, -0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({  0.5f,  0.5f, -0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({  0.5f,  0.5f,  0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({  0.5f,  0.5f,  0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({ -0.5f,  0.5f,  0.5f,  0.0f, 0.0f });
    pMesh->AddPoint({ -0.5f,  0.5f, -0.5f,  0.0f, 1.0f });

    return pMesh;
}

int main(int argc, char** argv)
{
    nsGraphicEngine::TGraphicEngine ge;

    auto initResult = ge.Init();
    if (!initResult) {
        return 1;
    }

    ge.SetTitle("MMO-Framework");
    ge.SetPosition(100, 100);
    ge.SetSize(800, 600);

    auto pCtx = ge.CreateContext(TGraphicEngine::PipeLineType::SIMPLE);

    auto pCamera = pCtx->CreateCamera();
    pCamera->SetPosition({ 0, 0, 0 });
    pCamera->SetWindowSize({800, 600});

    {
        auto pObject = pCtx->CreateRenderableObject();
        auto pTexture = TTextureFactory::Load("wood.png");
        auto pMesh = CreateCube();

        pObject->SetTexture(pTexture);
        pObject->SetMesh(pMesh);

        pObject->SetPosition({ 1, 0, 3 });
        pObject->SetRotation({ 45, 45, 0 });
    }
    {
        auto pObject = pCtx->CreateRenderableObject();
        auto pTexture = TTextureFactory::Load("hole.jpg");
        auto pMesh = CreateCube();

        pObject->SetTexture(pTexture);
        pObject->SetMesh(pMesh);

        pObject->SetPosition({ -1, 0, 3 });
        pObject->SetRotation({ 45, 45, 0 });
    }
    {
        auto pObject = pCtx->CreateRenderableObject();
        auto pTexture = TTextureFactory::Load("wood.png");
        auto pMesh = CreateCube();

        pObject->SetTexture(pTexture);
        pObject->SetMesh(pMesh);

        pObject->SetPosition({ -1, 1, 5 });
        pObject->SetRotation({ 45, 45, 0 });
    }
    {
        auto pObject = pCtx->CreateRenderableObject();
        auto pTexture = TTextureFactory::Load("hole.jpg");
        auto pMesh = CreateCube();

        pObject->SetTexture(pTexture);
        pObject->SetMesh(pMesh);

        pObject->SetPosition({ 1, 1, 5 });
        pObject->SetRotation({ 45, 45, 0 });
    }

    while (true) {
        auto workResult = ge.GenerateInputEvents();
        if (!workResult) {
            break;
        }

        auto kmc = ge.GetKeyMouseContainer();

        const float X_MULTI = -0.002f;
        const float Y_MULTI = 0.002f;

        if (kmc->mouseButtonState[(int)MouseButton::LEFT]) {
            for (auto& mm : kmc->mouseMotionEvents) {
                pCamera->AddRotation({ mm.yrel * Y_MULTI, mm.xrel * X_MULTI, 0 });
            }
        }

        for (auto& key : kmc->keyEvents) {

            if (key.state != KeyState::DOWN) {
                continue;
            }

            if (key.keyCode == KeyCodes::W) {
                pCamera->AddPosition({0,0,0.05});
            }
            if (key.keyCode == KeyCodes::S) {
                pCamera->AddPosition({ 0,0, -0.05 });
            }
            if (key.keyCode == KeyCodes::A) {
                pCamera->AddPosition({ 0.05,0,0 });
            }
            if (key.keyCode == KeyCodes::D) {
                pCamera->AddPosition({ -0.05,0, 0 });
            }
            if (key.keyCode == KeyCodes::Q) {
                pCamera->AddPosition({ 0,-0.05,0 });
            }
            if (key.keyCode == KeyCodes::E) {
                pCamera->AddPosition({ 0, 0.05, 0 });
            }
        }

        ge.Draw();
    }

    return 0;
}

