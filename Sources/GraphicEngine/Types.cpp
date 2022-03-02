
/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Types.h"

#include <Magnum/GL/AbstractShaderProgram.h>
#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/CubeMapTexture.h>
#include <Magnum/GL/Mesh.h>
#include <Magnum/GL/Texture.h>
#include <Magnum/Trade/AbstractImporter.h>

namespace nsGraphicEngine
{
    template class Magnum::ResourceManager<Magnum::GL::Mesh, Magnum::Trade::AbstractImporter, 
        Magnum::GL::Texture2D, Magnum::GL::CubeMapTexture, Magnum::GL::AbstractShaderProgram>;
}