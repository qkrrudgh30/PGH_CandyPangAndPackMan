// MonsterAstar.h

#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class MonsterAstar : public GameEngineActor
{
public:
    // constrcuter destructer
    MonsterAstar();
    ~MonsterAstar();

    // delete Function
    MonsterAstar(const MonsterAstar& _Other) = delete;
    MonsterAstar(MonsterAstar&& _Other) noexcept = delete;
    MonsterAstar& operator=(const MonsterAstar& _Other) = delete;
    MonsterAstar& operator=(MonsterAstar&& _Other) noexcept = delete;

protected:

private:
    float Speed_;
    float4 Scale_;
    GameEngineRenderer* Render_;

    void Start() override;
    void Update() override;
    void Render() override;
};