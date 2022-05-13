
/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "RenderableObject.h"

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


using namespace nsGraphicEngine;

void TRenderableObject::SetMesh(TMesh* pMesh)
{
    mMesh = pMesh;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mMesh->GetDataSize(), mMesh->GetPointData(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::SetTexture(TTexture* pTexture)
{
    //GLenum format;
    //if (nrComponents == 1)
    //    format = GL_RED;
    //else if (nrComponents == 3)
    //    format = GL_RGB;
    //else if (nrComponents == 4)
    //    format = GL_RGBA;

    //glBindTexture(GL_TEXTURE_2D, textureID);
    //glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    //glGenerateMipmap(GL_TEXTURE_2D);


    mTexture = pTexture;

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width = mTexture->mWidth;
    int height = mTexture->mHeight;
    int nrChannels = mTexture->mBpp;

    unsigned char* data = mTexture->mData;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::Draw()
{
    glBindVertexArray(VAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glDrawArrays(GL_TRIANGLES, 0, mMesh->GetPointCount());
}
//-------------------------------------------------------------------------------------------------------
TRenderableObject::~TRenderableObject()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
//-------------------------------------------------------------------------------------------------------
glm::mat4 TRenderableObject::GetMatrix() const
{
    auto matrix = glm::mat4(1.0f);
    matrix = glm::translate(matrix, mPosition);
    matrix = glm::rotate(matrix, glm::radians(mRotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    matrix = glm::rotate(matrix, glm::radians(mRotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    matrix = glm::rotate(matrix, glm::radians(mRotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    matrix = glm::scale(matrix, mScales);

    return matrix;
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::SetPosition(const glm::vec3& pos)
{
    mPosition = pos;
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::SetRotation(const glm::vec3& angles)
{
    mRotation = angles;
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::SetScale(const glm::vec3& scales)
{
    mScales = scales;
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::AddPosition(const glm::vec3& pos)
{
    mPosition += pos;
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::AddRotation(const glm::vec3& angles)
{
    mRotation += angles;
}
//-------------------------------------------------------------------------------------------------------
void TRenderableObject::AddScale(const glm::vec3& scales)
{
    mScales += scales;
}
//-------------------------------------------------------------------------------------------------------

