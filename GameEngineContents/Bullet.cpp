// Bullet.cpp

#include "Bullet.h"
#include <GameEngineBase/GameEngineTime.h>

Bullet::Bullet()
    : Time(0.f)
{
}

Bullet::~Bullet()
{
}

void Bullet::Start()
{
    GameEngineRenderer* Render = CreateRendererToScale("Bullet.bmp", { 30, 30 });

    Death(2.0f);
}

void Bullet::Update()
{
    SetMove(float4::RIGHT * GameEngineTime::GetDeltaTime() * 200.0f);
}