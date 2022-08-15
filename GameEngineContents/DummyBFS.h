// DummyBFS.h

#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class DummyBFS : public GameEngineActor
{
public:
    // constrcuter destructer
    DummyBFS();
    ~DummyBFS();

    // delete Function
    DummyBFS(const DummyBFS& _Other) = delete;
    DummyBFS(DummyBFS&& _Other) noexcept = delete;
    DummyBFS& operator=(const DummyBFS& _Other) = delete;
    DummyBFS& operator=(DummyBFS&& _Other) noexcept = delete;

protected:

private:
    float Speed_;
    float4 Scale_;
    GameEngineRenderer* Render_;

    void Start() override;
    void Update() override;
    void Render() override;
};