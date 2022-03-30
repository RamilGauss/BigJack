/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "Shader.h"

#include <Corrade/Containers/Reference.h>
#include <Corrade/Utility/Resource.h>
#include <Magnum/GL/CubeMapTexture.h>
#include <Magnum/GL/Shader.h>
#include <Magnum/GL/Version.h>

using namespace nsGraphicEngine;
using namespace Magnum;

namespace
{
    enum : Int { TextureLayer = 0 };
}

TShader::TShader()
{
    Utility::Resource rs("data");

    GL::Shader vert(GL::Version::GL330, GL::Shader::Type::Vertex);
    GL::Shader frag(GL::Version::GL330, GL::Shader::Type::Fragment);

    vert.addSource(rs.get("CubeMapShader.vert"));
    frag.addSource(rs.get("CubeMapShader.frag"));

    CORRADE_INTERNAL_ASSERT_OUTPUT(GL::Shader::compile({vert, frag}));

    attachShaders({vert, frag});

    CORRADE_INTERNAL_ASSERT_OUTPUT(link());

    _transformationProjectionMatrixUniform = uniformLocation("transformationProjectionMatrix");

    setUniform(uniformLocation("textureData"), TextureLayer);
}
//--------------------------------------------------------------------------
TShader& TShader::setTransformationProjectionMatrix(const Magnum::Matrix4& matrix)
{
    setUniform(_transformationProjectionMatrixUniform, matrix);
    return *this;
}
//--------------------------------------------------------------------------
TShader& TShader::setTexture(GL::CubeMapTexture& texture)
{
    texture.bind(TextureLayer);
    return *this;
}
//--------------------------------------------------------------------------
