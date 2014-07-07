/* Tyler Jaszkowiak
 * 29 Dec 2014
 * main.cpp
 * 
 * This is the main game logic for the Connect 4 app. Either player may go 
 * first, then turns alternate between the user and the computer. 
 *
 * Computer moves are determined via recursive calls to the minimax algorithm.
 *
 * If no best outcome is found, the computer plays the first move at the top of
 * the randomized possible move array.
 *
 * TODO: allow user to choose token 'x' or 'o'
 *       allow user to choose who goes first
 *       make board size and win condition choice?
 *       save these choices in a config file somehow
 *       save score history
 *       the minimax repeats work - could we save a tree of possible game moves and outcomes?
 *       add icon
 *       make resizeable window
 *       optimize weighted heuristic to only search once
 */

#pragma once
#include "stdafx.h"

// minimax()
// The minimax algorithm, to be called recursively
// input: the board, depth of minimax search, recommended move, and its 
//     resulting value
// output: the values, passed by reference, of the recommended move and its
//     value are edited
void minimax(const Board &game, int depth, Moveclass *recommended, float* best_value) {
    // base case: passed gameboard represents a completed game or depth is 0
    //            return the evaluation
    if (game.gameover() || depth == 0) {
        *best_value = game.evaluate();
    } 
    // otherwise: use recursive calls to determine the best possible legal move
    else {
        stack<Moveclass> moves;
        game.legal_moves(moves);	// populates the stack with legal moves
        float value;
	*best_value=game.worst_case();
        while(!moves.empty() ) {
            Moveclass try_it(8), reply(8);
            try_it = moves.top();
            Board newgame = game;
            newgame.play(try_it);
            minimax(newgame, depth-1, &reply, &value);
	    // if the value from the recursive call is better than previous
	    // values, edit the values of best_value and recommended move
            if( game.better(value, *best_value) ) {
                *best_value = value;
                *recommended = try_it;
            }
            moves.pop();
        }
    }
}

