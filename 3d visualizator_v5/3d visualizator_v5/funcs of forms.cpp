#include "stdafx.h"
#include "global.h"
#include "func.h"
#include "FormLoad.h"
#include "FormDemo.h"
#include "Form1.h"
#include "Form_Process.h"
#include "conversions.h"
#include "OpenGL funcs.h"

String^ MyScan(FILE * ptrFile,bool &isOk)
{
	int res, res2;
	int k=0;
	String^ str=L""; char chi[256]=""; char chend;
	do
	{
		chend=0;
		res = fscanf(ptrFile,"%[^\n]",chi);
		res2= fscanf(ptrFile,"%c", &chend);

		if (res==EOF)
		{
			isOk=false;
			break;
		}

		if (strcmp(chi,"***dthe*next***") != 0)
		{
			if (res>0)
				str+=ChToStr(chi);
			if (res2>0)
			{
				char* ch=new char[1];
				ch[0]=chend;
				ch[1]=0;
				str+=ChToStr(ch);
			}
			k++;
		}
		else
		{
			if (k==1)
				str=str->Remove(str->Length-1);
			break;
		}
	}while (1==1);	
	
	return str;
}

array<String^>^ MyScanToTextBox(FILE * ptrFile,bool &isOk)
{
	String^ str = isOk ? MyScan(ptrFile,isOk) : L"";
	unsigned int n=1, k=0;int l=str->Length;
	for (int i=0; i<l; i++)
		if (str[i]==L'\n')
			n++;
	if (n==1)
		n++;
	array<String^>^ tempArray = gcnew array<String^>(n-1);

	for (int i=0; i<l; i++)
		if (str[i]!=L'\n')
			tempArray[k]+=str[i];
		else
			k++;

	return tempArray;
}

void My3dvisualizator_v5::Form1::ResetLanguageMainForm(int mode)
{
	std::string stri = StrTostr(Application::StartupPath) + std::string("\\data\\") + Language[mode] + std::string(".ini");
	const char* out = strToCh(stri);
	FILE * ptrFile;
	fopen_s(&ptrFile, out,"r");
	bool isOk = false;
	if (ptrFile != NULL)//проверка на корректность файла
		isOk= true;
	else
		return;

	if (GRAPHICS.mode_Now==mode_Form1)//защита от повторной смены €зыка
		return;
	else
		mode_Form1= GRAPHICS.mode_Now;

	String^ CaptionGL = isOk ? MyScan(ptrFile,isOk) : L"";//заголовок окна OpenGL
	
	if (GRAPHICS.isinitOpenGl==true)
	{
		const char *title = StrToCh(CaptionGL);
		ChangeTitleOpenGL(title);
	}

	Text = isOk ? MyScan(ptrFile,isOk) : L"";//название формы

	FileToolStripMenuItem->Text = isOk ? MyScan(ptrFile, isOk) : L"";//меню
		очистить‘ункцииToolStripMenuItem->Text = isOk ? MyScan(ptrFile, isOk) : L"";
		сохранить‘ункцииToolStripMenuItem->Text = isOk ? MyScan(ptrFile, isOk) : L"";
		загрузить‘ункцииToolStripMenuItem->Text = isOk ? MyScan(ptrFile, isOk) : L"";
	ƒемоToolStripMenuItem->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	—правкаToolStripMenuItem->Text = isOk ? MyScan(ptrFile, isOk) : L"";

	button1->Text = isOk ? MyScan(ptrFile,isOk) : L"";//кнопки
	button2->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	button3->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	button4->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	button5->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	button6->Text = isOk ? MyScan(ptrFile,isOk) : L"";

	label2->Text = isOk ? MyScan(ptrFile,isOk) : L"";//надписи
	label3->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	label4->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	label5->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	label6->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	label7->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	label8->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	label9->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	label11->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	label1->Text = isOk ? MyScan(ptrFile, isOk) : L"";
	label12->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	label13->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	label16->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	label17->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	label18->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	label19->Text = isOk ? MyScan(ptrFile,isOk) : L"";

	/*textBox2->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	textBox3->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	textBox4->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	textBox5->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	textBox6->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	textBox7->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	textBox8->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	textBox9->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	textBox11->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	textBox12->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	textBox13->Text = isOk ? MyScan(ptrFile,isOk) : L"";*/

	checkBox1->Text = isOk ? MyScan(ptrFile,isOk) : L"";//checkboxes
	checkBox2->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	checkBox3->Text = isOk ? MyScan(ptrFile,isOk) : L"";

	comboBox1->Items->Clear();
	if (isOk)	comboBox1->Items->Add(MyScan(ptrFile,isOk));
	if (isOk)	comboBox1->Items->Add(MyScan(ptrFile,isOk));
	if (isOk)	comboBox1->Items->Add(MyScan(ptrFile,isOk));
	comboBox1->SelectedIndex = GRAPHICS.modeoses;

	comboBox2->Items->Clear();
	if (isOk)	comboBox2->Items->Add(MyScan(ptrFile, isOk));
	if (isOk)	comboBox2->Items->Add(MyScan(ptrFile, isOk));
	if (isOk)	comboBox2->Items->Add(MyScan(ptrFile, isOk));
	if (isOk)	comboBox2->Items->Add(MyScan(ptrFile, isOk));
	comboBox2->SelectedIndex = GRAPHICS.modecolor - 1;

	fclose(ptrFile);
}

