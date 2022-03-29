// PangManLevel.h

#pragma once

#include <GameEngine/GameEngineLevel.h>

// Ό³Έν :
class PangManLevel : public GameEngineLevel
{
public:
    // constrcuter destructer
    PangManLevel();
    ~PangManLevel();

    // delete Function
    PangManLevel(const PangManLevel& _Other) = delete;
    PangManLevel(PangManLevel&& _Other) noexcept = delete;
    PangManLevel& operator=(const PangManLevel& _Other) = delete;
    PangManLevel& operator=(PangManLevel&& _Other) noexcept = delete;

protected:
    void Loading() override;
    void Update() override;
    void LevelChangeStart() override;
    void LevelChangeEnd() override;

private:

};

