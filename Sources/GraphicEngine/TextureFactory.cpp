/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <algorithm>
#include <string>

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

#include "TextureFactory.h"
#include "Texture.h"

using namespace nsGraphicEngine;

TTexture* TTextureFactory::Load(const std::string& absPath)
{
    int width, height, bpp;
    unsigned char* data = stbi_load(absPath.c_str(), &width, &height, &bpp, STBI_rgb_alpha);
    if (!data) {
        return nullptr;
    }

    auto pTexture = new TTexture();

    pTexture->mWidth = width;
    pTexture->mHeight = height;
    pTexture->mBpp = bpp;

    pTexture->mData = new unsigned char[pTexture->GetSize()];
    memcpy(pTexture->mData, data, pTexture->GetSize());

    stbi_image_free(data);

    return pTexture;
}
//----------------------------------------------------------------------------------------------
bool TTextureFactory::Save(TTexture* pTexture, const std::string& absPath)
{
    return false;
}
//----------------------------------------------------------------------------------------------
void TTextureFactory::Unload(TTexture* pTexture)
{
    delete pTexture;
}
//----------------------------------------------------------------------------------------------
