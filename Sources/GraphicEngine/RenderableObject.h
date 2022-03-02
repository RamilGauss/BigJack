
/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Types.h"

#include <Magnum/SceneGraph/Drawable.h>

namespace nsGraphicEngine
{
    class TRenderableObject : public Object3D, public Magnum::SceneGraph::Drawable3D
    {
    public:
        TRenderableObject(const std::string& prefix, Object3D* parent, SceneGraph::DrawableGroup3D* group);

        void draw(const Magnum::Matrix4& transformationMatrix, SceneGraph::Camera3D& camera) override;

    private:
        Resource<GL::Buffer> _buffer;
        Resource<GL::Mesh> _mesh;
        Resource<GL::AbstractShaderProgram, CubeMapShader> _shader;
        Resource<GL::CubeMapTexture> _texture;
    };
}