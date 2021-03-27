#pragma once
#include "MyForm.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� EditForm
	/// </summary>
	public ref class EditForm : public System::Windows::Forms::Form
	{
	public:

		EditForm(void)
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
		~EditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listComponents;
	protected:
	private: System::Windows::Forms::ListBox^ listAvailable;
	private: System::Windows::Forms::Label^ labelComponents;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonClose;
	private: System::Windows::Forms::ListBox^ listNote;
	private: System::Windows::Forms::Button^ button1;



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
			this->listComponents = (gcnew System::Windows::Forms::ListBox());
			this->listAvailable = (gcnew System::Windows::Forms::ListBox());
			this->labelComponents = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonClose = (gcnew System::Windows::Forms::Button());
			this->listNote = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listComponents
			// 
			this->listComponents->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listComponents->FormattingEnabled = true;
			this->listComponents->ItemHeight = 20;
			this->listComponents->Location = System::Drawing::Point(43, 67);
			this->listComponents->Name = L"listComponents";
			this->listComponents->Size = System::Drawing::Size(256, 244);
			this->listComponents->TabIndex = 0;
			// 
			// listAvailable
			// 
			this->listAvailable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listAvailable->FormattingEnabled = true;
			this->listAvailable->ItemHeight = 20;
			this->listAvailable->Location = System::Drawing::Point(320, 67);
			this->listAvailable->Name = L"listAvailable";
			this->listAvailable->Size = System::Drawing::Size(256, 244);
			this->listAvailable->TabIndex = 1;
			// 
			// labelComponents
			// 
			this->labelComponents->AutoSize = true;
			this->labelComponents->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelComponents->Location = System::Drawing::Point(39, 34);
			this->labelComponents->Name = L"labelComponents";
			this->labelComponents->Size = System::Drawing::Size(160, 20);
			this->labelComponents->TabIndex = 2;
			this->labelComponents->Text = L"���������� ������";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(324, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(189, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"��������� ����������";
			// 
			// buttonClose
			// 
			this->buttonClose->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonClose->Location = System::Drawing::Point(455, 329);
			this->buttonClose->Name = L"buttonClose";
			this->buttonClose->Size = System::Drawing::Size(121, 84);
			this->buttonClose->TabIndex = 4;
			this->buttonClose->Text = L"���������";
			this->buttonClose->UseVisualStyleBackColor = true;
			// 
			// listNote
			// 
			this->listNote->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listNote->FormattingEnabled = true;
			this->listNote->ItemHeight = 20;
			this->listNote->Location = System::Drawing::Point(185, 329);
			this->listNote->Name = L"listNote";
			this->listNote->Size = System::Drawing::Size(248, 84);
			this->listNote->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(43, 329);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 84);
			this->button1->TabIndex = 6;
			this->button1->Text = L"������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EditForm::button1_Click);
			// 
			// EditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(618, 454);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listNote);
			this->Controls->Add(this->buttonClose);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelComponents);
			this->Controls->Add(this->listAvailable);
			this->Controls->Add(this->listComponents);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"EditForm";
			this->Text = L"EditForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
