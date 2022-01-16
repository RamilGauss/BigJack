
#include "GraphicsSystem.h"
#include "PostprocessingGameState.h"

#include "OgreSceneManager.h"
#include "OgreCamera.h"
#include "OgreRoot.h"
#include "OgreConfigFile.h"
#include "Compositor/OgreCompositorManager2.h"

//Declares WinMain / main
#include "MainEntryPointHelper.h"
#include "System/Android/AndroidSystems.h"
#include "System/MainEntryPoints.h"

namespace Demo
{
    class DllExport PostprocessingGraphicsSystem : public GraphicsSystem
    {
        virtual Ogre::CompositorWorkspace* setupCompositor()
        {
            //Delegate compositor creation to the game state. It could be done here,
            //but we would later have to inform the game state about some data.
            assert( dynamic_cast<PostprocessingGameState*>(mCurrentGameState) );
            return static_cast<PostprocessingGameState*>(mCurrentGameState)->setupCompositor();
        }

        virtual void setupResources(void)
        {
            GraphicsSystem::setupResources();

            Ogre::ConfigFile cf;
            cf.load( AndroidSystems::openFile( mResourcePath + "resources2.cfg" ) );

            Ogre::String originalDataFolder = cf.getSetting( "DoNotUseAsResource", "Hlms", "" );

            if( originalDataFolder.empty() )
                originalDataFolder = AndroidSystems::isAndroid() ? "/" : "./";
            else if( *(originalDataFolder.end() - 1) != '/' )
                originalDataFolder += "/";

            const char *c_locations[6] =
            {
                "2.0/scripts/materials/TutorialSky_Postprocess",
                "2.0/scripts/materials/Postprocessing",
                "2.0/scripts/materials/Postprocessing/GLSL",
                "2.0/scripts/materials/Postprocessing/HLSL",
                "2.0/scripts/materials/Postprocessing/Metal",
                "2.0/scripts/materials/Postprocessing/SceneAssets",
            };

#if OGRE_PLATFORM != OGRE_PLATFORM_APPLE && OGRE_PLATFORM != OGRE_PLATFORM_APPLE_IOS
            Ogre::String dataFolder = originalDataFolder + "packs/cubemapsJS.zip";
#else
            Ogre::String dataFolder = originalDataFolder + "cubemapsJS.zip";
#endif
#if OGRE_PLATFORM != OGRE_PLATFORM_ANDROID
            addResourceLocation( dataFolder, "Zip", "General" );
#else
            addResourceLocation( dataFolder, "APKZip", "General" );
#endif

            for( size_t i=0; i<6; ++i )
            {
                Ogre::String dataFolder = originalDataFolder + c_locations[i];
                addResourceLocation( dataFolder, getMediaReadArchiveType(), "General" );
            }
        }

    public:
        PostprocessingGraphicsSystem( GameState *gameState ) :
            GraphicsSystem( gameState )
        {
        }
    };

    void MainEntryPoints::createSystems( GameState **outGraphicsGameState,
                                         GraphicsSystem **outGraphicsSystem,
                                         GameState **outLogicGameState,
                                         LogicSystem **outLogicSystem )
    {
        PostprocessingGameState *gfxGameState = new PostprocessingGameState(
        "This sample depends on the media files:\n"
        "   * Samples/Media/2.0/materials/Common/*.*\n"
        "   * Samples/Media/2.0/materials/Postprocessing/*.*\n"
        "   * Samples/Media/2.0/scripts/materials/TutorialSky_Postprocess/*.*\n"
        "   * Samples/Media/packs/cubemapsJS.zip\n" );

        GraphicsSystem *graphicsSystem = new PostprocessingGraphicsSystem( gfxGameState );

        gfxGameState->_notifyGraphicsSystem( graphicsSystem );

        *outGraphicsGameState = gfxGameState;
        *outGraphicsSystem = graphicsSystem;
    }

    void MainEntryPoints::destroySystems( GameState *graphicsGameState,
                                          GraphicsSystem *graphicsSystem,
                                          GameState *logicGameState,
                                          LogicSystem *logicSystem )
    {
        delete graphicsSystem;
        delete graphicsGameState;
    }

    const char* MainEntryPoints::getWindowTitle(void)
    {
        return "Postprocessing Sample";
    }
}

