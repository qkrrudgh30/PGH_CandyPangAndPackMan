// MonsterRightHand.h

#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class MonsterRightHand : public GameEngineActor
{
public:
    // constrcuter destructer
    MonsterRightHand();
    ~MonsterRightHand();

    // delete Function
    MonsterRightHand(const MonsterRightHand& _Other) = delete;
    MonsterRightHand(MonsterRightHand&& _Other) noexcept = delete;
    MonsterRightHand& operator=(const MonsterRightHand& _Other) = delete;
    MonsterRightHand& operator=(MonsterRightHand&& _Other) noexcept = delete;

protected:

private:
    float Speed_;
    float4 Scale_;
    GameEngineRenderer* Render_;

    void Start() override;
    void Update() override;
    void Render() override;
};