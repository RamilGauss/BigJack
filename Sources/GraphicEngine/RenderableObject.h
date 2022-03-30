
/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once


#include <Magnum/SceneGraph/Drawable.h>

#include "TypeDef.h"

#include "Types.h"

#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"

namespace nsGraphicEngine
{
    class DllExport TRenderableObject : public Object3D, public Magnum::SceneGraph::Drawable3D
    {
    public:
        TMesh* mMesh = nullptr;
        TShader* mShader = nullptr;
        TTexture* mTexture = nullptr;


        TRenderableObject(const std::string& prefix, Object3D* parent, Magnum::SceneGraph::DrawableGroup3D* group);

        void draw(const Magnum::Matrix4& transformationMatrix, Magnum::SceneGraph::Camera3D& camera) override;

    private:
        Magnum::Resource<Magnum::GL::Buffer> _buffer;
        Magnum::Resource<Magnum::GL::Mesh> _mesh;
        Magnum::Resource<Magnum::GL::AbstractShaderProgram, TShader> _shader;
        Magnum::Resource<Magnum::GL::CubeMapTexture> _texture;
    };
}