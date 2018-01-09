#pragma once
#include "RK4.h"

namespace RungeKutta {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  drawButton;
	private: System::Windows::Forms::Panel^  plotPanel;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  aTextBox;
	private: System::Windows::Forms::TextBox^  TTextBox;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  TTermBox;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  epsTextBox;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  tauTextBox;

	private: System::Windows::Forms::Label^  label5;
	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->drawButton = (gcnew System::Windows::Forms::Button());
			this->plotPanel = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->aTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TTermBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->epsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tauTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// drawButton
			// 
			this->drawButton->Location = System::Drawing::Point(12, 48);
			this->drawButton->Name = L"drawButton";
			this->drawButton->Size = System::Drawing::Size(75, 23);
			this->drawButton->TabIndex = 0;
			this->drawButton->Text = L"Draw";
			this->drawButton->UseVisualStyleBackColor = true;
			this->drawButton->Click += gcnew System::EventHandler(this, &MainForm::drawButton_Click);
			// 
			// plotPanel
			// 
			this->plotPanel->BackColor = System::Drawing::SystemColors::Window;
			this->plotPanel->Location = System::Drawing::Point(404, 48);
			this->plotPanel->Name = L"plotPanel";
			this->plotPanel->Size = System::Drawing::Size(588, 498);
			this->plotPanel->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 120);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"A = ";
			// 
			// aTextBox
			// 
			this->aTextBox->Location = System::Drawing::Point(118, 120);
			this->aTextBox->Name = L"aTextBox";
			this->aTextBox->Size = System::Drawing::Size(100, 22);
			this->aTextBox->TabIndex = 3;
			this->aTextBox->Text = L"2";
			// 
			// TTextBox
			// 
			this->TTextBox->Location = System::Drawing::Point(118, 162);
			this->TTextBox->Name = L"TTextBox";
			this->TTextBox->Size = System::Drawing::Size(100, 22);
			this->TTextBox->TabIndex = 5;
			this->TTextBox->Text = L"2";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 162);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"T = ";
			this->label2->Click += gcnew System::EventHandler(this, &MainForm::label2_Click);
			// 
			// TTermBox
			// 
			this->TTermBox->Location = System::Drawing::Point(118, 202);
			this->TTermBox->Name = L"TTermBox";
			this->TTermBox->Size = System::Drawing::Size(100, 22);
			this->TTermBox->TabIndex = 7;
			this->TTermBox->Text = L"2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(22, 205);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"T_terminal = ";
			// 
			// epsTextBox
			// 
			this->epsTextBox->Location = System::Drawing::Point(118, 248);
			this->epsTextBox->Name = L"epsTextBox";
			this->epsTextBox->Size = System::Drawing::Size(100, 22);
			this->epsTextBox->TabIndex = 9;
			this->epsTextBox->Text = L"0,01";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(22, 248);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"epsilon = ";
			// 
			// tauTextBox
			// 
			this->tauTextBox->Location = System::Drawing::Point(118, 288);
			this->tauTextBox->Name = L"tauTextBox";
			this->tauTextBox->Size = System::Drawing::Size(100, 22);
			this->tauTextBox->TabIndex = 11;
			this->tauTextBox->Text = L"0,1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(25, 288);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 17);
			this->label5->TabIndex = 10;
			this->label5->Text = L"tau = ";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1046, 628);
			this->Controls->Add(this->tauTextBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->epsTextBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->TTermBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->TTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->aTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->plotPanel);
			this->Controls->Add(this->drawButton);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void drawButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Color^ col = gcnew Color();
		Pen^ pen = gcnew Pen(col->Blue);
		Graphics^ im = plotPanel->CreateGraphics();
		im->Clear(Color::White);

		int width = plotPanel->Width;
		int height = plotPanel->Height;
		drawAxes(im);

		A = Convert::ToDouble(aTextBox->Text);
		T = Convert::ToDouble(TTextBox->Text);
		T_terminal = Convert::ToDouble(TTermBox->Text);
		epsilon = Convert::ToDouble(epsTextBox->Text);
		tau = Convert::ToDouble(tauTextBox->Text);

		std::pair<std::vector<double>, std::vector<double>> slnvec;
		std::vector<double> xvec;
		std::vector<double> yvec;

		slnvec = solve(0, 0, T_terminal, tau);
		xvec = slnvec.first;
		yvec = slnvec.second;

		for (int i = 0; i < xvec.size() - 1; i++) {
			// Create points that define line.
			Point point1 = Point(50 * xvec[i] + (plotPanel->Width) / 2, 50 * yvec[i] + (plotPanel->Height) / 2);
			Point point2 = Point(50 * xvec[i + 1] + (plotPanel->Width) / 2, 50 * yvec[i + 1] + (plotPanel->Height) / 2);
			Graphics^ im = plotPanel->CreateGraphics();
			im->DrawLine(pen, point1, point2);
		}
	}

	private: void drawAxes(Graphics^ im) {
		int width = plotPanel->Width;
		int height = plotPanel->Height;

		Color^ col = gcnew Color();
		Pen^ pen = gcnew Pen(col->Red);
	
		im->DrawLine(pen, width / 2, 0, width / 2, height);
		im->DrawLine(pen, 0, height / 2, width, height / 2);
	}
	

	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
