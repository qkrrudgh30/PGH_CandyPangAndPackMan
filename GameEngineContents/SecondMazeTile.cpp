// SecondMazeTile.cpp

#include "SecondMazeTile.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>

SecondMazeTile::SecondMazeTile()
{

}

SecondMazeTile::~SecondMazeTile()
{

}

void SecondMazeTile::Start()
{
    SetPosition({ 200, 200 });
    SetScale({ 50, 50 });

    GameEngineRenderer* Render = CreateRendererToScale("SecondMazeTile.bmp", { 30, 30 });
}

void SecondMazeTile::Update()
{
}

void SecondMazeTile::Render()
{
}
