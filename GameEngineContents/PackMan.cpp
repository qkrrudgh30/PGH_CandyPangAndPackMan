// PackMan.cpp

#include "PackMan.h"
#include <GameEngineBase/GameEngineWindow.h>

#include "TitleLevel.h"
#include "PangManLevel.h"
#include "FirstMazeLevel.h"
#include "SecondMazeLevel.h"
#include "ThirdMazeLevel.h"
#include "EndingLevel.h"

PackMan::PackMan()
{
}

PackMan::~PackMan()
{
}

void PackMan::GameInit()
{
    GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 100, 100 }, { 1280, 720 });

    CreateLevel<TitleLevel>("Title");
    CreateLevel<PangManLevel>("PangMan");
    CreateLevel<FirstMazeLevel>("FirstMaze");
    CreateLevel<SecondMazeLevel>("SecondMaze");
    CreateLevel<ThirdMazeLevel>("ThirdMaze");
    CreateLevel<EndingLevel>("Ending");

    ChangeLevel("Title");
}

void PackMan::GameLoop()
{

}
void PackMan::GameEnd()
{

}