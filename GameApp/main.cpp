// main.cpp

#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>

int __stdcall WinMain(_In_ HINSTANCE    hInstance,
    _In_opt_ HINSTANCE                  hPrevInstance,
    _In_ char*                          lpCmdLine,
    _In_ int                            nCmdShow)
{
    GameEngineWindow::GetInst().CreateGameWindow(nullptr, "PackMan");
    GameEngineWindow::GetInst().ShowGameWindow();

    return 0;
}