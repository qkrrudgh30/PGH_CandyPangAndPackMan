// GameEngine.h

#pragma once
#include <string>
#include <GameEngineBase/GameEngineDebug.h>

class GameEngine
{
public:
    GameEngine();
    ~GameEngine();

    // delete Function
    GameEngine(const GameEngine& _Other) = delete;
    GameEngine(GameEngine&& _Other) noexcept = delete;
    GameEngine& operator=(const GameEngine& _Other) = delete;
    GameEngine& operator=(GameEngine&& _Other) noexcept = delete;

    virtual void GameInit() = 0;
    virtual void GameLoop() = 0;
    virtual void GameEnd() = 0;

    template<typename GameType>
    static void Start()
    {
        GameEngineDebug::LeakCheckOn();

        GameType UserGame;
        UserContents_ = &UserGame;

        WindowCreate();

        EngineEnd();
    }

    static GameEngine& GlobalEngine()
    {
        if (nullptr == UserContents_)
        {
            MsgBoxAssert("GEngine ERROR Engine Is Not Start ");
        }

        return *UserContents_;
    }

protected:

private:
    static GameEngine* UserContents_;

    static void WindowCreate();
    static void EngineInit();
    static void EngineLoop();
    static void EngineEnd();
};