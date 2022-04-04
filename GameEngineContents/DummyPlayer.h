#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class DummyPlayer : public GameEngineActor
{
public:
    // constrcuter destructer
    DummyPlayer();
    ~DummyPlayer();

    // delete Function
    DummyPlayer(const DummyPlayer& _Other) = delete;
    DummyPlayer(DummyPlayer&& _Other) noexcept = delete;
    DummyPlayer& operator=(const DummyPlayer& _Other) = delete;
    DummyPlayer& operator=(DummyPlayer&& _Other) noexcept = delete;

protected:

private:
    GameEngineRenderer* Render_;

    void Start() override;
    void Update() override;
    void Render() override;
};