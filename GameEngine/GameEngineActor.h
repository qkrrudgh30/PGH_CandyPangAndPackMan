// GameEngineActor.h

#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineEnum.h"
#include <list>

// 설명 :
class GameEngineRenderer;
class GameEngineLevel;
class GameEngineActor : public GameEngineNameObject
{
public:
    friend GameEngineLevel;

    // constrcuter destructer
    GameEngineActor();
    virtual ~GameEngineActor();

    // delete Function
    GameEngineActor(const GameEngineActor& _Other) = delete;
    GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
    GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
    GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

    inline GameEngineLevel* GetLevel()
    {
        return Level_;
    }

    inline float4 GetPosition()
    {
        return Position_;
    }
    inline float4 GetScale()
    {
        return Scale_;
    }

    inline void SetPosition(float4 _Value)
    {
        Position_ = _Value;
    }
    inline void SetScale(float4 _Value)
    {
        Scale_ = _Value;
    }


protected:
    virtual void Start() = 0;
    virtual void Update() {}
    virtual void Render() {}

    void DebugRectRender();

private:
    GameEngineLevel* Level_;
    float4 Position_;
    float4 Scale_;

    inline void SetLevel(GameEngineLevel* _Level)
    {
        Level_ = _Level;
    }

public:
    // GameEngineRenderer* CreateRenderer(RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

    GameEngineRenderer* CreateRenderer(const std::string& _Image, RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

    GameEngineRenderer* CreateRendererToScale(const std::string& _Image, const float4& _Scale, RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

    void Renderering();

private:
    // 이터레이터
    std::list<GameEngineRenderer*>::iterator StartRenderIter;
    std::list<GameEngineRenderer*>::iterator EndRenderIter;

    std::list<GameEngineRenderer*> RenderList_;


};