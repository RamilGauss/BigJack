/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MeshFactory.h"
#include "Mesh.h"

using namespace nsGraphicEngine;

TMesh* TMeshFactory::CreateEmpty()
{
    return new TMesh();
}
//-----------------------------------------------------------------------------------------------
TMesh* TMeshFactory::CreateCube(float size)
{
    //Magnum::Primitives::cubeSolid();


    return new TMesh();
}
//-----------------------------------------------------------------------------------------------
TMesh* TMeshFactory::CreatePlate(float height, float width, float depth)
{
    return new TMesh();
}
//-----------------------------------------------------------------------------------------------
TMesh* TMeshFactory::CreateSphere(float radius, int pointCount)
{
    return new TMesh();
}
//-----------------------------------------------------------------------------------------------
TMesh* TMeshFactory::CreateCone(float height, float radius, int pointCount)
{
    return new TMesh();
}
//-----------------------------------------------------------------------------------------------
TMesh* TMeshFactory::CreateCylinder(float height, float radius, int pointCount)
{
    return new TMesh();
}
//-----------------------------------------------------------------------------------------------
void TMeshFactory::Destroy(TMesh* pMesh)
{

}
//-----------------------------------------------------------------------------------------------
