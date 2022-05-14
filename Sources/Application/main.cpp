/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

#include <SDL_main.h>

#include "GraphicEngine.h"
#include "GraphicEngineContext.h"

#include "TextureFactory.h"
#include "ShaderFactory.h"
#include "MeshFactory.h"

#include "GuiDemo.h"

const int W = 1024;
const int H = 800;

const int CAMERA_COUNT = 4;

using namespace nsGraphicEngine;

TCamera* pCamera[CAMERA_COUNT];

TGuiDemo g_GuiDemo;

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

void CreateContext0(TGraphicEngine& ge)
{
    auto pCtx = ge.CreateContext(TGraphicEngine::PipeLineType::SIMPLE);

    pCtx->AddRender(&g_GuiDemo);

    pCamera[0] = pCtx->CreateCamera();
    pCamera[0]->SetPosition({ 0, 0, 0 });
    pCamera[0]->SetWindowPosition({ 0 , 0 });
    pCamera[0]->SetWindowSize({ W / 2 , H / 2 });

    pCamera[1] = pCtx->CreateCamera();
    pCamera[1]->SetPosition({ 0, 0, 0 });
    pCamera[1]->SetWindowPosition({ W / 2 , 0 });
    pCamera[1]->SetWindowSize({ W / 2 , H / 2 });
    {
        auto pObject = pCtx->CreateRenderableObject();
        auto pTexture = TTextureFactory::Load("stone.tga");
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

    pCtx->SetGuiCamera(pCamera[0]);
}

void CreateContext1(TGraphicEngine& ge)
{
    auto pCtx = ge.CreateContext(TGraphicEngine::PipeLineType::SIMPLE);

    pCamera[2] = pCtx->CreateCamera();
    pCamera[2]->SetPosition({ 0, 0, 0 });
    pCamera[2]->SetWindowPosition({ 0 , H / 2 });
    pCamera[2]->SetWindowSize({ W / 2 , H / 2 });

    pCamera[3] = pCtx->CreateCamera();
    pCamera[3]->SetPosition({ 0, 0, 0 });
    pCamera[3]->SetWindowPosition({ W / 2 , H / 2 });
    pCamera[3]->SetWindowSize({ W / 2 , H / 2 });
    {
        auto pObject = pCtx->CreateRenderableObject();
        auto pTexture = TTextureFactory::Load("stone.tga");
        auto pMesh = CreateCube();

        pObject->SetTexture(pTexture);
        pObject->SetMesh(pMesh);

        pObject->SetPosition({ 1, 0, 3 });
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
}

int main(int argc, char** argv)
{
    TGraphicEngine ge;

    auto initResult = ge.Init();
    if (!initResult) {
        return 1;
    }

    ge.SetTitle("MMO-Framework");
    ge.SetPosition(100, 100);
    ge.SetSize(W, H);

    CreateContext0(ge);
    CreateContext1(ge);

    int cameraIndex = 0;

    while (true) {
        auto w = ge.GetWidth();
        auto h = ge.GetHeight();

        pCamera[0]->SetWindowPosition({ 0 , 0 });
        pCamera[0]->SetWindowSize({ w / 2 , h / 2 });

        pCamera[1]->SetWindowPosition({ w / 2 , 0 });
        pCamera[1]->SetWindowSize({ w / 2 , h / 2 });

        pCamera[2]->SetWindowPosition({ 0 , h / 2 });
        pCamera[2]->SetWindowSize({ w / 2 , h / 2 });

        pCamera[3]->SetWindowPosition({ w / 2 , h / 2 });
        pCamera[3]->SetWindowSize({ w / 2 , h / 2 });

        auto workResult = ge.GenerateInputEvents();
        if (!workResult) {
            break;
        }

        auto kmc = ge.GetKeyMouseContainer();

        const float X_MULTI = -0.002f;
        const float Y_MULTI = 0.002f;

        auto pC = pCamera[cameraIndex];

        if (kmc->mouseButtonState[(int)MouseButton::LEFT]) {
            for (auto& mm : kmc->mouseMotionEvents) {
                pC->AddRotation({ mm.yrel * Y_MULTI, mm.xrel * X_MULTI, 0 });
            }
        }

        for (auto& key : kmc->keyEvents) {

            if (key.state != KeyState::DOWN) {
                continue;
            }

            if (key.keyCode == KeyCodes::W) {
                pC->MoveForward(0.05f);
            }
            if (key.keyCode == KeyCodes::S) {
                pC->MoveForward(-0.05f);
            }
            if (key.keyCode == KeyCodes::A) {
                pC->MoveRight(0.05f);
            }
            if (key.keyCode == KeyCodes::D) {
                pC->MoveRight(-0.05f);
            }
            if (key.keyCode == KeyCodes::Q) {
                pC->MoveUp(-0.05f);
            }
            if (key.keyCode == KeyCodes::E) {
                pC->MoveUp(0.05f);
            }

            if (key.keyCode == KeyCodes::T) {
                cameraIndex++;
                cameraIndex %= CAMERA_COUNT;
            }
        }

        ge.Draw();
    }

    return 0;
}

