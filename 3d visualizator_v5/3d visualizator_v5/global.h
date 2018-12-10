#pragma once
#include "stdafx.h"

//of global
constexpr double PI = 3.14159265;
constexpr double E = 2.71828183;

constexpr char dops[] = ",.0123456789xyt+-*/^()";//допустимые символы
constexpr char dopd[] = "scpgqarlfvbimnu";//опустимые действия. краткая запись (один символ)//sin, cos, tg, ctg, sqrt
const std::string eqf[15]={//эквивалент функциям в полной записи
"sin","cos","tg","ctg","sqrt",
"abs","round","ceil","floor",
"asin","acos","atg","actg",
"ln","log"};

const double smallV=0.001,bigV=1000000;//малая величина, большая величина
const int soarr=101,sostr=1000,sorazm=10;
//(sizeofarr,sizeofstr,sizeofrazmern)размер массива значений(сетки), размер строки в символах, размер числа в символах

//язык
extern int mode_Form1;//какой язык установлен на форме Form1
extern int mode_FormLoad;//какой язык установлен на форме Formload
extern int mode_FormDemo;//какой язык установлен на форме FormDemo
extern int mode_FormProcess;//какой язык установлен на форме FormProcess
extern std::string Language[2];//имена файлов для рус и англ
extern std::string error_otpfr_func;
extern std::string errors[12];
extern int num_func_calculateing;//какая функция по номеру рассчитывается сейчас(для show_errors)