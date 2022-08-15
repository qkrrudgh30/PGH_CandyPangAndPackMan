// PangManLevel.h

#pragma once

#include <GameEngine/GameEngineLevel.h>
#include <vector>

// Ό³Έν :
class PangManLevel : public GameEngineLevel
{
public:
    // constrcuter destructer
    PangManLevel();
    ~PangManLevel();

    // delete Function
    PangManLevel(const PangManLevel& _Other) = delete;
    PangManLevel(PangManLevel&& _Other) noexcept = delete;
    PangManLevel& operator=(const PangManLevel& _Other) = delete;
    PangManLevel& operator=(PangManLevel&& _Other) noexcept = delete;

protected:
    void Loading() override;
    void Update() override;
    void LevelChangeStart() override;
    void LevelChangeEnd() override;

private:
    size_t PangMapRowSize_;
    size_t PangMapColSize_;
    int PangMap_[22][22];
    int PangVisitMap_[22][22];
    int PangDir_[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int CurrMouseRow;
    int CurrMouseCol;

    void ShufflePangMap(void);
    void DrawPangMap(void);
    void BFSPang(int CurrRow, int CurrCol);

};

