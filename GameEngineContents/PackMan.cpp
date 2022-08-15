// PackMan.cpp

#include "PackMan.h"

#include "TitleLevel.h"
#include "PangManLevel.h"
#include "FirstMazeLevel.h"
#include "SecondMazeLevel.h"
#include "ThirdMazeLevel.h"
#include "EndingLevel.h"

#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngine/GameEngineImageManager.h>

PackMan::PackMan()
{
}

PackMan::~PackMan()
{
}

void PackMan::GameInit()
{
    GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 100, 100 }, { 1280, 720 });

    GameEngineDirectory ResourcesDir;
    ResourcesDir.MoveParent("PGH_PackMan");
    ResourcesDir.Move("Resources");
    ResourcesDir.Move("Image");

    std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

    for (size_t i = 0; i < AllImageFileList.size(); i++)
    {
        GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
    }

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