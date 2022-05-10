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
        glm::dmat4x4 mMatrix;

        glm::dvec2 mWindowSize;
        glm::dvec2 mWindowPosition;

    public:
        // Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
        enum Camera_Movement 
        {
            FORWARD,
            BACKWARD,
            LEFT,
            RIGHT
        };

        // Default camera values
        static constexpr float YAW = -90.0f;
        static constexpr float PITCH = 0.0f;
        static constexpr float SPEED = 2.5f;
        static constexpr float SENSITIVITY = 0.1f;
        static constexpr float ZOOM = 45.0f;

        // camera Attributes
        glm::vec3 Position;
        glm::vec3 Front;
        glm::vec3 Up;
        glm::vec3 Right;
        glm::vec3 WorldUp;
        // euler Angles
        float Yaw;
        float Pitch;
        // camera options
        float MovementSpeed;
        float MouseSensitivity;
        float Zoom;

        // constructor with vectors
        TCamera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), 
                glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), 
                float yaw = YAW, 
                float pitch = PITCH);
        TCamera(float posX, float posY, float posZ, 
                float upX,  float upY,  float upZ, 
                float yaw, float pitch);

        // returns the view matrix calculated using Euler Angles and the LookAt Matrix
        glm::mat4 GetViewMatrix();

        // processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
        void ProcessKeyboard(Camera_Movement direction, float deltaTime);
        // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
        void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
        // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
        void ProcessMouseScroll(float yoffset);

        virtual ~TCamera();
    private:
        // calculates the front vector from the Camera's (updated) Euler Angles
        void updateCameraVectors();
    };
}

