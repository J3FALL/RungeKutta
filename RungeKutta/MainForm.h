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
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1046, 628);
			this->Controls->Add(this->plotPanel);
			this->Controls->Add(this->drawButton);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void drawButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Color^ col = gcnew Color();
		Pen^ pen = gcnew Pen(col->Blue);
		Graphics^ im = plotPanel->CreateGraphics();
		int width = plotPanel->Width;
		int height = plotPanel->Height;
		drawAxes(im);

		solve();

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
	

	};
}
