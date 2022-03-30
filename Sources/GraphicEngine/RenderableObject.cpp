
/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "RenderableObject.h"

#include <Corrade/Containers/Optional.h>
#include <Corrade/Utility/Directory.h>
#include <Corrade/Utility/Resource.h>
#include <Magnum/ImageView.h>
#include <Magnum/Mesh.h>
#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/Mesh.h>
#include <Magnum/GL/CubeMapTexture.h>
#include <Magnum/GL/Texture.h>
#include <Magnum/GL/TextureFormat.h>
#include <Magnum/Math/Functions.h>
#include <Magnum/MeshTools/Compile.h>
#include <Magnum/MeshTools/FlipNormals.h>
#include <Magnum/MeshTools/Reference.h>
#include <Magnum/Primitives/Cube.h>
#include <Magnum/SceneGraph/Scene.h>
#include <Magnum/SceneGraph/Camera.h>
#include <Magnum/Trade/AbstractImporter.h>
#include <Magnum/Trade/ImageData.h>
#include <Magnum/Trade/MeshData.h>

using namespace nsGraphicEngine;

using namespace Magnum;


TRenderableObject::TRenderableObject(const std::string& prefix, Object3D* parent, SceneGraph::DrawableGroup3D* group) :
    Object3D(parent), SceneGraph::Drawable3D(*this, group)
{

}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::draw(const Matrix4& transformationMatrix, SceneGraph::Camera3D& camera)
{

}
//-------------------------------------------------------------------------------------------------------
