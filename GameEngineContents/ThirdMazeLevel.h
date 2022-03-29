// ThirdMazeLevel.h

#pragma once

#include <GameEngine/GameEngineLevel.h>

// Ό³Έν :
class ThirdMazeLevel : public GameEngineLevel
{
public:
    // constrcuter destructer
    ThirdMazeLevel();
    ~ThirdMazeLevel();

    // delete Function
    ThirdMazeLevel(const ThirdMazeLevel& _Other) = delete;
    ThirdMazeLevel(ThirdMazeLevel&& _Other) noexcept = delete;
    ThirdMazeLevel& operator=(const ThirdMazeLevel& _Other) = delete;
    ThirdMazeLevel& operator=(ThirdMazeLevel&& _Other) noexcept = delete;

protected:
    void Loading() override;
    void Update() override;
    void LevelChangeStart() override;
    void LevelChangeEnd() override;

private:

};

