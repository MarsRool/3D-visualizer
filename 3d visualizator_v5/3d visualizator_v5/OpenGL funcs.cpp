#include "stdafx.h"
#include "global.h"
//#include "graph.h"
#include "data\GL_my\freeglut.h"
#include "func.h"
#include "graph.h"
#include "conversions.h"
#include <windows.h>
using namespace std;

float WinWid=600.0;
float WinHie=600.0;
float Angle=0.0;
float AngleV=0.0;
float scx=1.0, scy=1.0, sc=1.0;
float scl=1.0, sclmin=0.8, sclmax=1.6;
unsigned int fps=25;
unsigned int chast=40;

double tii=0; int datatii=0;//tii- текущее время в секундах. datatii- номер data[] каждой функции

int razm=5000;//размер куба

void SaveOpenGlScreen(System::String^ name)
{
	// Convert & save to file
	System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(int(scx*WinWid), int(scy*WinHie), System::Drawing::Imaging::PixelFormat::Format24bppRgb);
	System::Drawing::Rectangle rect(0, 0, bmp->Width, bmp->Height);
	System::Drawing::Imaging::BitmapData^ bmpData =
		bmp->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite,	bmp->PixelFormat);
	
	glReadPixels(0, 0, int(scx*WinWid), int(scy*WinHie), GL_BGR_EXT, GL_UNSIGNED_BYTE, (void*)bmpData->Scan0);
	bmp->UnlockBits(bmpData);
	bmp->RotateFlip(System::Drawing::RotateFlipType::RotateNoneFlipY);

	if (System::IO::File::Exists(name))
		System::IO::File::Delete(name);
	bmp->Save(name, System::Drawing::Imaging::ImageFormat::Bmp);
}

void ChangeTitleOpenGL(const char *title)
{
	glutSetWindowTitle(title);
}

bool graph_func::CheckOutOfLims(int i, int j, double zmini, double zmaxi)//true - если 4 точки не выходят за пределы zmin и zmax {[i,j], [i+1,j], [i,j+1], [i+1,j+1]}
{
	int datatii_d;
	if (isFuncDynamic)
		datatii_d=datatii;
	else
		datatii_d=0;
	//check min
	if ((data[datatii_d].Matr[i][j]<zmini) || (data[datatii_d].Matr[i+1][j]<zmini) || (data[datatii_d].Matr[i][j+1]<zmini) || (data[datatii_d].Matr[i+1][j+1]<zmini))
		return false;

	//check max
	if ((data[datatii_d].Matr[i][j]>zmaxi) || (data[datatii_d].Matr[i+1][j]>zmaxi) || (data[datatii_d].Matr[i][j+1]>zmaxi) || (data[datatii_d].Matr[i+1][j+1]>zmaxi))
		return false;

	return true;
}

double graph_func::Max(int ngrid)//максимальный z
{
	if (failed==false)
	{
		double max;
		bool istmax=false;
		for (int ii=0;ii<ndata;ii++)
			for (int i=0;i<=ngrid;i++)
				for (int j=0;j<=ngrid;j++)
					if(data[ii].Matrnorm[i][j] && istmax==false)
					{
						max=data[ii].Matr[i][j];
						istmax=true;
						break;
					}

		for (int ii=0;ii<ndata;ii++)
			for (int i=0;i<=ngrid;i++)
				for (int j=0;j<=ngrid;j++)
					if (max<data[ii].Matr[i][j] && data[ii].Matrnorm[i][j]==true)
						max = data[ii].Matr[i][j];
		return max;
	}
	else
		return 0;
}

double graph_func::Min(int ngrid)//минимальный z
{
	if (failed==false)
	{
		double min;
		bool istmin=false;
		for (int ii=0;ii<ndata;ii++)
			for (int i=0;i<=ngrid;i++)
				for (int j=0;j<=ngrid;j++)
					if(data[ii].Matrnorm[i][j] && istmin==false)
					{
						min=data[ii].Matr[i][j];
						istmin=true;
						break;
					}

		for (int ii=0;ii<ndata;ii++)
			for (int i=0;i<=ngrid;i++)
				for (int j=0;j<=ngrid;j++)
					if (min>data[ii].Matr[i][j] && data[ii].Matrnorm[i][j]==true)
						min = data[ii].Matr[i][j];
		return min;
	}
	else
		return 0;
}

void graph::SetDrawData(unsigned int fpsi)
{
	chast=(int)1000/fpsi;
	fps=fpsi;
}

void graph_func::CalculateMatrixOut(int ngrid, bool isautozmax, bool isautozmin)
{//реинициализация функции (сообщение программе о том, что надо строить новую функцию)
	/*ngrid=a;
	xmin=b;
	xmax=c;
	ymin=d;
	ymax=e;
	for (int i=0;i<=ngrid;i++)
		for (int j=0;j<=ngrid;j++)
			Matr[i][j]=Matri[i][j];
	for (int i=0;i<=ngrid;i++)
		for (int j=0;j<=ngrid;j++)
			Matrnorm[i][j]=Matrnor[i][j];*/
	if (failed==false)
	{
		//zimn и zmax уже рассчитаны

		for (int ii=0; ii<ndata; ii++)
			for (int i=0; i<=ngrid; i++)
				for (int j=0; j<=ngrid; j++)
					if (data[ii].Matrnorm[i][j]==true)
						data[ii].nMatr[i][j]=(data[ii].Matr[i][j]-zmin)/(zmax-zmin)*razm-razm/2;
	}
}

