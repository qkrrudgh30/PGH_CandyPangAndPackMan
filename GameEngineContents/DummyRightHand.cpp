// DummyRightHand.cpp

#include "DummyRightHand.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEngineInput.h>

DummyRightHand::DummyRightHand()
    : Speed_(100.f)
    , Scale_({ 32.f, 32.f })
    , Render_(nullptr)
{

}

DummyRightHand::~DummyRightHand()
{

}

void DummyRightHand::Start()
{
    SetScale({ 32, 32 });

    Render_ = CreateRenderer("MonsterRightHandPang.bmp", RenderPivot::CENTER, { 0, 0 });
    Render_->GetImage()->Cut({ 32, 32 });
    Render_->SetIndex(0, { 32.f, 32.f });
}

void DummyRightHand::Update()
{
}

void DummyRightHand::Render()
{
}
