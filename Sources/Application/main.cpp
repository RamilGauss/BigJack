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
    ge.SetSize(800, 600);

    auto pCtx = ge.CreateContext(nsGraphicEngine::TGraphicEngine::PipeLineType::SIMPLE);

    while (true) {
        auto workResult = ge.Work();
        if (!workResult) {
            break;
        }

        static int counter = 0;

        if (counter == 10) {

            auto pCamera = pCtx->CreateCamera();
            auto pObject = pCtx->CreateRenderableObject();

            auto png = nsGraphicEngine::TTextureFactory::Load("C:\\GitHub\\magnum\\magnum-examples-2020.06\\src\\textured-triangle\\1.png");
            auto tga = nsGraphicEngine::TTextureFactory::Load("C:\\GitHub\\magnum\\magnum-examples-2020.06\\src\\textured-triangle\\stone.tga");
            auto pEmptyMesh = nsGraphicEngine::TMeshFactory::CreateEmpty();

            //struct TriangleVertex 
            //{
            //    Vector2 position;
            //    Vector2 textureCoordinates;
            //};
            //const TriangleVertex data[]
            //{
            //    {{-0.5f, -0.5f}, {0.0f, 0.0f}},
            //    {{ 0.5f, -0.5f}, {1.0f, 0.0f}},
            //    {{ 0.0f,  0.5f}, {0.5f, 1.0f}}
            //};

            //using Position = GL::Attribute<0, Vector2>;
            //using TextureCoordinates = GL::Attribute<1, Vector2>;

            //GL::Buffer buffer;
            //buffer.setData(data);
            //pEmptyMesh->setCount(3)
            //.addVertexBuffer(std::move(buffer), 0, Position{}, TextureCoordinates{});

            //pObject->mMesh = pEmptyMesh;
            //pObject->mTexture = tga;

            //pCamera->GetObject()->translate(Magnum::Vector3::zAxis(3.0f));

            //pCamera->GetCamera3D()->setAspectRatioPolicy(SceneGraph::AspectRatioPolicy::Extend)
            //    .setProjectionMatrix(Matrix4::perspectiveProjection(55.0_degf, 1.0f, 0.001f, 100.0f))
            //    .setViewport(GL::defaultFramebuffer.viewport().size());
        }
        counter++;
    }

    return 0;
}

