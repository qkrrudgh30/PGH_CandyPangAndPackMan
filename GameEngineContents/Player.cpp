// Player.cpp

#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEngineInput.h>

#include <GameEngine/GameEngineLevel.h> 
#include "Bullet.h" 

Player::Player()
    : Speed_(100.f)
{
}

Player::~Player()
{
}


void Player::Start()
{
    SetPosition(GameEngineWindow::GetScale().Half());
    SetScale({ 30, 30 });

    GameEngineRenderer* Render = CreateRendererToScale("Player.bmp", { 30, 30 });

    if (false == GameEngineInput::GetInst()->IsKey("MoveLeft"))
    {
        GameEngineInput::GetInst()->CreateKey("MoveLeft", 'A');
        GameEngineInput::GetInst()->CreateKey("MoveRight", 'D');
        GameEngineInput::GetInst()->CreateKey("MoveUp", 'W');
        GameEngineInput::GetInst()->CreateKey("MoveDown", 'S');
        GameEngineInput::GetInst()->CreateKey("Jump", VK_LSHIFT);
        GameEngineInput::GetInst()->CreateKey("Fire", VK_SPACE);
    }
}

void Player::Update()
{
    if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
    {
        SetMove(float4::RIGHT * GameEngineTime::GetDeltaTime() * Speed_);
    }
    if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
    {
        SetMove(float4::LEFT * GameEngineTime::GetDeltaTime() * Speed_);
    }
    if (true == GameEngineInput::GetInst()->IsPress("MoveUp"))
    {
        SetMove(float4::UP * GameEngineTime::GetDeltaTime() * Speed_);
    }
    if (true == GameEngineInput::GetInst()->IsPress("MoveDown"))
    {
        SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * Speed_);
    }

    if (true == GameEngineInput::GetInst()->IsDown("Fire"))
    {
        Bullet* Ptr = GetLevel()->CreateActor<Bullet>();

        Ptr->SetPosition(GetPosition());
    }
}

void Player::Render()
{
}