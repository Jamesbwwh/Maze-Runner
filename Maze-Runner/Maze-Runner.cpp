#include <msclr\marshal_cppstd.h>
#include <Windows.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <fstream>
#include "Maze-Runner.h"
#include "Maze.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

void RedirectIOToConsole();

[STAThread]
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	RedirectIOToConsole();
	Application::Run(gcnew MazeRunner::MazeRunner);
}

void RedirectIOToConsole()
{
	AllocConsole();
	*stdout = *_fdopen(_open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT), "w");
	setvbuf(stdout, NULL, _IONBF, 0);
	ios::sync_with_stdio();
}
