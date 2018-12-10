#include "stdafx.h"
#include "global.h"
#include "func.h"
#include <windows.h>
using namespace std;

/*old
unsigned char * dtuch(double a)//double to unsigned char[]
{
	unsigned char cha[23], *ch;//cha-число с цифрами наоборот, ch- число
	short int i = 0;//сколько символов в cha
	double drob;//дробная часть числа
	double cel;//целая часть числа
	bool ismn = false;//true - если отрицательное число
	drob = modf(a, &cel);
	int drob100 = (int)(100 * drob);//
	if (a < 0)
	{
		ismn = true;
		cel = fabs(cel);
		drob100 = fabs((float)drob100);
	}
	if (drob != 0)
	{
		i = 3;
		cha[0] = '0' + drob100 % 10;
		cha[1] = '0' + (int)(drob100 / 10);
		cha[2] = ',';
	}
	if (cel == 0)
	{
		i++;
		cha[i - 1] = '0';
	}
	else
		while (fabs((float)cel) > 0)
		{
			i++;
			cha[i - 1] = '0' + (int)rest(cel, 10);//+остаток деления на 10
			modf(cel / 10, &cel);
		}
	if (ismn == true)
	{
		i++;
		cha[i - 1] = '-';
	}
	ch = new unsigned char[i + 1];
	ch[i] = '\0';
	for (int j = i - 1; j >= 0; j--)
		ch[j] = cha[i - j - 1];
	return ch;
}*/

unsigned char * dtuch(double a, int precision=2)//double to unsigned char[]
{
	unsigned char cha[64], *ch;//cha-число с цифрами наоборот, ch- число
	short int i = 0;//сколько символов в cha
	double drob;//дробная часть числа
	double cel;//целая часть числа
	bool ismn = false;//true - если отрицательное число
	drob = modf(fabs(a), &cel);
	int drob_10N = int(drob * pow(10, precision));//дробная часть, умноженная на 10^precision
	int cel_int = (int)cel;//целая часть типа int
	if (a < 0)
	{
		ismn = true;
	}
	if (drob != 0)
	{
		i = precision + 1;
		for (int j = 0; j < precision; j++)
		{
			cha[j] = '0' + drob_10N % 10;
			drob_10N /= 10;
		}
		cha[precision] = '.';
	}
	if (cel == 0)
	{
		i++;
		cha[i - 1] = '0';
	}
	else
		while (cel_int > 0)
		{
			i++;
			cha[i - 1] = '0' + cel_int % 10;//+остаток деления на 10
			cel_int /= 10;
		}
	if (ismn == true)
	{
		i++;
		cha[i - 1] = '-';
	}
	ch = new unsigned char[i + 1];
	ch[i] = '\0';
	for (int j = i - 1; j >= 0; j--)
		ch[j] = cha[i - j - 1];
	return ch;
}

double uchtd(unsigned char * ch, bool &failed)
{
	double res = 0;
	bool ismn = false;//отрицательное ли число
	int n = 0;//длина ch
	while (ch[n] != '\0' && n < 64)
		n++;

	if (!(ch[0] == '-' || (ch[0] >= '0' && ch[0] <= '9')) || ch[n - 1] == '.' || ch[n - 1] == ',')
		failed = true;

	int i_dot = -1;
	for (int i = 1; i < n; i++)
		if (!(ch[i] >= '0' && ch[i] <= '9'))
		{
			if ((ch[i] == '.' || ch[i] == ',') && i_dot == -1)
				i_dot = i;
			else
			{
				failed = true;
				break;
			}
		}

	if (failed == false)
	{
		if (ch[0] == '-')
			ismn = true;
		if (i_dot == -1)
		{
			for (int i = 0; i < n; i++)
				if (ch[i] != '-')
					res = res * 10 + ch[i] - '0';
		}
		else
		{
			for (int i = 0; i < i_dot; i++)
				if (ch[i] != '-')
					res = res * 10 + ch[i] - '0';
			for (int i = i_dot + 1; i < n; i++)
				res = res + double(ch[i] - '0') / pow(10.0, i - i_dot);
		}
	}
	if (ismn == false)
		return res;
	else
	{
		res = -res;
		return res;
	}
	if (failed == true)
		return 0;
}

unsigned char * ituch(int a)
{
	return dtuch(a, 0);
}

int uchti(unsigned char * ch, bool &failed)
{
	double res = uchtd(ch, failed), cel;
	double drob = modf(fabs(res), &cel);
	if (drob != 0)
	{
		failed = true;
		return 0;
	}
	return int(res);
}