void graph::FuncsReOut()
{
	double ext=0;
	
	if (nfuncs>0)
	{
		//нахождение экстремумов всех функций и времен
		if (isautozmin==true)//начальная установка в ноль, если значения не заданы
			Zmin=0;
		if (isautozmax==true)
			Zmax=0;

		for (int i=0;i<nfuncs;i++)//найти первый допустимый экстремум
			if (funcs[i].failed==false)
			{
				if (isautozmin==true)
					Zmin=funcs[i].Min(ngrid);
				if (isautozmax==true)
					Zmax=funcs[i].Max(ngrid);
				if (Zmin<Zmax)
					break;
			}

		for (int i=0;i<nfuncs;i++)//для каждой допустимой функции найти экстремумы
			if (funcs[i].failed==false)
			{
				if (isautozmin==true)
				{
					ext=funcs[i].Min(ngrid);
					if (Zmin>ext)
						Zmin=ext;
				}

				if (isautozmax==true)
				{
					ext=funcs[i].Max(ngrid);
					if (Zmax<ext)
						Zmax=ext;
				}
			}

		if (fabs(Zmax-Zmin)<smallV)//если экстремумы примерно равны(плоскость), то расширить область на 0,5 в каждую сторону
			{Zmax+=0.5;Zmin-=0.5;}

		for (int i=0;i<nfuncs;i++)//прислвоить каждой функции глобальный максимум
		{
			funcs[i].zmin=Zmin;
			funcs[i].zmax=Zmax;
		}

		//расчет
		for (int i=0; i<nfuncs; i++)//рассчитать графические координаты каждой функции
			funcs[i].CalculateMatrixOut(ngrid, isautozmax, isautozmin);

		//разрешение на вывод
		for (int i=0; i<nfuncs; i++)
			if (funcs[i].failed==false)
				funcs[i].isfunc=true;
			else
				funcs[i].isfunc=false;

		ReInitColors();//инициализация цвета функций и типа раскраски
	}
}

void graph::ReInitColors()
{
	//инициализация цвета функций и типа раскраски
	for (int i = 0; i<nfuncs; i++)
	{
		funcs[i].type_of_color = modecolor;
		if (modecolor == 2)//градиентно одним цветом
		{
			double variation = 0.2;
			funcs[i].color_grad[0] = RGB_MR(funcs[i].color.getColor(0) + variation, funcs[i].color.getColor(1) + variation, funcs[i].color.getColor(2) + variation);
			funcs[i].color_grad[1] = RGB_MR(funcs[i].color.getColor(0), funcs[i].color.getColor(1) + variation, funcs[i].color.getColor(2) - variation);
			funcs[i].color_grad[2] = RGB_MR(funcs[i].color.getColor(0) - variation, funcs[i].color.getColor(1) - variation, funcs[i].color.getColor(2) - variation);
			funcs[i].color_grad[3] = RGB_MR(funcs[i].color.getColor(0), funcs[i].color.getColor(1) - variation, funcs[i].color.getColor(2) + variation);
		}
		else if (modecolor == 3)//градиентно четырьмя цветами
		{
			for (int j=0; j < 4; j++)
				funcs[i].color_grad[j] = color_type1[j];
		}
	}
}

