// MonsterBFS.cpp

#include "MonsterBFS.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEngineInput.h>

MonsterBFS::MonsterBFS()
	: Speed_(100.f)
	, Scale_({32.f, 32.f})
	, Render_(nullptr)
{

}

MonsterBFS::~MonsterBFS()
{

}

void MonsterBFS::Start()
{
    SetPosition({300.f, 300.f});
    SetScale({ 32.f, 32.f });

    Render_ = CreateRenderer("MonsterBFS.bmp", RenderPivot::CENTER, { 0, 0 });
    Render_->GetImage()->Cut(GetScale());
    Render_->CreateAnimation("MonsterBFS.bmp", "MonsterBFSUp", 0, 8, 0.05f);
    Render_->CreateAnimation("MonsterBFS.bmp", "MonsterBFSDown", 9, 17, 0.05f);
    Render_->CreateAnimation("MonsterBFS.bmp", "MonsterBFSLeft", 18, 26, 0.05f);
    Render_->CreateAnimation("MonsterBFS.bmp", "MonsterBFSRight", 27, 35, 0.05f);
    Render_->ChangeAnimation("MonsterBFSRight");
}

void MonsterBFS::Update()
{
}

void MonsterBFS::Render()
{
}
