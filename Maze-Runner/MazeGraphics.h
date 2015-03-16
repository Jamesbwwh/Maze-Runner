#include "Maze.h"

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace MazeRunner {

	/// <summary>
	/// Summary for MazeGraphics
	/// </summary>
	public ref class MazeGraphics : public System::Windows::Forms::UserControl
	{
	private:
		int width, height, cellWidth, cellHeight, left, top;
		Maze *theMaze;
	public:
		static array<Color ^ >^ color = gcnew array < Color ^ >
		{
			Color::White,
			Color::Black,
			Color::Yellow,
			Color::Red,
			Color::Pink,
			Color::Orange
		};
		void paint(Graphics^ g);
		void canvasSize();
		static void updateGraphics(MazeGraphics g);
	public:
		MazeGraphics(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MazeGraphics()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// MazeGraphics
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->button1);
			this->Name = L"MazeGraphics";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
