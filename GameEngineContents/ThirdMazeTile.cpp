// ThirdMazeTile.cpp

#include "ThirdMazeTile.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>

ThirdMazeTile::ThirdMazeTile()
{

}

ThirdMazeTile::~ThirdMazeTile()
{

}

void ThirdMazeTile::Start()
{
    SetPosition({ 300, 300 });
    SetScale({ 30, 30 });

    GameEngineRenderer* Render = CreateRendererToScale("ThirdMazeTile.bmp", { 30, 30 });
}

void ThirdMazeTile::Update()
{
}

void ThirdMazeTile::Render()
{
}
