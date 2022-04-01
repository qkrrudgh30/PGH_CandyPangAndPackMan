// TitleHelp.h

#pragma once

#include "GameEngine/GameEngineActor.h"

// Ό³Έν :
class TitleHelp : public GameEngineActor
{
public:
    // constrcuter destructer
    TitleHelp();
    ~TitleHelp();

    // delete Function
    TitleHelp(const TitleHelp& _Other) = delete;
    TitleHelp(TitleHelp&& _Other) noexcept = delete;
    TitleHelp& operator=(const TitleHelp& _Other) = delete;
    TitleHelp& operator=(TitleHelp&& _Other) noexcept = delete;

protected:

private:
    void Start() override;
    void Update() override;
    void Render() override;

};