void My3dvisualizator_v5::FormLoad::ResetLanguageLoadForm(int mode)
{
	std::string stri = StrTostr(Application::StartupPath) + std::string("\\data\\") + Language[mode] + std::string("load.ini");
	const char* out = strToCh(stri);
	FILE * ptrFile;
	fopen_s(&ptrFile, out, "r");
	bool isOk=false;
	if (ptrFile != NULL)//проверка на корректность файла
		isOk= true;
	else
		return;

	if (GRAPHICS.mode_Now==mode_FormLoad)//защита от повторной смены €зыка
		return;
	else
		mode_FormLoad = GRAPHICS.mode_Now;

	Text = isOk ? MyScan(ptrFile,isOk) : L"";//название формы

	button1->Text = isOk ? MyScan(ptrFile,isOk) : L"";//button1
	button2->Text = isOk ? MyScan(ptrFile, isOk) : L"";//button2
	button3->Text = isOk ? MyScan(ptrFile, isOk) : L"";//button3

	dataGridView1->Columns[0]->HeaderText = isOk ? MyScan(ptrFile, isOk) : L"";
	dataGridView1->Columns[1]->HeaderText = isOk ? MyScan(ptrFile, isOk) : L"";
	dataGridView1->Columns[2]->HeaderText = isOk ? MyScan(ptrFile, isOk) : L"";

	fclose(ptrFile);
}

void My3dvisualizator_v5::Form_Process::ResetLanguageProcessForm(int mode)
{
	std::string stri = StrTostr(Application::StartupPath) + std::string("\\data\\") + Language[mode] + std::string("process.ini");
	const char* out = strToCh(stri);
	FILE * ptrFile;
	fopen_s(&ptrFile, out, "r");
	bool isOk=false;
	if (ptrFile != NULL)//проверка на корректность файла
		isOk= true;
	else
		return;

	if (GRAPHICS.mode_Now==mode_FormProcess)//защита от повторной смены €зыка
		return;
	else
		mode_FormProcess= GRAPHICS.mode_Now;

	Text = isOk ? MyScan(ptrFile,isOk) : L"";//название формы

	label2->Text = isOk ? MyScan(ptrFile,isOk) : L"";//labels
	label4->Text = isOk ? MyScan(ptrFile,isOk) : L"";
	label5->Text = isOk ? MyScan(ptrFile,isOk) : L"";

	textBox1->Lines = isOk ? MyScanToTextBox(ptrFile,isOk) : gcnew array<String^>(0);//textbox1
	
	button1->Text = isOk ? MyScan(ptrFile,isOk) : L"";//button1

	fclose(ptrFile);
}

void My3dvisualizator_v5::FormDemo::ResetLanguageDemoForm(int mode)
{
	std::string stri = StrTostr(Application::StartupPath) + std::string("\\data\\") + Language[mode] + std::string("demo.ini");
	const char* out = strToCh(stri);
	FILE * ptrFile;
	fopen_s(&ptrFile, out, "r");
	bool isOk = false;
	if (ptrFile != NULL)//проверка на корректность файла
		isOk = true;
	else
		return;

	if (GRAPHICS.mode_Now == mode_FormDemo)//защита от повторной смены €зыка
		return;
	else
		mode_FormDemo = GRAPHICS.mode_Now;

	Text = isOk ? MyScan(ptrFile, isOk) : L"";//название формы

	button1->Text = isOk ? MyScan(ptrFile, isOk) : L"";//button1
	button2->Text = isOk ? MyScan(ptrFile, isOk) : L"";//button2

	dataGridView1->Columns[0]->HeaderText = isOk ? MyScan(ptrFile, isOk) : L"";
	dataGridView1->Columns[1]->HeaderText = isOk ? MyScan(ptrFile, isOk) : L"";
	dataGridView1->Columns[2]->HeaderText = isOk ? MyScan(ptrFile, isOk) : L"";

	fclose(ptrFile);
}

