// SecondMazeTile.h

#pragma once

#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class SecondMazeTile : public GameEngineActor
{
public:
    // constrcuter destructer
    SecondMazeTile();
    ~SecondMazeTile();

    // delete Function
    SecondMazeTile(const SecondMazeTile& _Other) = delete;
    SecondMazeTile(SecondMazeTile&& _Other) noexcept = delete;
    SecondMazeTile& operator=(const SecondMazeTile& _Other) = delete;
    SecondMazeTile& operator=(SecondMazeTile&& _Other) noexcept = delete;

protected:

private:
    void Start() override;
    void Update() override;
    void Render() override;

};

