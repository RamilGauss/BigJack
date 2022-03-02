
/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <Magnum/ResourceManager.h>
#include <Magnum/GL/GL.h>
#include <Magnum/SceneGraph/MatrixTransformation3D.h>
#include <Magnum/Trade/Trade.h>

namespace nsGraphicEngine
{
    extern template class Magnum::ResourceManager<Magnum::GL::Mesh, Magnum::Trade::AbstractImporter, Magnum::GL::Texture2D,
        Magnum::GL::CubeMapTexture, Magnum::GL::AbstractShaderProgram>;

    using CubeMapResourceManager = 
        Magnum::ResourceManager<Magnum::GL::Mesh, Magnum::Trade::AbstractImporter, 
                                Magnum::GL::Texture2D, Magnum::GL::CubeMapTexture, 
                                Magnum::GL::AbstractShaderProgram>;
    using Object3D = Magnum::SceneGraph::Object<Magnum::SceneGraph::MatrixTransformation3D>;
    using Scene3D = Magnum::SceneGraph::Scene<Magnum::SceneGraph::MatrixTransformation3D>;
}