#include <msclr\marshal_cppstd.h>
#include <Windows.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include "MazeGUI.h"

[System::STAThread]
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	System::Windows::Forms::Application::Run(gcnew MazeRunner::MazeGUI);
}

//RedirectIOToConsole();
//JavaVM *jvm;
//JNIEnv *env = create_vm(jvm);
//jclass cls = env->FindClass("Hello");
//jmethodID mid = env->GetStaticMethodID(cls, "World", "()Ljava/lang/String;");
//jstring returnString = (jstring)env->CallStaticObjectMethod(cls, mid);
//const char *js = env->GetStringUTFChars(returnString, NULL);
//cout << js;
//RedirectIOToConsole();
//this->Refresh();
//maze->printString();
//cout << js << endl;
//cout << width << " " << height << " " << cellWidth << " " << cellHeight << endl;
