#ifndef CONSOLELIB_H_INCLUDED
#define CONSOLELIB_H_INCLUDED
//#pragma once
#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>
#include <time.h>
#if defined(__linux__)
		#include<unistd.h>// Linuxϵͳ
	#elif defined(_WIN32)
		#include<windows.h>// Windowsϵͳ
#endif

/** ���ߣ����룩 */
void sleep_micro(int time);
/** ���ߣ��룩 */
void sleep_second(int time);

 /* ���ÿ���̨���ڱ��� */
//void SetTitle(const WCHAR* title);
void SetTitle(const char* title);
/* 0-��ɫ, 1-��ɫ,   2-��ɫ,      3-ǳ��ɫ,     4-��ɫ,   5-��ɫ,   6-��ɫ,   7-��ɫ,
 * 8-��ɫ, 9-����ɫ, 10-����ɫ,   11-��ǳ��ɫ   12-����ɫ 13-����ɫ 14-����ɫ 15-����ɫ
 */
void SetColor(int, int);
/** ���ÿ���̨����Ŀ�͸� */
void SetConsoleWindowSize(int width, int height);
/* ���ù���x��y����-���������� */
void SetPosition(int x, int y);
/* ��̬��ӡ������Ϣ */
void PrintString(const char* msgString);
/* ����fgets, ��ȡ��Ӧ���ȵ��ַ���*/
void Read(char* Str, int BufferSize);
/* �õ��û�����ļ� */
int GetKey();
/* �õ���ǰ��ϵͳʱ�䣬����������ʱ���� */
char* GetTime();
void Clear(int X, int Y);
/* �����Ϣ��ʾ�� */
void ClearMessage();

#endif // CONSOLELIB_H_INCLUDED