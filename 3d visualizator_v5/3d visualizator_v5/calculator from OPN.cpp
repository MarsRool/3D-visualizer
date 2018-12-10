#include "stdafx.h"
#include "OpenGL funcs.h"
#include "global.h"
#include "graph.h"
#include "func.h"
using namespace std;

short int np[sostr];
short int flag_fail_t=-1;
/*
-1 - нет ошибки
0 - деление на малое число
1 - ошибочное возведение в степень
*/
bool dopustzn=false;//true - если хоть раз вычисление было проведено без ошибки

/*float powmy(int a,int b)
{
	int res=1;
	if (b==0) return 1;
	else {
		for (int c=1;c<=b;c++) 
			res*=a;
		return res;
	}
}*/

/*void Matrix(char inpoutstrii[sostr],int schii)*/
void graph_func::CalculateMatrix(int ngrid, double &xsha, double &ysha, double &tsha, double xmin, double xmax, double ymin, double ymax, int t1, int t2, unsigned int fps, System::Windows::Forms::ProgressBar^ ProgBar)
{//расчет матрицы значений (расчет каждого производится во внешней функции calculate)
	ProgBar->Value=0;
	dopustzn=false;
	if (failed==false)
	{
		xsha=(xmax-xmin)/ngrid;
		ysha=(ymax-ymin)/ngrid;
		if (t2>=t1 && isFuncDynamic)
			tsha=(double)1/fps;
		if (isFuncDynamic == false)//если функция не динамична инициализировать 1 data
		{
			ndata = 1;
			data = new graph_data[ndata];
			data[0].reinit(ngrid+1);
		}
		else//инициализировать data[ndata]
		{
			if (t2>=t1)  
				ndata=fps*(t2-t1)+1;
			else
			{
				failed=true;//по идее это исключение уже обработано в Form1.h, но все же
				GRAPHICS.SetError(7);
				//MsgBoxShow(L"Недопустимый временной диапазон");/*err7*/
			}
			data = new graph_data[ndata];
			for (int i=0; i<ndata; i++)
				data[i].reinit(ngrid+1);
		}
		for (int ii=0;ii<ndata;ii++)
			for (int i=0;i<=ngrid;i++)
				for (int j=0;j<=ngrid;j++)
					data[ii].Matrnorm[i][j]=true;

		if(Contain('x',outstr,outsch-1)==false && Contain('y',outstr,outsch-1)==false && Contain('t',outstr,outsch-1)==false)
		{
			//функция не содержит переменных(константа.) инициализировать одно значение data
			data[0].Matrnorm[0][0]=true;
			data[0].Matr[0][0]=calculate(outstr, outsch-1,0,0,0,0,0,0);
			if (data[0].Matrnorm[0][0]==true)
			{
				for (int i=0;i<=ngrid;i++)
					for (int j=0;j<=ngrid;j++)
						data[0].Matr[i][j]=data[0].Matr[0][0];
			}
			else
			{
				if (flag_fail_t==0)
					GRAPHICS.SetError(8);
					//MsgBoxShow(L"Деление на малое число или нуль");/*err8*/
				else if(flag_fail_t==1)
					GRAPHICS.SetError(9);
					//MsgBoxShow(L"Ошибочное возведение в степень");/*err9*/
				else
					GRAPHICS.SetError(10);
					//MsgBoxShow(L"Нет ни одного допустимого значения функции");/*err10*/
				failed=true;
			}
			ProgBar->Value=100;
		}
		else
		{
			unsigned int a=1, ki=0, ksl=ndata*ngrid*ngrid/100*a, ks=ksl;//a- процент разбиения, ki- колво выполненных оперций, ks- следующий порог отображения, ksl- колво операций(4% от всех) от максимума 
			for (int ii=0;ii<ndata;ii++)
				for (int i=0;i<=ngrid;i++)
					for (int j=0;j<=ngrid;j++)
					{
						ki++;
						if (ki>ks)
						{
							if(ProgBar->Value<=100-a)
							{
								ProgBar->Value+=a;
							}
							ks+=ksl;
						}
						double xi=xmin+i*xsha, yi=ymin+j*ysha, tit=0;
						if (isFuncDynamic == true)
							tit=t1+tsha*ii;
						data[ii].Matr[i][j]=calculate(outstr, outsch-1,xi,yi,tit,ii,i,j);
					}

			for (int ii=0;ii<ndata;ii++)
				for (int i=0;i<=ngrid;i++)
					for (int j=0;j<=ngrid;j++)
						if (data[ii].Matrnorm[i][j]==true)
						{
							dopustzn=true;
							break;
						}
			if (dopustzn==false)
			{
				GRAPHICS.SetError(10);
				//MsgBoxShow(L"Нет ни одного допустимого значения функции");/*err10*/
				failed=true;
			}

			if(failed==false)
				ProgBar->Value=100;
		}
	}
}

