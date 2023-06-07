#pragma once
#include"PhoneNumber.h"

namespace LAB7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ number1;
	private: System::Windows::Forms::TextBox^ number2;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ result_label;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Label^ label4;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->number1 = (gcnew System::Windows::Forms::TextBox());
			this->number2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->result_label = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(248, 305);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 45);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Знайти";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(188, 145);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 26);
			this->textBox1->TabIndex = 1;
			this->textBox1->Click += gcnew System::EventHandler(this, &MyForm::get_info);
			// 
			// number1
			// 
			this->number1->Location = System::Drawing::Point(188, 214);
			this->number1->Name = L"number1";
			this->number1->Size = System::Drawing::Size(167, 26);
			this->number1->TabIndex = 2;
			this->number1->Click += gcnew System::EventHandler(this, &MyForm::get_info);
			// 
			// number2
			// 
			this->number2->Location = System::Drawing::Point(188, 246);
			this->number2->Name = L"number2";
			this->number2->Size = System::Drawing::Size(167, 26);
			this->number2->TabIndex = 3;
			this->number2->Click += gcnew System::EventHandler(this, &MyForm::get_info);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 148);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(131, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Заданий номер:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(52, 214);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Телефон №1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(52, 252);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Телефон №2";
			// 
			// result_label
			// 
			this->result_label->Location = System::Drawing::Point(385, 174);
			this->result_label->Name = L"result_label";
			this->result_label->Size = System::Drawing::Size(195, 60);
			this->result_label->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(149, 61);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(317, 38);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Пошук заданого номера";
			// 
			// button_exit
			// 
			this->button_exit->BackColor = System::Drawing::Color::IndianRed;
			this->button_exit->FlatAppearance->BorderSize = 0;
			this->button_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_exit->Location = System::Drawing::Point(535, 12);
			this->button_exit->Margin = System::Windows::Forms::Padding(0);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(31, 31);
			this->button_exit->TabIndex = 9;
			this->button_exit->Text = L"х";
			this->button_exit->UseVisualStyleBackColor = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &MyForm::button_exit_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(385, 151);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(93, 20);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Результат:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightGray;
			this->ClientSize = System::Drawing::Size(592, 379);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->result_label);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->number2);
			this->Controls->Add(this->number1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Click += gcnew System::EventHandler(this, &MyForm::get_info);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void get_info(System::Object^ sender, System::EventArgs^ e) {
		TextBox^ textBox = safe_cast<TextBox^>(sender);
		textBox->Text = ""; 
	}

	private: System::Void textBox1_Leave(System::Object^ sender, System::EventArgs^ e) {
		TextBox^ textBox = safe_cast<TextBox^>(sender);
		try {
			PhoneNumber^ phoneNumber = gcnew PhoneNumber(textBox->Text);

			this->result_label->Text = phoneNumber->ToString();
		}
		catch (System::Exception^ ex) {
			String^ errorMessage = ex->Message;
			MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK);
			textBox->Text = ""; 
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			PhoneNumber^ phoneNumber1 = gcnew PhoneNumber(number1->Text);
			PhoneNumber^ phoneNumber2 = gcnew PhoneNumber(number2->Text);
			PhoneNumber^ targetNumber = gcnew PhoneNumber(textBox1->Text); 

			if (phoneNumber1->isIncluded(targetNumber) || phoneNumber2->isIncluded(targetNumber)) {
				result_label->Text = "\nЗаданий номер є";
			}
			else {
				result_label->Text = "\nЗаданого номера немає";
			}
		}
		catch (System::Exception^ ex) {
			MessageBox::Show(ex->Message, "Помилка", MessageBoxButtons::OK);
		}
	}


	};
}
