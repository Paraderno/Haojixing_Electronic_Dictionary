/*
 * Created by 籲������� on 2022/7/14.
 */
#include "draw.h"

/*!
 * ���ƿ�ʼҳ��
 */
void DrawTheMainMenu()
{
    SetPosition(28,5);
    printf("��ӭʹ�úü��ǵ��Ӵʵ䣡");
    SetPosition(18,7);
    printf("1.��½");
    SetPosition(18,9);
    printf("2.ע��");
    SetPosition(18,11);
    printf("3.�˳�");
    SetPosition(18,13);
    printf("4.ע��");
    SetPosition(18,15);
    printf("����������ѡ��");
}

void DrawTheFrame()
{
    setlocale(LC_ALL, "ZH-CN");
    SetTitle("�ü��ǵ��Ӵʵ�");
    SetColor(13,0);
    SetConsoleWindowSize(80,30);
    SetPosition(0,0);
    for (int i = 0; i < 40; ++i) {
        printf("��");
    }

    SetPosition(0,25);
    for (int i = 0; i < 40; ++i) {
        printf("��");
    }

    for (int i = 1; i < 25; ++i) {
        SetPosition(79,i);
        printf("*");
        SetPosition(0,i);
        printf("*");
    }
}