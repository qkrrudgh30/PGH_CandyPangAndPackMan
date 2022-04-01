// TitleLevel.cpp

#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "GameEngineBase/GameEngineInput.h"
#include "TitleLogo.h"
#include "TitleHelp.h"

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Loading()
{
    GameEngineInput::GetInst()->CreateKey("GoToFirstMaze", 'K');
}

void TitleLevel::Update()
{
    if (true == GameEngineInput::GetInst()->IsPress("GoToFirstMaze"))
    {
        GameEngine::GlobalEngine().ChangeLevel("FirstMaze");
    }
}

void TitleLevel::LevelChangeStart()
{
    CreateActor<TitleLogo>(0, "TitleLogo");
    CreateActor<TitleHelp>(1, "TitleHelp");
}

void TitleLevel::LevelChangeEnd()
{
}
