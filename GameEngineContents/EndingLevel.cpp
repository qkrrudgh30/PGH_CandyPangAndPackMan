// EndingLevel.cpp

#include "EndingLevel.h"
#include "GameEngine/GameEngine.h"
#include "GameEngineBase/GameEngineInput.h"

enum class ORDER
{
    BACKGROUND,
    PLAYER,
    MONSTER,
    TILE,
    UI
};

EndingLevel::EndingLevel()
{

}

EndingLevel::~EndingLevel()
{

}

void EndingLevel::Loading()
{
	GameEngineInput::GetInst()->CreateKey("GoToTitleFromEnding", 'E');
}

void EndingLevel::Update()
{
    if (true == GameEngineInput::GetInst()->IsPress("GoToTitleFromEnding"))
    {
        GameEngine::GlobalEngine().ChangeLevel("Title");
    }
}

void EndingLevel::LevelChangeStart()
{
}

void EndingLevel::LevelChangeEnd()
{
}

