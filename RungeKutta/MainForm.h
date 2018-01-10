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
	/// ������ ��� MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	protected:

	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
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
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// drawButton
			// 
			this->drawButton->Location = System::Drawing::Point(19, 178);
			this->drawButton->Margin = System::Windows::Forms::Padding(2);
			this->drawButton->Name = L"drawButton";
			this->drawButton->Size = System::Drawing::Size(75, 22);
			this->drawButton->TabIndex = 0;
			this->drawButton->Text = L"Solve";
			this->drawButton->UseVisualStyleBackColor = true;
			this->drawButton->Click += gcnew System::EventHandler(this, &MainForm::drawButton_Click);
			// 
			// plotPanel
			// 
			this->plotPanel->BackColor = System::Drawing::SystemColors::Window;
			this->plotPanel->Location = System::Drawing::Point(303, 11);
			this->plotPanel->Margin = System::Windows::Forms::Padding(2);
			this->plotPanel->Name = L"plotPanel";
			this->plotPanel->Size = System::Drawing::Size(825, 592);
			this->plotPanel->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 31);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"A = ";
			// 
			// aTextBox
			// 
			this->aTextBox->Location = System::Drawing::Point(88, 28);
			this->aTextBox->Margin = System::Windows::Forms::Padding(2);
			this->aTextBox->Name = L"aTextBox";
			this->aTextBox->Size = System::Drawing::Size(76, 20);
			this->aTextBox->TabIndex = 3;
			this->aTextBox->Text = L"2";
			// 
			// TTextBox
			// 
			this->TTextBox->Location = System::Drawing::Point(88, 52);
			this->TTextBox->Margin = System::Windows::Forms::Padding(2);
			this->TTextBox->Name = L"TTextBox";
			this->TTextBox->Size = System::Drawing::Size(76, 20);
			this->TTextBox->TabIndex = 5;
			this->TTextBox->Text = L"2";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(19, 57);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"T = ";
			this->label2->Click += gcnew System::EventHandler(this, &MainForm::label2_Click);
			// 
			// TTermBox
			// 
			this->TTermBox->Location = System::Drawing::Point(88, 139);
			this->TTermBox->Margin = System::Windows::Forms::Padding(2);
			this->TTermBox->Name = L"TTermBox";
			this->TTermBox->Size = System::Drawing::Size(76, 20);
			this->TTermBox->TabIndex = 7;
			this->TTermBox->Text = L"100";
			this->TTermBox->TextChanged += gcnew System::EventHandler(this, &MainForm::TTermBox_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 142);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"t_terminal = ";
			// 
			// epsTextBox
			// 
			this->epsTextBox->Location = System::Drawing::Point(88, 76);
			this->epsTextBox->Margin = System::Windows::Forms::Padding(2);
			this->epsTextBox->Name = L"epsTextBox";
			this->epsTextBox->Size = System::Drawing::Size(76, 20);
			this->epsTextBox->TabIndex = 9;
			this->epsTextBox->Text = L"0.01";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 79);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"epsilon = ";
			// 
			// tauTextBox
			// 
			this->tauTextBox->Location = System::Drawing::Point(88, 115);
			this->tauTextBox->Margin = System::Windows::Forms::Padding(2);
			this->tauTextBox->Name = L"tauTextBox";
			this->tauTextBox->Size = System::Drawing::Size(76, 20);
			this->tauTextBox->TabIndex = 11;
			this->tauTextBox->Text = L"0.01";
			this->tauTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::tauTextBox_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 118);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(61, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"time step = ";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(128, 252);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(86, 17);
			this->radioButton1->TabIndex = 12;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"x-component";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(128, 275);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(86, 17);
			this->radioButton2->TabIndex = 13;
			this->radioButton2->Text = L"y-component";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton2_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(19, 227);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Stability";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(19, 256);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Poincare";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(19, 285);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 16;
			this->button3->Text = L"Auto-corr";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(19, 411);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 17;
			this->button4->Text = L"L1-exp";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(125, 416);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(25, 13);
			this->label6->TabIndex = 18;
			this->label6->Text = L"L1=";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(88, 345);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(76, 20);
			this->textBox1->TabIndex = 19;
			this->textBox1->Text = L"200";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(88, 371);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(76, 20);
			this->textBox2->TabIndex = 20;
			this->textBox2->Text = L"2";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(23, 348);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(22, 13);
			this->label7->TabIndex = 21;
			this->label7->Text = L"M=";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(23, 374);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(32, 13);
			this->label8->TabIndex = 22;
			this->label8->Text = L"T_L=";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1139, 614);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
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
			this->Margin = System::Windows::Forms::Padding(2);
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
		N = omega * T / (2 * M_PI);
		std::pair<std::vector<double>, std::vector<double>> slnvec;
		std::vector<double> xvec;
		std::vector<double> yvec;

		slnvec = solve(0, 0,0,T_terminal, tau);
		xvec = slnvec.first;
		yvec = slnvec.second;

		for (int i = 0; i < xvec.size() - 1; i++) {
			// Create points that define line.
			Point point1 = Point(20 * xvec[i] + (plotPanel->Width) / 2, -5 * yvec[i] + (plotPanel->Height) / 2);
			Point point2 = Point(20 * xvec[i + 1] + (plotPanel->Width) / 2, -5 * yvec[i + 1] + (plotPanel->Height) / 2);
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
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		std::pair<std::vector<double>, std::vector<double>> slnvec0;
		std::pair<std::vector<double>, std::vector<double>> slnvec1;
		std::vector<double> xvec0, xvec1, yvec0, yvec1;
		Color^ col = gcnew Color();
		Pen^ pen = gcnew Pen(col->Blue);
		Graphics^ im = plotPanel->CreateGraphics();
		im->Clear(Color::White);
		slnvec0 = solve(0, 0,0, T_terminal, tau);
		slnvec1 = solve(0.01, 0.01,0, T_terminal, tau);
		xvec0 = slnvec0.first;
		yvec0 = slnvec0.second;
		xvec1 = slnvec1.first;
		yvec1 = slnvec1.second;
		if (radioButton1->Checked == true) {
			for (int i = 1; i < xvec0.size()-2; i++) {
				// Create points that define line.
				Point point1 = Point( 8*tau*i,  -5000 * (xvec0[i]-xvec1[i]) + (plotPanel->Height) / 2);
				Point point2 = Point(8*tau*(i+1), -5000 *(xvec0[i + 1]- xvec1[i + 1]) + (plotPanel->Height) / 2);
				im->DrawLine(pen, point1, point2);
			}
			
		}
		else {
			for (int i = 1; i < yvec0.size() - 2; i++) {
				// Create points that define line.
				Point point1 = Point(8 * tau*i, -5000 * (yvec0[i] - yvec1[i]) + (plotPanel->Height) / 2);
				Point point2 = Point(8 * tau*(i + 1), -5000 * (yvec0[i + 1] - yvec1[i + 1]) + (plotPanel->Height) / 2);
				im->DrawLine(pen, point1, point2);
			}
		}

}
private: System::Void TTermBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (TTermBox->Text != "") {
		T_terminal = Convert::ToDouble(TTermBox->Text);
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	double xconst = 1;
	double yconst = 1;
	double eps = 0.1; //Serves only for double comparison, i.e. we need something like x=const, but use abs(x-const)<eps
	std::vector<int> poincare_x,poincare_x_pos,poincare_x_neg,poincare_y, poincare_y_pos, poincare_y_neg;
	std::pair<std::vector<double>, std::vector<double>> slnvec0;
	std::vector<double> xvec0, yvec0;
	//Doing RK
	slnvec0 = solve(0, 0,0, T_terminal, tau);
	xvec0 = slnvec0.first;
	yvec0 = slnvec0.second;
	Color^ col = gcnew Color();
	Pen^ pen = gcnew Pen(col->Red);
	Graphics^ im = plotPanel->CreateGraphics();
	im->Clear(Color::White);
	Point point1 = Point(0,  (plotPanel->Height) / 2);
	Point point2 = Point(plotPanel->Width,  (plotPanel->Height) / 2);
	im->DrawLine(pen, point1, point2);
	//For x=const
	if (radioButton1->Checked == true) {
		for (int i = 1; i < xvec0.size() - 2; i++) {
			//See comment for eps above
			if (abs(xvec0[i] - xconst) < eps) {
				//Remember number of that x
				poincare_x.push_back(i);
			}
		}
		//ONLY for graphical purposes we divide all numbers on two groups with positive and negative y (for const y)
		for (int i = 1; i < poincare_x.size(); i++) {
			if (yvec0[poincare_x[i]]>=0) {
				//Here we store positive ones
				poincare_x_pos.push_back(i);
			}
			else {
				//Negative ones
				poincare_x_neg.push_back(i);
			}
		}
		//For stability purposes we need at least one point (it could happen, than for lower T_terminal we dont have one)
		if (poincare_x.size() > 0) {
			//Draw positive y's
			for (int i = 0; i < poincare_x_pos.size()-1; i++) {
				Pen^ pen = gcnew Pen(col->Blue);
				Point point1 = Point(20 * tau*poincare_x[poincare_x_pos[i]], -5 * (yvec0[poincare_x[poincare_x_pos[i]]]) + (plotPanel->Height) / 2);
				Point point2 = Point(20 * tau*poincare_x[poincare_x_pos[i+1]], -5 * (yvec0[poincare_x[poincare_x_pos[i+1]]]) + (plotPanel->Height) / 2);
				im->DrawLine(pen, point1, point2);
			}
			//And negative y's separately
			for (int i = 0; i < poincare_x_neg.size() - 1; i++) {
				Pen^ pen = gcnew Pen(col->Blue);
				Point point1 = Point(20 * tau*poincare_x[poincare_x_neg[i]], -5 * (yvec0[poincare_x[poincare_x_neg[i]]]) + (plotPanel->Height) / 2);
				Point point2 = Point(20 * tau*poincare_x[poincare_x_neg[i + 1]], -5 * (yvec0[poincare_x[poincare_x_neg[i + 1]]]) + (plotPanel->Height) / 2);
				im->DrawLine(pen, point1, point2);
			}
		}
	}
	else { //Now we do the same, but for y=const
		for (int i = 1; i < yvec0.size() - 2; i++) {
			//See comment for eps above
			if (abs(yvec0[i] - yconst) < eps) {
				//Remember number of that x
				poincare_y.push_back(i);
			}
		}
		//ONLY for graphical purposes we divide all numbers on two groups with positive and negative y (for const y)
		for (int i = 1; i < poincare_y.size(); i++) {
			if (xvec0[poincare_y[i]] >= 0) {
				//Here we store positive ones
				poincare_y_pos.push_back(i);
			}
			else {
				//Negative ones
				poincare_y_neg.push_back(i);
			}
		}
		//For stability purposes we need at least one point (it could happen, than for lower T_terminal we dont have one)
		if (poincare_y.size() > 0) {
			//Draw positive x's
			for (int i = 0; i < poincare_y_pos.size() - 1; i++) {
				Pen^ pen = gcnew Pen(col->Blue);
				Point point1 = Point(20 * tau*poincare_y[poincare_y_pos[i]], -5 * (xvec0[poincare_y[poincare_y_pos[i]]]) + (plotPanel->Height) / 2);
				Point point2 = Point(20 * tau*poincare_y[poincare_y_pos[i + 1]], -5 * (xvec0[poincare_y[poincare_y_pos[i + 1]]]) + (plotPanel->Height) / 2);
				im->DrawLine(pen, point1, point2);
			}
			//And negative x's separately
			for (int i = 0; i < poincare_y_neg.size() - 1; i++) {
				Pen^ pen = gcnew Pen(col->Blue);
				Point point1 = Point(20 * tau*poincare_y[poincare_y_neg[i]], -5 * (xvec0[poincare_y[poincare_y_neg[i]]]) + (plotPanel->Height) / 2);
				Point point2 = Point(20 * tau*poincare_y[poincare_y_neg[i + 1]], -5 * (xvec0[poincare_y[poincare_y_neg[i + 1]]]) + (plotPanel->Height) / 2);
				im->DrawLine(pen, point1, point2);
			}
		}
	}
}
private: System::Void tauTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (TTermBox->Text != "") {
		tau = Convert::ToDouble(tauTextBox->Text);
	}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	double acor_x1,acor_x2,acor_y1,acor_y2 = 0;
	std::pair<std::vector<double>, std::vector<double>> slnvec0;
	std::vector<double> xvec0, yvec0;
	slnvec0 = solve(0, 0,0, T_terminal, tau);
	xvec0 = slnvec0.first;
	yvec0 = slnvec0.second;
	Color^ col = gcnew Color();
	Pen^ pen = gcnew Pen(col->Blue);
	Graphics^ im = plotPanel->CreateGraphics();
	im->Clear(Color::White);
	if (radioButton1->Checked == true) {
		for (int j = 1; j < T_terminal / tau - 1; j++) {
			acor_x1 = 0;
			acor_x2 = 0;
			for (int i = 1; i < T_terminal / tau - 1 - j; i++) {
				acor_x1 += xvec0[i] * xvec0[i + j] * tau;
				acor_x2 += xvec0[i] * xvec0[i + j + 1] * tau;
			}
			Point point1 = Point(10 * tau*j, -0.005 * (acor_x1)+(plotPanel->Height) / 2);
			Point point2 = Point(10 * tau*j + 1, -0.005 * (acor_x2)+(plotPanel->Height) / 2);
			im->DrawLine(pen, point1, point2);
		}
	}
	else {
		for (int j = 1; j < T_terminal / tau - 1; j++) {
			acor_y1 = 0;
			acor_y2 = 0;
			for (int i = 1; i < T_terminal / tau - 1 - j; i++) {
				acor_y1 += yvec0[i] * yvec0[i + j] * tau;
				acor_y2 += yvec0[i] * yvec0[i + j + 1] * tau;
			}
			Point point1 = Point(10 * tau*j, -0.005 * (acor_y1)+(plotPanel->Height) / 2);
			Point point2 = Point(10 * tau*j + 1, -0.005 * (acor_y2)+(plotPanel->Height) / 2);
			im->DrawLine(pen, point1, point2);
		}
	}
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	double l1_exp,x0,y0;
	std::pair<std::vector<double>, std::vector<double>> slnvec0;
	slnvec0 = solve(0, 0, 0, 100, 0.01);
	x0 = slnvec0.first[slnvec0.first.size() - 1];
	y0 = slnvec0.second[slnvec0.first.size() - 1];
	l1_exp = Lyapunov_exp(x0, y0, M_L, T_L);
	label6->Text = "L1=" + Convert::ToString(l1_exp);
}
};
}
