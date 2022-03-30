// Player.cpp

#include "Player.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>

Player::Player()
{
}

Player::~Player()
{
}


void Player::Start()
{
    SetPosition(GameEngineWindow::GetScale().Half());
    SetScale({ 100, 100 });

    GameEngineRenderer* Render = CreateRendererToScale("Player.bmp", { 30, 30 });
}

void Player::Update()
{
}

void Player::Render()
{
}