// FirstMazeTile.cpp

#include "FirstMazeTile.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>

FirstMazeTile::FirstMazeTile()
{

}

FirstMazeTile::~FirstMazeTile()
{

}

void FirstMazeTile::Start()
{
    SetPosition({100, 100});
    SetScale({ 30, 30 });

    GameEngineRenderer* Render = CreateRendererToScale("FirstMazeTile.bmp", { 30, 30 });
}

void FirstMazeTile::Update()
{
}

void FirstMazeTile::Render()
{
}
