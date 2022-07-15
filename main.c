/*
 * 程序入口
 */

#include <stdio.h>
#include <malloc.h>
#include<windows.h>
#include<conio.h>
#include "List.h"
#include "admin.h"
#include "public.h"
#include "draw.h"
#include"user.h"

void test1(DoublyLinkList* WordListHead)
{
    printf("样例测试1\n");
    Word word1 = { "abandon","抛弃" };
    Word word2 = { "abstract","抽象的,不具体的" };
    Word word3 = { "absent","缺席的" };

    InsertDoublyLinkList(WordListHead, 1, word1);
    PrintDoublyLinkList(WordListHead);

    InsertDoublyLinkList(WordListHead, 1, word2);
    PrintDoublyLinkList(WordListHead);

    DeleteDoublyLinkListByPos(WordListHead, 2);
    PrintDoublyLinkList(WordListHead);

    InsertDoublyLinkList(WordListHead, 1, word3);
    GetDoublyLinkListElement(WordListHead, 1);
    PrintDoublyLinkList(WordListHead);

    InsertDoublyLinkList(WordListHead, 2, word2);
    PrintDoublyLinkList(WordListHead);

    ChangeDoublyLinkElement(WordListHead, 2, word1);
    PrintDoublyLinkList(WordListHead);

    //    Delete(WordListHead,"abandon","v.","抛弃");
    PrintDoublyLinkList(WordListHead);

    //    Modify(WordListHead,1,"abandon","v.","抛弃");
    PrintDoublyLinkList(WordListHead);

    EnToCn(WordListHead, "abandon");
    CnToEn(WordListHead, "抽象的");

    InsertDoublyLinkList(WordListHead, 2, word3);
    FuzzySearch(WordListHead, "abs");
}

void test2(DoublyLinkList* WordListHead) {
        //DrawTheMainMenu();
        //DrawTheFrame();
        //DrawChangeableFrame(10);
        //DrawInnerFrame();
        //DrawDividingLine();
        //DrawChangeableDividingLine(10);
        //DrawAdminMenu();
        //DrawUserMenu();
        //DrawRegisterPage();
        //DrawFindEn(WordListHead);
        //DrawFindCn(WordListHead);
        //DrawTheStarCase(10);
        //DrawAddPage();
        //DrawDeletePage();
    //DrawSuccessMessage("登陆");
        //DrawFailMessage(const char* message);
    //system("pause");
}

void test3(DoublyLinkList* WordListHead) {
    PrintDoublyLinkList(WordListHead);
    printf("%d", WordListHead->length);
    SaveWords(WordListHead);
}

int main() {
    DoublyNode* WordListTail = (DoublyNode*)malloc(sizeof(DoublyNode));
    WordListTail->next = NULL;
    WordListTail->prev = NULL;

    /*!
     * 双向链表的头结点
     */
    DoublyLinkList* WordListHead = (DoublyLinkList*)malloc(sizeof(DoublyLinkList));
    WordListHead->length = 1;
    WordListHead->next = WordListTail;
    LoadWords(WordListHead);
    //  test1(WordListHead);
    //  test2(WordListHead);
    //  test3(WordListHead);

    int opt,now;
    DrawTheMainMenu();
    SetPosition(35, 16);
    scanf("%d", &opt);
    /*
    * 登录界面 1
    * 注册界面 2
    * 退出程序 3
    * 注销账户 4
    */
    while (TRUE)
    {
        if (opt == 1)
        {
            system("cls");
            DrawLogInPage();
            scanf("%d", &now);
        }
        if (opt == 2)
        {
            DrawUserMenu();
        }
        if (opt == 3)
        {
            SetPosition(20, 20);
            printf("欢迎再次使用\n");
            SetPosition(20, 25);
            break;
        }
        if (opt == 4)
        {

        }
        opt = now;
    }
    return 0;
}