double partofS(double a, double b,double c, double d)
{//расстояние от точки (a,b) до (c,d)
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

double InverseSrgbCompanding(double c)
{
	if (c > 0.04045)
		c = pow((c+0.055)/1.055, 2.4);
	else
		c /= 12.92;

	return c;
}

double SrgbCompanding(double c)
{
	if (c > 0.0031308)
		c = 1.055*pow(c, 1/2.4)-0.055;
	else
		c *= 12.92;

	return c;
}

double ColorMix(double color1i, double color2i, double mix)
{//смешивание цветов. состовляющие 2 цветов. mix- расстояние точки от первого цвета до второго(от 0 до 1)
	double result = 0;

	color1i = InverseSrgbCompanding(color1i);
	color2i = InverseSrgbCompanding(color2i);

	result = color1i * (1 - mix) + color2i * mix;
	//result = color1i * mix + color2i * (1 - mix);

	result = SrgbCompanding(result);
	
	return result;
}

double graph_func::counticolor(double a, double b, int c, int k)
{//координаты текущей точки, i - номер цвета (0,1,2) в RGB_MR
	double res=0.0;
	switch(type_of_color)
	{
	case 1:
		{
			return color.getColor(k);
		}break;
	case 2:
	case 3://раскраска 4 цветами от dl,dr,ul,ur.
		{
			//расчет цвета текущего полигона
			double n=1;//(вид сверху)
			double rastofdl=partofS(a,b,-razm/2,razm/2)/razm*n;//dl расстояние от текущей точки до нижнего левого угла(точка 1)
			double rastoful=partofS(a,b,-razm/2,-razm/2)/razm*n;//ul расстояние от текущей точки до верхнего левого угла(точка 2)
			double rastofur=partofS(a,b,razm/2,-razm/2)/razm*n;//ur расстояние от текущей точки до верхнего правого угла(точка 3)
			double rastofdr=partofS(a,b,razm/2,razm/2)/razm*n;//dr расстояние от текущей точки до нижнего правого угла(точка 4)
			double idl,iul,iur,idr;
			if (rastofdl>1)
				idl=0;
			else
				idl=color_grad[0].getColor(k)*(1-rastofdl);//цвет от нижнего левого угла(1)

			if (rastoful>1)
				iul=0;
			else
				iul=color_grad[1].getColor(k)*(1-rastoful);//цвет от верхнего левого угла(2)

			if (rastofur>1)
				iur=0;
			else
				iur=color_grad[2].getColor(k)*(1-rastofur);//цвет от верхнего правого угла(3)

			if (rastofdr>1)
				idr=0;
			else
				idr=color_grad[3].getColor(k)*(1-rastofdr);//цвет от нижнего правого угла(4)

			res=idl+iul+iur+idr;
			if (res>1)
				return 1.0;
			else if (res<0)
				return 0.0;
			else
				return res;
		}break;
	case 4:
		{//ландшафт. радуга от красного до фиолетового сверху вниз.
			double partofc = 1-(c+razm/2)/double(razm);//расстояние до верха в кубе(от 0 до 1)
			int hi = partofc != 1 ? (int)floor(partofc*6) : 5;//7 цветов. 6 отрезков. hi-номер отрезка сверху вниз. от 0 до 5. соответственно с верхним цветом отрезка.
			double mix = (partofc-double(hi)*0.1666667)*6;
			res = ColorMix(color_grad_land[hi].getColor(k), color_grad_land[hi+1].getColor(k), mix);
			return res;
		}break;
	default: return 0;
	}
	
}

void Text_OpenGL(GLfloat x,GLfloat y,GLfloat z,const unsigned char* text)
{//вывод текста
    glRasterPos3f(x,y,z);
	//HFONT font=CreateFont(
    //glutBitmapString(GLUT_BITMAP_9_BY_15, text);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);
}

short int oprpangle()//возвращает четверть угла
{
	if(Angle>=0 && Angle<90) return 1;
	else if(Angle>=90 && Angle<180) return 2;
	else if(Angle>=180 && Angle<270) return 3;
	else if(Angle>=270 && Angle<360) return 4;

	if (1==1)
	{
		Angle=0;
		return 0;
	}
}

void DrawOses()//перерисовка осей
{
	glLineWidth(3);
	short int chetv=oprpangle();
	int smes=150;
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	if (GRAPHICS.modeoses==2)
	{
		switch (chetv)//конус z
		{
		case 1:{glTranslatef(-razm/2,razm/2,razm/2+smes);}break;
		case 2:{glTranslatef(razm/2,razm/2,razm/2+smes);}break;
		case 3:{glTranslatef(razm/2,-razm/2,razm/2+smes);}break;
		case 4:{glTranslatef(-razm/2,-razm/2,razm/2+smes);}break;
		}
	}
	if (GRAPHICS.modeoses==0 || GRAPHICS.modeoses==1)
	{
		glTranslatef(-razm/2,-razm/2,razm/2+smes);
	}
	
	glutSolidCone(50,300,20,50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	if (GRAPHICS.modeoses==2)
	{
		switch (chetv)//конус x
		{
		case 1:{glTranslatef(razm/2+smes,-razm/2,-razm/2);}break;
		case 2:{glTranslatef(razm/2+smes,+razm/2,-razm/2);}break;
		case 3:{glTranslatef(razm/2+smes,+razm/2,-razm/2);}break;
		case 4:{glTranslatef(razm/2+smes,-razm/2,-razm/2);}break;
		}
	}
	if (GRAPHICS.modeoses==0 || GRAPHICS.modeoses==1)
	{
		glTranslatef(razm/2+smes,-razm/2,-razm/2);
	}
	glRotatef(90,0.0,1.0,0.0);
	glutSolidCone(50,300,20,50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	if (GRAPHICS.modeoses==2)
	{
		switch (chetv)//конус y
		{
		case 1:{glTranslatef(-razm/2,razm/2+smes,-razm/2);}break;
		case 2:{glTranslatef(-razm/2,razm/2+smes,-razm/2);}break;
		case 3:{glTranslatef(razm/2,razm/2+smes,-razm/2);}break;
		case 4:{glTranslatef(razm/2,razm/2+smes,-razm/2);}break;
		}
	}
	if (GRAPHICS.modeoses==0 || GRAPHICS.modeoses==1)
	{
		glTranslatef(-razm/2,razm/2+smes,-razm/2);
	}
	glRotatef(-90,1.0,0.0,0.0);
	glutSolidCone(50,300,20,50);
	glPopMatrix();
	if (GRAPHICS.modeoses==2)
	{
		switch (chetv)//цветные линии
		{
		case 1:{glBegin(GL_LINES);
			glColor3f(0.0,0.0,1.0); glVertex3f(-razm/2,razm/2,-razm/2); glVertex3f(-razm/2,razm/2,razm/2+smes+100);//z
			glColor3f(1.0,0.0,0.0); glVertex3f(-razm/2,-razm/2,-razm/2); glVertex3f(razm/2+smes+100,-razm/2,-razm/2);//x
			glColor3f(0.0,1.0,0.0); glVertex3f(-razm/2,-razm/2,-razm/2); glVertex3f(-razm/2,razm/2+smes+100,-razm/2);//y
			glEnd();}break;
		case 2:{glBegin(GL_LINES);
			glColor3f(0.0,0.0,1.0); glVertex3f(razm/2,razm/2,-razm/2); glVertex3f(razm/2,razm/2,razm/2+smes+100);//z
			glColor3f(1.0,0.0,0.0); glVertex3f(-razm/2,razm/2,-razm/2); glVertex3f(razm/2+smes+100,razm/2,-razm/2);//x
			glColor3f(0.0,1.0,0.0); glVertex3f(-razm/2,-razm/2,-razm/2); glVertex3f(-razm/2,razm/2+smes+100,-razm/2);//y
			glEnd();}break;
		case 3:{glBegin(GL_LINES);
			glColor3f(0.0,0.0,1.0); glVertex3f(razm/2,-razm/2,-razm/2); glVertex3f(razm/2,-razm/2,razm/2+smes+100);//z
			glColor3f(1.0,0.0,0.0); glVertex3f(-razm/2,razm/2,-razm/2); glVertex3f(razm/2+smes+100,razm/2,-razm/2);//x
			glColor3f(0.0,1.0,0.0); glVertex3f(razm/2,-razm/2,-razm/2); glVertex3f(razm/2,razm/2+smes+100,-razm/2);//y
			glEnd();}break;
		case 4:{glBegin(GL_LINES);
			glColor3f(0.0,0.0,1.0); glVertex3f(-razm/2,-razm/2,-razm/2); glVertex3f(-razm/2,-razm/2,razm/2+smes+100);//z
			glColor3f(1.0,0.0,0.0); glVertex3f(-razm/2,-razm/2,-razm/2); glVertex3f(razm/2+smes+100,-razm/2,-razm/2);//x
			glColor3f(0.0,1.0,0.0); glVertex3f(razm/2,-razm/2,-razm/2); glVertex3f(razm/2,razm/2+smes+100,-razm/2);//y
			glEnd();}break;
		}
	}
	if (GRAPHICS.modeoses==0 || GRAPHICS.modeoses==1)
	{
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,1.0); glVertex3f(-razm/2,-razm/2,-razm/2); glVertex3f(-razm/2,-razm/2,razm/2+smes+100);//z
		glColor3f(1.0,0.0,0.0); glVertex3f(-razm/2,-razm/2,-razm/2); glVertex3f(razm/2+smes+100,-razm/2,-razm/2);//x
		glColor3f(0.0,1.0,0.0); glVertex3f(-razm/2,-razm/2,-razm/2); glVertex3f(-razm/2,razm/2+smes+100,-razm/2);//y
		glEnd();
	}

	//рисование делений на осях
	if ((GRAPHICS.modeistoses==true) && (GRAPHICS.modepokaz))
	{
		int del_length=razm/35;
		int del_sha=razm/(GRAPHICS.ndeloses+1);//для делений для промежуточных значений. если деления и крайние то в скобках -
		if (GRAPHICS.modeoses==0 || GRAPHICS.modeoses==1)
		{
			for (int i=1; i<=GRAPHICS.ndeloses; i++)
			{
				glBegin(GL_LINES);
				glColor3f(0.0,0.0,1.0); glVertex3f(-razm/2,-razm/2,i*del_sha-razm/2); glVertex3f(-razm/2-del_length,-razm/2,i*del_sha-razm/2);
				glColor3f(1.0,0.0,0.0); glVertex3f(i*del_sha-razm/2,-razm/2,-razm/2); glVertex3f(i*del_sha-razm/2,-razm/2-del_length,-razm/2);
				glColor3f(0.0,1.0,0.0); glVertex3f(-razm/2,i*del_sha-razm/2,-razm/2); glVertex3f(-razm/2-del_length,i*del_sha-razm/2,-razm/2);
				glEnd();
			}
		}
		else if (GRAPHICS.modeoses==2)
		{
			for (int i=1; i<=GRAPHICS.ndeloses; i++)
			{
				switch (chetv)
				{
					case 1:{glBegin(GL_LINES);
					glColor3f(0.0,0.0,1.0); glVertex3f(-razm/2,razm/2,i*del_sha-razm/2); glVertex3f(-razm/2-del_length,razm/2,i*del_sha-razm/2);//z
					glColor3f(1.0,0.0,0.0); glVertex3f(i*del_sha-razm/2,-razm/2,-razm/2); glVertex3f(i*del_sha-razm/2,-razm/2-del_length,-razm/2);
					glColor3f(0.0,1.0,0.0); glVertex3f(-razm/2,i*del_sha-razm/2,-razm/2); glVertex3f(-razm/2-del_length,i*del_sha-razm/2,-razm/2);
					glEnd();}break;
					case 2:{glBegin(GL_LINES);
					glColor3f(0.0,0.0,1.0); glVertex3f(razm/2,razm/2,i*del_sha-razm/2); glVertex3f(razm/2,razm/2+del_length,i*del_sha-razm/2);//z
					glColor3f(1.0,0.0,0.0); glVertex3f(i*del_sha-razm/2,razm/2,-razm/2); glVertex3f(i*del_sha-razm/2,razm/2+del_length,-razm/2);
					glColor3f(0.0,1.0,0.0); glVertex3f(-razm/2,i*del_sha-razm/2,-razm/2); glVertex3f(-razm/2-del_length,i*del_sha-razm/2,-razm/2);
					glEnd();}break;
					case 3:{glBegin(GL_LINES);
					glColor3f(0.0,0.0,1.0); glVertex3f(razm/2,-razm/2,i*del_sha-razm/2); glVertex3f(razm/2+del_length,-razm/2,i*del_sha-razm/2);//z
					glColor3f(1.0,0.0,0.0); glVertex3f(i*del_sha-razm/2,razm/2,-razm/2); glVertex3f(i*del_sha-razm/2,razm/2+del_length,-razm/2);
					glColor3f(0.0,1.0,0.0); glVertex3f(razm/2,i*del_sha-razm/2,-razm/2); glVertex3f(razm/2+del_length,i*del_sha-razm/2,-razm/2);
					glEnd();}break;
					case 4:{glBegin(GL_LINES);
					glColor3f(0.0,0.0,1.0); glVertex3f(-razm/2,-razm/2,i*del_sha-razm/2); glVertex3f(-razm/2,-razm/2-del_length,i*del_sha-razm/2);//z
					glColor3f(1.0,0.0,0.0); glVertex3f(i*del_sha-razm/2,-razm/2,-razm/2); glVertex3f(i*del_sha-razm/2,-razm/2-del_length,-razm/2);
					glColor3f(0.0,1.0,0.0); glVertex3f(razm/2,i*del_sha-razm/2,-razm/2); glVertex3f(razm/2+del_length,i*del_sha-razm/2,-razm/2);
					glEnd();}break;
				}
			}
		}
	}
}

void ShowText()
{//отрисовка текста
	GLfloat xi[9],yi[9],zi[9];
	zi[0]=0;
	xi[1]=0;zi[1]=-razm/2;
	yi[2]=0;zi[2]=-razm/2;
	int i=30;
	short int chetv=oprpangle();
	if (GRAPHICS.modeoses==1 || GRAPHICS.modeoses==2)
	{
		switch (chetv)
		{
		case 1:{xi[0]=-razm/2+i;yi[0]=razm/2-i; yi[1]=-razm/2-i*8; xi[2]=-razm/2-i*8;}break;
		case 2:{xi[0]=razm/2-i;yi[0]=razm/2-i; yi[1]=razm/2+i*8; xi[2]=-razm/2-i*8;}break;
		case 3:{xi[0]=razm/2-i;yi[0]=-razm/2+i; yi[1]=razm/2+i*8; xi[2]=razm/2+i*8;}break;
		case 4:{xi[0]=-razm/2+i;yi[0]=-razm/2+i; yi[1]=-razm/2-i*8; xi[2]=razm/2+i*8;}break;
		}
	}
	if (GRAPHICS.modeoses==0)
	{
		xi[0]=-razm/2+i;yi[0]=-razm/2+i; yi[1]=-razm/2-i*8; xi[2]=-razm/2-i*8;
	}

	glColor3f(0.0,0.0,1.0);
	Text_OpenGL(xi[0],yi[0],zi[0]+100,(unsigned char *)"z");//-razm/2,-razm/2,0
	glColor3f(1.0,0.0,0.0);
	Text_OpenGL(xi[1],yi[1],zi[1],(unsigned char *)"x");//0,-razm/2,-razm/2
	glColor3f(0.0,1.0,0.0);
	Text_OpenGL(xi[2],yi[2],zi[2],(unsigned char *)"y");//-razm/2,0,-razm/2

	GLfloat smr= GLfloat(razm)/2/10;
	zi[3]=-razm/2+smr;xi[3]=-razm/2;
	zi[4]=-razm/2+smr;xi[4]=razm/2;
	zi[5]=-razm/2-smr;yi[5]=-razm/2;
	zi[6]=-razm/2-smr;yi[6]=razm/2;
	zi[7]=-razm/2;
	zi[8]=razm/2;
	if (GRAPHICS.modeoses==1 || GRAPHICS.modeoses==2)
	{
		switch (chetv)//xmin,xmax,ymin,ymax,zmin,zmax
		{
		case 1:{yi[3]=-razm/2+i; yi[4]=-razm/2+i; xi[5]=-razm/2+i; xi[6]=-razm/2+i; xi[7]=-razm/2+i;yi[7]=razm/2-i; xi[8]=-razm/2+i;yi[8]=razm/2-i;}break;
		case 2:{yi[3]=razm/2-i; yi[4]=razm/2-i; xi[5]=-razm/2+i; xi[6]=-razm/2+i; xi[7]=razm/2-i;yi[7]=razm/2-i; xi[8]=razm/2-i;yi[8]=razm/2-i;}break;
		case 3:{yi[3]=razm/2-i; yi[4]=razm/2-i; xi[5]=razm/2-i; xi[6]=razm/2-i; xi[7]=razm/2-i;yi[7]=-razm/2+i; xi[8]=razm/2-i;yi[8]=-razm/2+i;}break;
		case 4:{yi[3]=-razm/2+i; yi[4]=-razm/2+i; xi[5]=razm/2-i; xi[6]=razm/2-i; xi[7]=-razm/2+i;yi[7]=-razm/2+i; xi[8]=-razm/2+i;yi[8]=-razm/2+i;}break;
		}
	}
	if (GRAPHICS.modeoses==0)
	{
		yi[3]=-razm/2+i; yi[4]=-razm/2+i; xi[5]=-razm/2+i; xi[6]=-razm/2+i; xi[7]=-razm/2+i;yi[7]=-razm/2+i; xi[8]=-razm/2+i;yi[8]=-razm/2+i;
	}

	//с округлением до сотых
	unsigned char *uchxmin,*uchxmax,*uchymin,*uchymax,*uchzmin,*uchzmax;

	uchxmin=dtuch(GRAPHICS.Xmin);
	uchxmax=dtuch(GRAPHICS.Xmax);
	uchymin=dtuch(GRAPHICS.Ymin);
	uchymax=dtuch(GRAPHICS.Ymax);
	uchzmin=dtuch(GRAPHICS.Zmin);
	uchzmax=dtuch(GRAPHICS.Zmax);
	//(unsigned char *)xmin
	glColor3f(1.0,0.0,0.0);
	Text_OpenGL(xi[3],yi[3],zi[3],uchxmin);//-razm/2,-razm/2,0
	Text_OpenGL(xi[4],yi[4],zi[4],uchxmax);//0,-razm/2,-razm/2
	
	glColor3f(0.0,1.0,0.0);
	Text_OpenGL(xi[5],yi[5],zi[5],uchymin);//-razm/2,0,-razm/2
	Text_OpenGL(xi[6],yi[6],zi[6],uchymax);//-razm/2,-razm/2,0
	Text_OpenGL(0,0,0,0);
	glColor3f(0.0,0.0,1.0);
	Text_OpenGL(xi[7],yi[7],zi[7],uchzmin);//0,-razm/2,-razm/2
	Text_OpenGL(xi[8],yi[8],zi[8],uchzmax);//-razm/2,0,-razm/2
}

void graph_func::RedrawFunc(int ngrid, const int &modecolor)//перерисовка функции
{
	if ((isfunc == true) && (failed == false) && (isFuncVisible == true))
	{
		glLineWidth(1);//отрисовка полигонов
		int datatii_d;//текущая data[] этой функции в зависимости оттого, статичная она или динамичная
		for (int i=0;i<ngrid;i++)
			for (int j=0;j<ngrid;j++)
			{
				if (isFuncDynamic)
					datatii_d=datatii;
				else
					datatii_d=0;
				if((data[datatii_d].Matrnorm[i][j]==true) && (data[datatii_d].Matrnorm[i][j+1]==true) && (data[datatii_d].Matrnorm[i+1][j+1]==true) && (data[datatii_d].Matrnorm[i+1][j]==true) && (CheckOutOfLims(i, j, zmin, zmax)==true))
				{
					double shag=razm/(ngrid);
					double xi=i*shag-razm/2, yi=j*shag-razm/2,
						zi=(data[datatii_d].nMatr[i][j]+
							data[datatii_d].nMatr[i][j+1]+
							data[datatii_d].nMatr[i+1][j+1]+
							data[datatii_d].nMatr[i+1][j])/4;//текущие координаты
					double xip=(i+1)*shag-razm/2,yip=(j+1)*shag-razm/2;
					glBegin(GL_QUADS);
						glColor3d(
							counticolor(xi, yi, zi, 0),
							counticolor(xi, yi, zi, 1),
							counticolor(xi, yi, zi, 2));
						glVertex3f(xi,yi,data[datatii_d].nMatr[i][j]);
						glVertex3f(xi,yip,data[datatii_d].nMatr[i][j+1]);
						glVertex3f(xip,yip,data[datatii_d].nMatr[i+1][j+1]);
						glVertex3f(xip,yi,data[datatii_d].nMatr[i+1][j]);
					glEnd();
				}
			}
		glLineWidth(2);//отрисовка сетки (вокруг каждого полигона)
		if (GRAPHICS.modegridgr==true)
			for (int i=0;i<ngrid;i++)
				for (int j=0;j<ngrid;j++)
				{
					if (isFuncDynamic)
						datatii_d=datatii;
					else
						datatii_d=0;
					if(data[datatii_d].Matrnorm[i][j]==true && data[datatii_d].Matrnorm[i][j+1]==true && data[datatii_d].Matrnorm[i+1][j+1]==true && data[datatii_d].Matrnorm[i+1][j]==true)
					{
						double shag=razm/(ngrid);
						double xi=i*shag-razm/2,yi=j*shag-razm/2;
						double xip=(i+1)*shag-razm/2,yip=(j+1)*shag-razm/2;
						glBegin(GL_LINES);
							glColor3f(0.0,0.0,0.0);
							glVertex3f(xi,yi,data[datatii_d].nMatr[i][j]); glVertex3f(xi,yip,data[datatii_d].nMatr[i][j+1]);
							glVertex3f(xi,yip,data[datatii_d].nMatr[i][j+1]); glVertex3f(xip,yip,data[datatii_d].nMatr[i+1][j+1]);
							glVertex3f(xip,yip,data[datatii_d].nMatr[i+1][j+1]); glVertex3f(xip,yi,data[datatii_d].nMatr[i+1][j]);
							glVertex3f(xi,yi,data[datatii_d].nMatr[i][j]); glVertex3f(xip,yi,data[datatii_d].nMatr[i+1][j]);
						glEnd();
					}
				}
	}
}

void DrawCube()
{//отрисовка ограничивающего параллелепипеда
	if (GRAPHICS.modeoses==0 || GRAPHICS.modeoses==1)
	{
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINES);
		//верх
		glVertex3f(-razm/2,-razm/2,razm/2); glVertex3f(razm/2,-razm/2,razm/2);
		glVertex3f(razm/2,-razm/2,razm/2); glVertex3f(razm/2,razm/2,razm/2);
		glVertex3f(razm/2,razm/2,razm/2); glVertex3f(-razm/2,razm/2,razm/2);
		glVertex3f(-razm/2,razm/2,razm/2); glVertex3f(-razm/2,-razm/2,razm/2);
		//бок
		glVertex3f(razm/2,-razm/2,razm/2); glVertex3f(razm/2,-razm/2,-razm/2);
		glVertex3f(-razm/2,razm/2,razm/2); glVertex3f(-razm/2,razm/2,-razm/2);
		glVertex3f(razm/2,razm/2,razm/2); glVertex3f(razm/2,razm/2,-razm/2);
		//низ
		glVertex3f(razm/2,razm/2,-razm/2); glVertex3f(-razm/2,razm/2,-razm/2);
		glVertex3f(razm/2,razm/2,-razm/2); glVertex3f(razm/2,-razm/2,-razm/2);
		glEnd();
	}

	if (GRAPHICS.modeoses==2)
	{
		glColor3f(0.0,0.0,0.0);
		short int chetv=oprpangle();
		glBegin(GL_LINES);
		//верх
		glVertex3f(-razm/2,-razm/2,razm/2); glVertex3f(razm/2,-razm/2,razm/2);
		glVertex3f(razm/2,-razm/2,razm/2); glVertex3f(razm/2,razm/2,razm/2);
		glVertex3f(razm/2,razm/2,razm/2); glVertex3f(-razm/2,razm/2,razm/2);
		glVertex3f(-razm/2,razm/2,razm/2); glVertex3f(-razm/2,-razm/2,razm/2);
		glEnd();
		switch(chetv)//нарисовать бок и низ(5 пар точек(,,))
		{
		case 1:{glBegin(GL_LINES);
			glVertex3f(razm/2,-razm/2,-razm/2); glVertex3f(razm/2,-razm/2,razm/2);
			glVertex3f(-razm/2,-razm/2,-razm/2); glVertex3f(-razm/2,-razm/2,razm/2);
			glVertex3f(razm/2,razm/2,-razm/2); glVertex3f(razm/2,razm/2,razm/2);

			glVertex3f(razm/2,razm/2,-razm/2); glVertex3f(-razm/2,razm/2,-razm/2);
			glVertex3f(razm/2,razm/2,-razm/2); glVertex3f(razm/2,-razm/2,-razm/2);
			glEnd();}break;
		case 2:{glBegin(GL_LINES);
			glVertex3f(razm/2,-razm/2,-razm/2); glVertex3f(razm/2,-razm/2,razm/2);
			glVertex3f(-razm/2,-razm/2,-razm/2); glVertex3f(-razm/2,-razm/2,razm/2);
			glVertex3f(-razm/2,razm/2,-razm/2); glVertex3f(-razm/2,razm/2,razm/2);

			glVertex3f(razm/2,razm/2,-razm/2); glVertex3f(razm/2,-razm/2,-razm/2);
			glVertex3f(-razm/2,-razm/2,-razm/2); glVertex3f(razm/2,-razm/2,-razm/2);
			glEnd();}break;
		case 3:{glBegin(GL_LINES);
			glVertex3f(-razm/2,razm/2,-razm/2); glVertex3f(-razm/2,razm/2,razm/2);
			glVertex3f(-razm/2,-razm/2,-razm/2); glVertex3f(-razm/2,-razm/2,razm/2);
			glVertex3f(razm/2,razm/2,-razm/2); glVertex3f(razm/2,razm/2,razm/2);

			glVertex3f(-razm/2,-razm/2,-razm/2); glVertex3f(-razm/2,razm/2,-razm/2);
			glVertex3f(-razm/2,-razm/2,-razm/2); glVertex3f(razm/2,-razm/2,-razm/2);
			glEnd();}break;
		case 4:{glBegin(GL_LINES);
			glVertex3f(razm/2,-razm/2,-razm/2); glVertex3f(razm/2,-razm/2,razm/2);
			glVertex3f(razm/2,razm/2,-razm/2); glVertex3f(razm/2,razm/2,razm/2);
			glVertex3f(-razm/2,razm/2,-razm/2); glVertex3f(-razm/2,razm/2,razm/2);

			glVertex3f(-razm/2,-razm/2,-razm/2); glVertex3f(-razm/2,razm/2,-razm/2);
			glVertex3f(razm/2,razm/2,-razm/2); glVertex3f(-razm/2,razm/2,-razm/2);
			glEnd();}break;
		}
	}
}

void Initialize()
{//часть инициализации (инициализация матрицы проекций)
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WinWid / 2, WinWid / 2, -WinHie / 2, WinHie / 2, -500, 500);
	glMatrixMode(GL_MODELVIEW);

}

