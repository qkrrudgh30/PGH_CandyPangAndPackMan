// GameEngineRenderer.h

#pragma once
#include "GameEngineActorSubObject.h"
#include "GameEngineEnum.h"
#include <map>

// ���� :
class GameEngineImage;
class GameEngineRenderer : public GameEngineActorSubObject
{
    friend GameEngineActor;

public:
    // constrcuter destructer
    GameEngineRenderer();
    ~GameEngineRenderer();

    // delete Function
    GameEngineRenderer(const GameEngineRenderer& _Other) = delete;
    GameEngineRenderer(GameEngineRenderer&& _Other) noexcept = delete;
    GameEngineRenderer& operator=(const GameEngineRenderer& _Other) = delete;
    GameEngineRenderer& operator=(GameEngineRenderer&& _Other) noexcept = delete;

    inline void SetTransColor(unsigned int _Color)
    {
        TransColor_ = _Color;
    }

    inline void SetPivot(const float4& _Pos)
    {
        RenderPivot_ = _Pos;
    }

    inline void SetPivotType(const RenderPivot& _Type)
    {
        PivotType_ = _Type;
    }

    inline void SetScaleMode(const RenderScaleMode& _Mode)
    {
        ScaleMode_ = _Mode;
    }

    void SetImageScale();

    inline void SetScale(const float4& _Scale)
    {
        ScaleMode_ = RenderScaleMode::User;
        RenderScale_ = _Scale;
    }

    inline GameEngineImage* GetImage()
    {
        return Image_;
    }

    void SetImage(const std::string& _Name);

    void SetIndex(size_t _Index, const float4& _Scale = { -1, -1});

    void CameraEffectOff()
    {
        IsCameraEffect_ = false;
    }

    void CameraEffectOn()
    {
        IsCameraEffect_ = true;
    }

protected:
    void Render();

private:
    friend class FrameAnimation;

    bool IsCameraEffect_;
    GameEngineImage* Image_;
    RenderPivot PivotType_; 
    RenderScaleMode ScaleMode_;
    float4 RenderPivot_;
    float4 RenderScale_;
    float4 RenderImageScale_;
    float4 RenderImagePivot_;
    unsigned int TransColor_;

// Animation ����
private:
    class FrameAnimation
    {
    public:
        GameEngineRenderer* Renderer_;
        GameEngineImage* Image_;
        int CurrentFrame_;
        int StartFrame_;
        int EndFrame_;
        float CurrentInterTime_;
        float InterTime_;
        bool Loop_;

    public:
        FrameAnimation()
            : Image_(nullptr),
            CurrentFrame_(-1),
            StartFrame_(-1),
            EndFrame_(-1),
            CurrentInterTime_(0.1f),
            InterTime_(0.1f),
            Loop_(true)
        {

        }

    public:
        void Update();

        void Reset()
        {
            CurrentFrame_ = StartFrame_;
            CurrentInterTime_ = InterTime_;
        }
    };

public:
    void CreateAnimation(const std::string& _Image, const std::string& _Name, int _StartIndex, int _EndIndex, float _InterTime, bool _Loop = true);

    
    void ChangeAnimation(const std::string& _Name);


private:
    std::map<std::string, FrameAnimation> Animations_;
    FrameAnimation* CurrentAnimation_;



};