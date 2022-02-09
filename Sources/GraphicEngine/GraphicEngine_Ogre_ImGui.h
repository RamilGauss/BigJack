/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IGraphicEngine_Ogre_ImGui.h"

#include "GraphicsSystem.h"
#include "PostprocessingGameState.h"

#define STR_NAME_GRAPHIC_ENGINE "GE"

/*
  Задачи класса: организация использования кванта времени (через Work()),
  выдача событий клавиатуры и мыши (те что не были поглощены GUI),
  отрисовка окна GUI,
  давать возможность управления камерой,
  добавление и изменение объектов.
*/

namespace nsGraphicEngine
{
    class DllExport TGraphicEngine_Ogre_ImGui :
        public IGraphicEngine_Ogre_ImGui
    {
        std::string mPathPluginCfg;
        std::string mPathOgreCfg;

        Ogre::v1::OverlaySystem* mOverlaySystem = nullptr;;

    public:
        TGraphicEngine_Ogre_ImGui();
        virtual ~TGraphicEngine_Ogre_ImGui();

        bool Init(const std::string& pathPluginCfg, const std::string& pathOgreCfg) override;
        void AddResource(const std::string& name, const std::string& type) override;

        void Work() override;
        void Done() override;

        Ogre::Root* GetRoot() override;
        Ogre::Window* GetWindow() override;


        //###
        bool IsNeedQuit();
        void Load();
        //###
    private:

        Demo::GameState* mGraphicsGameState = nullptr;
        Demo::GraphicsSystem* mGraphicsSystem = nullptr;
    };
}