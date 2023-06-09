#pragma once
#include"GameWillRun.h"
enum Modes  { None = 0,Easy,Medium,Hard };
Modes M=None;
namespace Snake 
{

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
		array<Button^>^ Modes = gcnew array<Button^>(3);
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			for (int i = 0; i < 3; i++)
			{
				this->Modes[i] = (gcnew System::Windows::Forms::Button());	////
				this->Modes[i]->Location = System::Drawing::Point(307, 236 + i * 102);
				this->Modes[i]->Size = System::Drawing::Size(184, 75);
				//this->Modes[i]->TabIndex = 0;
				//this->Modes[i]->Text = L" ";
				this->Modes[i]->UseMnemonic = false;
				this->Modes[i]->UseVisualStyleBackColor = true;
				this->Modes[i]->Hide();
				this->Controls->Add(this->Modes[i]);
			}
			Modes[0]->Image = System::Drawing::Image::FromFile("E.png");
			this->Modes[0]->Click += gcnew System::EventHandler(this, &MyForm::E_Click);
			Modes[1]->Image = System::Drawing::Image::FromFile("M.png");
			this->Modes[1]->Click += gcnew System::EventHandler(this, &MyForm::M_Click);
			Modes[2]->Image = System::Drawing::Image::FromFile("H.png");
			this->Modes[2]->Click += gcnew System::EventHandler(this, &MyForm::H_Click);
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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	private: System::ComponentModel::IContainer^  components;	////
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->Location = System::Drawing::Point(307, 276);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(184, 75);
			this->button1->TabIndex = 0;
			this->button1->Text = L" ";
			this->button1->UseMnemonic = false;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->Location = System::Drawing::Point(307, 378);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(184, 75);
			this->button2->TabIndex = 1;
			this->button2->Text = L" ";
			this->button2->UseMnemonic = false;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(800, 600);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		button1->Hide();
		button2->Hide();
		for (int i = 0; i < 3; i++)
		{
			Modes[i]->Show();
		}
	}
	private: System::Void E_Click(System::Object^  sender, System::EventArgs^  e)
	{
		M = Easy;
		Play();
	}
	private: System::Void M_Click(System::Object^  sender, System::EventArgs^  e)
	{
		M = Medium;
		Play();
	}
	private: System::Void H_Click(System::Object^  sender, System::EventArgs^  e)
	{
		M = Hard;
		Play();
	}
	Void Play() 
	{
		if (M != None)
		{
			GameWillRun Game(M);
			this->Hide();
			Game.ShowDialog();
			//after game ending
			button1->Show();
			button2->Show();
			for (int i = 0; i < 3; i++)
			{
				Modes[i]->Hide();
			}
			this->Show();
		}
			
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Close();
}
};
}
