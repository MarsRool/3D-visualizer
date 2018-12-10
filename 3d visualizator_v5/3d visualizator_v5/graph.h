#pragma once
#include "stdafx.h"
#include "global.h"

#pragma pack(push, 1)
class graph_func;
class ListOfFuncs
{
private:
	std::vector<char *> names;
	std::vector<char **> Funcs;
public:
	ListOfFuncs();
	void AddFunc(char* namei, char **Funcs_i);
	void Clear();
	char* GetName(int k);
};

class RGB_MR
{
private:
	double color3[3];
public:
	RGB_MR();
	RGB_MR(double colori[3]);
	RGB_MR(double c1, double c2, double c3);
	double getColor(int k);
	void setColor(int k, double colori);
	void operator=(const RGB_MR& right);
};

class graph_data
{
private:
	int k;//количество точек;
	double **Matr, **nMatr;//значения матрицы z=f(x,y,t), координаты точек
	bool **Matrnorm;//допустимое ли значение

	friend graph_func;
public:
	graph_data();
	~graph_data();

	void reinit(int i);	
};

class graph_func
{
public:
	//данные(1)
	bool failed;//true, если преобразование с ошибкой
	bool isFuncDynamic;//true-если функция динамическая
	bool isfunc;//есть ли функция на отрисовку
	bool isFuncVisible;//true-если надо отрисовать функцию
	
	//функция(2)
	int outsch;//сколько символов в конечной строке
	char str[sostr];//введенная строка
	char strpr[sostr];//преобразованная строка
	char outstr[sostr];//выходная строка
	double zmin,zmax;//минимальные и максимальные значения x,y,z

	short int type_of_color;//тип раскраски функции. как в GRAPHICS
	RGB_MR color;//стандартный(монотонный) цвет функции
	RGB_MR color_grad[4];//градиентный цвет downleft, downright, upleft, upright colors (от 0.0 до 1.0)
	RGB_MR color_grad_land[7];//ландшафт. по второй схеме. радуга от красного до фиолетового сверху вниз.

	//unsigned int TimeCalcMatrs, TimeCalcChoords;//времена расчета CalculateMatrix и CalculateMatrixOut

private:
	//значения сетки(3)
	graph_data *data;//данные функции.
	int ndata;//количество матриц значений функции

public:
	graph_func();
	void Translate(char *instr, int len);
	void testFuncOnDymanic();
	void ClearData();
	void CalculateMatrix(int ngrid, double &xsha, double &ysha, double &tsha, double xmin, double xmax, double ymin, double ymax, int t1, int t2, unsigned int fps, System::Windows::Forms::ProgressBar^ ProgBar);
	void CalculateMatrixOut(int ngrid, bool isautozmax, bool isautozmin);
	void RedrawFunc(int ngrid, const int &modecolor);

	double Min(int ngrid);//расчет экстремумов
	double Max(int ngrid);//по всем данным всех времен

	void SaveData(FILE *file);
	void LoadData(FILE *file, int ngrid);
private:
	void TranslatingToEquvalentOp();
	void stackmachine();
	double calculate(char inpoutstr[sostr],int sch, double x, double y, double t, int tii, int indi, int indj);
	double counticolor(double a, double b, int c, int k);

	bool CheckOutOfLims(int i, int j, double zmini, double zmaxi);//true - если 4 точки не выходят за пределы zmin и zmax {[i,j], [i+1,j], [i,j+1], [i+1,j+1]}
};

class graph
{
public:
	int ngrid;//количество полигонов / одно ребро (количество точек на 1 больше)
	double xsha,ysha,tsha;//шаг сетки по x и y. шаг времени
	bool IsTimeStartedNow;//true - если процесс запущен сейчас
	double ti;//текущее время
	int t1, t2;//начальное и конечное время в секундах

	bool isinitOpenGl;//инициализирован OpenGL
	short int modecolor;/*тип раскраски функции.
				  1-разными цветами каждую функцию(монотонно)
				  2-разными цветами каждую функцию(градиентно)
				  3-раскраска 4 цветами от dl,dr,ul,ur.
				  4-ландшафт.*/
	int modeoses;//тип расположения осей
	int ndeloses;//количество делений на оси (для начала промежуточных, т.е. не при макс и мин значениях)
	bool moderot;//Вращается ли график
	bool modegridgr;//есть ли сетка на графике
	bool modeistoses;//есть ли оси
	bool modepokaz;//есть ли показания максимумов и минимумов
	bool istDynamic;//есть ли хоть одна динамическая функция
	unsigned int fps,ffs;//fps, размер шрифта формы
	RGB_MR color_type1[4];//по первой схеме. downleft, downright, upleft, upright colors (от 0.0 до 1.0)
	RGB_MR color_type2[7];//по второй схеме. радуга от красного до фиолетового сверху вниз.
	bool isLoaded;//произошла ли загрузка из файла(если да, то обносить элементы Form1 и установить равным false)

	double Xmin,Xmax,Ymin,Ymax,Zmin,Zmax;//минимальные и максимальные значения x,y,z
	bool isautozmin, isautozmax;//есть ли auto в zmin и zmax

	int nfuncs;//количество функций.
	graph_func *funcs;//функции и их данные
	
	bool Failed;//true- если неправильно указаны параметры на форме

	int scrw, scrh;//ширина и высота экрана

	std::string *ErrorsGlobal;//массив ошибок при расчете
	int nvsego_ErrorsGlobal, k_ErrorsGlobal;//всего зарезервировано ошибок, сколько ошибок в функциях(или др.)
	int mode_Now;//определяет, какой сейчас язык

	ListOfFuncs listOfFuncs;//для загрузки (!FileInfo.info)содержит список сохранений и их функций в локальном виде
public:
	graph();
	void AddFunc(char *instr, int len, const RGB_MR &colori, System::Windows::Forms::ProgressBar^ ProgBar);
	bool DeleteFunc(int k);//удалить функцию под номером k
	/*useless*/bool ClearDataFunc(int k);//очистить данные элемента под номером k
	bool ReInitFunc(int k, char *instr, int len, const RGB_MR &colori, System::Windows::Forms::ProgressBar^ ProgBar);//реинициализировать элемент под номером k
	
	void InitErrorsGlobal(int n);
	void SetError(int num);//добавить ошибку в массив ошибок GRAPHICS::ErrorsGlobal. n_func-номер ошибочной функции(нумерация с нуля(в самой функции прибавляется 1)). num-номер ошибки
	void ShowErrors(System::Windows::Forms::TextBox^ txtb);//вывести ошибки в TextBox формы Form_Process
	
	void TestOnDynamics();//проверка на существование динамической функции
	void FuncsReOut();//подготовка функций к выводу(включает инициализацию цветов)
	void ReInitColors();//инициализация цвета функций и типа раскраски
	void SetDrawData(unsigned int fpsi);
	void RedrawAll();

	void SaveToFile(const char * name);//сохранить функции
	void LoadFromFile(const char * name);//загрузить функции
	void SaveToFileInfo(System::String^ FileInfo, char* name);
private:
};
#pragma pack(pop)

extern graph GRAPHICS;