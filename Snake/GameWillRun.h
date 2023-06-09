#pragma once
#include<iostream>
#include<ctime>

namespace Snake 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	enum direction { STOP = 0, UP, DOWN, LEFT, RIGHT };
	/// <summary>
	/// Summary for GameWillRun
	/// </summary>
	public ref class GameWillRun : public System::Windows::Forms::Form
	{
		bool game_over;
		const int height = 25, width = 25;
		int tail_length = 0;
		int x, y, food_x, food_y;
		int score;
		direction DIRECT;
		int noOFLabelused = 0;
		double x2 = 22, y2 = 22;
		array<Label^>^ arr = gcnew array<Label^>(625);
		array<int^>^ tail_x = gcnew array<int^>(625);
		array<int^>^ tail_y = gcnew array<int^>(625);
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label2;
			 
	public:
		GameWillRun(int m)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			START_GAME(m);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GameWillRun()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
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
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &GameWillRun::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->label1->Location = System::Drawing::Point(29, 2);
			this->label1->MinimumSize = System::Drawing::Size(667, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(667, 25);
			this->label1->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label4->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->label4->Location = System::Drawing::Point(4, 2);
			this->label4->MaximumSize = System::Drawing::Size(25, 666);
			this->label4->MinimumSize = System::Drawing::Size(25, 666);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(25, 666);
			this->label4->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label3->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->label3->Location = System::Drawing::Point(693, 2);
			this->label3->MaximumSize = System::Drawing::Size(25, 666);
			this->label3->MinimumSize = System::Drawing::Size(25, 666);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(25, 666);
			this->label3->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label2->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->label2->Location = System::Drawing::Point(29, 644);
			this->label2->MinimumSize = System::Drawing::Size(667, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(667, 25);
			this->label2->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label5->Location = System::Drawing::Point(77, 674);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(107, 22);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Score = 0 ";
			// 
			// GameWillRun
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(730, 700);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"GameWillRun";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &GameWillRun::GameWillRun_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GameWillRun::GameWillRun_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void START_GAME(int m)
		{
			switch (m)
			{
			case 1:
				this->timer1->Enabled = true;
				this->timer1->Interval = 160;
				break;
			case 2:
				this->timer1->Enabled = true;
				this->timer1->Interval = 130;
				break;
			case 3:
				this->timer1->Enabled = true;
				this->timer1->Interval = 100;
				break;
			}
			for (int i = 0; i < 625; i++)
			{
				this->arr[i] = (gcnew System::Windows::Forms::Label());
				this->tail_x[i] = (gcnew int());
				this->tail_y[i] = (gcnew int());
				this->arr[i]->Hide();
				this->Controls->Add(this->arr[i]);
				this->arr[i]->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->arr[i]->Margin = System::Windows::Forms::Padding(0);
				this->arr[i]->MaximumSize = System::Drawing::Size(20, 20);
				this->arr[i]->MinimumSize = System::Drawing::Size(20, 20);
				this->arr[i]->Name = L"arr[i]";
				this->arr[i]->Size = System::Drawing::Size(20, 20);
				this->arr[i]->TabIndex = 0;
				this->arr[i]->Text = L" ";
			}
			game_over = false;
			score = 0;
			DIRECT = STOP;
			srand(time(NULL));
			food_x = rand() % width;
			food_y = rand() % height;
			x = width / 2;
			y = height / 2;

		}
		bool checkInArray(int fx,int fy)
		{
			for (int i = 0; i < tail_length; i++)
			{
				if (*tail_x[i] ==fx&&*tail_y[i]==y)
				{
					return 0;
				}
			}
			return 1;
		}
		void SNAKE_GROWTH()
		{
			int X1 = *tail_x[0];
			int Y1 = *tail_y[0];
			int prev_x, prev_y;
			*tail_x[0] = x;
			*tail_y[0] = y;
			for (int i = 1; i < tail_length - 1; i++)
			{
				prev_x = *tail_x[i];
				prev_y = *tail_y[i];
				*tail_x[i] = X1;
				*tail_y[i] = Y1;
				X1 = prev_x;
				Y1 = prev_y;
			}
			//for snake movement
			switch (DIRECT)
			{
			case LEFT:
				y--;
				break;
			case RIGHT:
				y++;
				break;
			case UP:
				x--;
				break;
			case DOWN:
				x++;
				break;
			default:
				break;
			}
			//gameover on hitting the wall
			if (x > width - 1 || x < 0 || y > height - 1 || y < 0)
				game_over = true;
			for (int i = 0; i < tail_length - 1; i++)
				//if the snake touches itself 
				//the game would be over
				if (*tail_x[i] == x && *tail_y[i] == y)
					game_over = true;
			if (x == food_x && y == food_y)
			{
				score += 1;
				this->label5->Text = "Score = " + score;
				srand(time(NULL));	
				tail_length++;
				*tail_x[tail_length] = -1;
				*tail_y[tail_length] = -1;
				do
				{
					food_x = rand() % width;
					food_y = rand() % height;
					if (food_x == x&&food_y == y)
					{
						continue;
					}
					else if (checkInArray(food_x, food_y) == 0)
					{
						continue;
					}
					else
						break;
				} while (1);
			}

		}
		void DISPLAY()
		{
			noOFLabelused = 0;
			//for printing the whole board
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (i == y && j == x)
					{
						this->arr[noOFLabelused]->Location = System::Drawing::Point(i * 20 + x2, j * 20 + y2);
						this->arr[noOFLabelused]->BackColor = System::Drawing::Color::Pink;
						arr[noOFLabelused]->Show();
						noOFLabelused++;
					}
					else if (i == food_y && j == food_x)
					{
						this->arr[noOFLabelused]->Location = System::Drawing::Point(i * 20 + x2, j * 20 + y2);
						this->arr[noOFLabelused]->BackColor = System::Drawing::Color::Green;
						arr[noOFLabelused]->Show();
						noOFLabelused++;
					}
					else
					{
						bool print = false;
						for (int k = 0; k<tail_length; k++)
						{
							if (*tail_x[k] == -1) 
								continue;
							if (*tail_x[k] == j && *tail_y[k] == i)
							{
								this->arr[noOFLabelused]->Location = System::Drawing::Point(i * 20 + x2, j * 20 + y2);
								this->arr[noOFLabelused]->BackColor = System::Drawing::Color::Red;
								arr[noOFLabelused]->Show();
								noOFLabelused++;
								print = true;
							}
						}
						if (!print)
						{
							this->arr[noOFLabelused]->Location = System::Drawing::Point(i * 20 + x2, j * 20 + y2);
							arr[noOFLabelused]->Show();
							this->arr[noOFLabelused]->BackColor = System::Drawing::Color::Black;
							noOFLabelused++;
						}
					}
				}
			}
		}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		if (!game_over)
		{
			DISPLAY();
			SNAKE_GROWTH();
		}
		else
		{
			this->Close();
		}
	}
	private: System::Void GameWillRun_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		switch (e->KeyCode)
		{
		case Keys::Left:
			DIRECT = LEFT;
			break;
		case Keys::Right:
			DIRECT = RIGHT;
			break;
		case Keys::Up:
			DIRECT = UP;
			break;
		case Keys::Down:
			DIRECT = DOWN;
			break;
		case Keys::X:
			game_over = true;
			break;
		}
	}
private: System::Void GameWillRun_Load(System::Object^  sender, System::EventArgs^  e) 
{
}
};
}