void reshape(int w, int h)
{//трансформация окна
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w/2,w/2,-h/2,h/2,-500,500);
	scx=w/WinWid;
	scy=h/WinHie;
	if (scx>scy)
		sc=scy;
	else
		sc=scx;
	glMatrixMode(GL_MODELVIEW);
}

void KeyBoard(unsigned char key, int x, int y)//fb- front(-1) or back(1), lr - left(-1) or right(1)
{//нажатие клавиши клавиатуры
	switch(key)
	{
	case 27: exit(0);
		break;
	}
}

void SKeyBoard(int key, int x, int y)
{//нажатие спецеальной клавиши клавиатуры
	/*switch(key)
	{
	case GLUT_KEY_LEFT: ;
		break;
	case GLUT_KEY_RIGHT:;
		break;
	}*/
}
short int modemouse=-1;
bool lb=false;
int mx=0,my=0;
bool rott=false;//true - когда нужно прекратить вращение на время вращения мышью
void MouseMove(int ax, int ay)//0
{//движение мыши
	modemouse=0;
	lb=false;
	mx=ax; my=ay;
	rott=false;
}

void MousePressed(int button, int state, int ax, int ay)//1
{//нажатие клавиши мыши
	modemouse=1;
	rott=true;
	switch(button)
	{
	case GLUT_LEFT_BUTTON:{lb=true;}break;
	case GLUT_MIDDLE_BUTTON:{lb=false;}break;
	case GLUT_RIGHT_BUTTON:{lb=false;}break;
	}
}

