//
// Created by 籲������� on 2022/7/14.
//

#include "draw.h"

void DrawTheFrame()
{
    //    SetTitle("�ü��ǵ��Ӵʵ�");
    SetColor(2, 0);
    SetConsoleWindowSize(80, 30);
    SetPosition(0, 0);
    for (int i = 0; i < 80; ++i) {
        printf("-");
    }

    SetPosition(0, 25);
    for (int i = 0; i < 80; ++i) {
        printf("-");
    }

    for (int i = 1; i < 25; ++i) {
        SetPosition(79, i);
        printf("*");
        SetPosition(0, i);
        printf("*");
    }
}

void DrawChangeableFrame(int sum)
{
    //    SetTitle("�ü��ǵ��Ӵʵ�");
    SetColor(2, 0);
    SetConsoleWindowSize(80, 30 + sum);
    SetPosition(0, 0);
    for (int i = 0; i < 80; ++i) {
        printf("-");
    }

    SetPosition(0, 25 + sum);
    for (int i = 0; i < 80; ++i) {
        printf("-");
    }

    for (int i = 1; i < 25 + sum; ++i) {
        SetPosition(79, i);
        printf("*");
        SetPosition(0, i);
        printf("*");
    }
}

void DrawInnerFrame()
{
    SetColor(2, 0);
    SetPosition(8, 6);
    for (int i = 0; i < 65; ++i) {
        printf("-");
    }
    SetPosition(8, 19);
    for (int i = 0; i < 65; ++i) {
        printf("-");
    }

    for (int i = 7; i < 19; ++i) {
        SetPosition(7, i);
        printf("|");
        SetPosition(73, i);
        printf("|");
    }
}

void DrawMessageFrame()
{
    SetColor(2, 0);
    SetPosition(22, 8);
    for (int i = 0; i < 33; ++i) {
        printf("-");
    }
    SetPosition(22, 15);
    for (int i = 0; i < 33; ++i) {
        printf("-");
    }

    for (int i = 9; i < 15; ++i) {
        SetPosition(21, i);
        printf("|");
        SetPosition(55, i);
        printf("|");
    }
}

void DrawDividingLine()
{
    SetColor(2, 0);
    SetPosition(1, 4);
    for (int i = 0; i < 78; ++i) {
        printf("-");
    }
    SetPosition(1, 17);
    for (int i = 0; i < 78; ++i) {
        printf("-");
    }
}

void DrawChangeableDividingLine(int sum)
{
    SetColor(2, 0);
    SetPosition(1, 4);
    for (int i = 0; i < 78; ++i) {
        printf("-");
    }
    SetPosition(1, 17 + sum);
    for (int i = 0; i < 78; ++i) {
        printf("-");
    }
}

void DrawTheMainMenu()
{
    DrawTheFrame();
    DrawInnerFrame();
    SetPosition(28, 3);
    printf("��ӭʹ�úü��ǵ��Ӵʵ䣡");
    SetPosition(18, 8);
    printf("1.��½");
    SetPosition(18, 10);
    printf("2.ע��");
    SetPosition(18, 12);
    printf("3.�˳�");
    SetPosition(18, 14);
    printf("4.ע��");
    SetPosition(18, 16);
    printf("����������ѡ��");
}

void DrawAdminMenu()
{
    DrawTheFrame();
    DrawInnerFrame();
    SetPosition(31, 3);
    printf("*�ü��ǵ��Ӵʵ�*");
    SetPosition(18, 7);
    printf("1.��ѯ��������");
    SetPosition(18, 9);
    printf("2.��ѯ����");
    SetPosition(18, 11);
    printf("3.������");
    SetPosition(18, 13);
    printf("4.ɾ������");
    SetPosition(18, 15);
    printf("5.�޸ĵ���");
    SetPosition(18, 17);
    printf("����������ѡ��");
}

