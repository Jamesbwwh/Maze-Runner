#include <Windows.h>
#include "Maze-Runner.h"

using namespace System;
using namespace System::Windows::Forms;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Application::Run(gcnew MazeRunner::MazeRunner);
}
