// GameEngine.cpp

#include "GameEngine.h"
#include <GameEngineBase/GameEngineWindow.h>

GameEngine * GameEngine::UserContents_ = nullptr;

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{

}

void GameEngine::GameInit()
{

}

void GameEngine::GameLoop()
{

}

void GameEngine::GameEnd()
{

}

void GameEngine::WindowCreate()
{
    GameEngineWindow::GetInst().CreateGameWindow(nullptr, "PackMan");
    GameEngineWindow::GetInst().ShowGameWindow();
    GameEngineWindow::GetInst().MessageLoop(EngineInit, EngineLoop);
}

void GameEngine::EngineInit()
{
    UserContents_->GameInit();
}
void GameEngine::EngineLoop()
{
    UserContents_->GameLoop();
}

void GameEngine::EngineEnd()
{
    UserContents_->GameEnd();

    GameEngineWindow::Destroy();
}