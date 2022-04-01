// TitleHelp.cpp

#include "TitleHelp.h"

TitleHelp::TitleHelp()
{

}

TitleHelp::~TitleHelp()
{

}

void TitleHelp::Start()
{
    SetPosition({ 930, 600 });
    SetScale({ 700, 200 });

    GameEngineRenderer* Render = CreateRendererToScale("TitleHelp.bmp", { 700, 200 });
}

void TitleHelp::Update()
{
}

void TitleHelp::Render()
{
}
