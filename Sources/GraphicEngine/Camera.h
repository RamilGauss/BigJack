/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

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
        TCamera();
        virtual ~TCamera();
    };
}
