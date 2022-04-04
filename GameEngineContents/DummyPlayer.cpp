// DummyPlayer.cpp

#include "DummyPlayer.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEngineInput.h>

DummyPlayer::DummyPlayer()
    : Render_(nullptr)
{
}

DummyPlayer::~DummyPlayer()
{
}


void DummyPlayer::Start()
{
    SetScale({ 32, 32 });

    Render_ = CreateRenderer("Player.bmp", RenderPivot::CENTER, { 0, 0 });
    Render_->GetImage()->Cut({ 32, 32 });
    Render_->SetIndex(42, { 32.f, 32.f });
}

void DummyPlayer::Update()
{
}

void DummyPlayer::Render()
{
}