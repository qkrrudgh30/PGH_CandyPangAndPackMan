// DummyAStar.h

#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class DummyAStar : public GameEngineActor
{
public:
    // constrcuter destructer
    DummyAStar();
    ~DummyAStar();

    // delete Function
    DummyAStar(const DummyAStar& _Other) = delete;
    DummyAStar(DummyAStar&& _Other) noexcept = delete;
    DummyAStar& operator=(const DummyAStar& _Other) = delete;
    DummyAStar& operator=(DummyAStar&& _Other) noexcept = delete;

protected:

private:
    float Speed_;
    float4 Scale_;
    GameEngineRenderer* Render_;

    void Start() override;
    void Update() override;
    void Render() override;
};