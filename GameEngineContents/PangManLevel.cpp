// PangManLevel.cpp

#define _CRT_SECURE_NO_WARNINGS

#include "PangManLevel.h"
#include "GameEngine/GameEngine.h"
#include "GameEngineBase/GameEngineInput.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "MonsterRightHand.h"
#include "MonsterBFS.h"
#include "MonsterAstar.h"
#include "DummyPlayer.h"
#include "DummyRightHand.h"
#include "DummyBFS.h"
#include "DummyAStar.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <queue>

enum class ORDER
{
    BACKGROUND,
    PLAYER,
    MONSTER,
    TILE,
    UI
};

PangManLevel::PangManLevel()
    : PangMapRowSize_(20)
    , PangMapColSize_(20)
    , CurrMouseRow(0)
    , CurrMouseCol(0)
{
    for (size_t i = 1; i <= PangMapRowSize_; ++i)
    {
        for (size_t j = 1; j <= PangMapRowSize_; ++j)
        {
            PangVisitMap_[i][j] = PangMap_[i][j] = 0;
        }
    }
}

PangManLevel::~PangManLevel()
{

}

void PangManLevel::Loading()
{
    srand((unsigned int)time(NULL));

    ShufflePangMap();
    
	GameEngineInput::GetInst()->CreateKey("GoToTitleFromPangMan", '1');
	GameEngineInput::GetInst()->CreateKey("Click", MK_LBUTTON);
}

void PangManLevel::Update()
{
    if (true == GameEngineInput::GetInst()->IsPress("GoToTitleFromPangMan"))
    {
        GameEngine::GlobalEngine().ChangeLevel("Title");
    }

    if (true == GameEngineInput::GetInst()->IsPress("Click"))
    {
        CurrMouseRow = (int)((GameEngineWindow::GetInst().GetMousePos().y) / 32.f);
        CurrMouseCol = (int)((GameEngineWindow::GetInst().GetMousePos().x) / 32.f);
        
        char RowString[100] = "\0";
        char ColString[100] = "\0";
        sprintf(RowString, "Row: %d", CurrMouseRow);
        sprintf(ColString, "Col: %d", CurrMouseCol);
        TextOut(GameEngine::BackBufferDC(), 800, 600, TEXT(RowString), 12);
        TextOut(GameEngine::BackBufferDC(), 800, 630, TEXT(ColString), 12);
        
        BFSPang(CurrMouseRow, CurrMouseCol);
    }
    DrawPangMap();
}

void PangManLevel::LevelChangeStart()
{
    DrawPangMap();
}

void PangManLevel::LevelChangeEnd()
{
}

void PangManLevel::ShufflePangMap(void)
{
    for (size_t i = 1; i <= PangMapRowSize_; ++i)
    {
        for (size_t j = 1; j <= PangMapColSize_; ++j)
        {
            PangMap_[i][j] = rand() % 4 + 1;
        }
    }
}

void PangManLevel::DrawPangMap(void)
{   
    for (int i = 0; i <= PangMapRowSize_; ++i)
    {
        for (int j = 0; j <= PangMapColSize_; ++j)
        {
            GameEngineRect DebugRect({ (float)(j * 32 + 16.f), (float)(i * 32 + 16.f)}, {32.f, 32.f});
            switch (PangMap_[i][j])
            {
            case 0:
            {
                HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
                HBRUSH hDefaultBrush = (HBRUSH)SelectObject(GameEngine::BackBufferDC(), hWhiteBrush);

                Rectangle(
                    GameEngine::BackBufferDC(),
                    DebugRect.CenterLeft(),
                    DebugRect.CenterTop(),
                    DebugRect.CenterRight(),
                    DebugRect.CenterBot()
                );

                SelectObject(GameEngine::BackBufferDC(), hDefaultBrush);
                DeleteObject(hWhiteBrush);
                
            }
                break;
            case 1:
            {
                HBRUSH hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
                HBRUSH hDefaultBrush = (HBRUSH)SelectObject(GameEngine::BackBufferDC(), hRedBrush);

                Rectangle(
                    GameEngine::BackBufferDC(),
                    DebugRect.CenterLeft(),
                    DebugRect.CenterTop(),
                    DebugRect.CenterRight(),
                    DebugRect.CenterBot()
                );
                SelectObject(GameEngine::BackBufferDC(), hDefaultBrush);
                DeleteObject(hRedBrush);

            }
                break;
            case 2:
            {
                HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
                HBRUSH hDefaultBrush = (HBRUSH)SelectObject(GameEngine::BackBufferDC(), hGreenBrush);

                Rectangle(
                    GameEngine::BackBufferDC(),
                    DebugRect.CenterLeft(),
                    DebugRect.CenterTop(),
                    DebugRect.CenterRight(),
                    DebugRect.CenterBot()
                );
                SelectObject(GameEngine::BackBufferDC(), hDefaultBrush);
                DeleteObject(hGreenBrush);

            }
                break;
            case 3:
            {
                HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
                HBRUSH hDefaultBrush = (HBRUSH)SelectObject(GameEngine::BackBufferDC(), hBlueBrush);

                Rectangle(
                    GameEngine::BackBufferDC(),
                    DebugRect.CenterLeft(),
                    DebugRect.CenterTop(),
                    DebugRect.CenterRight(),
                    DebugRect.CenterBot()
                );
                SelectObject(GameEngine::BackBufferDC(), hDefaultBrush);
                DeleteObject(hBlueBrush);

            }
                break;
            case 4:
            {
                HBRUSH hYellowBrush = CreateSolidBrush(RGB(255, 255, 0));
                HBRUSH hDefaultBrush = (HBRUSH)SelectObject(GameEngine::BackBufferDC(), hYellowBrush);

                Rectangle(
                    GameEngine::BackBufferDC(),
                    DebugRect.CenterLeft(),
                    DebugRect.CenterTop(),
                    DebugRect.CenterRight(),
                    DebugRect.CenterBot()
                );

                SelectObject(GameEngine::BackBufferDC(), hDefaultBrush);
                DeleteObject(hYellowBrush);
            }
                break;
            }
        }
    }
    

}
void PangManLevel::BFSPang(int StartRow, int StartCol)
{
    std::queue<std::pair<int, int>> next;
    next.push(std::make_pair(StartRow, StartCol));
    PangVisitMap_[StartRow][StartCol] = 1;

    while (false == next.empty())
    {
        int CurrRow = next.front().first;
        int CurrCol = next.front().second;
        next.pop();
        for (int i = 0; i < 4; ++i)
        {
            int NextRow = CurrRow + PangDir_[i][0];
            int NextCol = CurrCol + PangDir_[i][1];

            if (0 == PangVisitMap_[NextRow][NextCol] && PangMap_[CurrRow][CurrCol] == PangMap_[NextRow][NextCol])
            {
                PangVisitMap_[NextRow][NextCol] = 1;
                next.push(std::make_pair(NextRow, NextCol));
            }
        }
    }

    for (int i = 1; i <= PangMapRowSize_; ++i)
    {
        for (int j = 1; j <= PangMapColSize_; ++j)
        {
            if (1 == PangVisitMap_[i][j])
            {
                PangMap_[i][j] = 0;
            }
        }
    }

    
}