namespace connect4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

		int userfirst, compwins, userwins, playagain, difficulty, bestpossible;
		Board* initptr;
		Moveclass* compmoveptr;
		Moveclass* umoveptr;
		float *bestval;

	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  lbl_userwins;
	private: System::Windows::Forms::Label^  lbl_compwins;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::RadioButton^  radioButton8;






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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lbl_userwins = (gcnew System::Windows::Forms::Label());
			this->lbl_compwins = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Enabled = false;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(20, 75);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(176, 147);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(59, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(163, 37);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Connect 4";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(35, 46);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(20, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"0";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(56, 46);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(20, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"1";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(76, 46);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(20, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"2";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(98, 46);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(20, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"3";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(120, 46);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(20, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"4";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(141, 46);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(20, 23);
			this->button6->TabIndex = 7;
			this->button6->Text = L"5";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::Control;
			this->button7->Location = System::Drawing::Point(164, 46);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(20, 23);
			this->button7->TabIndex = 8;
			this->button7->Text = L"6";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->Enabled = false;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::Color::Black;
			this->textBox2->Location = System::Drawing::Point(20, 228);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(176, 29);
			this->textBox2->TabIndex = 9;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button8
			// 
			this->button8->Enabled = false;
			this->button8->Location = System::Drawing::Point(20, 263);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(87, 23);
			this->button8->TabIndex = 10;
			this->button8->Text = L"Replay";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(109, 263);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(87, 23);
			this->button9->TabIndex = 11;
			this->button9->Text = L"Exit";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(204, 253);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"User wins:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(204, 273);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"AI wins:";
			// 
			// lbl_userwins
			// 
			this->lbl_userwins->AutoSize = true;
			this->lbl_userwins->BackColor = System::Drawing::Color::Transparent;
			this->lbl_userwins->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbl_userwins->Location = System::Drawing::Point(267, 253);
			this->lbl_userwins->Name = L"lbl_userwins";
			this->lbl_userwins->Size = System::Drawing::Size(0, 13);
			this->lbl_userwins->TabIndex = 14;
			// 
			// lbl_compwins
			// 
			this->lbl_compwins->AutoSize = true;
			this->lbl_compwins->BackColor = System::Drawing::Color::Transparent;
			this->lbl_compwins->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbl_compwins->Location = System::Drawing::Point(267, 273);
			this->lbl_compwins->Name = L"lbl_compwins";
			this->lbl_compwins->Size = System::Drawing::Size(0, 13);
			this->lbl_compwins->TabIndex = 15;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->BackColor = System::Drawing::Color::Transparent;
			this->radioButton1->Location = System::Drawing::Point(227, 65);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(31, 17);
			this->radioButton1->TabIndex = 16;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"1";
			this->radioButton1->UseVisualStyleBackColor = false;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->BackColor = System::Drawing::Color::Transparent;
			this->radioButton2->Location = System::Drawing::Point(227, 89);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(31, 17);
			this->radioButton2->TabIndex = 17;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"2";
			this->radioButton2->UseVisualStyleBackColor = false;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->BackColor = System::Drawing::Color::Transparent;
			this->radioButton3->Location = System::Drawing::Point(227, 113);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(31, 17);
			this->radioButton3->TabIndex = 18;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"3";
			this->radioButton3->UseVisualStyleBackColor = false;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->BackColor = System::Drawing::Color::Transparent;
			this->radioButton4->Location = System::Drawing::Point(227, 137);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(31, 17);
			this->radioButton4->TabIndex = 19;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"4";
			this->radioButton4->UseVisualStyleBackColor = false;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton4_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->BackColor = System::Drawing::Color::Transparent;
			this->radioButton5->Checked = true;
			this->radioButton5->Location = System::Drawing::Point(227, 161);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(31, 17);
			this->radioButton5->TabIndex = 20;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"5";
			this->radioButton5->UseVisualStyleBackColor = false;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton5_CheckedChanged);
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->BackColor = System::Drawing::Color::Transparent;
			this->radioButton6->Location = System::Drawing::Point(227, 185);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(31, 17);
			this->radioButton6->TabIndex = 21;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"6";
			this->radioButton6->UseVisualStyleBackColor = false;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton6_CheckedChanged);
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->BackColor = System::Drawing::Color::Transparent;
			this->radioButton7->Location = System::Drawing::Point(227, 209);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(31, 17);
			this->radioButton7->TabIndex = 22;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"7";
			this->radioButton7->UseVisualStyleBackColor = false;
			this->radioButton7->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton7_CheckedChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(211, 46);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 13);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Difficulty";
			// 
			// radioButton8
			// 
			this->radioButton8->AutoSize = true;
			this->radioButton8->BackColor = System::Drawing::Color::Transparent;
			this->radioButton8->Location = System::Drawing::Point(227, 233);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(31, 17);
			this->radioButton8->TabIndex = 24;
			this->radioButton8->TabStop = true;
			this->radioButton8->Text = L"8";
			this->radioButton8->UseVisualStyleBackColor = false;
			this->radioButton8->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton8_CheckedChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(282, 296);
			this->Controls->Add(this->radioButton8);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->radioButton7);
			this->Controls->Add(this->radioButton6);
			this->Controls->Add(this->radioButton5);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->lbl_compwins);
			this->Controls->Add(this->lbl_userwins);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button7);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->Text = L"Connect 4";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				difficulty = 5;
				compwins = 0;
				userwins = 0;
				userfirst = 1;
				initptr = new Board();
				umoveptr = new Moveclass(8);
				compmoveptr = new Moveclass(8);
				textBox1->Text = initptr->sprint();
				bestval = new float;
			 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 initptr->play(0);
			 textBox1->Text = initptr->sprint();
			 button1->Enabled=false;
			 button2->Enabled=false;
			 button3->Enabled=false;
			 button4->Enabled=false;
			 button5->Enabled=false;
			 button6->Enabled=false;
			 button7->Enabled=false;
			 if ( initptr->gameover() ) {
				 endgame();
				 return;
			 }
			 minimax(*initptr,difficulty,compmoveptr, bestval);
			 initptr->play(*compmoveptr);
			 textBox1->Text = initptr->sprint();
			 if (initptr->islegal(0)) button1->Enabled=true;
			 if (initptr->islegal(1)) button2->Enabled=true;
			 if (initptr->islegal(2)) button3->Enabled=true;
			 if (initptr->islegal(3)) button4->Enabled=true;
			 if (initptr->islegal(4)) button5->Enabled=true;
			 if (initptr->islegal(5)) button6->Enabled=true;
			 if (initptr->islegal(6)) button7->Enabled=true;
			 if ( initptr->gameover() ) endgame();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 initptr->play(1);
			 textBox1->Text = initptr->sprint();
			 button1->Enabled=false;
			 button2->Enabled=false;
			 button3->Enabled=false;
			 button4->Enabled=false;
			 button5->Enabled=false;
			 button6->Enabled=false;
			 button7->Enabled=false;
			 if ( initptr->gameover() ) {
				 endgame();
				 return;
			 }
			 minimax(*initptr,difficulty,compmoveptr, bestval);
			 initptr->play(*compmoveptr);
			 textBox1->Text = initptr->sprint();
			 if (initptr->islegal(0)) button1->Enabled=true;
			 if (initptr->islegal(1)) button2->Enabled=true;
			 if (initptr->islegal(2)) button3->Enabled=true;
			 if (initptr->islegal(3)) button4->Enabled=true;
			 if (initptr->islegal(4)) button5->Enabled=true;
			 if (initptr->islegal(5)) button6->Enabled=true;
			 if (initptr->islegal(6)) button7->Enabled=true;
			 if ( initptr->gameover() ) endgame();
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 initptr->play(2);
			 textBox1->Text = initptr->sprint();
			 button1->Enabled=false;
			 button2->Enabled=false;
			 button3->Enabled=false;
			 button4->Enabled=false;
			 button5->Enabled=false;
			 button6->Enabled=false;
			 button7->Enabled=false;
			 if ( initptr->gameover() ) {
				 endgame();
				 return;
			 }
			 minimax(*initptr,difficulty,compmoveptr, bestval);
			 initptr->play(*compmoveptr);
			 textBox1->Text = initptr->sprint();
			 if (initptr->islegal(0)) button1->Enabled=true;
			 if (initptr->islegal(1)) button2->Enabled=true;
			 if (initptr->islegal(2)) button3->Enabled=true;
			 if (initptr->islegal(3)) button4->Enabled=true;
			 if (initptr->islegal(4)) button5->Enabled=true;
			 if (initptr->islegal(5)) button6->Enabled=true;
			 if (initptr->islegal(6)) button7->Enabled=true;
			 if ( initptr->gameover() ) endgame();
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 initptr->play(3);
			 textBox1->Text = initptr->sprint();
			 button1->Enabled=false;
			 button2->Enabled=false;
			 button3->Enabled=false;
			 button4->Enabled=false;
			 button5->Enabled=false;
			 button6->Enabled=false;
			 button7->Enabled=false;
			 if ( initptr->gameover() ) {
				 endgame();
				 return;
			 }
			 minimax(*initptr,difficulty,compmoveptr, bestval);
			 initptr->play(*compmoveptr);
			 textBox1->Text = initptr->sprint();
			 if (initptr->islegal(0)) button1->Enabled=true;
			 if (initptr->islegal(1)) button2->Enabled=true;
			 if (initptr->islegal(2)) button3->Enabled=true;
			 if (initptr->islegal(3)) button4->Enabled=true;
			 if (initptr->islegal(4)) button5->Enabled=true;
			 if (initptr->islegal(5)) button6->Enabled=true;
			 if (initptr->islegal(6)) button7->Enabled=true;
			 if ( initptr->gameover() ) endgame();
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 initptr->play(4);
			 textBox1->Text = initptr->sprint();
			 button1->Enabled=false;
			 button2->Enabled=false;
			 button3->Enabled=false;
			 button4->Enabled=false;
			 button5->Enabled=false;
			 button6->Enabled=false;
			 button7->Enabled=false;
			 if ( initptr->gameover() ) {
				 endgame();
				 return;
			 }
			 minimax(*initptr,difficulty,compmoveptr, bestval);
			 initptr->play(*compmoveptr);
			 textBox1->Text = initptr->sprint();
			 if (initptr->islegal(0)) button1->Enabled=true;
			 if (initptr->islegal(1)) button2->Enabled=true;
			 if (initptr->islegal(2)) button3->Enabled=true;
			 if (initptr->islegal(3)) button4->Enabled=true;
			 if (initptr->islegal(4)) button5->Enabled=true;
			 if (initptr->islegal(5)) button6->Enabled=true;
			 if (initptr->islegal(6)) button7->Enabled=true;
			 if ( initptr->gameover() ) endgame();
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 initptr->play(5);
			 textBox1->Text = initptr->sprint();
			 button1->Enabled=false;
			 button2->Enabled=false;
			 button3->Enabled=false;
			 button4->Enabled=false;
			 button5->Enabled=false;
			 button6->Enabled=false;
			 button7->Enabled=false;
			 if ( initptr->gameover() ) {
				 endgame();
				 return;
			 }
			 minimax(*initptr,difficulty,compmoveptr, bestval);
			 initptr->play(*compmoveptr);
			 textBox1->Text = initptr->sprint();
			 if (initptr->islegal(0)) button1->Enabled=true;
			 if (initptr->islegal(1)) button2->Enabled=true;
			 if (initptr->islegal(2)) button3->Enabled=true;
			 if (initptr->islegal(3)) button4->Enabled=true;
			 if (initptr->islegal(4)) button5->Enabled=true;
			 if (initptr->islegal(5)) button6->Enabled=true;
			 if (initptr->islegal(6)) button7->Enabled=true;
			 if ( initptr->gameover() ) endgame();
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 initptr->play(6);
			 textBox1->Text = initptr->sprint();
			 button1->Enabled=false;
			 button2->Enabled=false;
			 button3->Enabled=false;
			 button4->Enabled=false;
			 button5->Enabled=false;
			 button6->Enabled=false;
			 button7->Enabled=false;
			 if ( initptr->gameover() ) {
				 endgame();
				 return;
			 }
			 minimax(*initptr,difficulty,compmoveptr, bestval);
			 initptr->play(*compmoveptr);
			 textBox1->Text = initptr->sprint();
			 if (initptr->islegal(0)) button1->Enabled=true;
			 if (initptr->islegal(1)) button2->Enabled=true;
			 if (initptr->islegal(2)) button3->Enabled=true;
			 if (initptr->islegal(3)) button4->Enabled=true;
			 if (initptr->islegal(4)) button5->Enabled=true;
			 if (initptr->islegal(5)) button6->Enabled=true;
			 if (initptr->islegal(6)) button7->Enabled=true;
			 if ( initptr->gameover() ) endgame();
		 }

