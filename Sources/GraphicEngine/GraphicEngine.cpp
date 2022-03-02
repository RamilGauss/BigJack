/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine.h"
#include "IRenderable.h"

#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Renderer.h>

using namespace nsGraphicEngine;
using namespace Magnum;

using namespace Math::Literals;

TGraphicEngine::TGraphicEngine(int argc, char** argv) :
    Platform::Sdl2Application(Platform::Sdl2Application::Arguments(argc, argv), NoCreate)
{
    setMinimalLoopPeriod(0);

}
//---------------------------------------------------------------------
TGraphicEngine::~TGraphicEngine()
{

}
//---------------------------------------------------------------------
bool TGraphicEngine::Init(const Platform::Sdl2Application::Configuration& configuration)
{
    auto createResult =  tryCreate(configuration);
    if (!createResult) {
        return false;
    }

    /* Set up perspective camera */
    (_cameraObject = new Object3D(&_scene))
        ->translate(Vector3::zAxis(3.0f));
    (_camera = new SceneGraph::Camera3D(*_cameraObject))
        ->setAspectRatioPolicy(SceneGraph::AspectRatioPolicy::Extend)
        .setProjectionMatrix(Matrix4::perspectiveProjection(55.0_degf, 1.0f, 0.001f, 100.0f))
        .setViewport(GL::defaultFramebuffer.viewport().size());

    return true;
}
//---------------------------------------------------------------------
bool TGraphicEngine::Work()
{
    return mainLoopIteration();
}
//---------------------------------------------------------------------
void TGraphicEngine::drawEvent() 
{
    GL::defaultFramebuffer.clear(
        GL::FramebufferClear::Color | GL::FramebufferClear::Depth);

    //_shader.setLightPosition({7.0f, 5.0f, 2.5f})
    //    .setLightColor(Color3{1.0f})
    //    .setDiffuseColor(_color)
    //    .setAmbientColor(Color3::fromHsv({_color.hue(), 1.0f, 0.3f}))
    //    .setTransformationMatrix(_transformation)
    //    .setNormalMatrix(_transformation.normalMatrix())
    //    .setProjectionMatrix(_projection)
    //    .draw(_mesh);

    // contexts
    for (auto& ctx : mContexts) {
        //ctx->Work();
    }

    // Render to target 
    // https://doc.magnum.graphics/magnum/classMagnum_1_1GL_1_1Framebuffer.html

    GL::defaultFramebuffer.clear(GL::FramebufferClear::Depth);
    GL::defaultFramebuffer.invalidate({GL::DefaultFramebuffer::InvalidationAttachment::Color});

    _camera->draw(_drawables);
    swapBuffers();
}
//---------------------------------------------------------------------
void TGraphicEngine::viewportEvent(ViewportEvent& event)
{
    Magnum::GL::defaultFramebuffer.setViewport({{}, event.framebufferSize()});
}
//---------------------------------------------------------------------
void TGraphicEngine::keyPressEvent(KeyEvent& event)
{

}
//---------------------------------------------------------------------
void TGraphicEngine::keyReleaseEvent(KeyEvent& event)
{

}
//---------------------------------------------------------------------
void TGraphicEngine::mousePressEvent(MouseEvent& event)
{

}
//---------------------------------------------------------------------
void TGraphicEngine::mouseReleaseEvent(MouseEvent& event)
{

}
//---------------------------------------------------------------------
void TGraphicEngine::mouseMoveEvent(MouseMoveEvent& event)
{

}
//---------------------------------------------------------------------
void TGraphicEngine::mouseScrollEvent(MouseScrollEvent& event)
{

}
//---------------------------------------------------------------------
void TGraphicEngine::textInputEvent(TextInputEvent& event)
{

}
//---------------------------------------------------------------------
