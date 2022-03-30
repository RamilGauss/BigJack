/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine.h"
#include "IRenderable.h"
#include "GraphicEngineContext.h"

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
    //std::string defaultPath;
    //if (Utility::Directory::exists(CUBEMAP_EXAMPLE_DIR))
    //    defaultPath = CUBEMAP_EXAMPLE_DIR;
    //else if (Utility::Directory::exists(CUBEMAP_EXAMPLE_INSTALL_DIR))
    //    defaultPath = CUBEMAP_EXAMPLE_INSTALL_DIR;
    //else
    //    defaultPath = Utility::Directory::path(Utility::Directory::executableLocation());

    ///* Finally, provide a way for the user to override the path */
    //Utility::Arguments args;
    //args.addFinalOptionalArgument("path", defaultPath)
    //    .setHelp("path", "directory where the +x.jpg, +y.jpg, ... files are")
    //    .addSkippedPrefix("magnum", "engine-specific options")
    //    .setGlobalHelp("Cube map rendering example")
    //    .parse(arguments.argc, arguments.argv);

    ///* Create the context after parsing arguments to avoid a flickering window
    //   in case parse() exits */
    //create(Configuration{}.setTitle("Magnum Cube Map Example"));

    //GL::Renderer::enable(GL::Renderer::Feature::DepthTest);
    //GL::Renderer::enable(GL::Renderer::Feature::FaceCulling);

    ///* Set up perspective camera */
    //(_cameraObject = new Object3D(&_scene))
    //    ->translate(Vector3::zAxis(3.0f));
    //(_camera = new SceneGraph::Camera3D(*_cameraObject))
    //    ->setAspectRatioPolicy(SceneGraph::AspectRatioPolicy::Extend)
    //    .setProjectionMatrix(Matrix4::perspectiveProjection(55.0_degf, 1.0f, 0.001f, 100.0f))
    //    .setViewport(GL::defaultFramebuffer.viewport().size());

    ///* Load image importer plugin */
    //PluginManager::Manager<Trade::AbstractImporter> manager;
    //Containers::Pointer<Trade::AbstractImporter> importer = manager.loadAndInstantiate("JpegImporter");
    //if (!importer) std::exit(1);

    //_resourceManager.set<Trade::AbstractImporter>("jpeg-importer",
    //    importer.release(), ResourceDataState::Final, ResourcePolicy::Manual);

    ///* Add objects to scene */
    //(new CubeMap(_resourceManager, args.value("path"), &_scene, &_drawables))
    //    ->scale(Vector3(20.0f));

    //(new Reflector(_resourceManager, &_scene, &_drawables))
    //    ->scale(Vector3(0.5f))
    //    .translate(Vector3::xAxis(-0.5f));

    //(new Reflector(_resourceManager, &_scene, &_drawables))
    //    ->scale(Vector3(0.3f))
    //    .rotate(37.0_degf, Vector3::xAxis())
    //    .translate(Vector3::xAxis(0.3f));

    ///* We don't need the importer anymore */
    //_resourceManager.free<Trade::AbstractImporter>();


    auto createResult = tryCreate(configuration);
    if (!createResult) {
        return false;
    }

    ///* Set up perspective camera */
    //(_cameraObject = new Object3D(&_scene))
    //    ->translate(Vector3::zAxis(3.0f));
    //(_camera = new SceneGraph::Camera3D(*_cameraObject))
    //    ->setAspectRatioPolicy(SceneGraph::AspectRatioPolicy::Extend)
    //    .setProjectionMatrix(Matrix4::perspectiveProjection(55.0_degf, 1.0f, 0.001f, 100.0f))
    //    .setViewport(GL::defaultFramebuffer.viewport().size());

    return true;
}
//---------------------------------------------------------------------
bool TGraphicEngine::Work()
{
    return mainLoopIteration();
}
//---------------------------------------------------------------------
TGraphicEngineContext* TGraphicEngine::CreateContext()
{
    auto pCtx = new TGraphicEngineContext();
    pCtx->Init(this);
    mContexts.push_back(pCtx);
    return pCtx;
}
//---------------------------------------------------------------------
void TGraphicEngine::DestroyContext(TGraphicEngineContext* pCtx)
{
    mContexts.remove(pCtx);
    delete pCtx;
}
//---------------------------------------------------------------------
void TGraphicEngine::drawEvent() 
{
    // Render to target 
    // https://doc.magnum.graphics/magnum/classMagnum_1_1GL_1_1Framebuffer.html

    GL::defaultFramebuffer.clear(GL::FramebufferClear::Depth);
    GL::defaultFramebuffer.invalidate({GL::DefaultFramebuffer::InvalidationAttachment::Color});

    // contexts
    for (auto& ctx : mContexts) {
        ctx->Work();
    }

    swapBuffers();
}
//---------------------------------------------------------------------
void TGraphicEngine::viewportEvent(ViewportEvent& event)
{
    GL::defaultFramebuffer.setViewport({{}, event.framebufferSize()});
    //_camera->setViewport(event.windowSize());
}
//---------------------------------------------------------------------
void TGraphicEngine::keyPressEvent(KeyEvent& event)
{
    //if (event.key() == KeyEvent::Key::Up)
    //    _cameraObject->rotate(-10.0_degf, _cameraObject->transformation().right().normalized());

    //else if (event.key() == KeyEvent::Key::Down)
    //    _cameraObject->rotate(10.0_degf, _cameraObject->transformation().right().normalized());

    //else if (event.key() == KeyEvent::Key::Left || event.key() == KeyEvent::Key::Right) {
    //    Float translationY = _cameraObject->transformation().translation().y();
    //    _cameraObject->translate(Vector3::yAxis(-translationY))
    //        .rotateY(event.key() == KeyEvent::Key::Left ? 10.0_degf : -10.0_degf)
    //        .translate(Vector3::yAxis(translationY));

    //} else {
    //    return;
    //}

    redraw();
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
