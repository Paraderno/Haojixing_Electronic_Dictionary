//
// Created by 绫波真美丽 on 2022/7/14.
//

#include "draw.h"

void DrawTheFrame()
{
    SetTitle("好记星电子词典");
    SetColor(2, 0);
    SetConsoleWindowSize(81, 31);
    SetPosition(0, 0);
    for (int i = 0; i < 80; ++i) {
        printf("-");
    }

    SetPosition(0, 30);
    for (int i = 0; i < 80; ++i) {
        printf("-");
    }

    for (int i = 1; i < 30; ++i) {
        SetPosition(79, i);
        printf("*");
        SetPosition(0, i);
        printf("*");
    }
}

void DrawChangeableFrame(int sum)
{
    SetTitle("好记星电子词典");
    SetColor(2, 0);
    SetConsoleWindowSize(81, 31 + sum);
    SetPosition(0, 0);
    for (int i = 0; i < 80; ++i) {
        printf("-");
    }

    SetPosition(0, 30 + sum);
    for (int i = 0; i < 80; ++i) {
        printf("-");
    }

    for (int i = 1; i < 30 + sum; ++i) {
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
    SetPosition(28, 5);
    printf("欢迎使用好记星电子词典！");
    SetPosition(18, 10);
    printf("1.登录");
    SetPosition(18, 12);
    printf("2.注册");
    SetPosition(18, 14);
    printf("3.退出");
    SetPosition(18, 16);
    printf("请输入您的选择：");
}

void DrawAdminMenu()
{
    DrawTheFrame();
    DrawInnerFrame();
    SetPosition(31, 3);
    printf("*好记星电子词典*");
    SetPosition(18, 9);
    printf("1.增加单词");
    SetPosition(18, 11);
    printf("2.删除单词");
    SetPosition(18, 13);
    printf("3.修改单词");
    SetPosition(18, 15);
    printf("4.退出");
    SetPosition(18, 17);
    printf("请输入您的选择：");
}

void DrawUserMenu()
{
    DrawTheFrame();
    DrawInnerFrame();
    SetPosition(31, 4);
    printf("*好记星电子词典*");
    SetPosition(18, 8);
    printf("1.英文查中文");
    SetPosition(18, 10);
    printf("2.中文查英文");
    SetPosition(18, 12);
    printf("3.收藏夹功能");
    SetPosition(18, 14);
    printf("4.退出登录");
    SetPosition(18, 16);
    printf("5.注销账号");
    SetPosition(18, 18);
    printf("请输入您的选择：");
}

void DrawRegisterPage()
{
    DrawTheFrame();
    DrawInnerFrame();
    SetPosition(31, 3);
    printf("*欢迎注册用户*");
    SetPosition(18, 10);
    printf("请输入用户名：");
    SetPosition(18, 15);
    printf("请输入密码：");
}

void DrawLogInPage()
{
    DrawTheFrame();
    DrawInnerFrame();
    SetPosition(31, 3);
    printf("*欢迎登录*");
    SetPosition(18, 9);
    printf("请输入账户类型（管理员为1，用户为0）：");
    SetPosition(18, 12);
    printf("请输入用户名：");
    SetPosition(18, 15);
    printf("请输入密码：");
}

void DrawLogOutPage()
{
    DrawTheFrame();
    DrawInnerFrame();
    SetPosition(31, 3);
    printf("*注销页面*");
    SetPosition(18, 9);
    printf("请输入账户类型（管理员为1，用户为0）：");
    SetPosition(18, 12);
    printf("请输入用户名：");
    SetPosition(18, 15);
    printf("请输入密码：");
}

void DrawFindEn()
{
    DrawTheFrame();
    SetPosition(5, 2);
    printf("请输入中文释义：");
    DrawChangeableDividingLine(5);
    SetPosition(5, 24);
    printf("1.回到主菜单");
    SetPosition(5, 26);
    printf("2.退出");
    SetPosition(5, 28);
    printf("请输入您的选择：");

}

void DrawFindCn()
{
    DrawTheFrame();
    SetPosition(5, 2);
    printf("请输入英文单词：");
    DrawDividingLine();
    SetPosition(5, 19);
    printf("1.回到主菜单");
    SetPosition(5, 21);
    printf("2.收藏此单词");
    SetPosition(5, 23);
    printf("3.退出");
    SetPosition(5, 25);
    printf("请输入您的选择：");
}

void DrawTheStarCase(int sum)
{
    //if (sum < 10)
    //{
    //    DrawTheFrame();
    //    SetPosition(4, 2);
    //    printf("*收藏夹*");
    //    DrawDividingLine();
    //    SetPosition(5, 19);
    //    printf("1.删除词条");
    //    SetPosition(5, 21);
    //    printf("2.退出");
    //    SetPosition(5, 23);
    //    printf("请输入您的选择：");
    //}
    //else
    //{
        DrawChangeableFrame(sum);
        SetPosition(4, 2);
        printf("*收藏夹*");
        DrawChangeableDividingLine(sum);
        SetPosition(5, 19 + sum);
        printf("1.删除词条");
        SetPosition(5, 21 + sum);
        printf("2.退出");
        SetPosition(5, 23 + sum);
        printf("请输入您的选择：");
    //}
}

void DrawAddPage()
{
    DrawTheFrame();
    SetPosition(5, 1);
    printf("请输入要增加的单词：");
    DrawDividingLine();
    SetPosition(5, 19);
    printf("1.回到主菜单");
    SetPosition(5, 21);
    printf("2.退出");
    SetPosition(5, 23);
    printf("请输入您的选择：");
}

void DrawDeletePage()
{
    DrawTheFrame();
    SetPosition(5, 1);
    printf("请输入要删除的单词：");
    DrawDividingLine();
    SetPosition(5, 19);
    printf("1.回到主菜单");
    SetPosition(5, 21);
    printf("2.退出");
    SetPosition(5, 23);
    printf("请输入您的选择：");
}

void DrawChangePage()
{
    DrawTheFrame();
    SetPosition(5, 1);
    printf("请输入要修改的单词：");
    DrawDividingLine();
    SetPosition(5, 19);
    printf("1.回到主菜单");
    SetPosition(5, 21);
    printf("2.退出");
    SetPosition(5, 23);
    printf("请输入您的选择：");
}

void DrawSuccessMessage(const char* message)
{
    DrawTheFrame();
    char text[50] = "——*";
    strcat(text, message);
    strcat(text, "成功*——");
    DrawMessageFrame();
    SetPosition(30, 12);
    printf("%s", text);
}

void DrawFailMessage(const char* message)
{
    DrawTheFrame();
    char text[50] = "——*";
    strcat(text, message);
    strcat(text, "失败*——");
    DrawMessageFrame();
    SetPosition(30, 12);
    printf("%s", text);
}