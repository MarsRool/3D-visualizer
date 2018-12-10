// 3d visualizator_v5.cpp: главный файл проекта.

#include "stdafx.h"
#include "FormMain.h"

using namespace My3dvisualizator_v5;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Включение визуальных эффектов Windows XP до создания каких-либо элементов управления
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Создание главного окна и его запуск
	Application::Run(gcnew FormMain());
	return 0;
}
