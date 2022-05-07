
/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once


#include "TypeDef.h"

#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"

namespace nsGraphicEngine
{
    class DllExport TRenderableObject
    {
    public:
        TMesh* mMesh = nullptr;
        TTexture* mTexture = nullptr;

        void Draw();

    private:
    };
}