void DrawUserMenu()
{
    DrawTheFrame();
    DrawInnerFrame();
    SetPosition(31, 3);
    printf("*�ü��ǵ��Ӵʵ�*");
    SetPosition(18, 7);
    printf("1.��ѯ��������");
    SetPosition(18, 9);
    printf("2.��ѯ����");
    SetPosition(18, 11);
    printf("3.�ղص���");
    SetPosition(18, 13);
    printf("4.չʾ�ղؼ�");
    SetPosition(18, 15);
    printf("5.��������");
    SetPosition(18, 17);
    printf("����������ѡ��");
}

void DrawRegisterPage()
{
    DrawTheFrame();
    DrawInnerFrame();
    SetPosition(31, 3);
    printf("*��ӭע���û�*");
    SetPosition(18, 10);
    printf("�������û�����");
    SetPosition(18, 15);
    printf("���������룺");
}

void DrawLogInPage()
{
    DrawTheFrame();
    DrawInnerFrame();
    SetPosition(31, 3);
    printf("*��ӭ��¼*");
    SetPosition(18, 9);
    printf("�������˻����ͣ�����ԱΪ1���û�Ϊ0����");
    SetPosition(18, 12);
    printf("�������û�����");
    SetPosition(18, 15);
    printf("���������룺");
}

void DrawFindEn()
{
    DrawTheFrame();
    SetPosition(5, 2);
    printf("�������������壺");
    DrawDividingLine();
    SetPosition(5, 19);
    printf("1.�ص����˵�");
    SetPosition(5, 21);
    printf("2.�˳�");
    SetPosition(5, 23);
    printf("����������ѡ��");

}

void DrawFindCn()
{
    DrawTheFrame();
    SetPosition(5, 2);
    printf("������Ӣ�ĵ��ʣ�");
    DrawDividingLine();
    SetPosition(5, 19);
    printf("1.�ص����˵�");
    SetPosition(5, 21);
    printf("2.�˳�");
    SetPosition(5, 23);
    printf("����������ѡ��");
}

void DrawTheStarCase(int sum)
{
    if (sum < 10)
    {
        DrawTheFrame();
        SetPosition(4, 2);
        printf("*�ղؼ�*");
        DrawDividingLine();
        SetPosition(5, 19);
        printf("1.�ص����˵�");
        SetPosition(5, 21);
        printf("2.�˳�");
        SetPosition(5, 23);
        printf("����������ѡ��");
    }
    else
    {
        DrawChangeableFrame(sum);
        SetPosition(4, 2);
        printf("*�ղؼ�*");
        DrawChangeableDividingLine(sum);
        SetPosition(5, 19 + sum);
        printf("1.�ص����˵�");
        SetPosition(5, 21 + sum);
        printf("2.�˳�");
        SetPosition(5, 23 + sum);
        printf("����������ѡ��");
    }
}

void DrawAddPage()
{
    DrawTheFrame();
    SetPosition(5, 2);
    printf("������Ҫ���ӵĵ��ʣ�");
    DrawDividingLine();
    SetPosition(5, 19);
    printf("1.�ص����˵�");
    SetPosition(5, 21);
    printf("2.�˳�");
    SetPosition(5, 23);
    printf("����������ѡ��");
}

void DrawDeletePage()
{
    DrawTheFrame();
    SetPosition(5, 2);
    printf("������Ҫɾ���ĵ��ʣ�");
    DrawDividingLine();
    SetPosition(5, 19);
    printf("1.�ص����˵�");
    SetPosition(5, 21);
    printf("2.�˳�");
    SetPosition(5, 23);
    printf("����������ѡ��");
}

void DrawSuccessMessage(const char* message)
{
    DrawTheFrame();
    char text[50] = "����*";
    strcat(text, message);
    strcat(text, "�ɹ�*����");
    DrawMessageFrame();
    SetPosition(30, 12);
    printf("%s", text);
}

void DrawFailMessage(const char* message)
{
    DrawTheFrame();
    char text[50] = "����*";
    strcat(text, message);
    strcat(text, "ʧ��*����");
    DrawMessageFrame();
    SetPosition(30, 12);
    printf("%s", text);
}