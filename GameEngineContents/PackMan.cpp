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
    CreateLevel<TitleLevel>("Title");
    CreateLevel<PangManLevel>("PangMan");
    CreateLevel<FirstMazeLevel>("FirstMaze");
    CreateLevel<SecondMazeLevel>("SecondMaze");
    CreateLevel<ThirdMazeLevel>("ThirdMaze");
    CreateLevel<EndingLevel>("Ending");

    ChangeLevel("FirstMaze");
}

void PackMan::GameLoop()
{

}
void PackMan::GameEnd()
{

}