void LoadErrors(int mode)
{
	std::string stri = StrTostr(Application::StartupPath) + std::string("\\data\\") + Language[mode] + std::string("errors.ini");
	const char* out = strToCh(stri);
	FILE * ptrFile;
	fopen_s(&ptrFile, out, "r");
	bool isOk=false;
	if (ptrFile != NULL)//проверка на корректность файла
		isOk= true;
	else
		return;
	error_otpfr_func = isOk ? StrTostr(MyScan(ptrFile,isOk)) : "";
	for (int i = 0; i < 12; i++)
		errors[i] = isOk ? StrTostr(MyScan(ptrFile,isOk)) : "";

	fclose(ptrFile);
}

template <typename T>
array<T^> ^ My3dvisualizator_v5::Form1::ReinitDynamixObjects(array<T^> ^obj,int m, int n)
//реинициализаци€ элементов функций(CheckBox, Label, TextBox, Button)
{
	if (n==m)
	{
		return obj;
	}
	else
	{
		array<T^> ^objout=gcnew array<T^>(n);
		for (int i=0;i<n;i++)
			if (i<m)
			{
				objout[i] = obj[i];
			}
		delete obj;
		return objout;
	}
}

template <typename T>
array<T^> ^ My3dvisualizator_v5::Form1::DeleteDynamixObjects(array<T^> ^obj,int m, int k)
//удалить объект под номером k(нумераци€ с 0)
{
	array<T^> ^objout=gcnew array<T^>(m-1);
	for (int i=0;i<m-1;i++)
	{
		if (i<k)
			objout[i] = obj[i];
		else if (i>=k)
			objout[i] = obj[i+1];
	}
	delete obj;
	return objout;
}

System::Windows::Forms::ProgressBar^ My3dvisualizator_v5::Form_Process::getProgBar()
{
	return progressBar1;
}

System::Windows::Forms::Label^ My3dvisualizator_v5::Form_Process::getLabel1()
{
	return label1;
}

System::Windows::Forms::Label^ My3dvisualizator_v5::Form_Process::getLabel3()
{
	return label3;
}

System::Windows::Forms::TextBox^ My3dvisualizator_v5::Form_Process::getTextBox()
{
	return textBox1;
}

void My3dvisualizator_v5::FormLoad::LoadListOfFuncsLoad()
{
	System::String^ FileInfo = Application::StartupPath + L"\\data\\Saves\\!FileInfo.info";
	const char *fileInfo_cCh = StrToCh(FileInfo);
	if (System::IO::File::Exists(FileInfo))
	{
		FILE * ptrFile;
		fopen_s(&ptrFile, fileInfo_cCh, "r");
		if (ptrFile == NULL)//проверка на корректность файла
			return;

		fseek(ptrFile, 0, SEEK_END);//проверка файла на пустоту
		if (ftell(ptrFile) != 0)
		{
			dataGridView1->Rows->Clear();
			dataGridView1->Columns[1]->DefaultCellStyle->WrapMode = DataGridViewTriState::True;
			GRAPHICS.listOfFuncs.Clear();
			
			int nfi = 0;
			fseek(ptrFile, 0, SEEK_SET);
			int n_rows = -1;
			while (!feof(ptrFile))
			{
				char* namei = new char[sostr];
				fscanf(ptrFile, "%[^\n]s\n", namei);//»м€
				fscanf(ptrFile, "\n");

				if (System::IO::File::Exists(Application::StartupPath+ChToStr(namei)))
				{
					int slash = 0, dot = 0;//выделение имени файла
					for (int i = 0; namei[i] != 0 && i < sostr; i++)
					{
						if (namei[i] == '\\')
							slash = i;
						if (namei[i] == '.')
							dot = i;
					}
					System::String^ Lname = L"";
					for (int i = slash + 1; i < dot; i++)
						Lname += wchar_t(namei[i]);

					fscanf(ptrFile, "%i\n", &nfi);//nfuncs
					char** functions_str = new char*[nfi];
					for (int i = 0; i < nfi; i++)
						functions_str[i] = new char[sostr];

					for (int i = 0; i < nfi; i++)
						fscanf(ptrFile, "%s\n", functions_str[i]);//funcs
					System::String^ func_Lstr = L"";
					for (int i = 0; i < nfi; i++)
					{
						func_Lstr += ChToStr(functions_str[i]) + L'\n';
					}

					System::String^ namePic = ChToStr(namei);//picture
					namePic = namePic->Remove(dot);
					namePic += L".bmp";
					namePic = Application::StartupPath + namePic;
					System::Drawing::Bitmap^ bmpi;


					dataGridView1->Rows->Add();

					n_rows++;
					dataGridView1->Rows[n_rows]->Height = 200;
					dataGridView1->Rows[n_rows]->Cells[0]->Value = Lname;
					dataGridView1->Rows[n_rows]->Cells[1]->Value = func_Lstr;
					if (System::IO::File::Exists(namePic))
					{
						bmpi = gcnew Bitmap(namePic);
						dataGridView1->Rows[n_rows]->Cells[2]->Value = bmpi;
					}

					GRAPHICS.listOfFuncs.AddFunc(namei, functions_str);
				}
			}
		}
		fclose(ptrFile);
	}
}

