// DummyAStar.cpp

#include "DummyAStar.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEngineInput.h>

DummyAStar::DummyAStar()
    : Speed_(100.f)
    , Scale_({ 32.f, 32.f })
    , Render_(nullptr)
{

}

DummyAStar::~DummyAStar()
{

}

void DummyAStar::Start()
{
    SetScale({ 32, 32 });

    Render_ = CreateRenderer("MonsterAStar.bmp", RenderPivot::CENTER, { 0, 0 });
    Render_->GetImage()->Cut({ 32, 32 });
    Render_->SetIndex(0, { 32.f, 32.f });
}

void DummyAStar::Update()
{
}

void DummyAStar::Render()
{
}
