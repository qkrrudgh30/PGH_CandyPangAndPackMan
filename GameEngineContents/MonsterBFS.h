// MonsterBFS.h

#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class MonsterBFS : public GameEngineActor
{
public:
    // constrcuter destructer
    MonsterBFS();
    ~MonsterBFS();

    // delete Function
    MonsterBFS(const MonsterBFS& _Other) = delete;
    MonsterBFS(MonsterBFS&& _Other) noexcept = delete;
    MonsterBFS& operator=(const MonsterBFS& _Other) = delete;
    MonsterBFS& operator=(MonsterBFS&& _Other) noexcept = delete;

protected:

private:
    float Speed_;
    float4 Scale_;
    GameEngineRenderer* Render_;

    void Start() override;
    void Update() override;
    void Render() override;
};