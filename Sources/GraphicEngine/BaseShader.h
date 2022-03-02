/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <Magnum/GL/AbstractShaderProgram.h>
#include <Magnum/Math/Matrix4.h>

namespace nsGraphicEngine
{
    class TBaseShader : public Magnum::GL::AbstractShaderProgram
    {
    public:
        typedef Magnum::GL::Attribute<0, Magnum::Vector3> Position;

        explicit TBaseShader();

        TBaseShader& setTransformationProjectionMatrix(const Magnum::Matrix4& matrix)
        {
            setUniform(_transformationProjectionMatrixUniform, matrix);
            return *this;
        }

        TBaseShader& setTexture(Magnum::GL::CubeMapTexture& texture);

    private:
        Int _transformationProjectionMatrixUniform;
    };
}
