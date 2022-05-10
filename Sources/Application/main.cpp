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

    auto pCtx = ge.CreateContext(nsGraphicEngine::TGraphicEngine::PipeLineType::SIMPLE);

    auto pCamera = pCtx->CreateCamera();
    pCamera->Position = { 0, 0, 0 };

    auto pObject = pCtx->CreateRenderableObject();

    auto pTexture = nsGraphicEngine::TTextureFactory::Load("wood.png");
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

    pObject->SetTexture(pTexture);
    pObject->SetMesh(pMesh);

    pObject->SetPosition({ 0, 0, 10 });

    while (true) {
        auto workResult = ge.Work();
        if (!workResult) {
            break;
        }
    }

    return 0;
}

