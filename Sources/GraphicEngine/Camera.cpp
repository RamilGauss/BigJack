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
    return glm::lookAt(mPosition, mPosition + GetForward(), GetUp());
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
    glm::mat4 m = glm::eulerAngleXYZ(mRotation.x, mRotation.y, mRotation.z);
    glm::mat4 mR(1.0f);
    auto right = GetRight();
    mR = glm::rotate(mR, angles.x, right);
    m = mR * m;
    glm::extractEulerAngleXYZ(m, mRotation.x, mRotation.y, mRotation.z);

    m = glm::eulerAngleXYZ(mRotation.x, mRotation.y, mRotation.z);
    glm::mat4 mU(1.0f);
    auto up = GetUp();
    mU = glm::rotate(mU, angles.y, up);
    m = mU *m;
    glm::extractEulerAngleXYZ(m, mRotation.x, mRotation.y, mRotation.z);

    m = glm::eulerAngleXYZ(mRotation.x, mRotation.y, mRotation.z);
    glm::mat4 mF(1.0f);
    auto forward = GetForward();
    mF = glm::rotate(mF, angles.z, forward);
    m = mF * m;
    glm::extractEulerAngleXYZ(m, mRotation.x, mRotation.y, mRotation.z);
}
//-------------------------------------------------------------------------------------------------------
glm::vec3 TCamera::GetPosition() const
{
    return mPosition;
}
//-------------------------------------------------------------------------------------------------------
glm::vec3 TCamera::GetRotation() const
{
    return mRotation;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::MoveForward(float value)
{
    mPosition += GetForward() * value;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::MoveRight(float value)
{
    mPosition += GetRight() * value;
}
//-------------------------------------------------------------------------------------------------------
void TCamera::MoveUp(float value)
{
    mPosition += GetUp() * value;
}
//-------------------------------------------------------------------------------------------------------
glm::vec3 TCamera::GetRight() const
{
    auto right = glm::cross(GetUp(), GetForward());
    
    return glm::normalize(right);
}
//-------------------------------------------------------------------------------------------------------
glm::vec3 TCamera::GetForward() const
{
    glm::mat4 rotMatrix = glm::eulerAngleXYZ(mRotation.x, mRotation.y, mRotation.z);

    auto forward4 = rotMatrix * glm::vec4(glm::vec3(0.0f, 0.0f, 1.0f), 0.0f);
    auto forward = glm::vec3(forward4.x, forward4.y, forward4.z);

    return glm::normalize(forward);
}
//-------------------------------------------------------------------------------------------------------
glm::vec3 TCamera::GetUp() const
{
    glm::mat4 rotMatrix = glm::eulerAngleXYZ(mRotation.x, mRotation.y, mRotation.z);

    auto up4 = rotMatrix * glm::vec4(glm::vec3(0.0f, 1.0f, 0.0f), 0.0f);
    auto up = glm::vec3(up4.x, up4.y, up4.z);

    return glm::normalize(up);
}
//-------------------------------------------------------------------------------------------------------
