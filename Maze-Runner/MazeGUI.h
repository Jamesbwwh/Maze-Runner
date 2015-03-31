#include <jni.h>
#include "MazeAlgorithm.h"
#include "Maze.h"

using namespace std;

JNIEnv* create_vm(JavaVM *jvm);
void RedirectIOToConsole();

#pragma once

namespace MazeRunner {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MazeGUI
	/// </summary>
	public ref class MazeGUI : public System::Windows::Forms::Form
	{
	public:
		MazeGUI(void)
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
		~MazeGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: JavaVM *jvm;
	private: JNIEnv *env = create_vm(jvm);
	private: jclass cls = env->FindClass("DepthFirstSearch");
	private: int width, height, cellWidth, cellHeight;
	private: Maze* maze;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;
	private: System::Windows::Forms::MenuStrip^  mnuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::TableLayoutPanel^  tblPanel;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;


	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;


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
			this->tblPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->mnuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->tblPanel->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->mnuStrip->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// tblPanel
			// 
			this->tblPanel->AutoSize = true;
			this->tblPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tblPanel->ColumnCount = 2;
			this->tblPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tblPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 75)));
			this->tblPanel->Controls->Add(this->tableLayoutPanel1, 0, 0);
			this->tblPanel->Controls->Add(this->pictureBox1, 1, 0);
			this->tblPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tblPanel->Location = System::Drawing::Point(0, 24);
			this->tblPanel->Name = L"tblPanel";
			this->tblPanel->RowCount = 1;
			this->tblPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tblPanel->Size = System::Drawing::Size(484, 438);
			this->tblPanel->TabIndex = 0;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox2, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->button1, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->button2, 0, 12);
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->label6, 0, 9);
			this->tableLayoutPanel1->Controls->Add(this->button3, 0, 11);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel5, 0, 10);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 13;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->Size = System::Drawing::Size(115, 432);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Row:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Location = System::Drawing::Point(3, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Column:";
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Location = System::Drawing::Point(3, 16);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(109, 20);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox2->Location = System::Drawing::Point(3, 55);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(109, 20);
			this->textBox2->TabIndex = 3;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->AutoSize = true;
			this->tableLayoutPanel2->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->radioButton1, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->radioButton2, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->radioButton3, 0, 3);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 81);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 4;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->Size = System::Drawing::Size(109, 87);
			this->tableLayoutPanel2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Location = System::Drawing::Point(4, 1);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(101, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Maze Generation";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->radioButton1->Location = System::Drawing::Point(4, 18);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(101, 17);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"None";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->radioButton2->Location = System::Drawing::Point(4, 42);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(101, 17);
			this->radioButton2->TabIndex = 2;
			this->radioButton2->Text = L"DFS";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->radioButton3->Location = System::Drawing::Point(4, 66);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(101, 17);
			this->radioButton3->TabIndex = 3;
			this->radioButton3->Text = L"Hunt and Kill";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->AutoSize = true;
			this->tableLayoutPanel3->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel3->Controls->Add(this->label4, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->radioButton4, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->radioButton5, 0, 2);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 203);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 3;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->Size = System::Drawing::Size(109, 63);
			this->tableLayoutPanel3->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(4, 1);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Maze Solving";
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Checked = true;
			this->radioButton4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->radioButton4->Location = System::Drawing::Point(4, 18);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(101, 17);
			this->radioButton4->TabIndex = 1;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"None";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->radioButton5->Location = System::Drawing::Point(4, 42);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(101, 17);
			this->radioButton5->TabIndex = 2;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"DFS";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Top;
			this->button1->Location = System::Drawing::Point(3, 174);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Run Generator";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MazeGUI::button1_Click);
			// 
			// button2
			// 
			this->button2->AutoSize = true;
			this->button2->Dock = System::Windows::Forms::DockStyle::Top;
			this->button2->Location = System::Drawing::Point(3, 391);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(109, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Save Image";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MazeGUI::button2_Click);
			// 
			// label5
			// 
			this->label5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label5->Location = System::Drawing::Point(3, 269);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(109, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Src (Row, Col):";
			// 
			// label6
			// 
			this->label6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label6->Location = System::Drawing::Point(3, 314);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(109, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Dst (Row, Col):";
			// 
			// button3
			// 
			this->button3->Dock = System::Windows::Forms::DockStyle::Top;
			this->button3->Location = System::Drawing::Point(3, 362);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(109, 23);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Run Solver";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MazeGUI::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(124, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(357, 432);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MazeGUI::pictureBox1_Paint);
			// 
			// mnuStrip
			// 
			this->mnuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			this->mnuStrip->Location = System::Drawing::Point(0, 0);
			this->mnuStrip->Name = L"mnuStrip";
			this->mnuStrip->Size = System::Drawing::Size(484, 24);
			this->mnuStrip->TabIndex = 1;
			this->mnuStrip->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->loadToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->loadToolStripMenuItem->Text = L"Load";
			this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MazeGUI::loadToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MazeGUI::exitToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->AutoSize = true;
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->Controls->Add(this->textBox3, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->textBox4, 1, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 285);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(109, 26);
			this->tableLayoutPanel4->TabIndex = 11;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->AutoSize = true;
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel5->Controls->Add(this->textBox5, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->textBox6, 1, 0);
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 330);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(109, 26);
			this->tableLayoutPanel5->TabIndex = 12;
			// 
			// textBox3
			// 
			this->textBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox3->Location = System::Drawing::Point(3, 3);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(48, 20);
			this->textBox3->TabIndex = 0;
			// 
			// textBox4
			// 
			this->textBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox4->Location = System::Drawing::Point(57, 3);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(49, 20);
			this->textBox4->TabIndex = 1;
			// 
			// textBox5
			// 
			this->textBox5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox5->Location = System::Drawing::Point(3, 3);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(48, 20);
			this->textBox5->TabIndex = 0;
			// 
			// textBox6
			// 
			this->textBox6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox6->Location = System::Drawing::Point(57, 3);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(49, 20);
			this->textBox6->TabIndex = 1;
			// 
			// MazeGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 462);
			this->Controls->Add(this->tblPanel);
			this->Controls->Add(this->mnuStrip);
			this->Name = L"MazeGUI";
			this->Text = L"Maze Runner";
			this->SizeChanged += gcnew System::EventHandler(this, &MazeGUI::MazeGUI_SizeChanged);
			this->tblPanel->ResumeLayout(false);
			this->tblPanel->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->mnuStrip->ResumeLayout(false);
			this->mnuStrip->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: jobject sendMazeJava() {
		jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");

		string toChar = maze->returnString();
		char *cstr = new char[toChar.length() + 1];
		strcpy(cstr, toChar.c_str());
		jstring toSend = env->NewStringUTF(cstr);

		jobject dfsObject = env->NewObject(cls, mid, toSend);
		return dfsObject;
	}

	private: void solveMazeDFS(jobject dfsObject, int x, int y) {
		jmethodID mid = env->GetMethodID(cls, "solveMaze", "(II)Z");
		env->CallNonvirtualVoidMethod(dfsObject, cls, mid, x, y);
	}

	private: void returnMaze(jobject dfsObject) {
		jmethodID mid = env->GetMethodID(cls, "returnString", "()Ljava/lang/String;");
		jstring returnString = (jstring)env->CallNonvirtualObjectMethod(dfsObject, cls, mid);

		const char *js = env->GetStringUTFChars(returnString, NULL);
		string toString = string(js);

		maze = new Maze(toString);
		env->ReleaseStringUTFChars(returnString, js);
	}

	private: void canvasSize() {
		width = pictureBox1->Width;
		height = pictureBox1->Height;
		cellWidth = width / maze->getCol();
		cellHeight = height / maze->getRow();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!radioButton1->Checked)
		{
			maze = new Maze(int::Parse(textBox1->Text), int::Parse(textBox2->Text));
			canvasSize();
		}
		if (radioButton2->Checked)
		{
			MazeAlgorithm::DFS(maze);
		}
		else if (radioButton3->Checked)
		{
			MazeAlgorithm::HAK(maze);
		}
		this->Refresh();
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void loadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		openFileDialog = gcnew OpenFileDialog();
		openFileDialog->Filter = "Text Files|*.txt";
		openFileDialog->Title = "Select a Text File";
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			StreamReader^ sr = gcnew StreamReader(openFileDialog->FileName);
			String^ strText = "";
			strText = sr->ReadToEnd();
			sr->Close();
			std::string strRaw = msclr::interop::marshal_as<std::string>(strText);
			maze = new Maze(strRaw);
			canvasSize();
			this->Refresh();
		}
	}
	private: System::Void MazeGUI_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		canvasSize();
	}
	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		if (maze != NULL)
		{
			Graphics^ g = e->Graphics;
			SolidBrush^ theBrush;
			for (int i = 0; i < maze->getRow(); i++) {
				for (int j = 0; j < maze->getCol(); j++) {
					switch (maze->getMaze(i, j)) {
					case Maze::WALL:
						theBrush = gcnew SolidBrush(Color::Black);//Pen(*color[Maze::WALL]);
						break;
					case Maze::UNEXPLORED:
					case Maze::GLADER:
						theBrush = gcnew SolidBrush(Color::White);//Pen(*color[Maze::UNEXPLORED]);
						break;
					case Maze::VISITED:
						theBrush = gcnew SolidBrush(Color::Yellow);//Pen(*color[Maze::VISITED]);
						break;
					case Maze::PATH:
					case Maze::GRIEVER:
						theBrush = gcnew SolidBrush(Color::Red);//Pen(*color[Maze::PATH]);
						break;
					default:
						break;
					}
					g->FillRectangle(theBrush, j * cellWidth, i * cellHeight, cellWidth, cellHeight);
					switch (maze->getMaze(i, j)) {
					case Maze::GLADER:
						theBrush = gcnew SolidBrush(Color::Orange);//Pen(*color[Maze::GLADER]);
						break;
					case Maze::GRIEVER:
						theBrush = gcnew SolidBrush(Color::Pink);//Pen(*color[Maze::GRIEVER]);
						break;
					default:
						break;
					}
					g->FillEllipse(theBrush, j * cellWidth, i * cellHeight, cellWidth, cellHeight);
				}
			}
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (maze != NULL)
		{
			saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->Filter = "Text Files|*.txt";
			saveFileDialog->Title = "Select a Text File";
			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				StreamWriter^ sw = gcnew StreamWriter(saveFileDialog->FileName);
				string strRaw = maze->returnString();
				String^ strText = msclr::interop::marshal_as<System::String^>(strRaw);
				sw->WriteLine(strText);
				sw->Close();
			}
		}
		else
		{
			MessageBox::Show("Error -> Maze Not Loaded!");
		}
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (radioButton5->Checked)
		{
			pair<int, int> src = { int::Parse(textBox3->Text), int::Parse(textBox4->Text) };
			pair<int, int> dst = { int::Parse(textBox5->Text), int::Parse(textBox6->Text) };
			maze->setMaze(dst.first, dst.second, Maze::GLADER);
			jobject javaMaze = sendMazeJava();
			solveMazeDFS(javaMaze, src.first, src.second);
			returnMaze(javaMaze);
			this->Refresh();
		}
	}
	};
}

JNIEnv* create_vm(JavaVM *jvm)
{
	HINSTANCE hinstLib = LoadLibrary(L"C:\\Program Files (x86)\\Java\\jdk1.8.0_40\\jre\\bin\\client\\jvm.dll");
	typedef jint(JNICALL *PtrCreateJavaVM)(JavaVM**, void**, void*);
	PtrCreateJavaVM ptrCreateJavaVM = (PtrCreateJavaVM)GetProcAddress(hinstLib, "JNI_CreateJavaVM");

	JNIEnv *env;
	JavaVMInitArgs vm_args;
	JavaVMOption options;

	options.optionString = "-Djava.class.path=..\\bin";
	vm_args.version = JNI_VERSION_1_8;
	vm_args.nOptions = 1;
	vm_args.options = &options;
	vm_args.ignoreUnrecognized = 0;

	int ret = ptrCreateJavaVM(&jvm, (void**)&env, &vm_args);
	if (ret < 0) cout << ("\nUnable to Launch JVM\n");
	return env;
}

void RedirectIOToConsole()
{
	AllocConsole();
	*stdout = *_fdopen(_open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT), "w");
	setvbuf(stdout, NULL, _IONBF, 0);
	ios::sync_with_stdio();
}
