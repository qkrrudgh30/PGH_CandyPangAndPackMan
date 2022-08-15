// DummyBFS.cpp

#include "DummyBFS.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEngineInput.h>

DummyBFS::DummyBFS()
    : Speed_(100.f)
    , Scale_({ 32.f, 32.f })
    , Render_(nullptr)
{

}

DummyBFS::~DummyBFS()
{

}

void DummyBFS::Start()
{
    SetScale({ 32, 32 });

    Render_ = CreateRenderer("MonsterBFS.bmp", RenderPivot::CENTER, { 0, 0 });
    Render_->GetImage()->Cut({ 32, 32 });
    Render_->SetIndex(0, { 32.f, 32.f });
}

void DummyBFS::Update()
{
}

void DummyBFS::Render()
{
}
