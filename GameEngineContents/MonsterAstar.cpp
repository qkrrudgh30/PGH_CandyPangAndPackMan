// MonsterAstar.cpp

#include "MonsterAstar.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEngineInput.h>

MonsterAstar::MonsterAstar()
	: Speed_(100.f)
	, Scale_({32.f, 32.f})
	, Render_(nullptr)
{

}

MonsterAstar::~MonsterAstar()
{

}

void MonsterAstar::Start()
{
    SetPosition({200.f, 200.f});
    SetScale({ 32, 32 });

    Render_ = CreateRenderer("MonsterAStar.bmp", RenderPivot::CENTER, { 0, 0 });
    Render_->GetImage()->Cut({ 32, 32 });
    Render_->CreateAnimation("MonsterAStar.bmp", "MonsterAStarUp", 0, 5, 0.05f);
    Render_->CreateAnimation("MonsterAStar.bmp", "MonsterAStarDown", 6, 11, 0.05f);
    Render_->CreateAnimation("MonsterAStar.bmp", "MonsterAStarLeft", 12, 17, 0.05f);
    Render_->CreateAnimation("MonsterAStar.bmp", "MonsterAStarRight", 18, 23, 0.05f);
    Render_->ChangeAnimation("MonsterAStarRight");

}

void MonsterAstar::Update()
{
}

void MonsterAstar::Render()
{
}
