#pragma once

#include "global.h"
#include "OpenGL funcs.h"
#include "translate to OPN.h"
#include "func.h"
#include "conversions.h"
#include "FormLoad.h"
#include "FormDemo.h"
#include "Form_Process.h"
#include "graph.h"
#pragma comment(lib, "user32.lib")

static double t = 0;
static int n_funcs = 0;//количество функций на форме

namespace My3dvisualizator_v5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(System::Windows::Forms::Form^ f)
		{
			InitializeComponent();
			Form_Main = f;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: void ResetLanguageMainForm(int mode);//dof me
			 template <typename T>
			 array<T^> ^ ReinitDynamixObjects(array<T^> ^obj, int m, int n);
			 template <typename T>
			 array<T^> ^ DeleteDynamixObjects(array<T^> ^obj, int m, int k);

	private: System::Windows::Forms::Form^ Form_Main;
	private: array<System::Windows::Forms::CheckBox^>^ checkBoxes;
	private: array<System::Windows::Forms::Label^>^ labels;
	private: array<System::Windows::Forms::TextBox^>^ textBoxes;
	private: array<System::Windows::Forms::Button^>^ buttons_color_func;
	private: array<System::Windows::Forms::Button^>^ buttons_random_color;
	private: array<System::Windows::Forms::Button^>^ buttons_delete_func;//dof me from end

	private: System::Windows::Forms::Label^  label4;
	protected:
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox8;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Label^  label13;





	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  FileToolStripMenuItem;

	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::Button^  button4;

	private: System::Windows::Forms::Button^  button5;

	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Button^  ru;
	private: System::Windows::Forms::Button^  en;
	private: System::Windows::Forms::Panel^  panel1;




	private: System::Windows::Forms::Button^  button6;

	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Panel^  panel9;

	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  ДемоToolStripMenuItem;





	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ToolStripMenuItem^  СправкаToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  очиститьФункцииToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  сохранитьФункцииToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  загрузитьФункцииToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;




































	private: System::ComponentModel::IContainer^  components;




	protected:

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->очиститьФункцииToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьФункцииToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->загрузитьФункцииToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ДемоToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->СправкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->ru = (gcnew System::Windows::Forms::Button());
			this->en = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel9->SuspendLayout();
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label4->Location = System::Drawing::Point(7, 62);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(118, 18);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Y-минимальное";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label3->Location = System::Drawing::Point(181, 5);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(127, 18);
			this->label3->TabIndex = 22;
			this->label3->Text = L"X-максимальное";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label2->Location = System::Drawing::Point(7, 5);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 18);
			this->label2->TabIndex = 21;
			this->label2->Text = L"X-минимальное";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->button1->Location = System::Drawing::Point(121, 145);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 31);
			this->button1->TabIndex = 20;
			this->button1->Text = L"Построить";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->textBox7->Location = System::Drawing::Point(184, 148);
			this->textBox7->Margin = System::Windows::Forms::Padding(2);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(130, 24);
			this->textBox7->TabIndex = 18;
			this->textBox7->Text = L"auto";
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->textBox6->Location = System::Drawing::Point(9, 148);
			this->textBox6->Margin = System::Windows::Forms::Padding(2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(130, 24);
			this->textBox6->TabIndex = 17;
			this->textBox6->Text = L"auto";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->textBox5->Location = System::Drawing::Point(184, 88);
			this->textBox5->Margin = System::Windows::Forms::Padding(2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(130, 24);
			this->textBox5->TabIndex = 16;
			this->textBox5->Text = L"1";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->textBox4->Location = System::Drawing::Point(9, 87);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(130, 24);
			this->textBox4->TabIndex = 15;
			this->textBox4->Text = L"-1";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->textBox3->Location = System::Drawing::Point(184, 27);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(130, 24);
			this->textBox3->TabIndex = 14;
			this->textBox3->Text = L"1";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->textBox2->Location = System::Drawing::Point(9, 27);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(130, 24);
			this->textBox2->TabIndex = 13;
			this->textBox2->Text = L"-1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label5->Location = System::Drawing::Point(181, 62);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(126, 18);
			this->label5->TabIndex = 24;
			this->label5->Text = L"Y-максимальное";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label6->Location = System::Drawing::Point(7, 126);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(118, 18);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Z-минимальное";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label7->Location = System::Drawing::Point(181, 126);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(126, 18);
			this->label7->TabIndex = 26;
			this->label7->Text = L"Z-максимальное";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label8->Location = System::Drawing::Point(8, 69);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(164, 36);
			this->label8->TabIndex = 27;
			this->label8->Text = L"Качество, количество\r\nполигонов на оси";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label9->Location = System::Drawing::Point(246, 67);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(100, 36);
			this->label9->TabIndex = 28;
			this->label9->Text = L"целое число,\r\nот 5 до 100";
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->textBox8->Location = System::Drawing::Point(193, 76);
			this->textBox8->Margin = System::Windows::Forms::Padding(2);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(44, 24);
			this->textBox8->TabIndex = 29;
			this->textBox8->Text = L"32";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label11->Location = System::Drawing::Point(7, 8);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(256, 18);
			this->label11->TabIndex = 31;
			this->label11->Text = L"Тип отображения осей и показаний";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Статические оси и показания", L"Статические оси и динамические показания",
					L"Динамические оси и показания"
			});
			this->comboBox1->Location = System::Drawing::Point(10, 28);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(304, 26);
			this->comboBox1->TabIndex = 32;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::Color::Transparent;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->checkBox1->Location = System::Drawing::Point(10, 116);
			this->checkBox1->Margin = System::Windows::Forms::Padding(2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(99, 22);
			this->checkBox1->TabIndex = 33;
			this->checkBox1->Text = L"Вращение";
			this->checkBox1->UseVisualStyleBackColor = false;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->BackColor = System::Drawing::Color::Transparent;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->checkBox2->Location = System::Drawing::Point(133, 116);
			this->checkBox2->Margin = System::Windows::Forms::Padding(2);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(58, 22);
			this->checkBox2->TabIndex = 34;
			this->checkBox2->Text = L"Оси";
			this->checkBox2->UseVisualStyleBackColor = false;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->BackColor = System::Drawing::Color::Transparent;
			this->checkBox3->Checked = true;
			this->checkBox3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->checkBox3->Location = System::Drawing::Point(209, 116);
			this->checkBox3->Margin = System::Windows::Forms::Padding(2);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(106, 22);
			this->checkBox3->TabIndex = 35;
			this->checkBox3->Text = L"Показания";
			this->checkBox3->UseVisualStyleBackColor = false;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox3_CheckedChanged);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label12->Location = System::Drawing::Point(8, 119);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(146, 36);
			this->label12->TabIndex = 36;
			this->label12->Text = L"Количество кадров\r\nв секунду";
			// 
			// textBox9
			// 
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->textBox9->Location = System::Drawing::Point(193, 126);
			this->textBox9->Margin = System::Windows::Forms::Padding(2);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(44, 24);
			this->textBox9->TabIndex = 37;
			this->textBox9->Text = L"25";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label13->Location = System::Drawing::Point(246, 116);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(100, 36);
			this->label13->TabIndex = 38;
			this->label13->Text = L"целое число,\r\nот 10 до 100";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Transparent;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->FileToolStripMenuItem,
					this->ДемоToolStripMenuItem, this->СправкаToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(772, 26);
			this->menuStrip1->TabIndex = 44;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// FileToolStripMenuItem
			// 
			this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->очиститьФункцииToolStripMenuItem,
					this->сохранитьФункцииToolStripMenuItem, this->загрузитьФункцииToolStripMenuItem
			});
			this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
			this->FileToolStripMenuItem->Size = System::Drawing::Size(58, 22);
			this->FileToolStripMenuItem->Text = L"Файл";
			// 
			// очиститьФункцииToolStripMenuItem
			// 
			this->очиститьФункцииToolStripMenuItem->Name = L"очиститьФункцииToolStripMenuItem";
			this->очиститьФункцииToolStripMenuItem->Size = System::Drawing::Size(220, 26);
			this->очиститьФункцииToolStripMenuItem->Text = L"Очистить функции";
			this->очиститьФункцииToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::очиститьФункцииToolStripMenuItem_Click);
			// 
			// сохранитьФункцииToolStripMenuItem
			// 
			this->сохранитьФункцииToolStripMenuItem->Name = L"сохранитьФункцииToolStripMenuItem";
			this->сохранитьФункцииToolStripMenuItem->Size = System::Drawing::Size(220, 26);
			this->сохранитьФункцииToolStripMenuItem->Text = L"Сохранить функции";
			this->сохранитьФункцииToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::сохранитьФункцииToolStripMenuItem_Click);
			// 
			// загрузитьФункцииToolStripMenuItem
			// 
			this->загрузитьФункцииToolStripMenuItem->Name = L"загрузитьФункцииToolStripMenuItem";
			this->загрузитьФункцииToolStripMenuItem->Size = System::Drawing::Size(220, 26);
			this->загрузитьФункцииToolStripMenuItem->Text = L"Загрузить функции";
			this->загрузитьФункцииToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::загрузитьФункцииToolStripMenuItem_Click);
			// 
			// ДемоToolStripMenuItem
			// 
			this->ДемоToolStripMenuItem->Name = L"ДемоToolStripMenuItem";
			this->ДемоToolStripMenuItem->Size = System::Drawing::Size(60, 22);
			this->ДемоToolStripMenuItem->Text = L"Демо";
			this->ДемоToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ДемоToolStripMenuItem_Click);
			// 
			// СправкаToolStripMenuItem
			// 
			this->СправкаToolStripMenuItem->Name = L"СправкаToolStripMenuItem";
			this->СправкаToolStripMenuItem->Size = System::Drawing::Size(79, 22);
			this->СправкаToolStripMenuItem->Text = L"Справка";
			this->СправкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::СправкаToolStripMenuItem1_Click);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BackColor = System::Drawing::Color::Transparent;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label16->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label16->Location = System::Drawing::Point(10, 5);
			this->label16->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(169, 18);
			this->label16->TabIndex = 47;
			this->label16->Text = L"Начальное время T1, с";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BackColor = System::Drawing::Color::Transparent;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label17->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label17->Location = System::Drawing::Point(191, 5);
			this->label17->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(160, 18);
			this->label17->TabIndex = 48;
			this->label17->Text = L"Конечное время T2, с";
			// 
			// textBox12
			// 
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->textBox12->Location = System::Drawing::Point(193, 31);
			this->textBox12->Margin = System::Windows::Forms::Padding(2);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(130, 24);
			this->textBox12->TabIndex = 46;
			this->textBox12->Text = L"10";
			// 
			// textBox11
			// 
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->textBox11->Location = System::Drawing::Point(13, 31);
			this->textBox11->Margin = System::Windows::Forms::Padding(2);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(130, 24);
			this->textBox11->TabIndex = 45;
			this->textBox11->Text = L"0";
			// 
			// trackBar1
			// 
			this->trackBar1->Enabled = false;
			this->trackBar1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->trackBar1->Location = System::Drawing::Point(11, 77);
			this->trackBar1->Margin = System::Windows::Forms::Padding(2);
			this->trackBar1->Maximum = 50;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(359, 56);
			this->trackBar1->TabIndex = 49;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::ChangeTimeIpTB);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BackColor = System::Drawing::Color::Transparent;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label18->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label18->Location = System::Drawing::Point(10, 57);
			this->label18->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(82, 18);
			this->label18->TabIndex = 50;
			this->label18->Text = L"Время T, с";
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button3->Location = System::Drawing::Point(81, 145);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 31);
			this->button3->TabIndex = 51;
			this->button3->Text = L"Продолжить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button4->Location = System::Drawing::Point(205, 145);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(74, 31);
			this->button4->TabIndex = 52;
			this->button4->Text = L"Пауза";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button5->Location = System::Drawing::Point(285, 145);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(85, 31);
			this->button5->TabIndex = 53;
			this->button5->Text = L"Стоп";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->BackColor = System::Drawing::Color::Transparent;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label19->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label19->Location = System::Drawing::Point(10, 17);
			this->label19->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(143, 18);
			this->label19->TabIndex = 54;
			this->label19->Text = L"Текущее время T, с";
			// 
			// textBox13
			// 
			this->textBox13->Enabled = false;
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->textBox13->Location = System::Drawing::Point(193, 14);
			this->textBox13->Margin = System::Windows::Forms::Padding(2);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(103, 24);
			this->textBox13->TabIndex = 55;
			this->textBox13->Text = L"0";
			this->textBox13->TextChanged += gcnew System::EventHandler(this, &Form1::textBox13_TextChanged);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 40;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button2->Location = System::Drawing::Point(11, 145);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(64, 31);
			this->button2->TabIndex = 56;
			this->button2->Text = L"Старт";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// ru
			// 
			this->ru->BackColor = System::Drawing::Color::Transparent;
			this->ru->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ru->FlatAppearance->BorderColor = System::Drawing::Color::PowderBlue;
			this->ru->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ru->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ru->ForeColor = System::Drawing::Color::Transparent;
			this->ru->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ru.Image")));
			this->ru->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ru->Location = System::Drawing::Point(728, 4);
			this->ru->Margin = System::Windows::Forms::Padding(2);
			this->ru->Name = L"ru";
			this->ru->Size = System::Drawing::Size(37, 37);
			this->ru->TabIndex = 58;
			this->ru->UseVisualStyleBackColor = false;
			this->ru->Click += gcnew System::EventHandler(this, &Form1::ru_Click);
			// 
			// en
			// 
			this->en->BackColor = System::Drawing::Color::Transparent;
			this->en->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->en->FlatAppearance->BorderColor = System::Drawing::Color::PowderBlue;
			this->en->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->en->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->en->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"en.Image")));
			this->en->Location = System::Drawing::Point(687, 4);
			this->en->Margin = System::Windows::Forms::Padding(2);
			this->en->Name = L"en";
			this->en->Size = System::Drawing::Size(37, 37);
			this->en->TabIndex = 59;
			this->en->UseVisualStyleBackColor = false;
			this->en->Click += gcnew System::EventHandler(this, &Form1::en_Click);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->panel1->Location = System::Drawing::Point(21, 70);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(744, 176);
			this->panel1->TabIndex = 60;
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(20, 35);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(154, 31);
			this->button6->TabIndex = 61;
			this->button6->Text = L"Добавить функцию";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::Transparent;
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->Controls->Add(this->label7);
			this->panel6->Controls->Add(this->label5);
			this->panel6->Controls->Add(this->label4);
			this->panel6->Controls->Add(this->textBox7);
			this->panel6->Controls->Add(this->textBox6);
			this->panel6->Controls->Add(this->textBox5);
			this->panel6->Controls->Add(this->textBox4);
			this->panel6->Controls->Add(this->textBox3);
			this->panel6->Controls->Add(this->textBox2);
			this->panel6->Controls->Add(this->label6);
			this->panel6->Controls->Add(this->label3);
			this->panel6->Controls->Add(this->label2);
			this->panel6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->panel6->Location = System::Drawing::Point(21, 250);
			this->panel6->Margin = System::Windows::Forms::Padding(2);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(346, 180);
			this->panel6->TabIndex = 62;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::Transparent;
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel7->Controls->Add(this->label17);
			this->panel7->Controls->Add(this->label16);
			this->panel7->Controls->Add(this->textBox12);
			this->panel7->Controls->Add(this->textBox11);
			this->panel7->Controls->Add(this->label13);
			this->panel7->Controls->Add(this->textBox9);
			this->panel7->Controls->Add(this->label12);
			this->panel7->Controls->Add(this->textBox8);
			this->panel7->Controls->Add(this->label9);
			this->panel7->Controls->Add(this->label8);
			this->panel7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->panel7->Location = System::Drawing::Point(381, 250);
			this->panel7->Margin = System::Windows::Forms::Padding(2);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(384, 180);
			this->panel7->TabIndex = 63;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::Transparent;
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel8->Controls->Add(this->button2);
			this->panel8->Controls->Add(this->textBox13);
			this->panel8->Controls->Add(this->label19);
			this->panel8->Controls->Add(this->button5);
			this->panel8->Controls->Add(this->button4);
			this->panel8->Controls->Add(this->button3);
			this->panel8->Controls->Add(this->label18);
			this->panel8->Controls->Add(this->trackBar1);
			this->panel8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->panel8->Location = System::Drawing::Point(381, 434);
			this->panel8->Margin = System::Windows::Forms::Padding(2);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(384, 183);
			this->panel8->TabIndex = 64;
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::Transparent;
			this->panel9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel9->Controls->Add(this->comboBox2);
			this->panel9->Controls->Add(this->label1);
			this->panel9->Controls->Add(this->checkBox3);
			this->panel9->Controls->Add(this->checkBox2);
			this->panel9->Controls->Add(this->checkBox1);
			this->panel9->Controls->Add(this->comboBox1);
			this->panel9->Controls->Add(this->label11);
			this->panel9->Controls->Add(this->button1);
			this->panel9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->panel9->Location = System::Drawing::Point(20, 434);
			this->panel9->Margin = System::Windows::Forms::Padding(2);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(346, 183);
			this->panel9->TabIndex = 65;
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Монотонно одним цветом", L"Градиентно одним цветом",
					L"Градиентно четырьмя цветами", L"Цветовая схема"
			});
			this->comboBox2->Location = System::Drawing::Point(11, 81);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(303, 26);
			this->comboBox2->TabIndex = 37;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label1->Location = System::Drawing::Point(8, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 18);
			this->label1->TabIndex = 36;
			this->label1->Text = L"Тип отображения функций";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(772, 628);
			this->Controls->Add(this->panel9);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->en);
			this->Controls->Add(this->ru);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L" Параметры функции z=f(x,y,t)";
			this->Activated += gcnew System::EventHandler(this, &Form1::Form1_Activated);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Activated(System::Object^  sender, System::EventArgs^  e) {
		if (GRAPHICS.isinitOpenGl == false)
		{
			srand(time(0));
			CalculateScreenSize(GRAPHICS.scrw, GRAPHICS.scrh);//инициализация разрешения экрана
			System::Drawing::Font^ FFf;//масштабирование формы
			if (GRAPHICS.scrw<1360)
				FFf = gcnew System::Drawing::Font("Microsoft Sans Serif", 6, FontStyle::Regular);
			if (GRAPHICS.scrw == 1360)
				FFf = gcnew System::Drawing::Font("Microsoft Sans Serif", 7, FontStyle::Regular);
			if (GRAPHICS.scrw>1360)
				FFf = gcnew System::Drawing::Font("Microsoft Sans Serif", 8, FontStyle::Regular);
			Form1::Font = FFf;
			ResetLanguageMainForm(GRAPHICS.mode_Now);
			LoadErrors(GRAPHICS.mode_Now);
			comboBox1->SelectedIndex = 0;
			GRAPHICS.modeoses = comboBox1->SelectedIndex;
			comboBox2->SelectedIndex = 2;
			GRAPHICS.modecolor = comboBox2->SelectedIndex + 1;
			checkBox1->Checked = true;
			GRAPHICS.moderot = checkBox1->Checked;
			GRAPHICS.modegridgr = false;
			GRAPHICS.isinitOpenGl = true;
			GRAPHICS.modeistoses = checkBox2->Checked;
			GRAPHICS.modepokaz = checkBox3->Checked;

			button6_Click(sender, e);//добавление функции
			textBoxes[0]->Text = L"x^2+y^2";
			String^ instr = textBoxes[0]->Text;//textBoxex[0]->Text; добавление функций
			My3dvisualizator_v5::Form_Process^ f = gcnew My3dvisualizator_v5::Form_Process();
			f->Show();
			ProgressBar^ pri = f->getProgBar();
			Label^ lb1 = f->getLabel1();
			Label^ lb3 = f->getLabel3();
			GRAPHICS.InitErrorsGlobal(2);
			GRAPHICS.AddFunc(StrToCh(instr), instr->Length,
				RGB_MR(double(buttons_color_func[0]->BackColor.R) / 256,
					double(buttons_color_func[0]->BackColor.G) / 256,
					double(buttons_color_func[0]->BackColor.B) / 256), pri);//добавить функцию

			GRAPHICS.ShowErrors(f->getTextBox());//вывести ошибки в текстбокс
			lb1->Text = L"1";
			lb3->Text = L"1";
			GRAPHICS.TestOnDynamics();
			GRAPHICS.FuncsReOut();

			buttons_color_func[0]->Enabled = false;
			buttons_random_color[0]->Enabled = false;

			GRAPHICS.ffs = Form1::Font->Size;
			System::Drawing::Font^ FF = gcnew System::Drawing::Font("Microsoft Sans Serif", GRAPHICS.ffs + 1, FontStyle::Regular);
			Form1::panel1->Font = FF;
			Form1::panel6->Font = FF;
			Form1::panel7->Font = FF;
			Form1::panel8->Font = FF;
			Form1::panel9->Font = FF;

			Form1::button6->Font = FF;
			Form1::en->Font = FF;
			Form1::ru->Font = FF;
			Form1::menuStrip1->Font = FF;
		}

		if (GRAPHICS.isLoaded == true)
			//обновление элементов при загрузке функции
		{
			GRAPHICS.isLoaded = false;

			//разные языки
			LoadErrors(GRAPHICS.mode_Now);
			ResetLanguageMainForm(GRAPHICS.mode_Now);

			//масшабирование форм и ее элементов
			CalculateScreenSize(GRAPHICS.scrw, GRAPHICS.scrh);//инициализация разрешения экрана
			System::Drawing::Font^ FFf;//масштабирование формы
			if (GRAPHICS.scrw<1360)
				FFf = gcnew System::Drawing::Font("Microsoft Sans Serif", 6, FontStyle::Regular);
			if (GRAPHICS.scrw == 1360)
				FFf = gcnew System::Drawing::Font("Microsoft Sans Serif", 7, FontStyle::Regular);
			if (GRAPHICS.scrw>1360)
				FFf = gcnew System::Drawing::Font("Microsoft Sans Serif", 8, FontStyle::Regular);

			GRAPHICS.ffs = Form1::Font->Size;
			System::Drawing::Font^ FF = gcnew System::Drawing::Font("Microsoft Sans Serif", GRAPHICS.ffs + 1, FontStyle::Regular);
			Form1::panel1->Font = FF;
			Form1::panel6->Font = FF;
			Form1::panel7->Font = FF;
			Form1::panel8->Font = FF;
			Form1::panel9->Font = FF;

			Form1::button6->Font = FF;
			Form1::en->Font = FF;
			Form1::ru->Font = FF;
			Form1::menuStrip1->Font = FF;

			//обновление функций
			for (int i = n_funcs - 1; i >= 0; i--)
			{
				CheckBox^ chbi = checkBoxes[i];
				Label^ lbi = labels[i];
				TextBox^ tbi = textBoxes[i];
				Button^ bti1 = buttons_color_func[i];
				Button^ bti2 = buttons_random_color[i];
				Button^ bti3 = buttons_delete_func[i];
				panel1->Controls->Remove(chbi);
				panel1->Controls->Remove(lbi);
				panel1->Controls->Remove(tbi);
				panel1->Controls->Remove(bti1);
				panel1->Controls->Remove(bti2);
				panel1->Controls->Remove(bti3);

				checkBoxes = DeleteDynamixObjects(checkBoxes, n_funcs, i);
				labels = DeleteDynamixObjects(labels, n_funcs, i);
				textBoxes = DeleteDynamixObjects(textBoxes, n_funcs, i);
				buttons_color_func = DeleteDynamixObjects(buttons_color_func, n_funcs, i);
				buttons_random_color = DeleteDynamixObjects(buttons_random_color, n_funcs, i);
				buttons_delete_func = DeleteDynamixObjects(buttons_delete_func, n_funcs, i);
				n_funcs--;
			}
			for (int i = 0; i < GRAPHICS.nfuncs; i++)
			{
				button6_Click(sender, e);//добавление функции
				checkBoxes[i]->Checked = GRAPHICS.funcs[i].isFuncVisible;
				textBoxes[i]->Text = ChToStr(GRAPHICS.funcs[i].str);
				buttons_color_func[i]->BackColor = Color::FromArgb(256 * GRAPHICS.funcs[i].color.getColor(0), 256 * GRAPHICS.funcs[i].color.getColor(1), 256 * GRAPHICS.funcs[i].color.getColor(2));
			}

			//остальных элементов
			textBox8->Text = uchToStr(dtuch(GRAPHICS.ngrid));
			textBox11->Text = uchToStr(dtuch(GRAPHICS.t1));
			textBox12->Text = uchToStr(dtuch(GRAPHICS.t2));
			GRAPHICS.ti = GRAPHICS.t1;
			GRAPHICS.isinitOpenGl = true;
			comboBox1->SelectedIndex = GRAPHICS.modeoses;
			comboBox2->SelectedIndex = GRAPHICS.modecolor - 1;
			checkBox1->Checked = GRAPHICS.moderot;
			GRAPHICS.modegridgr = false;
			checkBox2->Checked = GRAPHICS.modeistoses;
			checkBox3->Checked = GRAPHICS.modepokaz;
			if (GRAPHICS.fps>10 && GRAPHICS.fps<100)
				textBox9->Text = uchToStr(dtuch(GRAPHICS.fps));
			else
			{
				if (GRAPHICS.fps>100) { GRAPHICS.fps = 100; textBox9->Text = L"100"; }
				if (GRAPHICS.fps<10) { GRAPHICS.fps = 10; textBox9->Text = L"10"; }
			}

			textBox2->Text = uchToStr(dtuch(GRAPHICS.Xmin));
			textBox3->Text = uchToStr(dtuch(GRAPHICS.Xmax));
			textBox4->Text = uchToStr(dtuch(GRAPHICS.Ymin));
			textBox5->Text = uchToStr(dtuch(GRAPHICS.Ymax));

			if (GRAPHICS.isautozmin == true)
				textBox6->Text = L"auto";
			else
				textBox6->Text = uchToStr(dtuch(GRAPHICS.Zmin));
			if (GRAPHICS.isautozmax == true)
				textBox7->Text = L"auto";
			else
				textBox7->Text = uchToStr(dtuch(GRAPHICS.Zmax));

			if (GRAPHICS.Failed == true)
				MessageBox::Show(this, strToStr(errors[0]), L"Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);

			//обновление элементов, управляющих временем
			textBox13->Text = uchToStr(dtuch(GRAPHICS.t1));
			trackBar1->Value = 0;
			if (GRAPHICS.istDynamic)
			{
				textBox13->Enabled = true;//разрешить управление динамическим процессом
				trackBar1->Enabled = true;
				button2->Enabled = true;
				button3->Enabled = true;
				button4->Enabled = false;
				button5->Enabled = false;
			}
			else
			{
				textBox13->Enabled = false;//запретить управление динамическим процессом
				trackBar1->Enabled = false;
				button2->Enabled = false;
				button3->Enabled = false;
				button4->Enabled = false;
				button5->Enabled = false;
			}
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		bool valf_changed = false;//true- если параметры на форме были изменены(тогда все равно надо реинициализировать неизменные функции)
		double xmint, xmaxt, ymint, ymaxt, zmint, zmaxt;
		int ngridt, fpst, t1t, t2t;
		GRAPHICS.modeoses = comboBox1->SelectedIndex;
		GRAPHICS.Failed = false;
		xmint = GRAPHICS.Xmin;
		xmaxt = GRAPHICS.Xmax;
		ymint = GRAPHICS.Ymin;
		ymaxt = GRAPHICS.Ymax;
		ngridt = GRAPHICS.ngrid;
		zmint = GRAPHICS.Zmin;
		zmaxt = GRAPHICS.Zmax;
		t1t = GRAPHICS.t1;
		t2t = GRAPHICS.t2;
		fpst = GRAPHICS.fps;
		bool isautozmint = GRAPHICS.isautozmin;
		bool isautozmaxt = GRAPHICS.isautozmax;

		if (textBox6->Text == L"auto")
			GRAPHICS.isautozmin = true;
		else
		{
			GRAPHICS.isautozmin = false;
			GRAPHICS.Zmin = StrToD(GRAPHICS.Failed, textBox6->Text);
		}
		if (textBox7->Text == L"auto")
			GRAPHICS.isautozmax = true;
		else
		{
			GRAPHICS.isautozmax = false;
			GRAPHICS.Zmax = StrToD(GRAPHICS.Failed, textBox7->Text);
		}
		GRAPHICS.Xmin = StrToD(GRAPHICS.Failed, textBox2->Text);
		GRAPHICS.Xmax = StrToD(GRAPHICS.Failed, textBox3->Text);
		GRAPHICS.Ymin = StrToD(GRAPHICS.Failed, textBox4->Text);
		GRAPHICS.Ymax = StrToD(GRAPHICS.Failed, textBox5->Text);

		if (GRAPHICS.Xmin>GRAPHICS.Xmax ||
			GRAPHICS.Ymin>GRAPHICS.Ymax ||
			(GRAPHICS.Zmin>GRAPHICS.Zmax && GRAPHICS.isautozmin == false && GRAPHICS.isautozmax == false))
			GRAPHICS.Failed = true;

		GRAPHICS.ngrid = (int)StrToD(GRAPHICS.Failed, textBox8->Text);
		if (GRAPHICS.ngrid >= soarr) { GRAPHICS.ngrid = soarr - 1; textBox8->Text = L"100"; }
		if (GRAPHICS.ngrid<5) { GRAPHICS.ngrid = 5; textBox8->Text = L"5"; }

		GRAPHICS.fps = (int)StrToD(GRAPHICS.Failed, textBox9->Text);
		if (GRAPHICS.fps>100) { GRAPHICS.fps = 100; textBox9->Text = L"100"; }
		if (GRAPHICS.fps<10) { GRAPHICS.fps = 10; textBox9->Text = L"10"; }

		GRAPHICS.t1 = StrToD(GRAPHICS.Failed, textBox11->Text);
		GRAPHICS.t2 = StrToD(GRAPHICS.Failed, textBox12->Text);
		GRAPHICS.ti = GRAPHICS.t1;

		if (GRAPHICS.t1>GRAPHICS.t2 && GRAPHICS.Failed == false && GRAPHICS.istDynamic)//исключение если t1>t2
			GRAPHICS.Failed = true;

		if (isautozmint != GRAPHICS.isautozmin || isautozmaxt != GRAPHICS.isautozmax ||
			xmint != GRAPHICS.Xmin || xmaxt != GRAPHICS.Xmax ||
			ymint != GRAPHICS.Ymin || ymaxt != GRAPHICS.Ymax ||
			zmint != GRAPHICS.Zmin || zmaxt != GRAPHICS.Zmax ||
			t1t != GRAPHICS.t1 || t2t != GRAPHICS.t2 || ngridt != GRAPHICS.ngrid || fpst != GRAPHICS.fps)
		{
			valf_changed = true;//проверка на изменение параметров формы
		}

		if (GRAPHICS.Failed == false)
		{
			My3dvisualizator_v5::Form_Process^ f = gcnew My3dvisualizator_v5::Form_Process();
			f->Show();
			ProgressBar^ pri = f->getProgBar();
			Label^ lb1 = f->getLabel1();
			Label^ lb3 = f->getLabel3();
			lb1->Text = L"0";
			lb3->Text = uchToStr(dtuch(n_funcs));
			f->Update();
			GRAPHICS.InitErrorsGlobal(n_funcs + 1);
			int equal = 0;//0- если функция не изменялась
			int k_calculated = 0;//для label1 of form_process. количество рассчитанных функций

			for (int i = 0; i < n_funcs; i++)//реинициализация функций
			{
				String^ instr = textBoxes[i]->Text;
				equal = -1;
				if (i < GRAPHICS.nfuncs)
				{
					equal = strcmp(StrToCh(instr), GRAPHICS.funcs[i].str);
					if (equal != 0 || valf_changed || GRAPHICS.funcs[i].failed == true)
						GRAPHICS.ReInitFunc(i, StrToCh(instr), instr->Length,
							RGB_MR(double(buttons_color_func[i]->BackColor.R) / 256,
								double(buttons_color_func[i]->BackColor.G) / 256,
								double(buttons_color_func[i]->BackColor.B) / 256), pri);
					else//если функция уже рассчитана
						pri->Value = 100;
				}
				else
					GRAPHICS.AddFunc(StrToCh(instr), instr->Length,
						RGB_MR(double(buttons_color_func[i]->BackColor.R) / 256,
							double(buttons_color_func[i]->BackColor.G) / 256,
							double(buttons_color_func[i]->BackColor.B) / 256), pri);
				if (GRAPHICS.funcs[i].failed == false)
					k_calculated++;
				lb1->Text = uchToStr(dtuch(k_calculated));
				f->Update();
			}
		GRAPHICS.ShowErrors(f->getTextBox());//вывести ошибки в текстбокс
		GRAPHICS.TestOnDynamics();
		GRAPHICS.FuncsReOut();
		}

		for (int i = GRAPHICS.nfuncs - 1; i >= 0; i--)
		{
			if (i >= n_funcs)
			{
				GRAPHICS.DeleteFunc(i);
			}
		}
		

		GRAPHICS.IsTimeStartedNow = false;

		if (GRAPHICS.Failed == false)//элементы, управляющие временем
		{
			textBox13->Text = uchToStr(dtuch(GRAPHICS.t1));
			if (GRAPHICS.istDynamic)
			{
				textBox13->Enabled = true;//разрешить управление динамическим процессом
				trackBar1->Enabled = true;
				button2->Enabled = true;
				button3->Enabled = true;
				button4->Enabled = false;
				button5->Enabled = false;
			}
			else
			{
				textBox13->Enabled = false;//запретить управление динамическим процессом
				trackBar1->Enabled = false;
				button2->Enabled = false;
				button3->Enabled = false;
				button4->Enabled = false;
				button5->Enabled = false;
			}
			if (GRAPHICS.nfuncs <= 0)
			{
				MessageBox::Show(this, strToStr(errors[11]), L"Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);/*err11*/
				GRAPHICS.Failed = true;
			}
		}
		else /*if (GRAPHICS.funcs[].failed==false)*/
		{
			System::Windows::Forms::DialogResult result = MessageBox::Show(this,
				strToStr(errors[0]), L"Ошибка", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);/*err0*/
			if (result == System::Windows::Forms::DialogResult::Cancel)
			{
				textBox2->Text = uchToStr(dtuch(xmint));
				textBox3->Text = uchToStr(dtuch(xmaxt));
				textBox4->Text = uchToStr(dtuch(ymint));
				textBox5->Text = uchToStr(dtuch(ymaxt));
				if (GRAPHICS.isautozmin == true)
					textBox6->Text = L"auto";
				else
					textBox6->Text = uchToStr(dtuch(zmint));
				if (GRAPHICS.isautozmax == true)
					textBox7->Text = L"auto";
				else
					textBox7->Text = uchToStr(dtuch(zmaxt));
				textBox8->Text = uchToStr(dtuch(/*(double)*/ngridt));
				textBox9->Text = uchToStr(dtuch(GRAPHICS.fps));
				textBox11->Text = uchToStr(dtuch(GRAPHICS.t1));
				textBox12->Text = uchToStr(dtuch(GRAPHICS.t2));
			}

			for (int i = 0; i<GRAPHICS.nfuncs; i++)
				GRAPHICS.funcs[i].failed = true;
		}
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		GRAPHICS.modeoses = comboBox1->SelectedIndex;
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		GRAPHICS.moderot = checkBox1->Checked;
	}
	private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		GRAPHICS.modeistoses = checkBox2->Checked;
	}
	private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		GRAPHICS.modepokaz = checkBox3->Checked;
	}
	private: System::Void ChangeTimeIpTB(System::Object^  sender, System::EventArgs^  e) {
		if (GRAPHICS.IsTimeStartedNow == false)
		{//событие по изменению значения trackbar'a
			double a, b, bs;//a- значение texbox'a, b- trackbar'a, bs- b в секундах
			a = StrToD(GRAPHICS.Failed, textBox13->Text);
			b = trackBar1->Value;
			bs = (double)b / trackBar1->Maximum*(GRAPHICS.t2 - GRAPHICS.t1) + GRAPHICS.t1;
			if (a != bs)
				textBox13->Text = uchToStr(dtuch(bs));
			GRAPHICS.ti = bs;
		}
	}
	private: System::Void textBox13_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (GRAPHICS.IsTimeStartedNow == false && GRAPHICS.istDynamic)
		{//событие по изменению textbox'a
			double a, b, bs;//a- значение texbox'a, b- trackbar'a, bs- b в секундах
			bool fail = false;
			a = StrToD(fail, textBox13->Text);
			if (fail == false)
			{
				if (a<GRAPHICS.t1)
				{
					a = GRAPHICS.t1;
					textBox13->Text = uchToStr(dtuch(a));
					trackBar1->Value = (double)(a - GRAPHICS.t1) / (GRAPHICS.t2 - GRAPHICS.t1)*trackBar1->Maximum;
				}
				else if (a>GRAPHICS.t2)
				{
					a = GRAPHICS.t2;
					textBox13->Text = uchToStr(dtuch(a));
					trackBar1->Value = (double)(a - GRAPHICS.t1) / (GRAPHICS.t2 - GRAPHICS.t1)*trackBar1->Maximum;
				}
				/*if (Contain('.',StrToCh(textBox13->Text),textBox13->Text->Length)==true || Contain(',',StrToCh(textBox13->Text),textBox13->Text->Length)==true)
				{
				textBox13->Text=uchToStr(dtuch(a));
				}*/
				b = trackBar1->Value;
				bs = (double)b / trackBar1->Maximum*(GRAPHICS.t2 - GRAPHICS.t1) + GRAPHICS.t1;
				if (a != bs)
					trackBar1->Value = (double)(a - GRAPHICS.t1) / (GRAPHICS.t2 - GRAPHICS.t1)*trackBar1->Maximum;
				GRAPHICS.ti = a;
			}
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (GRAPHICS.IsTimeStartedNow == false)
		{
			button2->Enabled = false;
			button3->Enabled = false;
			button4->Enabled = true;
			button5->Enabled = true;
			GRAPHICS.IsTimeStartedNow = true;
			trackBar1->Enabled = false;
			textBox13->Enabled = false;
			GRAPHICS.ti = GRAPHICS.t1;
			textBox13->Text = uchToStr(dtuch(GRAPHICS.t1));
			trackBar1->Value = 0;
		}
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (GRAPHICS.IsTimeStartedNow == false && GRAPHICS.ti != GRAPHICS.t2)
		{
			button2->Enabled = false;
			button3->Enabled = false;
			button4->Enabled = true;
			button5->Enabled = true;
			GRAPHICS.IsTimeStartedNow = true;
			trackBar1->Enabled = false;
			textBox13->Enabled = false;
		}
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		if (GRAPHICS.IsTimeStartedNow == true)
		{
			button2->Enabled = true;
			button3->Enabled = true;
			button4->Enabled = false;
			button5->Enabled = false;
			GRAPHICS.IsTimeStartedNow = false;
			trackBar1->Enabled = true;
			textBox13->Enabled = true;
		}
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		if (GRAPHICS.IsTimeStartedNow == true)
		{
			button2->Enabled = true;
			button3->Enabled = true;
			button4->Enabled = false;
			button5->Enabled = false;
			GRAPHICS.IsTimeStartedNow = false;
			trackBar1->Enabled = true;
			textBox13->Enabled = true;
			GRAPHICS.ti = GRAPHICS.t1;
			textBox13->Text = uchToStr(dtuch(GRAPHICS.t1));
			trackBar1->Value = 0;
		}
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (GRAPHICS.IsTimeStartedNow == true)
		{
			if (GRAPHICS.ti<GRAPHICS.t1)
				GRAPHICS.ti = GRAPHICS.t1;
			else if (GRAPHICS.ti>GRAPHICS.t2)
			{
				GRAPHICS.ti = GRAPHICS.t2;
				GRAPHICS.IsTimeStartedNow = false;
				button2->Enabled = true;
				button3->Enabled = false;
				button4->Enabled = false;
				button5->Enabled = false;
				trackBar1->Enabled = true;
				textBox13->Enabled = true;
				textBox13->Text = uchToStr(dtuch(GRAPHICS.t2));
				trackBar1->Value = trackBar1->Maximum;
			}
			else
				GRAPHICS.ti += (double)timer1->Interval / 1000;

			textBox13->Text = uchToStr(dtuch(GRAPHICS.ti));
			trackBar1->Value = (double)(GRAPHICS.ti - GRAPHICS.t1) / (GRAPHICS.t2 - GRAPHICS.t1)*trackBar1->Maximum;
		}
		/*if (progressBar1->Value==100)
		t+=(double)timer1->Interval/1000;
		else if (progressBar1->Value<100)
		t=0;
		if (t>=1)
		{
		t=0;
		progressBar1->Visible=false;
		progressBar1->Value=0;
		Form1::Height=sizef-35;
		}*/
	}
	private: System::Void ru_Click(System::Object^  sender, System::EventArgs^  e) {
		if (GRAPHICS.mode_Now != 0)
		{
			GRAPHICS.mode_Now = 0;
			ResetLanguageMainForm(GRAPHICS.mode_Now);
			LoadErrors(GRAPHICS.mode_Now);
		}
	}
	private: System::Void en_Click(System::Object^  sender, System::EventArgs^  e) {
		if (GRAPHICS.mode_Now != 1)
		{
			GRAPHICS.mode_Now = 1;
			ResetLanguageMainForm(GRAPHICS.mode_Now);
			LoadErrors(GRAPHICS.mode_Now);
		}
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		checkBoxes = ReinitDynamixObjects(checkBoxes, n_funcs, n_funcs + 1);
		labels = ReinitDynamixObjects(labels, n_funcs, n_funcs + 1);
		textBoxes = ReinitDynamixObjects(textBoxes, n_funcs, n_funcs + 1);
		buttons_color_func = ReinitDynamixObjects(buttons_color_func, n_funcs, n_funcs + 1);
		buttons_random_color = ReinitDynamixObjects(buttons_random_color, n_funcs, n_funcs + 1);
		buttons_delete_func = ReinitDynamixObjects(buttons_delete_func, n_funcs, n_funcs + 1);
		int panel_width = panel1->Size.Width;

		System::Drawing::Font^ FF = gcnew System::Drawing::Font("Microsoft Sans Serif", GRAPHICS.ffs + 1, FontStyle::Regular);

		panel1->AutoScrollPosition = Point(0, 0);//без этого криво добавляются если прокрутить
		CheckBox^ chbi = gcnew CheckBox();
		chbi->Size = Drawing::Size(18, 17);
		chbi->Location = Drawing::Point(11, 11 + 36 * n_funcs);
		chbi->Text = L"";
		chbi->Checked = true;
		chbi->Font = FF;
		chbi->CheckedChanged += gcnew System::EventHandler(this, &Form1::CheckedChangedFunci);
		panel1->Controls->Add(chbi);
		checkBoxes[n_funcs] = chbi;

		Label^ lbi = gcnew Label();
		lbi->Size = Drawing::Size(50, 18);
		lbi->Location = Drawing::Point(35, 9 + 36 * n_funcs);
		lbi->Text = uchToStr(dtuch(n_funcs + 1)) + L") z=";
		lbi->Font = FF;
		panel1->Controls->Add(lbi);
		labels[n_funcs] = lbi;

		TextBox^ tbi = gcnew TextBox();
		tbi->Size = Drawing::Size(panel_width - 220, 24);//618
		tbi->Location = Drawing::Point(91, 6 + 36 * n_funcs);
		tbi->Text = L"";
		tbi->Font = FF;
		panel1->Controls->Add(tbi);
		textBoxes[n_funcs] = tbi;

		Button^ bti1 = gcnew Button();//установить цвет
		bti1->Size = Drawing::Size(28, 28);
		bti1->Location = Drawing::Point(panel_width - 122, 5 + 36 * n_funcs);
		bti1->Text = L"";
		bti1->Font = FF;
		bti1->BackColor = Color::FromArgb(rand() / 128, rand() / 128, rand() / 128);
		bti1->Click += gcnew EventHandler(this, &Form1::changeColorFunci);
		panel1->Controls->Add(bti1);
		buttons_color_func[n_funcs] = bti1;

		Button^ bti2 = gcnew Button();//рандомный цвет
		bti2->Size = Drawing::Size(28, 28);
		bti2->Location = Drawing::Point(panel_width - 88, 5 + 36 * n_funcs);
		bti2->Text = L"#";
		bti2->Font = FF;
		bti2->Click += gcnew EventHandler(this, &Form1::randomColorFunci);
		panel1->Controls->Add(bti2);
		buttons_random_color[n_funcs] = bti2;

		Button^ bti3 = gcnew Button();
		bti3->Size = Drawing::Size(28, 28);
		bti3->Location = Drawing::Point(panel_width - 54, 5 + 36 * n_funcs);
		bti3->Text = L"";
		bti3->Font = FF;
		bti3->BackgroundImage = Image::FromFile(L"data\\cross.png");
		bti3->BackgroundImageLayout = ImageLayout::Stretch;
		bti3->Click += gcnew EventHandler(this, &Form1::deleteFunci);
		panel1->Controls->Add(bti3);
		buttons_delete_func[n_funcs] = bti3;

		n_funcs++;
	}
	private: System::Void deleteFunci(System::Object^ sender, System::EventArgs^ e) {
		panel1->AutoScrollPosition = Point(0, 0);//без этого криво добавляются если прокрутить
		Button^ bti3 = reinterpret_cast <Button^>(sender);
		Point^ choords = bti3->Location;
		int k = (choords->Y - 5) / 36;//номер(с нуля) функции в массивах buttons,..
		CheckBox^ chbi = checkBoxes[k];
		Label^ lbi = labels[k];
		TextBox^ tbi = textBoxes[k];
		Button^ bti1 = buttons_color_func[k];
		Button^ bti2 = buttons_random_color[k];
		panel1->Controls->Remove(chbi);
		panel1->Controls->Remove(lbi);
		panel1->Controls->Remove(tbi);
		panel1->Controls->Remove(bti1);
		panel1->Controls->Remove(bti2);
		panel1->Controls->Remove(bti3);
		for (int i = k + 1; i<n_funcs; i++)
		{
			chbi = checkBoxes[i];
			lbi = labels[i];
			tbi = textBoxes[i];
			bti1 = buttons_color_func[i];
			bti2 = buttons_random_color[i];
			bti3 = buttons_delete_func[i];
			chbi->Top -= 36;
			lbi->Top -= 36;
			tbi->Top -= 36;
			bti1->Top -= 36;
			bti2->Top -= 36;
			bti3->Top -= 36;
			lbi->Text = uchToStr(dtuch(i)) + L") z=";
		}

		checkBoxes = DeleteDynamixObjects(checkBoxes, n_funcs, k);
		labels = DeleteDynamixObjects(labels, n_funcs, k);
		textBoxes = DeleteDynamixObjects(textBoxes, n_funcs, k);
		buttons_color_func = DeleteDynamixObjects(buttons_color_func, n_funcs, k);
		buttons_random_color = DeleteDynamixObjects(buttons_random_color, n_funcs, k);
		buttons_delete_func = DeleteDynamixObjects(buttons_delete_func, n_funcs, k);
		n_funcs--;
	}
	private: System::Void CheckedChangedFunci(System::Object^ sender, System::EventArgs^ e) {
		panel1->AutoScrollPosition = Point(0, 0);//без этого криво добавляются если прокрутить
		CheckBox^ chbi = reinterpret_cast <CheckBox^>(sender);
		Point^ choords = chbi->Location;
		int k = (choords->Y - 11) / 36;//номер(с нуля) функции в массивах buttons,..
		GRAPHICS.funcs[k].isFuncVisible = chbi->Checked;
	}
	private: System::Void changeColorFunci(System::Object^ sender, System::EventArgs^ e) {
		panel1->AutoScrollPosition = Point(0, 0);//без этого криво добавляются если прокрутить
		Button^ bti = reinterpret_cast <Button^>(sender);
		Point^ choords = bti->Location;
		int k = (choords->Y - 5) / 36;//номер(с нуля) функции в массивах buttons,..
		if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			bti->BackColor = colorDialog1->Color;
			if (bti->BackColor != buttons_color_func[k]->BackColor)
				buttons_color_func[k] = bti;
			if (k < GRAPHICS.nfuncs)
				GRAPHICS.funcs[k].color = RGB_MR(double(colorDialog1->Color.R) / 256, double(colorDialog1->Color.G) / 256, double(colorDialog1->Color.B) / 256);
			GRAPHICS.ReInitColors();
		}
	}
	private: System::Void randomColorFunci(System::Object^ sender, System::EventArgs^ e) {
		panel1->AutoScrollPosition = Point(0, 0);//без этого криво добавляются если прокрутить
		Button^ bti = reinterpret_cast <Button^>(sender);
		Point^ choords = bti->Location;
		int k = (choords->Y - 5) / 36;//номер(с нуля) функции в массивах buttons,..
		buttons_color_func[k]->BackColor = Color::FromArgb(rand() / 128, rand() / 128, rand() / 128);
		if (k < GRAPHICS.nfuncs)
			GRAPHICS.funcs[k].color = RGB_MR(double(buttons_color_func[k]->BackColor.R) / 256, double(buttons_color_func[k]->BackColor.G) / 256, double(buttons_color_func[k]->BackColor.B) / 256);
		GRAPHICS.ReInitColors();
	}
	private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		Form_Main->Close();
	}
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		GRAPHICS.modecolor = comboBox2->SelectedIndex + 1;
		GRAPHICS.ReInitColors();
		if (comboBox2->SelectedIndex == 0 || comboBox2->SelectedIndex == 1)
			for (int i = 0; i < n_funcs; i++)
			{
				buttons_color_func[i]->Enabled = true;
				buttons_random_color[i]->Enabled = true;
			}
		else
			for (int i = 0; i < n_funcs; i++)
			{
				buttons_color_func[i]->Enabled = false;
				buttons_random_color[i]->Enabled = false;
			}
	}
	private: System::Void СправкаToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		Open_Help();
	}
	private: System::Void очиститьФункцииToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		while (GRAPHICS.nfuncs > 0)
		{
			GRAPHICS.DeleteFunc(0);
		}
		for (int i = n_funcs - 1; i >= 0; i--)
		{
			CheckBox^ chbi = checkBoxes[i];
			Label^ lbi = labels[i];
			TextBox^ tbi = textBoxes[i];
			Button^ bti1 = buttons_color_func[i];
			Button^ bti2 = buttons_random_color[i];
			Button^ bti3 = buttons_delete_func[i];
			panel1->Controls->Remove(chbi);
			panel1->Controls->Remove(lbi);
			panel1->Controls->Remove(tbi);
			panel1->Controls->Remove(bti1);
			panel1->Controls->Remove(bti2);
			panel1->Controls->Remove(bti3);

			checkBoxes = DeleteDynamixObjects(checkBoxes, n_funcs, i);
			labels = DeleteDynamixObjects(labels, n_funcs, i);
			textBoxes = DeleteDynamixObjects(textBoxes, n_funcs, i);
			buttons_color_func = DeleteDynamixObjects(buttons_color_func, n_funcs, i);
			buttons_random_color = DeleteDynamixObjects(buttons_random_color, n_funcs, i);
			buttons_delete_func = DeleteDynamixObjects(buttons_delete_func, n_funcs, i);
			n_funcs--;
		}
	}
	private: System::Void сохранитьФункцииToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		saveFileDialog1->Filter = "MR funcs files (*.MRf5)|*.MRf5|All files (*.*)|*.*";
		saveFileDialog1->RestoreDirectory = true;
		saveFileDialog1->InitialDirectory = Application::StartupPath + L"\\data\\Saves";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			GRAPHICS.SaveToFile(StrToCh(saveFileDialog1->FileName));
			GRAPHICS.SaveToFileInfo(Application::StartupPath + L"\\data\\Saves\\!FileInfo.info", StrToCh(saveFileDialog1->FileName->Substring(Application::StartupPath->Length)));
		}
	}
	private: System::Void загрузитьФункцииToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		My3dvisualizator_v5::FormLoad^ f = gcnew My3dvisualizator_v5::FormLoad();
		f->Show();
	}
	private: System::Void ДемоToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		My3dvisualizator_v5::FormDemo^ f = gcnew My3dvisualizator_v5::FormDemo();
		f->Show();
	}
};
}