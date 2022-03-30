// GameEngineInput.h

#pragma once
#include <Windows.h>
#include <map>
#include <string>

// Ό³Έν :
class GameEngineInput
{
private:
    class GameEngineKey
    {
        friend GameEngineInput;

        bool Down_;
        bool Press_;
        bool Up_;
        bool Free_;

        int Key_;

        bool KeyCheck()
        {
            return 0 != GetAsyncKeyState(Key_);
        }

        void Update();

        void Reset()
        {
            Down_ = false;
            Press_ = false;
            Up_ = false;
            Free_ = true;
        }
    };

private:
    static GameEngineInput* Inst_;

public:
    static GameEngineInput* GetInst()
    {
        return Inst_;
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
    void Update();
    void CreateKey(const std::string& _Name, int _Key);

    bool IsDown(const std::string& _Name);
    bool IsUp(const std::string& _Name);
    bool IsPress(const std::string& _Name);
    bool IsFree(const std::string& _Name);
    bool IsKey(const std::string& _Name);

protected:

private:
    std::map<std::string, GameEngineKey> AllInputKey_;

    // constrcuter destructer
    GameEngineInput();
    ~GameEngineInput();

    // delete Function
    GameEngineInput(const GameEngineInput& _Other) = delete;
    GameEngineInput(GameEngineInput&& _Other) noexcept = delete;
    GameEngineInput& operator=(const GameEngineInput& _Other) = delete;
    GameEngineInput& operator=(GameEngineInput&& _Other) noexcept = delete;
};