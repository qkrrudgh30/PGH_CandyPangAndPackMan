// ThirdMazeLevel.cpp

#include "ThirdMazeLevel.h"
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

ThirdMazeLevel::ThirdMazeLevel()
{

}

ThirdMazeLevel::~ThirdMazeLevel()
{

}

void ThirdMazeLevel::Loading()
{
	GameEngineInput::GetInst()->CreateKey("GoToEnding", '4');
}

void ThirdMazeLevel::Update()
{
    if (true == GameEngineInput::GetInst()->IsPress("GoToEnding"))
    {
        GameEngine::GlobalEngine().ChangeLevel("Ending");
    }
}

void ThirdMazeLevel::LevelChangeStart()
{
}

void ThirdMazeLevel::LevelChangeEnd()
{
}

