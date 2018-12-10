#include "stdafx.h"
#include "global.h"
#include "conversions.h"

#include <iostream>
#include <windows.h>
#include <ShellAPI.h>
#pragma comment(lib,"shell32.lib")
using namespace std;

double rest(const double &a, const int &b)//остаток от деления
{
	double cel;//целая часть от деления
	modf(a/b,&cel);
	modf(a-cel*b,&cel);
	return cel;
}

bool Contain(char t, char* in,int schc)//есть ли символ t в массиве символов in до schc(включительно)
{
	for (int i=0;i<schc;i++)
		if (t==in[i]) return true;
	return false;
}

bool Contain(char t, const char* in,int schc)//есть ли символ t в массиве символов in до schc(включительно)
{
	for (int i=0;i<schc;i++)
		if (t==in[i]) return true;
	return false;
}

void MsgBoxShow(System::String^ msg)
{
	System::Windows::Forms::MessageBox::Show(msg, L"Ошибка", System::Windows::Forms::MessageBoxButtons::OK,System::Windows::Forms::MessageBoxIcon::Warning );
}

char* outFOPZ(char *instr)
{
	char outstr[sostr];
	int i,j=0,k=0,l=0;
	for (i=0;i<sostr;i++)
		outstr[i]=0;
	i=0;
	bool rest=false;//true, когда нужен эквивалент функции в полное записи
	while(instr[i]!=0)
	{
		j=0;
		rest=false;
		while(dopd[j]!=0)
		{
			if(instr[i]==dopd[j])
			{
				k=0;
				string t=eqf[j];
				rest=true;
				while(t[k]!=0)
				{
					outstr[l]=t[k];
					l++;
					k++;
				}
				i++;
				break;
			}
			j++;
		}
		if(rest==false)
		{
			outstr[l]=instr[i];
			l++;
			i++;
		}
	}
	return outstr;
}

int getprior(char ii)//получить приоритет символа-оператора действия
{
switch (ii)
{
case '(': return 1;break;
case ')': return 1;break;
case '-': return 2;break;
case '+': return 2;break;

case 's': return 5;break;
case 'c': return 5;break;
case 'p': return 5;break;
case 'g': return 5;break;
case 'q': return 5;break;

case 'a': return 5;break;
case 'r': return 5;break;
case 'l': return 5;break;
case 'f': return 5;break;

case 'v': return 5;break;
case 'b': return 5;break;
case 'i': return 5;break;
case 'm': return 5;break;

case 'n': return 5;break;
case 'u': return 5;break;

case '*': return 3;break;
case '/': return 3;break;
case '^': return 4;break;
case 'x': return -1;break;
case 'y': return -1;break;
case 't': return -1;break;

default:return 1000;
}
}

void CalculateScreenSize(int &x, int &y)
{
	x = GetSystemMetrics(SM_CXSCREEN);
	y = GetSystemMetrics(SM_CYSCREEN);
}

void Open_Help()
{
	ShellExecute(NULL,L"Open",L"data\\3D_Visualizer_v5.chm",NULL,NULL,SW_RESTORE);
}