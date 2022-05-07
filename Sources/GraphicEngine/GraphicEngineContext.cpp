/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngineContext.h"
#include "ShaderFactory.h"

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
    std::string vertexShaderText =
        "layout (location = 0) in vec3 VertexPosition;"\
        "layout (location = 1) in vec3 VertexNormal;"\
        "layout (location = 2) in vec2 VertexTexCoord;"\
        "out vec3 Position;"\
        "out vec3 Normal;"\
        "out vec2 TexCoord;"\
        "uniform mat4 ModelViewMatrix;"\
        "uniform mat3 NormalMatrix;"\
        "uniform mat4 ProjectionMatrix;"\
        "uniform mat4 MVP;"\
        "void main()"\
        "{"\
        "    TexCoord = VertexTexCoord;"\
        "    Normal = normalize(NormalMatrix * VertexNormal);"\
        "    Position = vec3(ModelViewMatrix * vec4(VertexPosition, 1.0));"\
        "    gl_Position = MVP * vec4(VertexPosition, 1.0);"\
        "}";

    std::string fragmentShaderText =
        "in vec3 Position;"\
        "in vec3 Normal;"\
        "in vec2 TexCoord;"\
        "uniform sampler2D Tex1;"\
        "struct LightInfo "\
        "{"\
        "    vec4 Position;"\
        "    vec3 Intensity;"\
        "};"\
        "uniform LightInfo Light;"\
        "struct MaterialInfo "\
        "{"\
        "    vec3 Kd;"\
        "    vec3 Ka;"\
        "    vec3 Ks;"\
        "    float Shininess;"\
        "};"\
        "uniform MaterialInfo Material;"\
        "layout(location = 0) out vec4 FragColor;"\
        "void phongModel(vec3 pos, vec3 norm, out vec3 ambAndDiff, out vec3 spec)"\
        "{"\
        "}"\
        "void main() "\
        "{"\
        "    vec3 ambAndDiff, spec;"\
        "    vec4 texColor = texture(Tex1, TexCoord);"\
        "    phongModel(Position, Normal, ambAndDiff, spec);"\
        "    FragColor = vec4(ambAndDiff, 1.0) * texColor + vec4(spec, 1.0);"\
        "}";

    std::list<nsGraphicEngine::TShaderFactory::TParams> params;

    params.push_back({ GL_VERTEX_SHADER, {vertexShaderText} });
    params.push_back({ GL_FRAGMENT_SHADER, {fragmentShaderText} });

    auto pShader = nsGraphicEngine::TShaderFactory::Create(params);

    return pShader;
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::Work()
{
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
