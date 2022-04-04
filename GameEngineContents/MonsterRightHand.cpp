// MonsterRightHand.cpp

#include "MonsterRightHand.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEngineInput.h>

MonsterRightHand::MonsterRightHand()
	: Speed_(100.f)
	, Scale_({32.f, 32.f})
	, Render_(nullptr)
{

}

MonsterRightHand::~MonsterRightHand()
{

}

void MonsterRightHand::Start()
{
    SetPosition(GameEngineWindow::GetScale().Half());
    SetScale({ 32, 32 });

    Render_ = CreateRenderer("MonsterRightHandPang.bmp", RenderPivot::CENTER, { 0, 0 });
    Render_->GetImage()->Cut(GetScale());
    Render_->CreateAnimation("MonsterRightHandPang.bmp", "MonsterRightHandPang", 0, 3, 0.05f);
    Render_->ChangeAnimation("MonsterRightHandPang");
}

void MonsterRightHand::Update()
{
}

void MonsterRightHand::Render()
{
}