void MouseWheel(int wheel, int dir, int ax, int ay)
{//колесо мыши
	lb=false;
	if (scl>sclmin && dir==-1)
		scl-=0.1;
	if (scl<sclmax && dir==1)
		scl+=0.1;
	
}

void MousePressedMove(int ax, int ay)//2
{//мышь зажата и двигается
	modemouse=2;
	rott=true;
	int dx,dy;
	float k=0.2;
	if (lb==true)
	{
		dx=ax-mx;
		dy=ay-my;
		Angle+=dx*k;
		AngleV+=dy*k;
		if (AngleV>360)
			AngleV-=360;
		if (AngleV<-360)
			AngleV+=360;
		mx=ax;my=ay;
	}
}

void Draw()
{//процедура главной перерисовки
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(-90,1.0,0.0,0.0);
	glRotatef(30,1.0,0.0,0.0);
	glRotatef(AngleV,1.0,0.0,0.0);
	glRotatef(Angle,0.0,0.0,1.0);//вращение
	
	glScalef(0.1*6/8,0.1*6/8,0.1*6/8);
	glScalef(0.95,0.95,0.95);
	glScalef(sc,sc,sc);
	glScalef(scl,scl,scl);
	glLineWidth(2);
	if (GRAPHICS.modeistoses==true)
		DrawCube();//отрисовка параллелепипеда
	else
		glutWireCube(5000);

	GRAPHICS.RedrawAll();//перерисовка функций
	
	glColor3f(1.0, 1.0, 1.0);

	//оси и показания
	if (GRAPHICS.modeistoses==true)
		DrawOses();//отрисовка осей
	if (GRAPHICS.modepokaz==true)
		ShowText();//отрисовка показаний, мин и макс значений переменных x,y,z

	glDisable(GL_DEPTH_TEST);
	glutSwapBuffers();
}

