// PackMan.h

#pragma once
#include <GameEngine/GameEngine.h>

class PackMan : public GameEngine
{
public:
    // constrcuter destructer
    PackMan();
    ~PackMan();

    // delete Function
    PackMan(const PackMan& _Other) = delete;
    PackMan(PackMan&& _Other) noexcept = delete;
    PackMan& operator=(const PackMan& _Other) = delete;
    PackMan& operator=(PackMan&& _Other) noexcept = delete;

    void GameInit() override;
    void GameLoop() override;
    void GameEnd() override;

protected:

private:

};

