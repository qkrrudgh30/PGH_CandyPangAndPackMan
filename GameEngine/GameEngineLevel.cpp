// GameEngineLevel.cpp

#include "GameEngineLevel.h"
#include "GameEngineActor.h"
#include "GameEngineCollision.h"

GameEngineLevel::GameEngineLevel()
    : CameraPos_(float4::ZERO)
{
}

GameEngineLevel::~GameEngineLevel()
{
    std::map<int, std::list<GameEngineActor*>>::iterator GroupStart = AllActor_.begin();
    std::map<int, std::list<GameEngineActor*>>::iterator GroupEnd = AllActor_.end();

    for (; GroupStart != GroupEnd; ++GroupStart)
    {
        std::list<GameEngineActor*>& Group = GroupStart->second;

        std::list<GameEngineActor*>::iterator StartActor = Group.begin();
        std::list<GameEngineActor*>::iterator EndActor = Group.end();

        for (; StartActor != EndActor; ++StartActor)
        {
            if (nullptr == (*StartActor))
            {
                continue;
            }
            delete (*StartActor);
            (*StartActor) = nullptr;
        }
    }

}


void GameEngineLevel::ActorUpdate()
{
    std::map<int, std::list<GameEngineActor*>>::iterator GroupStart;
    std::map<int, std::list<GameEngineActor*>>::iterator GroupEnd;

    std::list<GameEngineActor*>::iterator StartActor;
    std::list<GameEngineActor*>::iterator EndActor;


    GroupStart = AllActor_.begin();
    GroupEnd = AllActor_.end();

    for (; GroupStart != GroupEnd; ++GroupStart)
    {
        std::list<GameEngineActor*>& Group = GroupStart->second;

        StartActor = Group.begin();
        EndActor = Group.end();

        for (; StartActor != EndActor; ++StartActor)
        {
            (*StartActor)->ReleaseUpdate();
            if (false == (*StartActor)->IsUpdate())
            {
                continue;
            }

            (*StartActor)->Update();
        }
    }
}
void GameEngineLevel::ActorRender()
{
    std::map<int, std::list<GameEngineActor*>>::iterator GroupStart;
    std::map<int, std::list<GameEngineActor*>>::iterator GroupEnd;

    std::list<GameEngineActor*>::iterator StartActor;
    std::list<GameEngineActor*>::iterator EndActor;


    GroupStart = AllActor_.begin();
    GroupEnd = AllActor_.end();

    for (; GroupStart != GroupEnd; ++GroupStart)
    {
        std::list<GameEngineActor*>& Group = GroupStart->second;

        StartActor = Group.begin();
        EndActor = Group.end();

        for (; StartActor != EndActor; ++StartActor)
        {
            if (false == (*StartActor)->IsUpdate())
            {
                continue;
            }
            (*StartActor)->Renderering();
        }


        StartActor = Group.begin();
        EndActor = Group.end();


        for (; StartActor != EndActor; ++StartActor)
        {
            if (false == (*StartActor)->IsUpdate())
            {
                continue;
            }

            (*StartActor)->Render();
        }
    }
}

void GameEngineLevel::CollisionDebugRender()
{
    std::map<std::string, std::list<GameEngineCollision*>>::iterator GroupStart = AllCollision_.begin();
    std::map<std::string, std::list<GameEngineCollision*>>::iterator GroupEnd = AllCollision_.end();

    std::list<GameEngineCollision*>::iterator StartCollision;
    std::list<GameEngineCollision*>::iterator EndCollision;

    for (; GroupStart != GroupEnd; ++GroupStart)
    {
        std::list<GameEngineCollision*>& Group = GroupStart->second;
        StartCollision = Group.begin();
        EndCollision = Group.end();
        for (; StartCollision != EndCollision; ++StartCollision)
        {
            if (false == (*StartCollision)->IsUpdate())
            {
                continue;
            }

            (*StartCollision)->DebugRender();
        }
    }
}

void GameEngineLevel::ActorRelease()
{
    // Collision under controls by Level.
    {
        std::map<std::string, std::list<GameEngineCollision*>>::iterator GroupStart = AllCollision_.begin();
        std::map<std::string, std::list<GameEngineCollision*>>::iterator GroupEnd = AllCollision_.end();

        std::list<GameEngineCollision*>::iterator StartCollision;
        std::list<GameEngineCollision*>::iterator EndCollision;


        for (; GroupStart != GroupEnd; ++GroupStart)
        {
            std::list<GameEngineCollision*>& Group = GroupStart->second;
            StartCollision = Group.begin();
            EndCollision = Group.end();
            for (; StartCollision != EndCollision; )
            {
                if (false == (*StartCollision)->IsDeath())
                {
                    ++StartCollision;
                    continue;
                }

                StartCollision = Group.erase(StartCollision);
            }
        }

    }

    // Delete Actor.
    {
        std::map<int, std::list<GameEngineActor*>>::iterator GroupStart;
        std::map<int, std::list<GameEngineActor*>>::iterator GroupEnd;

        std::list<GameEngineActor*>::iterator StartActor;
        std::list<GameEngineActor*>::iterator EndActor;

        GroupStart = AllActor_.begin();
        GroupEnd = AllActor_.end();

        for (; GroupStart != GroupEnd; ++GroupStart)
        {
            std::list<GameEngineActor*>& Group = GroupStart->second;

            StartActor = Group.begin();
            EndActor = Group.end();
            for (; StartActor != EndActor; )
            {
                if (true == (*StartActor)->IsDeath())
                {
                    delete* StartActor;
                    StartActor = Group.erase(StartActor);
                    continue;
                }

                // 삭제가 안됐다면 콜리전이나 랜더러를 확인해본다.
                (*StartActor)->Release();

                ++StartActor;
            }
        }
    }
}

void GameEngineLevel::AddCollision(const std::string& _GroupName, GameEngineCollision* _Collision)
{
    AllCollision_[_GroupName].push_back(_Collision);
}
