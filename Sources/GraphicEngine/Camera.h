/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>

namespace nsGraphicEngine
{
    class DllExport TCamera
    {
        glm::vec3 mPosition = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 mRotation = glm::vec3(0.0f, 0.0f, 0.0f);

        glm::vec2 mWindowSize = glm::vec2(100, 100);
        glm::vec2 mWindowPosition = glm::vec2(0.0f, 0.0f);

        float mZoom = 45.0f;
    public:
        void SetZoom(float value);
        void SetWindowSize(const glm::vec2& value);
        void SetWindowPosition(const glm::vec2& value);

        const float GetZoom() const;
        const glm::vec2 GetWindowSize() const;
        const glm::vec2 GetWindowPosition() const;

        glm::mat4 GetMatrix() const;

        void SetPosition(const glm::vec3& pos);
        void SetRotation(const glm::vec3& angles);

        void AddPosition(const glm::vec3& pos);
        void AddRotation(const glm::vec3& angles);

        glm::vec3 GetPosition() const;
        glm::vec3 GetRotation() const;

        void MoveForward(float value);
        void MoveRight(float value);
        void MoveUp(float value);

    protected:
        glm::vec3 GetForward() const;
        glm::vec3 GetUp() const;
        glm::vec3 GetRight() const;
    };
}

