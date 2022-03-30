/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "TypeDef.h"

#include "Types.h"

#include <Magnum/ResourceManager.h>
#include <Magnum/GL/GL.h>
#include <Magnum/SceneGraph/MatrixTransformation3D.h>
#include <Magnum/Trade/Trade.h>
#include <Corrade/Utility/Arguments.h>
#include <Corrade/Utility/Directory.h>
#include <Corrade/PluginManager/Manager.h>
#include <Magnum/GL/AbstractShaderProgram.h>
#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/Context.h>
#include <Magnum/GL/CubeMapTexture.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Extensions.h>
#include <Magnum/GL/Mesh.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/GL/Texture.h>
#include <Magnum/Platform/Sdl2Application.h>
#include <Magnum/SceneGraph/Drawable.h>
#include <Magnum/SceneGraph/Scene.h>
#include <Magnum/SceneGraph/Camera.h>
#include <Magnum/Trade/AbstractImporter.h>

namespace nsGraphicEngine
{
    class TGraphicEngineContext;

    class DllExport TGraphicEngine : public Magnum::Platform::Sdl2Application
    {
        std::list<TGraphicEngineContext*> mContexts;

    public:

        TGraphicEngine(int argc, char** argv);
        virtual ~TGraphicEngine();

        bool Init(const Magnum::Platform::Sdl2Application::Configuration& configuration);

        bool Work();

        TGraphicEngineContext* CreateContext();
        void DestroyContext(TGraphicEngineContext* pCtx);

    protected:
        void drawEvent() override;

        void viewportEvent(ViewportEvent& event) override;

        void keyPressEvent(KeyEvent& event) override;
        void keyReleaseEvent(KeyEvent& event) override;

        void mousePressEvent(MouseEvent& event) override;
        void mouseReleaseEvent(MouseEvent& event) override;
        void mouseMoveEvent(MouseMoveEvent& event) override;
        void mouseScrollEvent(MouseScrollEvent& event) override;
        void textInputEvent(TextInputEvent& event) override;
    };
}