void My3dvisualizator_v5::FormDemo::LoadListOfFuncsDemo()
{
	System::String^ FileInfo = Application::StartupPath + L"\\data\\Saves\\Demo\\!FileInfo.info";
	const char *fileInfo_cCh = StrToCh(FileInfo);
	if (System::IO::File::Exists(FileInfo))
	{
		FILE * ptrFile;
		fopen_s(&ptrFile, fileInfo_cCh, "r");
		if (ptrFile == NULL)//проверка на корректность файла
			return;

		fseek(ptrFile, 0, SEEK_END);//проверка файла на пустоту
		if (ftell(ptrFile) != 0)
		{
			dataGridView1->Rows->Clear();
			dataGridView1->Columns[1]->DefaultCellStyle->WrapMode = DataGridViewTriState::True;
			GRAPHICS.listOfFuncs.Clear();

			int nfi = 0;
			fseek(ptrFile, 0, SEEK_SET);
			int n_rows = -1;
			while (!feof(ptrFile))
			{
				char* namei = new char[sostr];
				fscanf(ptrFile, "%[^\n]s\n", namei);//»м€
				fscanf(ptrFile, "\n");

				int slash = 0, dot = 0;//выделение имени файла
				for (int i = 0; namei[i] != 0 && i<sostr; i++)
				{
					if (namei[i] == '\\')
						slash = i;
					if (namei[i] == '.')
						dot = i;
				}
				System::String^ Lname = L"";
				for (int i = slash + 1; i < dot; i++)
					Lname += wchar_t(namei[i]);

				fscanf(ptrFile, "%i\n", &nfi);//nfuncs
				char** functions_str = new char*[nfi];
				for (int i = 0; i < nfi; i++)
					functions_str[i] = new char[sostr];

				for (int i = 0; i < nfi; i++)
					fscanf(ptrFile, "%s\n", functions_str[i]);//funcs
				System::String^ func_Lstr = L"";
				for (int i = 0; i < nfi; i++)
				{
					func_Lstr += ChToStr(functions_str[i]) + L'\n';
				}

				System::String^ namePic = ChToStr(namei);//picture
				namePic = namePic->Remove(dot);
				namePic += L".bmp";
				System::Drawing::Bitmap^ bmpi;

				dataGridView1->Rows->Add();

				n_rows++;
				dataGridView1->Rows[n_rows]->Height = 200;
				dataGridView1->Rows[n_rows]->Cells[0]->Value = Lname;
				dataGridView1->Rows[n_rows]->Cells[1]->Value = func_Lstr;
				if (System::IO::File::Exists(Application::StartupPath + namePic))
				{
					bmpi = gcnew Bitmap(Application::StartupPath + namePic);
					dataGridView1->Rows[n_rows]->Cells[2]->Value = bmpi;
				}

				GRAPHICS.listOfFuncs.AddFunc(namei, functions_str);
			}
		}
		fclose(ptrFile);
	}
}