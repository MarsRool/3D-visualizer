// 3d visualizator_v5.cpp: ������� ���� �������.

#include "stdafx.h"
#include "FormMain.h"

using namespace My3dvisualizator_v5;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew FormMain());
	return 0;
}
