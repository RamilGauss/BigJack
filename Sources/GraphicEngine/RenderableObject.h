
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
        TMesh* mMesh = nullptr;
        TTexture* mTexture = nullptr;

        unsigned int VBO = 0;
        unsigned int VAO = 0;

        unsigned int texture = 0;

        glm::mat4 mMatrix;
    public:

        virtual ~TRenderableObject();

        void SetMesh(TMesh* pMesh);
        void SetTexture(TTexture* pTexture);

        void Draw();

        const glm::mat4& GetMatrix() const;

        void SetPosition(glm::vec3 pos);
    private:
    };
}