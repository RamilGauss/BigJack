/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine.h"
#include "IRenderable.h"
#include "GraphicEngineContext.h"

using namespace nsGraphicEngine;

TGraphicEngineContext* TGraphicEngine::CreateContext(PipeLineType pipeLineType)
{
    auto pCtx = new TGraphicEngineContext();
    pCtx->Init(this);
    mContexts.push_back(pCtx);
    return pCtx;
}
//---------------------------------------------------------------------
void TGraphicEngine::DestroyContext(TGraphicEngineContext* pCtx)
{
    mContexts.remove(pCtx);
    delete pCtx;
}
//---------------------------------------------------------------------
void TGraphicEngine::Render() 
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (auto& ctx : mContexts) {
        ctx->Work();
    }
}
//---------------------------------------------------------------------
