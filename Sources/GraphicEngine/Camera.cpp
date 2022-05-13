/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Camera.h"

#include <glm/gtx/euler_angles.hpp>

using namespace nsGraphicEngine;

void TCamera::SetZoom(float value)
{
    mZoom = value;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::SetWindowSize(const glm::vec2& value)
{
    mWindowSize = value;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::SetWindowPosition(const glm::vec2& value)
{
    mWindowPosition = value;
}
//-------------------------------------------------------------------------------------------------------
const float TCamera::GetZoom() const
{
    return mZoom;
}
//-------------------------------------------------------------------------------------------------------
const glm::vec2 TCamera::GetWindowSize() const
{
    return mWindowSize;
}
//-------------------------------------------------------------------------------------------------------
const glm::vec2 TCamera::GetWindowPosition() const
{
    return mWindowPosition;
}
//-------------------------------------------------------------------------------------------------------
glm::mat4 TCamera::GetMatrix() const
{
    glm::mat4 rotMatrix = glm::eulerAngleXYZ(mRotation.x, mRotation.y, mRotation.z);

    auto front4 = rotMatrix * glm::vec4(glm::vec3(0.0f, 0.0f, 1.0f), 0.0f);
    auto up4 = rotMatrix * glm::vec4(glm::vec3(0.0f, 1.0f, 0.0f), 0.0f);

    auto front = glm::vec3(front4.x, front4.y, front4.z);
    auto up = glm::vec3(up4.x, up4.y, up4.z);

    front = glm::normalize(front);
    up = glm::normalize(up);

    return glm::lookAt(mPosition, mPosition + front, up);
}
//-------------------------------------------------------------------------------------------------------
void TCamera::SetPosition(const glm::vec3& pos)
{
    mPosition = pos;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::SetRotation(const glm::vec3& angles)
{
    mRotation = angles;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::AddPosition(const glm::vec3& pos)
{
    mPosition += pos;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::AddRotation(const glm::vec3& angles)
{
    mRotation += angles;
}
//-------------------------------------------------------------------------------------------------------
