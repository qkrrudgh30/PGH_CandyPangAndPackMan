// Player.cpp

#include "Player.h"
#include <GameEngineBase/GameEngineWindow.h>

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
}

void Player::Update()
{
}

void Player::Render()
{
    DebugRectRender();
}