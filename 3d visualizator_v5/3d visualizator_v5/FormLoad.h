#pragma once

#include "global.h"
#include "graph.h"
#include "func.h"
#include "conversions.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace My3dvisualizator_v5 {

	/// <summary>
	/// Сводка для FormHelp
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class FormLoad : public System::Windows::Forms::Form
	{
	public:
		FormLoad(void)
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
		~FormLoad()
		{
			if (components)
			{
				delete components;
			}
		}

	private: void ResetLanguageLoadForm(int mode);
	private: void LoadListOfFuncsLoad();

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::DataGridView^  dataGridView1;



	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column3;

	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(206, 503);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Загрузить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormLoad::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(305, 503);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(143, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Загрузить из файла";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FormLoad::button2_Click);
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(725, 486);
			this->panel1->TabIndex = 2;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(717, 478);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormLoad::dataGridView1_CellClick);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(463, 503);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(84, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Отмена";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FormLoad::button3_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Имя";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Функции";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 320;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Изображение";
			this->Column3->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 230;
			// 
			// FormHelp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(749, 540);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"FormHelp";
			this->Text = L"Загрузка функций";
			this->Activated += gcnew System::EventHandler(this, &FormLoad::FormLoad_Activated);
			this->Load += gcnew System::EventHandler(this, &FormLoad::FormLoad_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormLoad_Load(System::Object^  sender, System::EventArgs^  e) {
				 mode_FormLoad=-1;
				 ResetLanguageLoadForm(GRAPHICS.mode_Now);

				 LoadListOfFuncsLoad();
			 }
	private: System::Void FormLoad_Activated(System::Object^  sender, System::EventArgs^  e) {
				 ResetLanguageLoadForm(GRAPHICS.mode_Now);
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 int indexOfRow = dataGridView1->CurrentRow->Index;
				 if (indexOfRow >= 0)
				 {
					 String^ stri = Application::StartupPath + ChToStr(GRAPHICS.listOfFuncs.GetName(indexOfRow));
					 GRAPHICS.LoadFromFile(StrToCh(stri));
					 GRAPHICS.listOfFuncs.Clear();
					 this->dataGridView1->Rows->Clear();
					 this->Close();
				 }
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 openFileDialog1->Filter = "MR funcs files (*.MRf5)|*.MRf5|All files (*.*)|*.*";
				 openFileDialog1->RestoreDirectory = true;
				 openFileDialog1->InitialDirectory = Application::StartupPath + L"\\data\\Saves";
				 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 GRAPHICS.LoadFromFile(StrToCh(openFileDialog1->FileName));
					 GRAPHICS.SaveToFileInfo(Application::StartupPath + L"\\data\\Saves\\!FileInfo.info", StrToCh(openFileDialog1->FileName->Substring(Application::StartupPath->Length)));
					 dataGridView1->Rows->Clear();
					 this->Close();
				 }
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->dataGridView1->Rows->Clear();
				 this->Close();
			 }
private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
				 if (dataGridView1->CurrentRow != __nullptr)
				 {
					 if (dataGridView1->CurrentRow->Index == -1)
					 {
						 button1->Enabled = false;
					 }
					 else if (dataGridView1->CurrentRow->Index >= 0)
					 {
						 button1->Enabled = true;
					 }
				 }
}
};
}