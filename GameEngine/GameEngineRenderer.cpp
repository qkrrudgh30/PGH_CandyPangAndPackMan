// GameEngineRenderer.cpp

#include "GameEngineRenderer.h"
#include "GameEngineImageManager.h"
#include "GameEngine.h"
#include <GameEngineBase/GameEngineDebug.h>

#pragma comment(lib, "msimg32.lib")

GameEngineRenderer::GameEngineRenderer()
    : Image_(nullptr)
    , PivotType_(RenderPivot::CENTER)
    , ScaleMode_(RenderScaleMode::Image)
    , TransColor_(RGB(255, 0, 255))
    , RenderImagePivot_({ 0,0 })
{
}

GameEngineRenderer::~GameEngineRenderer()
{
}

void GameEngineRenderer::SetImageScale()
{
    if (nullptr == Image_)
    {
        MsgBoxAssert("존재하지 않는 이미지로 크기를 조절하려고 했습니다.");
        return;
    }

    ScaleMode_ = RenderScaleMode::Image;
    RenderScale_ = Image_->GetScale();
    RenderImageScale_ = Image_->GetScale();
}


void GameEngineRenderer::SetImage(const std::string& _Name)
{
    GameEngineImage* FindImage = GameEngineImageManager::GetInst()->Find(_Name);
    if (nullptr == FindImage)
    {
        MsgBoxAssertString(_Name + "존재하지 않는 이미지를 랜더러에 세팅하려고 했습니다.");
        return;
    }

    Image_ = FindImage;
    SetImageScale();
}

void GameEngineRenderer::Render()
{
    if (nullptr == Image_)
    {
        MsgBoxAssert("랜더러에 이미지가 세팅되어 있지 않으면 랜더링이 안됩니다.");
        return;
    }

    float4 RenderPos = GetActor()->GetPosition() + RenderPivot_;

    switch (PivotType_)
    {
    case RenderPivot::CENTER:
        GameEngine::BackBufferImage()->TransCopy(Image_, RenderPos - RenderScale_.Half(), RenderScale_, RenderImagePivot_, RenderImageScale_, TransColor_);
        break;
    case RenderPivot::BOT:
        // GameEngine::BackBufferImage()->TransCopyCenterScale(Image_, RenderPos, RenderScale, TransColor_);
        break;
    default:
        break;
    }
}