private: void endgame() {
			 if( initptr->isdefeat() ) {
				 textBox2->Text = "You lose.";
				 compwins++;
				 lbl_compwins->Text = System::Convert::ToString(compwins);
			 } else if (initptr->isvictory() ) {
				 textBox2->Text = "You win!";
				 userwins++;
				 lbl_userwins->Text = System::Convert::ToString(userwins);
			 } else {
				 textBox2->Text = "Draw game...";
			 }
			 button1->Enabled=false;
			 button2->Enabled=false;
			 button3->Enabled=false;
			 button4->Enabled=false;
			 button5->Enabled=false;
			 button6->Enabled=false;
			 button7->Enabled=false;
			 button8->Enabled=true; //replay button
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 free(initptr);
			 initptr = new Board();
			 textBox1->Text = initptr->sprint();
			 textBox2->Text = "";
			 button1->Enabled=true;
			 button2->Enabled=true;
			 button3->Enabled=true;
			 button4->Enabled=true;
			 button5->Enabled=true;
			 button6->Enabled=true;
			 button7->Enabled=true;
			 button8->Enabled=false; // disable replay button when it is clicked
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 exit(0);
		 }
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 difficulty=1;
		 }
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 difficulty=2;
		 }
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 difficulty=3;
		 }
private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 difficulty=4;
		 }
private: System::Void radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 difficulty=5;
		 }
private: System::Void radioButton6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 difficulty=6;
		 }
private: System::Void radioButton7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 difficulty=7;
		 }
private: System::Void radioButton8_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 difficulty=8;
		 }
};
}

