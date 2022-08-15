// DummyRightHand.h

#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class DummyRightHand : public GameEngineActor
{
public:
    // constrcuter destructer
    DummyRightHand();
    ~DummyRightHand();

    // delete Function
    DummyRightHand(const DummyRightHand& _Other) = delete;
    DummyRightHand(DummyRightHand&& _Other) noexcept = delete;
    DummyRightHand& operator=(const DummyRightHand& _Other) = delete;
    DummyRightHand& operator=(DummyRightHand&& _Other) noexcept = delete;

protected:

private:
    float Speed_;
    float4 Scale_;
    GameEngineRenderer* Render_;

    void Start() override;
    void Update() override;
    void Render() override;
};