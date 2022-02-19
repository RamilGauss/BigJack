//#include <windows.h>
//
//
//#include "GraphicEngine_Ogre_ImGui.h"
//#include "SdlInputHandler.h"
//
//void LoadResourses(nsGraphicEngine::TGraphicEngine_Ogre_ImGui& ge);
//
//int WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR strCmdLine, INT nCmdShow)
//{
//    nsGraphicEngine::TGraphicEngine_Ogre_ImGui ge;
//
//    auto initResult = ge.Init();
//    if (initResult == false) {
//        return 1;
//    }
//
//    bool isLoaded = false;
//    int counter = 0;
//
//    while (!ge.IsNeedQuit()) {
//
//        if (!isLoaded && counter == 20000) {
//            LoadResourses(ge);
//
//            // input
//            Demo::SdlInputHandler* inputHandler = ge.mGraphicsSystem->getInputHandler();
//            inputHandler->setGrabMousePointer(true);
//            inputHandler->setMouseVisible(false);
//            inputHandler->setMouseRelative(true);
//
//            ge.Load();
//            isLoaded = true;
//        }
//
//        ge.Work();
//
//        if (isLoaded) {
//            double timeSinceLast = 1.0 / 60.0;
//            ge.mGraphicsGameState->update(timeSinceLast);
//        }
//
//        counter++;
//    }
//
//    ge.Done();
//    return 0;
//}
//
//void LoadResourses(nsGraphicEngine::TGraphicEngine_Ogre_ImGui& ge)
//{
//    //ge.AddResource();
//    ge.mGraphicsSystem->LoadResourses();
//
//    ge.mGraphicsSystem->CreateContext();
//}


#include <SDL_main.h>

#include <Corrade/Containers/ArrayView.h>
#include <Corrade/Containers/Optional.h>
#include <Corrade/PluginManager/Manager.h>
#include <Corrade/Utility/Resource.h>
#include <Magnum/ImageView.h>
#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Mesh.h>
#include <Magnum/GL/Texture.h>
#include <Magnum/GL/TextureFormat.h>
#include <Magnum/Platform/Sdl2Application.h>
#include <Magnum/Trade/AbstractImporter.h>
#include <Magnum/Trade/ImageData.h>

#include <MagnumPlugins/TgaImporter/TgaImporter.h>

#include "TexturedTriangleShader.h"

namespace Magnum
{
    namespace Examples
    {

        class TexturedTriangleExample : public Platform::Application
        {
        public:
            explicit TexturedTriangleExample(const Arguments& arguments);

        private:
            void drawEvent() override;

            GL::Mesh _mesh;
            TexturedTriangleShader _shader;
            GL::Texture2D _texture;
        };

        TexturedTriangleExample::TexturedTriangleExample(const Arguments& arguments) :
            Platform::Application{arguments, Configuration{}
                .setTitle("Magnum Textured Triangle Example")}
        {
            struct TriangleVertex
            {
                Vector2 position;
                Vector2 textureCoordinates;
            };
            const TriangleVertex data[]{
                {{-0.5f, -0.5f}, {0.0f, 0.0f}}, /* Left position and texture coordinate */
                {{ 0.5f, -0.5f}, {1.0f, 0.0f}}, /* Right position and texture coordinate */
                {{ 0.0f,  0.5f}, {0.5f, 1.0f}}  /* Top position and texture coordinate */
            };

            GL::Buffer buffer;
            buffer.setData(data);
            _mesh.setCount(3)
                .addVertexBuffer(std::move(buffer), 0,
                    TexturedTriangleShader::Position{},
                    TexturedTriangleShader::TextureCoordinates{});

            /* Load TGA importer plugin */
            PluginManager::Manager<Trade::AbstractImporter> manager;
            Trade::TgaImporter importer;
            //Containers::Pointer<Trade::AbstractImporter> importer =
            //    manager.loadAndInstantiate("TgaImporter");
            //if (!importer) std::exit(1);

            /* Load the texture */
            //const Utility::Resource rs{"textured-triangle-data"};
            //if (!importer.openData(rs.getRaw("stone.tga")))
            if (!importer.openFile("../Media/stone.tga"))
                std::exit(2);

            /* Set texture data and parameters */
            Containers::Optional<Trade::ImageData2D> image = importer.image2D(0);
            CORRADE_INTERNAL_ASSERT(image);
            _texture.setWrapping(GL::SamplerWrapping::ClampToEdge)
                .setMagnificationFilter(GL::SamplerFilter::Linear)
                .setMinificationFilter(GL::SamplerFilter::Linear)
                .setStorage(1, GL::textureFormat(image->format()), image->size())
                .setSubImage(0, {}, * image);
        }

        void TexturedTriangleExample::drawEvent()
        {
            GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);

            using namespace Math::Literals;

            _shader
                .setColor(0xffb2b2_rgbf)
                .bindTexture(_texture)
                .draw(_mesh);

            swapBuffers();
        }

    }
}

MAGNUM_APPLICATION_MAIN(Magnum::Examples::TexturedTriangleExample)

