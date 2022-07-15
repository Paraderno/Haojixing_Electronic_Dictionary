#ifndef CONSOLELIB_H_INCLUDED
#define CONSOLELIB_H_INCLUDED
//#pragma once
#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>
#include <time.h>
#if defined(__linux__)
		#include<unistd.h>// Linux系统
	#elif defined(_WIN32)
		#include<windows.h>// Windows系统
#endif

/** 休眠（毫秒） */
void sleep_micro(int time);
/** 休眠（秒） */
void sleep_second(int time);

 /* 设置控制台窗口标题 */
//void SetTitle(const WCHAR* title);
void SetTitle(const char* title);
/* 0-黑色, 1-蓝色,   2-绿色,      3-浅绿色,     4-红色,   5-紫色,   6-黄色,   7-白色,
 * 8-灰色, 9-淡蓝色, 10-淡绿色,   11-淡浅绿色   12-淡红色 13-淡紫色 14-淡黄色 15-亮白色
 */
void SetColor(int, int);
/** 设置控制台窗体的宽和高 */
void SetConsoleWindowSize(int width, int height);
/* 设置光标的x、y坐标-正常坐标轴 */
void SetPosition(int x, int y);
/* 动态打印文字信息 */
void PrintString(const char* msgString);
/* 类似fgets, 读取对应长度的字符串*/
void Read(char* Str, int BufferSize);
/* 得到用户输入的键 */
int GetKey();
/* 得到当前的系统时间，包含年月日时分秒 */
char* GetTime();
void Clear(int X, int Y);
/* 清空信息显示区 */
void ClearMessage();

#endif // CONSOLELIB_H_INCLUDED