double graph_func::calculate(char inpoutstr[sostr], int sch, double x, double y, double t, int tii, int indi, int indj)
{//функция расчета текущего значения функции из ОПН]
	flag_fail_t=-1;
    char c;
	char symbi[40];//текущий элемент строки
	short int lengthsymbi=0;//длина элемента строки
	double res=0;//вспомогательный элемент для числа
	bool drob;int jn;int jj;
	stack<long double> S;
	//разделить строку на элементы
	int k=0;//сколько элементов в входной строке
	np[0]=-1;
	for (int i=0;i<sch;i++)
	if (inpoutstr[i]==' ')
	{
		k++;
		np[k]=i;
	}
	k++;
	np[k]=sch;
    for(int i=0;i<k;i++)
	if (data[tii].Matrnorm[indi][indj]==true)
	{
		lengthsymbi=0;
		for (int j=np[i]+1;j<np[i+1];j++)
		{
			symbi[lengthsymbi]=inpoutstr[j];
			lengthsymbi++;
		}
		c=symbi[0];
        switch(c)
        {
            case '+':{ // если операция сложения
                double op1=S.top();
                S.pop();
                double op2=S.top();
                S.pop();
                double result=op2 + op1;
                S.push(result);
            }break;
            case '-':{ // если операция вычитания
                double op1=S.top();
                S.pop();
                double op2=S.top();
                S.pop();
                double result=op2 - op1;
                S.push(result);
            }break;
            case '*':{ // если операция умножения
                double op1=S.top();
                S.pop();
                double op2=S.top();
                S.pop();
                double result=op2 * op1;
                S.push(result);
            }break;
            case '/':{ // если операция деления
                double op1=S.top();
                S.pop();
                double op2=S.top();
                S.pop();
				double result;
				if (!(fabs(op1)<smallV))
					result=op2 / op1;
				else
				{
					flag_fail_t=0;//деление на маленькое число
					data[tii].Matrnorm[indi][indj]=false;
				}
                S.push(result);
            }break;
			case '^':{ // если операция возведения в степень
                double op1=S.top();
                S.pop();
                double op2=S.top();
                S.pop();
                double result;
				double cel;
				if (!(op2<0 && (fabs(modf(op1,&cel))>smallV))  &&  !(fabs(op2)<smallV && op1<=0))
				{
					result=pow(op2,op1);
					S.push(result);
				}
				else 
				{
					flag_fail_t=1;//недопустимое возведение в степень
					data[tii].Matrnorm[indi][indj]=false;
				}
            }break;
			case 's':{//sin
				double op=S.top();
				S.pop();
				double result=sin(op);
				S.push(result);
			}break;
			case 'c':{//cos
				double op=S.top();
				S.pop();
				double result=cos(op);
				S.push(result);
			}break;
			case 'p':{//tg
				double op=S.top();
				S.pop();
				double result;
				if (fabs(fabs(fmod(op,PI))-PI/2)>0.01)
				{
					result=tan(op);
					S.push(result);
				}
				else
					data[tii].Matrnorm[indi][indj]=false;
			}break;
			case 'g':{//ctg
				double op=S.top();
				S.pop();
				double result;
				if (fabs(fmod(op,PI))>0.01)
				{
					result=tan(PI/2-op);
					S.push(result);
				}
				else
					data[tii].Matrnorm[indi][indj]=false;
			}break;
			case 'q':{//sqrt
				double op=S.top();
				S.pop();
				double result;
				if (op>=0)
				{
					result=sqrt(op);
					S.push(result);
				}
				else
					data[tii].Matrnorm[indi][indj]=false;
			}break;

			case 'a':{//abs
				double op=S.top();
				S.pop();
				double result;
				result=fabs(op);
				S.push(result);
			}break;
			case 'r':{//round
				double op=S.top();
				S.pop();
				double result;
				result=round(op);
				S.push(result);
			}break;
			case 'l':{//ceil
				double op=S.top();
				S.pop();
				double result;
				result=ceil(op);
				S.push(result);
			}break;
			case 'f':{//floor
				double op=S.top();
				S.pop();
				double result;
				result=floor(op);
				S.push(result);
			}break;

			case 'v':{//asin
				double op=S.top();
				S.pop();
				double result;
				if(op>=-1 && op<=1)
					result=asin(op);
				else
					data[tii].Matrnorm[indi][indj]=false;
				S.push(result);
			}break;
			case 'b':{//acos
				double op=S.top();
				S.pop();
				double result;
				if(op>=-1 && op<=1)
					result=acos(op);
				else
					data[tii].Matrnorm[indi][indj]=false;
				S.push(result);
			}break;
			case 'i':{//atg
				double op=S.top();
				S.pop();
				double result;
				result=atan(op);
				S.push(result);
			}break;
			case 'm':{//actg
				double op=S.top();
				S.pop();
				double result;
				result=PI/2-atan(op);
				S.push(result);
			}break;

			case 'n':{//ln
				double op=S.top();
				S.pop();
				double result;
				if(op>0)
					result=log(op);
				else
					data[tii].Matrnorm[indi][indj]=false;
				S.push(result);
			}break;
			case 'u':{//log
				double op=S.top();
				S.pop();
				double result;
				if(op>0)
					result=log10(op);
				else
					data[tii].Matrnorm[indi][indj]=false;
				S.push(result);
			}break;

			case 'x':{S.push(x);}break;
			case 'y':{S.push(y);}break;
			case 't':{S.push(t);}break;
            default: // если цифра
			{
				if (c>='0' && c<='9'){
					res=0;
					drob=false;//дробная ли часть
					jn=1000;
					for (int j=0;j<lengthsymbi;j++)
					{
						if ((symbi[j]==','||symbi[j]=='.') && drob==false)
						{
							drob=true;
							jn=j+1;
						}
					if (drob==false && symbi[j]!='.' && symbi[j]!=',')
						res=res*10+symbi[j]-'0';
					}
					if (drob==true)
					for (jj=jn;jj<lengthsymbi;jj++)
					{
						//res=res+(symbi[jj]-'0')/pow(10,jj-jn+1);
						double idrob=symbi[jj]-'0';//текущий дробный символ
						for (int l=jj;l>=jn;l--)
							idrob/=10;
						res+=idrob;
					}

				S.push(res);
				}
			}
        }
    }
	if (!S.empty()) return S.top();
	else 
	{
		data[tii].Matrnorm[indi][indj]=false;
		return -100000;
	}
}