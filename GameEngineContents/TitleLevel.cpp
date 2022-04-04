// TitleLevel.cpp

#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "GameEngineBase/GameEngineInput.h"
#include "TitleLogo.h"
#include "TitleHelp.h"

enum class ORDER
{
    BACKGROUND,
    PLAYER,
    MONSTER,
    TILE,
    UI
};

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Loading()
{
    GameEngineInput::GetInst()->CreateKey("GoToFirstMaze", 'K');
    GameEngineInput::GetInst()->CreateKey("GoToPangMan", 'G');
}

void TitleLevel::Update()
{
    if (true == GameEngineInput::GetInst()->IsPress("GoToFirstMaze"))
    {
        GameEngine::GlobalEngine().ChangeLevel("FirstMaze");
    }

    if (true == GameEngineInput::GetInst()->IsPress("GoToPangMan"))
    {
        GameEngine::GlobalEngine().ChangeLevel("PangMan");
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
