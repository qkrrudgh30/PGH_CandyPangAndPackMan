// ThirdMazeTile.h

#pragma once

#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class ThirdMazeTile : public GameEngineActor
{
public:
    // constrcuter destructer
    ThirdMazeTile();
    ~ThirdMazeTile();

    // delete Function
    ThirdMazeTile(const ThirdMazeTile& _Other) = delete;
    ThirdMazeTile(ThirdMazeTile&& _Other) noexcept = delete;
    ThirdMazeTile& operator=(const ThirdMazeTile& _Other) = delete;
    ThirdMazeTile& operator=(ThirdMazeTile&& _Other) noexcept = delete;

protected:

private:
    void Start() override;
    void Update() override;
    void Render() override;

};

