/*
 * Created by 绫波真美丽 on 2022/7/14.
 */
#include "draw.h"

/*!
 * 绘制开始页面
 */
void DrawTheMainMenu()
{
    SetPosition(28,5);
    printf("欢迎使用好记星电子词典！");
    SetPosition(18,7);
    printf("1.登陆");
    SetPosition(18,9);
    printf("2.注册");
    SetPosition(18,11);
    printf("3.退出");
    SetPosition(18,13);
    printf("4.注销");
    SetPosition(18,15);
    printf("请输入您的选择：");
}

void DrawTheFrame()
{
    setlocale(LC_ALL, "ZH-CN");
    SetTitle("好记星电子词典");
    SetColor(13,0);
    SetConsoleWindowSize(80,30);
    SetPosition(0,0);
    for (int i = 0; i < 40; ++i) {
        printf("■");
    }

    SetPosition(0,25);
    for (int i = 0; i < 40; ++i) {
        printf("■");
    }

    for (int i = 1; i < 25; ++i) {
        SetPosition(79,i);
        printf("*");
        SetPosition(0,i);
        printf("*");
    }
}