void Timer_OpenGL(int value)
{//таймер
	if (GRAPHICS.moderot==true && rott==false)
		Angle+=0.8*chast/40;
	if(Angle>360)
		Angle-=360;
	if(Angle<0)
		Angle+=360;

	tii=GRAPHICS.ti;
	if (tii>GRAPHICS.t2)
		tii=GRAPHICS.t2;
	if (tii<GRAPHICS.t1)
		tii=GRAPHICS.t1;
	datatii=(tii-(double)GRAPHICS.t1)*fps;
	Draw();
	glutTimerFunc(chast, Timer_OpenGL, 0);
}

void init_OpenGL(int argc, char* argv[])
{//инициализация
	int winwidt, winhiet;
	winwidt=GRAPHICS.scrw-(int)(785*GRAPHICS.ffs/8+10)-30;
	if (winwidt>(GRAPHICS.scrh-100))
		winhiet=GRAPHICS.scrh-100;
	else
		winhiet=winwidt;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);//GLUT_DOUBLE
	glutInitWindowSize(winwidt, winhiet);
	glutInitWindowPosition((int)785*GRAPHICS.ffs/8+10,5);
	glutCreateWindow("Визуализация функций z=f(x,y,t)");
	//
	glutDisplayFunc(Draw);
	glutTimerFunc(chast, Timer_OpenGL, 0);
	Initialize();
	glutReshapeFunc(reshape);
	glutMotionFunc(MousePressedMove);
	glutPassiveMotionFunc(MouseMove);
	glutMouseFunc(MousePressed);
	glutMouseWheelFunc(MouseWheel);
	glutKeyboardFunc(KeyBoard);
	glutSpecialFunc(SKeyBoard);
	glutMainLoop();
}