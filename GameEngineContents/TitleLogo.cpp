// TitleLogo.cpp

#include "TitleLogo.h"

TitleLogo::TitleLogo()
{

}

TitleLogo::~TitleLogo()
{

}

void TitleLogo::Start()
{
    SetPosition({ 485, 300 });
    SetScale({ 970, 600 });

    GameEngineRenderer* Render = CreateRendererToScale("TitleLogo.bmp", { 970, 600 });
}

void TitleLogo::Update()
{
}

void TitleLogo::Render()
{
}
