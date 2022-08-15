// FirstMazeTile.h

#pragma once

#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class FirstMazeTile : public GameEngineActor
{
public:
    // constrcuter destructer
    FirstMazeTile();
    ~FirstMazeTile();

    // delete Function
    FirstMazeTile(const FirstMazeTile& _Other) = delete;
    FirstMazeTile(FirstMazeTile&& _Other) noexcept = delete;
    FirstMazeTile& operator=(const FirstMazeTile& _Other) = delete;
    FirstMazeTile& operator=(FirstMazeTile&& _Other) noexcept = delete;

protected:

private:
    void Start() override;
    void Update() override;
    void Render() override;

};

