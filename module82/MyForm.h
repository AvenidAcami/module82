#pragma once

#include <set>
#include <map>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <iostream>
namespace module82 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ openFileBtn;
	protected:
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ currentText;
	private: System::Windows::Forms::ListBox^ uniqueWords;
	private: System::Windows::Forms::ListBox^ stats;
	private: System::Windows::Forms::Label^ wordsCountLabel;
	private: System::Windows::Forms::Label^ label1;

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
			this->openFileBtn = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->currentText = (gcnew System::Windows::Forms::TextBox());
			this->uniqueWords = (gcnew System::Windows::Forms::ListBox());
			this->stats = (gcnew System::Windows::Forms::ListBox());
			this->wordsCountLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// openFileBtn
			// 
			this->openFileBtn->Location = System::Drawing::Point(42, 510);
			this->openFileBtn->Name = L"openFileBtn";
			this->openFileBtn->Size = System::Drawing::Size(238, 38);
			this->openFileBtn->TabIndex = 0;
			this->openFileBtn->Text = L"ќткрыть файл";
			this->openFileBtn->UseVisualStyleBackColor = true;
			this->openFileBtn->Click += gcnew System::EventHandler(this, &MyForm::openFileBtn_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// currentText
			// 
			this->currentText->Location = System::Drawing::Point(42, 44);
			this->currentText->Multiline = true;
			this->currentText->Name = L"currentText";
			this->currentText->ReadOnly = true;
			this->currentText->Size = System::Drawing::Size(238, 449);
			this->currentText->TabIndex = 1;
			// 
			// uniqueWords
			// 
			this->uniqueWords->FormattingEnabled = true;
			this->uniqueWords->ItemHeight = 16;
			this->uniqueWords->Location = System::Drawing::Point(302, 44);
			this->uniqueWords->Name = L"uniqueWords";
			this->uniqueWords->Size = System::Drawing::Size(288, 116);
			this->uniqueWords->TabIndex = 2;
			// 
			// stats
			// 
			this->stats->FormattingEnabled = true;
			this->stats->ItemHeight = 16;
			this->stats->Location = System::Drawing::Point(302, 185);
			this->stats->Name = L"stats";
			this->stats->Size = System::Drawing::Size(284, 308);
			this->stats->TabIndex = 3;
			// 
			// wordsCountLabel
			// 
			this->wordsCountLabel->AutoSize = true;
			this->wordsCountLabel->Location = System::Drawing::Point(498, 521);
			this->wordsCountLabel->Name = L"wordsCountLabel";
			this->wordsCountLabel->Size = System::Drawing::Size(14, 16);
			this->wordsCountLabel->TabIndex = 4;
			this->wordsCountLabel->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(314, 521);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 16);
			this->label1->TabIndex = 5;
			this->label1->Text = L"ќбщее количество слов:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 568);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->wordsCountLabel);
			this->Controls->Add(this->stats);
			this->Controls->Add(this->uniqueWords);
			this->Controls->Add(this->currentText);
			this->Controls->Add(this->openFileBtn);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void openFileBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
	System::Windows::Forms::DialogResult result = openFileDialog1->ShowDialog();
	if (result == System::Windows::Forms::DialogResult::OK) {
		stats->Items->Clear();
		uniqueWords->Items->Clear();
		System::String^ filePath = openFileDialog1->FileName;
		System::String^ text = File::ReadAllText(filePath);
		currentText->Text = text;
		std::string stdText = msclr::interop::marshal_as<std::string>(text);
		array <System::String^>^ splittedText = text->Split(' ');
		wordsCountLabel->Text = System::Convert::ToString(splittedText->Length);
		std::set<std::string> uniq;
		for (int i = 0; i < splittedText->Length; i++){
			System::String^ temp = splittedText[i];
			uniq.insert(msclr::interop::marshal_as<std::string>(temp));
		}
		uniqueWords->Text = "";
		for (std::set<std::string>::iterator it = uniq.begin(); it != uniq.end(); ++it) {
			std::string str = *it;
			System::String^ sysStr = gcnew String(str.c_str());
			std::cout << msclr::interop::marshal_as<std::string>(sysStr) << " ";
			uniqueWords->Items->Add(sysStr);
		}
		std::map<std::string, int> words;
		for (int i = 0; i < splittedText->Length; i++){
			System::String^ temp = splittedText[i];
			auto it1 = words.find(msclr::interop::marshal_as<std::string>(temp));
			if (it1 != words.end()) {
				it1->second++;
			}
			else {
				words.insert({ msclr::interop::marshal_as<std::string>(temp), 1 });
			}
			
		}
		for (auto it = words.begin(); it != words.end(); ++it) {
			std::string key = it->first;
			int value = it->second;
			System::String^ sysStr = gcnew String(key.c_str());
			stats->Items->Add(sysStr + "	" + it->second);
		}
		
		
	}

	
}
};
}
