// GameEngineWindow.h

#pragma once
#include <Windows.h>
#include <string>
#include "GameEngineMath.h"

// ���� :
class GameEngineWindow
{
private:
    static GameEngineWindow* Inst_;

public:
    inline static GameEngineWindow& GetInst()
    {
        return *Inst_;
    }

    static void Destroy()
    {
        if (nullptr != Inst_)
        {
            delete Inst_;
            Inst_ = nullptr;
        }
    }

public:
    void RegClass(HINSTANCE _hInst);
    void CreateGameWindow(HINSTANCE _hInst, const std::string& _Title);
    void ShowGameWindow();
    void MessageLoop(void(*_InitFunction)(), void(*_LoopFunction)());

    void SetWindowScaleAndPosition(float4 _Pos, float4 _Scale);

    void Off();

    static inline HDC GetHDC()
    {
        return Inst_->HDC_;
    }

    static inline float4 GetScale()
    {
        return Inst_->Scale_;
    }

    static inline float4 GetMousePos()
    {
        return MousePosition_;
    }

    static void SetMousePos(float _MouseX, float _MouseY)
    {
        MousePosition_.x = _MouseX;
        MousePosition_.y = _MouseY;
    }

protected:

private:
    std::string Title_;
    bool WindowOn_;
    HINSTANCE hInst_;
    HWND hWnd_;
    HDC HDC_;
    float4 Scale_;

    static float4 MousePosition_;

    // constrcuter destructer
    GameEngineWindow();
    ~GameEngineWindow();

    // delete Function
    GameEngineWindow(const GameEngineWindow& _Other) = delete;
    GameEngineWindow(GameEngineWindow&& _Other) noexcept = delete;
    GameEngineWindow& operator=(const GameEngineWindow& _Other) = delete;
    GameEngineWindow& operator=(GameEngineWindow&& _Other) noexcept = delete;

};

