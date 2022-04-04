// PackManMap.h

#pragma once

enum {
    WALL = 0,
    PATH = 1,
    SLOW = 2,
    MapRowScale = 25,
    MapColScale = 25
};

// Ό³Έν :
class PackManMap
{
public:
    int ArrayMap[MapRowScale + 1][MapColScale + 1];
    int ArrayVisitMap[MapRowScale + 1][MapColScale + 1];

    // constrcuter destructer
    PackManMap();
    ~PackManMap();

    // delete Function
    PackManMap(const PackManMap& _Other) = delete;
    PackManMap(PackManMap&& _Other) noexcept = delete;
    PackManMap& operator=(const PackManMap& _Other) = delete;
    PackManMap& operator=(PackManMap&& _Other) noexcept = delete;

protected:

private:
    void GenerateMapByBinaryTree();

};

