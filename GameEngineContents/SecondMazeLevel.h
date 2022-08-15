// SecondMazeLevel.h

#pragma once

#include <GameEngine/GameEngineLevel.h>

// Ό³Έν :
class SecondMazeLevel : public GameEngineLevel
{
public:
    // constrcuter destructer
    SecondMazeLevel();
    ~SecondMazeLevel();

    // delete Function
    SecondMazeLevel(const SecondMazeLevel& _Other) = delete;
    SecondMazeLevel(SecondMazeLevel&& _Other) noexcept = delete;
    SecondMazeLevel& operator=(const SecondMazeLevel& _Other) = delete;
    SecondMazeLevel& operator=(SecondMazeLevel&& _Other) noexcept = delete;

protected:
    void Loading() override;
    void Update() override;
    void LevelChangeStart() override;
    void LevelChangeEnd() override;

private:

};

