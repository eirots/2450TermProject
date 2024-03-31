#pragma once
#include "uvsimulator.h"
#include "file_serializer.h"

#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <Windows.h>
#include <msclr\marshal_cppstd.h>


namespace UVSIM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			uvsimulator = new UVSimulator();
			bool stopClicked = false;
			UpdatePCLabel();
			UpdateACLabel();
			PopulateMemoryGrid();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: bool stopClicked;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ counterVal;
	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ accumVal;
	private: System::Windows::Forms::Label^ title;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ inputCommand;
	private: System::Windows::Forms::TextBox^ inputValue;
	private: System::Windows::Forms::Button^ buttonAdd;




	private: System::Windows::Forms::DataGridView^ dataGridMemory;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ memAddress;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ memValue;
	private: System::Windows::Forms::TextBox^ console;
	private: System::Windows::Forms::Button^ buttonRun;
	private: System::Windows::Forms::Button^ buttonStop;
	private: System::Windows::Forms::Button^ buttonAddValue;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::TextBox^ screen;
	private: System::Windows::Forms::TextBox^ fileText;

	private: System::Windows::Forms::Button^ buttonOpen;
	private: System::Windows::Forms::Button^ buttonLoad;
	private: System::Windows::Forms::Button^ buttonEdit;



	private: System::Windows::Forms::Label^ fileLabel;
	private: System::Windows::Forms::Button^ buttonSave;

		   UVSimulator* uvsimulator;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle12 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->counterVal = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->accumVal = (gcnew System::Windows::Forms::Label());
			this->title = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->inputCommand = (gcnew System::Windows::Forms::TextBox());
			this->inputValue = (gcnew System::Windows::Forms::TextBox());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->dataGridMemory = (gcnew System::Windows::Forms::DataGridView());
			this->memAddress = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->memValue = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->console = (gcnew System::Windows::Forms::TextBox());
			this->buttonRun = (gcnew System::Windows::Forms::Button());
			this->buttonStop = (gcnew System::Windows::Forms::Button());
			this->buttonAddValue = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->screen = (gcnew System::Windows::Forms::TextBox());
			this->buttonOpen = (gcnew System::Windows::Forms::Button());
			this->buttonLoad = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->fileText = (gcnew System::Windows::Forms::TextBox());
			this->fileLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridMemory))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(42, 188);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Counter:";
			// 
			// counterVal
			// 
			this->counterVal->AutoSize = true;
			this->counterVal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->counterVal->Location = System::Drawing::Point(115, 188);
			this->counterVal->Name = L"counterVal";
			this->counterVal->Size = System::Drawing::Size(26, 20);
			this->counterVal->TabIndex = 1;
			this->counterVal->Text = L"pc";
			this->toolTip1->SetToolTip(this->counterVal, L"Displays your Program Counter, this is your current address.");
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(42, 218);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Accumulator:";
			// 
			// accumVal
			// 
			this->accumVal->AutoSize = true;
			this->accumVal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->accumVal->Location = System::Drawing::Point(150, 218);
			this->accumVal->Name = L"accumVal";
			this->accumVal->Size = System::Drawing::Size(26, 20);
			this->accumVal->TabIndex = 3;
			this->accumVal->Text = L"ac";
			this->toolTip1->SetToolTip(this->accumVal, L"Displays the value currently saved in the accumulator.");
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			this->title->Location = System::Drawing::Point(121, 95);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(122, 37);
			this->title->TabIndex = 4;
			this->title->Text = L"UVSim";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(42, 250);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(127, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Input Command:";
			this->label3->UseMnemonic = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(42, 282);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(95, 20);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Input Value:";
			this->label4->UseMnemonic = false;
			// 
			// inputCommand
			// 
			this->inputCommand->AcceptsReturn = true;
			this->inputCommand->AcceptsTab = true;
			this->inputCommand->Location = System::Drawing::Point(176, 249);
			this->inputCommand->MaxLength = 4;
			this->inputCommand->Name = L"inputCommand";
			this->inputCommand->Size = System::Drawing::Size(100, 20);
			this->inputCommand->TabIndex = 7;
			this->toolTip1->SetToolTip(this->inputCommand, L"Input your 4-digit operation here.");
			// 
			// inputValue
			// 
			this->inputValue->Enabled = false;
			this->inputValue->Location = System::Drawing::Point(143, 284);
			this->inputValue->MaxLength = 5;
			this->inputValue->Name = L"inputValue";
			this->inputValue->Size = System::Drawing::Size(100, 20);
			this->inputValue->TabIndex = 8;
			this->toolTip1->SetToolTip(this->inputValue, L"Input your 4 digit signed word here.");
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(104, 319);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(72, 33);
			this->buttonAdd->TabIndex = 9;
			this->buttonAdd->Text = L"ADD";
			this->toolTip1->SetToolTip(this->buttonAdd, L"Select to add value in the Input Command field to the memory address listed in Co"
				L"unter.");
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonAdd_Click);
			// 
			// dataGridMemory
			// 
			this->dataGridMemory->AllowUserToAddRows = false;
			this->dataGridMemory->AllowUserToDeleteRows = false;
			this->dataGridMemory->AllowUserToResizeColumns = false;
			this->dataGridMemory->AllowUserToResizeRows = false;
			dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle9->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle9->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle9->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle9->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridMemory->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle9;
			this->dataGridMemory->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridMemory->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->memAddress,
					this->memValue
			});
			dataGridViewCellStyle10->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle10->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle10->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle10->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle10->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle10->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridMemory->DefaultCellStyle = dataGridViewCellStyle10;
			this->dataGridMemory->Location = System::Drawing::Point(372, 218);
			this->dataGridMemory->MultiSelect = false;
			this->dataGridMemory->Name = L"dataGridMemory";
			this->dataGridMemory->ReadOnly = true;
			dataGridViewCellStyle11->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle11->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle11->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle11->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle11->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle11->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridMemory->RowHeadersDefaultCellStyle = dataGridViewCellStyle11;
			this->dataGridMemory->RowHeadersVisible = false;
			dataGridViewCellStyle12->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dataGridMemory->RowsDefaultCellStyle = dataGridViewCellStyle12;
			this->dataGridMemory->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridMemory->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridMemory->ShowEditingIcon = false;
			this->dataGridMemory->ShowRowErrors = false;
			this->dataGridMemory->Size = System::Drawing::Size(240, 360);
			this->dataGridMemory->TabIndex = 10;
			this->dataGridMemory->TabStop = false;
			this->toolTip1->SetToolTip(this->dataGridMemory, L"First column displays the memory address. The second column displays the value cu"
				L"rrently saved at that address.");
			this->dataGridMemory->SelectionChanged += gcnew System::EventHandler(this, &MyForm::dataGridMemory_SelectionChanged);
			// 
			// memAddress
			// 
			this->memAddress->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->memAddress->HeaderText = L"Address";
			this->memAddress->Name = L"memAddress";
			this->memAddress->ReadOnly = true;
			this->memAddress->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// memValue
			// 
			this->memValue->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->memValue->HeaderText = L"Value";
			this->memValue->Name = L"memValue";
			this->memValue->ReadOnly = true;
			this->memValue->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(449, 184);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(79, 24);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Memory";
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(442, 584);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(88, 33);
			this->buttonClear->TabIndex = 13;
			this->buttonClear->Text = L"CLEAR ALL";
			this->toolTip1->SetToolTip(this->buttonClear, L"Select to clear your program completely.");
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &MyForm::buttonClear_Click);
			// 
			// console
			// 
			this->console->HideSelection = false;
			this->console->Location = System::Drawing::Point(46, 431);
			this->console->Multiline = true;
			this->console->Name = L"console";
			this->console->ReadOnly = true;
			this->console->Size = System::Drawing::Size(278, 81);
			this->console->TabIndex = 12;
			this->console->TabStop = false;
			this->console->Text = L"Welcome to UVSim! Highlight fields for additional help.";
			this->toolTip1->SetToolTip(this->console, L"This will display prompts and messges to help you create your program.");
			// 
			// buttonRun
			// 
			this->buttonRun->Location = System::Drawing::Point(65, 372);
			this->buttonRun->Name = L"buttonRun";
			this->buttonRun->Size = System::Drawing::Size(72, 33);
			this->buttonRun->TabIndex = 10;
			this->buttonRun->Text = L"RUN";
			this->toolTip1->SetToolTip(this->buttonRun, L"Select to run your created program.");
			this->buttonRun->UseVisualStyleBackColor = true;
			this->buttonRun->Click += gcnew System::EventHandler(this, &MyForm::buttonRun_Click);
			// 
			// buttonStop
			// 
			this->buttonStop->Location = System::Drawing::Point(143, 372);
			this->buttonStop->Name = L"buttonStop";
			this->buttonStop->Size = System::Drawing::Size(72, 33);
			this->buttonStop->TabIndex = 11;
			this->buttonStop->Text = L"STOP";
			this->toolTip1->SetToolTip(this->buttonStop, L"Select to stop your program while it is running.");
			this->buttonStop->UseVisualStyleBackColor = true;
			this->buttonStop->Click += gcnew System::EventHandler(this, &MyForm::buttonStop_Click);
			// 
			// buttonAddValue
			// 
			this->buttonAddValue->Enabled = false;
			this->buttonAddValue->Location = System::Drawing::Point(249, 284);
			this->buttonAddValue->Name = L"buttonAddValue";
			this->buttonAddValue->Size = System::Drawing::Size(75, 23);
			this->buttonAddValue->TabIndex = 14;
			this->buttonAddValue->Text = L"ADD";
			this->toolTip1->SetToolTip(this->buttonAddValue, L"Select to add value in Input Value to the memory address noted in the console.");
			this->buttonAddValue->UseVisualStyleBackColor = true;
			this->buttonAddValue->Visible = false;
			this->buttonAddValue->Click += gcnew System::EventHandler(this, &MyForm::buttonAddValue_Click);
			// 
			// screen
			// 
			this->screen->HideSelection = false;
			this->screen->Location = System::Drawing::Point(46, 536);
			this->screen->Multiline = true;
			this->screen->Name = L"screen";
			this->screen->ReadOnly = true;
			this->screen->Size = System::Drawing::Size(278, 81);
			this->screen->TabIndex = 15;
			this->screen->TabStop = false;
			this->screen->Text = L"Program outputs will display here.";
			this->toolTip1->SetToolTip(this->screen, L"This will display values printed to screen whent he program is run.");
			// 
			// buttonOpen
			// 
			this->buttonOpen->Location = System::Drawing::Point(573, 110);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(75, 23);
			this->buttonOpen->TabIndex = 17;
			this->buttonOpen->Text = L"OPEN";
			this->toolTip1->SetToolTip(this->buttonOpen, L"Select to browse a file path to open or edit.");
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &MyForm::buttonOpen_Click);
			// 
			// buttonLoad
			// 
			this->buttonLoad->Location = System::Drawing::Point(372, 136);
			this->buttonLoad->Name = L"buttonLoad";
			this->buttonLoad->Size = System::Drawing::Size(75, 23);
			this->buttonLoad->TabIndex = 18;
			this->buttonLoad->Text = L"LOAD";
			this->toolTip1->SetToolTip(this->buttonLoad, L"Select to load the program file chosen.");
			this->buttonLoad->UseVisualStyleBackColor = true;
			this->buttonLoad->Click += gcnew System::EventHandler(this, &MyForm::buttonLoad_Click);
			// 
			// buttonEdit
			// 
			this->buttonEdit->Location = System::Drawing::Point(453, 136);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(75, 23);
			this->buttonEdit->TabIndex = 19;
			this->buttonEdit->Text = L"EDIT";
			this->toolTip1->SetToolTip(this->buttonEdit, L"Select to edit the file chosen.");
			this->buttonEdit->UseVisualStyleBackColor = true;
			this->buttonEdit->Click += gcnew System::EventHandler(this, &MyForm::buttonEdit_Click);
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(534, 136);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(75, 23);
			this->buttonSave->TabIndex = 21;
			this->buttonSave->Text = L"SAVE";
			this->toolTip1->SetToolTip(this->buttonSave, L"Select to save current program to a file.");
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &MyForm::buttonSave_Click);
			// 
			// fileText
			// 
			this->fileText->Location = System::Drawing::Point(372, 110);
			this->fileText->Name = L"fileText";
			this->fileText->Size = System::Drawing::Size(195, 20);
			this->fileText->TabIndex = 16;
			// 
			// fileLabel
			// 
			this->fileLabel->AutoSize = true;
			this->fileLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->fileLabel->Location = System::Drawing::Point(368, 87);
			this->fileLabel->Name = L"fileLabel";
			this->fileLabel->Size = System::Drawing::Size(110, 20);
			this->fileLabel->TabIndex = 20;
			this->fileLabel->Text = L"Load/Edit File:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(692, 685);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->fileLabel);
			this->Controls->Add(this->buttonEdit);
			this->Controls->Add(this->buttonLoad);
			this->Controls->Add(this->buttonOpen);
			this->Controls->Add(this->fileText);
			this->Controls->Add(this->screen);
			this->Controls->Add(this->buttonAddValue);
			this->Controls->Add(this->buttonStop);
			this->Controls->Add(this->buttonRun);
			this->Controls->Add(this->console);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->dataGridMemory);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->inputValue);
			this->Controls->Add(this->inputCommand);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->title);
			this->Controls->Add(this->accumVal);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->counterVal);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridMemory))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		String^ filePath = "";
		void PopulateMemoryGrid()
		{
			// Clear existing rows
			dataGridMemory->Rows->Clear();

			// Access memory data from UVSimulator
			std::vector<int> memory;
			for (int i = 0; i < 100; ++i) {
				memory.push_back(uvsimulator->getMemory(i));
			}

			// Populate DataGridView with memory data

			for (size_t i = 0; i < memory.size(); ++i) {

				String^ address = i.ToString("D2");
				dataGridMemory->Rows->Add(address, memory[i].ToString());
			}
		}
	private:
		System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {
			if (ValidateInputCommand(inputCommand->Text)){
				int pcValue = uvsimulator->getPC();
				int commandVal = System::Convert::ToInt16(inputCommand->Text);
				uvsimulator->setMemory(pcValue, commandVal);
				uvsimulator->setPC(pcValue + 1);
				inputCommand->Text = "";
				console->Text = "Select RUN to process your program when all commands have been added.";
				UpdatePCLabel();
				PopulateMemoryGrid();
			}
			else {
				console->Text = "Invalid input. Commands are 4-digit opcodes.";
			}
		}
		System::Void buttonRun_Click(System::Object^ sender, System::EventArgs^ e) {
			buttonRun->Enabled = false;
			int startPC = uvsimulator->getPC();
			uvsimulator->setPC(0);
			int pc;
			stopClicked = false;
			screen->Text = "";
			do{
				pc = uvsimulator->getPC();
				int instruction = uvsimulator->getMemory(pc);
				int opcode = instruction / 100;
				int operand = instruction % 100;

				switch (opcode) {
				case 10:
				{
					UpdatePCLabel();
					console->Text = "Enter your word from keyboard at location "
						+ operand.ToString() + " (e.g. +1234)";
					inputValue->Enabled = true;
					inputCommand->Enabled = false;
					buttonAddValue->Enabled = true;
					buttonAddValue->Visible = true;
					buttonAdd->Enabled = false;
					buttonAdd->Visible = false;
					while (buttonAdd->Visible == false) {
						Application::DoEvents();
						System::Threading::Thread::Sleep(100);
					}
					uvsimulator->setPC(pc + 1);
				}break;
				case 11:
				{
					UpdatePCLabel();
					int word = uvsimulator->getMemory(operand);
					if (screen->Text == "") {
						screen->Text += word.ToString();
					}
					else {
						screen->Text += Environment::NewLine + word.ToString();
					}
					uvsimulator->setPC(pc + 1);
				}break;
				default:
					uvsimulator->executeProgram(instruction);
					UpdatePCLabel();
					UpdateACLabel();
					break;
				}
				if (stopClicked) {
					break; // Exit the loop if "STOP" button is clicked
				}

			} while (pc < 100 && pc >= 0);
			PopulateMemoryGrid();
			buttonRun->Enabled = true;
			console->Text = "Program process complete!";
			uvsimulator->setPC(startPC);
			UpdatePCLabel();
			
		}
		System::Void buttonStop_Click(System::Object^ sender, System::EventArgs^ e) {
			
			stopClicked = true;
			buttonAddValue->Enabled = false;
			buttonAddValue->Visible = false;
			inputValue->Text = "";
			console->Text = "Process stopped";
			inputValue->Enabled = false;
			inputCommand->Enabled = true;
			buttonAdd->Enabled = true;
			buttonAdd->Visible = true;
			UpdatePCLabel();
		}
		System::Void buttonAddValue_Click(System::Object^ sender, System::EventArgs^ e) {
			if (ValidateInputValue(inputValue->Text)) {
				int pcValue = uvsimulator->getPC();
				int instruction = uvsimulator->getMemory(pcValue);
				int operand = instruction % 100;
				int value;
				if (Int32::TryParse(inputValue->Text, value)) {
;
					uvsimulator->setMemory(operand, value);
					PopulateMemoryGrid();

					buttonAddValue->Enabled = false;
					buttonAddValue->Visible = false;
					buttonAdd->Enabled = true;
					buttonAdd->Visible = true;
					inputValue->Text = "";
					console->Text = "";
					inputValue->Enabled = false;
					inputCommand->Enabled = true;
				}
			}
			else {
				console->Text = "Invalid input. Values are 4-digit signed decimal number (+/-1234).";
			}
		}
		System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) {
			for (int i = 0; i < 100; ++i) {
				uvsimulator->setMemory(i, 0);
			}
			uvsimulator->setPC(0);
			uvsimulator->setAccumulator(0);
			inputValue->Text = "";
			inputCommand->Text = "";
			console->Text = L"Welcome to UVSim! Highlight fields for additional help.";
			screen->Text = L"Program outputs will display here.";
			UpdatePCLabel();
			UpdateACLabel();
			PopulateMemoryGrid();
		}
		
		System::Void buttonOpen_Click(System::Object^ sender, System::EventArgs^ e)
		{
			// Create an instance of the OpenFileDialog class
			OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

			// Set properties for the file dialog
			openFileDialog1->Filter = "Text Files|*.txt|All Files|*.*"; // Specify the file types to be displayed
			openFileDialog1->Title = "Select a File"; // Set the dialog title
			openFileDialog1->Multiselect = false; // Allow only single file selection

			// Show the file dialog and check if the user selects a file
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				// Get the selected file path
				System::String^ filePath = openFileDialog1->FileName;

				// Convert System::String^ to std::string
				std::string selectedFilePath = msclr::interop::marshal_as<std::string>(filePath);
				fileText->Text = filePath;
			}
	
		}
		//Currently non-functional, issue saving/loading to bin
		System::Void buttonLoad_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ filePath = fileText->Text;
			if (filePath == "") {
				console->Text = "Select a file path before loading.";
			}
			else {}
		}
		//Currently non-functional, issue saving/loading to bin
		System::Void buttonEdit_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ filePath = fileText->Text;
			if (filePath == "") {
				console->Text = "Select a file path before editing.";
			}
			else {}
		}
		//Currently non-functional, issue saving/loading to bin
		System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e)
		{}
		// Custom method to update the label with the value of the "pc" variable
		void UpdatePCLabel()
		{
			// Access the value of the "pc" variable using the getPC() member function of UVSimulator
			int pcValue = uvsimulator->getPC();

			// Update the text of the label to display the value of the "pc" variable
			counterVal->Text = pcValue.ToString();
		}
		void UpdateACLabel()
		{
			// Access the value of the "acummulator" variable using the getAccumulator() member function of UVSimulator
			int acValue = uvsimulator->getAccumulator();

			// Update the text of the label to display the value of the "accumulator" variable
			accumVal->Text = acValue.ToString();
		}
		void dataGridMemory_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
			// Clear the selection to prevent rows or cells from being selected
			dataGridMemory->ClearSelection();
		}
		bool ValidateInputCommand(String^ inputCommand) {
			// Check if the inputCommand is empty or null
			if (String::IsNullOrEmpty(inputCommand)) {
				return false;
			}

			// Check if the inputCommand has exactly 4 characters
			if (inputCommand->Length != 4) {
				return false;
			}

			// Check if all characters in the inputCommand are digits
			for each (char c in inputCommand) {
				if (!Char::IsDigit(c)) {
					return false;
				}
			}

			// If all checks pass, return true
			return true;
		}
		bool ValidateInputValue(String^ inputValue) {
			if (String::IsNullOrEmpty(inputValue)) {
				return false;
			}
			if (inputValue->Length != 5) {
				return false;
			}
			return ValidateInputValueFormat(inputValue);
		}
		bool ValidateInputValueFormat(System::String^ inputValue) {
			// Convert System::String^ to std::string
			std::string inputStr = msclr::interop::marshal_as<std::string>(inputValue);

			// Regular expression pattern to match a 4-digit signed integer
			std::regex pattern("^[-+]?\\d{4}$");

			// Check if the input matches the pattern
			if (std::regex_match(inputStr, pattern)) {
				return true;
			}
			else {
				return false;
			}
		}
	};
}
