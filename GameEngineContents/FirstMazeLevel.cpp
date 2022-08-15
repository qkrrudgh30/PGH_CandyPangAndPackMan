// FirstMazeLevel.cpp

#include "FirstMazeLevel.h"
#include "Player.h"
#include "BotUI.h"
#include "MonsterRightHand.h"
#include "FirstMazeTile.h"

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

FirstMazeLevel::FirstMazeLevel()
    : CameraSpeed_(100.f)
{

}

FirstMazeLevel::~FirstMazeLevel()
{

}

void FirstMazeLevel::Loading()
{
    GameEngineInput::GetInst()->CreateKey("GoToSecondMaze", '2');
}

void FirstMazeLevel::Update()
{
    if (true == GameEngineInput::GetInst()->IsPress("CameraUp"))
    {
        MoveCameraPos(float4::UP * GameEngineTime::GetDeltaTime() * CameraSpeed_);
    }
    if (true == GameEngineInput::GetInst()->IsPress("CameraDown"))
    {
        MoveCameraPos(float4::DOWN * GameEngineTime::GetDeltaTime() * CameraSpeed_);
    }
    if (true == GameEngineInput::GetInst()->IsPress("CameraRight"))
    {
        MoveCameraPos(float4::RIGHT * GameEngineTime::GetDeltaTime() * CameraSpeed_);
    }
    if (true == GameEngineInput::GetInst()->IsPress("CameraLeft"))
    {
        MoveCameraPos(float4::LEFT * GameEngineTime::GetDeltaTime() * CameraSpeed_);
    }

    if (true == GameEngineInput::GetInst()->IsPress("GoToSecondMaze"))
    {
        GameEngine::GlobalEngine().ChangeLevel("SecondMaze");
    }
}

void FirstMazeLevel::LevelChangeStart()
{
    CreateActor<Player>((int)ORDER::PLAYER, "Player");
    CreateActor<BotUI>((int)ORDER::UI, "BotUI");
    CreateActor<MonsterRightHand>((int)ORDER::UI, "MonsterRightHand");
    CreateActor<FirstMazeTile>((int)ORDER::TILE, "FirstMazeTile");

    GameEngineInput::GetInst()->CreateKey("CameraUp", VK_UP);
    GameEngineInput::GetInst()->CreateKey("CameraDown", VK_DOWN);
    GameEngineInput::GetInst()->CreateKey("CameraRight", VK_RIGHT);
    GameEngineInput::GetInst()->CreateKey("CameraLeft", VK_LEFT);
}

void FirstMazeLevel::LevelChangeEnd()
{
}

