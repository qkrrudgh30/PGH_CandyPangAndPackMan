// GameEngineActor.h

#pragma once
#include "GameEngineLevel.h"
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineUpdateObject.h>
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineEnum.h"
#include <list>

// ���� :
class GameEngineLevel;
class GameEngineRenderer;
class GameEngineCollision;
class GameEngineActor : public GameEngineNameObject, public GameEngineUpdateObject
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

    inline float4 GetCameraEffectPosition()
    {
        return Position_ - GetLevel()->GetCameraPos();
    }

    inline float4 GetPosition()
    {
        return Position_;
    }
    inline float4 GetScale()
    {
        return Scale_;
    }

    inline void SetMove(float4 _Value)
    {
        Position_ += _Value;
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
    void Release();

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
    GameEngineRenderer* CreateRenderer(RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

    GameEngineRenderer* CreateRenderer(const std::string& _Image, RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

    GameEngineRenderer* CreateRendererToScale(const std::string& _Image, const float4& _Scale, RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

    void Renderering();

private:
    std::list<GameEngineRenderer*>::iterator StartRenderIter;
    std::list<GameEngineRenderer*>::iterator EndRenderIter;

    std::list<GameEngineRenderer*> RenderList_;

public:
    GameEngineCollision* CreateCollision(const std::string& _GroupName, float4 _Scale, float4 _Pivot = { 0, 0 });

private:
    std::list<GameEngineCollision*> CollisionList_;
};