double StrToD(bool &failed, System::String^ stri)//System::String^ to Double
{
	double res=0;
	char chstr[sostr];
	bool ismn=false;//отрицательное ли число
	int n = stri->Length;
	for (int i=0;i<n+10;i++)
		chstr[i]=0;
	for (int i=0;i<n;i++)
		chstr[i]=(char)stri[i];

	if (!(chstr[0]=='-' || (chstr[0]>='0' && chstr[0]<='9')) || chstr[n]=='.' || chstr[n]==',')
		failed=true;
	else
	{
		if (chstr[0]=='-')
			ismn=true;
		if (Contain('.',chstr,n)==false && Contain(',',chstr,n)==false)
		{
			for (int i=0;i<n;i++)
				if(chstr[i]!='-')
				{
					if (!(chstr[i]>='0' && chstr[i]<='9'))
						failed=true;
					res=res*10+chstr[i]-'0';
				}
		}
		else
		{
			int posd=0;
			for (int i=0;i<n;i++)
				if(chstr[i]=='.' || chstr[i]==',')
				{
					posd=i;
					break;
				}
			chstr[n+1]='0';
			for(int i=posd+1;i<=n+1;i++)
				chstr[i-1]=chstr[i];
			int k=posd+3;
			for (int i=0;i<k;i++)
				if(chstr[i]!='-')
				{
					if (!(chstr[i]>='0' && chstr[i]<='9' || chstr[i]==0))
						failed=true;
					if (chstr[i]==0)
						res=res*10;
					else
						res=res*10+chstr[i]-'0';
				}
				res/=1000;
		}
	}
	if (ismn==false)
		return res;
	else
	{
		res=-res;
		return res;
	}
	if (failed==true) return 0;
}

System::String^ uchToStr(unsigned char * ch)//unsigned char[] to System::String^
{
	int i=0;
	System::String^ stri = L"";
	while (ch[i]!=0)
	{
	stri+=(wchar_t)ch[i];
	i++;
	}
	return stri;
}

unsigned char * StrTouch(System::String^ stri)//System::String^ to unsigned char[]
{
	int l = stri->Length;
	unsigned char * ch = new unsigned char[l + 1];
	for (int i = 0; i < l; i++)
		ch[i] = unsigned char(stri[i]);
	ch[l] = '\0';
	return ch;
}

string uchTostr(unsigned char * ch)//unsigned char[] to string
{
	int i = 0;
	string stri = "";
	while (ch[i]!=0)
	{
		stri += char(ch[i]);
		i++;
	}
	return stri;
}

unsigned char * strTouch(string stri)//string to unsigned char[]
{
	int l = stri.length();
	unsigned char * ch = new unsigned char[l + 1];
	for (int i = 0; i < l; i++)
		ch[i] = unsigned char(stri[i]);
	ch[l] = '\0';
	return ch;
}

System::String^ ChToStr(char * ch)//Char[] to System::String^
{
	int i = 0;
	System::String^ stri = L"";
	while (ch[i]!=0)
	{
		if (ch[i] == -88)
			stri += L'Ё';
		else if (ch[i] == -72)
			stri += L'ё';
		else if (ch[i] >= -64 && ch[i] <= -1)
			stri += wchar_t(ch[i] + 1104);
		else
			stri += wchar_t(ch[i]);
		i++;
	}

	return stri;
}

char * StrToCh(System::String^ Str)//System::String^ to Char[]
{
	int l = Str->Length;
	char * ch = new char[l + 1];
	for (int i = 0; i < l; i++)
	{
		if (Str[i] == 1025)
			ch[i] = 'Ё';
		else if (Str[i] == 1105)
			ch[i] = 'ё';
		else if (Str[i] >= 1040 && Str[i] <= 1103)
			ch[i] = Str[i] - 1104;
		else
			ch[i] = (char)Str[i];
	}
	ch[l] = '\0';
	return ch;
}

string ChTostr(char * ch)//char[] to string
{
	int i = 0;
	string stri = "";
	while (ch[i] != 0)
	{
		stri += ch[i];
		i++;
	}
	return stri;
}

char * strToCh(string stri)//string to char[]
{
	int l = stri.length();
	char * ch = new char[l + 1];
	for (int i = 0; i < l; i++)
		ch[i] = stri[i];
	ch[l] = '\0';
	return ch;
}

string StrTostr(System::String^ Str)//System::String^ to string
{
	int l = Str->Length;
	string stri = "";
	for (int i=0; i<l; i++)
	{
		if (Str[i] == 1025)
			stri += 'Ё';
		else if (Str[i] == 1105)
			stri += 'ё';
		else if (Str[i] >= 1040 && Str[i] <= 1103)
			stri += Str[i] - 1104;
		else
			stri += (char)Str[i];
	}
	return stri;
}

System::String^ strToStr(string stri)//string to System::String^
{
	int l = stri.length();
	System::String^ Str = L"";
	for (int i=0; i<l; i++)
	{
		if (stri[i] == -88)
			Str += L'Ё';
		else if (stri[i] == -72)
			Str += L'ё';
		else if (stri[i] >= -64 && stri[i] <= -1)
			Str += wchar_t(stri[i] + 1104);
		else
			Str += wchar_t(stri[i]);
	}
	return Str;
}