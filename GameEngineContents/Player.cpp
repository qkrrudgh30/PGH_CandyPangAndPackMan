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
    , Render_(nullptr)
{
}

Player::~Player()
{
}


void Player::Start()
{
    SetPosition(GameEngineWindow::GetScale().Half());
    SetScale({ 32, 32 });

    Render_ = CreateRenderer("Player.bmp", RenderPivot::CENTER, { 0, 0});
    Render_->GetImage()->Cut({32, 32});
    Render_->CreateAnimation("Player.bmp", "PlayerUp", 0, 13, 0.05f);
    Render_->CreateAnimation("Player.bmp", "PlayerDown", 14, 27, 0.05f);
    Render_->CreateAnimation("Player.bmp", "PlayerLeft", 28, 41, 0.05f);
    Render_->CreateAnimation("Player.bmp", "PlayerRight", 42, 55, 0.05f);
    Render_->ChangeAnimation("PlayerRight");

    CreateCollision("Player", { 32, 32 }, {0, 100});

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
        Render_->ChangeAnimation("PlayerRight");
        SetMove(float4::RIGHT * GameEngineTime::GetDeltaTime() * Speed_);
    }
    if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
    {
        Render_->ChangeAnimation("PlayerLeft");
        SetMove(float4::LEFT * GameEngineTime::GetDeltaTime() * Speed_);
    }
    if (true == GameEngineInput::GetInst()->IsPress("MoveUp"))
    {
        Render_->ChangeAnimation("PlayerUp");
        SetMove(float4::UP * GameEngineTime::GetDeltaTime() * Speed_);
    }
    if (true == GameEngineInput::GetInst()->IsPress("MoveDown"))
    {
        Render_->ChangeAnimation("PlayerDown");
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