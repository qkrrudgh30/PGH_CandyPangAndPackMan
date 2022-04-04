// SecondMazeLevel.cpp

#include "SecondMazeLevel.h"
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

SecondMazeLevel::SecondMazeLevel()
{

}

SecondMazeLevel::~SecondMazeLevel()
{

}

void SecondMazeLevel::Loading()
{
	GameEngineInput::GetInst()->CreateKey("GoToThirdMaze", '3');
}

void SecondMazeLevel::Update()
{
    if (true == GameEngineInput::GetInst()->IsPress("GoToThirdMaze"))
    {
        GameEngine::GlobalEngine().ChangeLevel("ThirdMaze");
    }
}

void SecondMazeLevel::LevelChangeStart()
{
}

void SecondMazeLevel::LevelChangeEnd()
{
}

