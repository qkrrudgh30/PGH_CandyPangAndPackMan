// PackManMap.cpp

#include "PackManMap.h"
#include <ctime>
#include <cstdlib>

PackManMap::PackManMap()
{
    srand((unsigned int)time(NULL));
	for (size_t i = 0; i <= MapRowScale; ++i)
	{
		for (size_t j = 0; j <= MapColScale; ++j)
		{
			ArrayMap[i][j] = ArrayVisitMap[i][j] = 0;
		}
	}
}

PackManMap::~PackManMap()
{

}

void PackManMap::GenerateMapByBinaryTree()
{
    for (size_t i = 1; i <= MapRowScale; ++i)
    {
        for (size_t j = 1; j <= MapColScale; ++j)
        {
            if (i % 2 == 0 || j % 2 == 0)
            {
                ArrayMap[i][j] = WALL;
            }
            else
            {
                ArrayMap[i][j] = PATH;
            }
        }
    }

    // �������� ���� Ȥ�� �Ʒ��� ���� �ձ�.
    for (size_t i = 1; i <= MapRowScale; ++i)
    {
        for (size_t j = 1; j <= MapColScale; ++j)
        {
            if (i % 2 == 0 || j % 2 == 0) { continue; }
            if (i == MapRowScale - 2 && j == MapColScale - 2) { continue; }

            if (i == MapRowScale - 2)
            {
                ArrayMap[i][j + 1] = PATH; // ������ �� ���̸� �������θ� ����.
                continue;
            }
            if (j == MapColScale - 2) 
            {
                ArrayMap[i + 1][j] = PATH; // ������ �� ĭ�̸� �Ʒ��θ� ����.
                continue;
            }
            // �ٷ� �� ���������� ��¦ �ƽ��� ���� ������, �׿ܷδ� ���� ����. 

            const size_t randNumber = ::rand() % 2;
            if (0 == randNumber) { ArrayMap[i][j + 1] = PATH; }
            else { ArrayMap[i + 1][j] = PATH; }
        }
    }
}
