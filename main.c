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


void test1(WordLinkList* WordListHead)
{
    printf("样例测试1\n");
    Word word1 = { "abandon","抛弃" };
    Word word2 = { "abstract","抽象的,不具体的" };
    Word word3 = { "absent","缺席的" };

    InsertWordLinkList(WordListHead, 1, word1);
    PrintWordLinkList(WordListHead);

    InsertWordLinkList(WordListHead, 1, word2);
    PrintWordLinkList(WordListHead);

    DeleteWordLinkListByPos(WordListHead, 2);
    PrintWordLinkList(WordListHead);

    InsertWordLinkList(WordListHead, 1, word3);
    GetWordLinkListElement(WordListHead, 1);
    PrintWordLinkList(WordListHead);

    InsertWordLinkList(WordListHead, 2, word2);
    PrintWordLinkList(WordListHead);

    ChangeWordListElement(WordListHead, 2, word1);
    PrintWordLinkList(WordListHead);

    //    Delete(WordListHead,"abandon","v.","抛弃");
    PrintWordLinkList(WordListHead);

    //    Modify(WordListHead,1,"abandon","v.","抛弃");
    PrintWordLinkList(WordListHead);

    EnToCn(WordListHead, "abandon");
    CnToEn(WordListHead, "抽象的");

    InsertWordLinkList(WordListHead, 2, word3);
    FuzzySearch(WordListHead, "abs");
}

void test2(WordLinkList* WordListHead) {
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

void test3(WordLinkList* WordListHead) {
    PrintWordLinkList(WordListHead);
    printf("%d", WordListHead->length);
    SaveDictionary(WordListHead);
}

int main() {
    WordNode* WordListTail = (WordNode*)malloc(sizeof(WordNode));
    WordListTail->next = NULL;
    WordListTail->prev = NULL;

    /*!
     * 双向链表的头结点
     */
    WordLinkList* WordListHead = (WordLinkList*)malloc(sizeof(WordLinkList));
    WordListHead->length = 1;
    WordListHead->next = WordListTail;
    LoadDictionary(WordListHead);

    AccountNode* AccountListTail = (AccountNode*)malloc(sizeof(AccountNode));
    AccountListTail->next = NULL;
    AccountListTail->prev = NULL;

    /*!
     * 双向链表的头结点
     */
    AccountLinkList* AccountListHead = (AccountLinkList*)malloc(sizeof(AccountLinkList));
    AccountListHead->length = 1;
    AccountListHead->next = AccountListTail;
    if (LoadAccountFile(AccountListHead) == 0) {
        return 0;
    }

    //  test1(WordListHead);
    //  test2(WordListHead);
    //  test3(WordListHead);

    int opt,now;
    DrawTheMainMenu();
    SetPosition(35, 16);
    scanf("%d", &opt);
    /*
    * 主界面 0
    * 登录界面 1
    * 注册界面 2
    * 退出程序 3
    * 注销账户 4
    * 用户界面 5
    * 管理员界面 6
    * 中文查英文 7
    * 英文查中文 8
    * 收藏单词界面 9
    * 展示收藏夹 10
    * 增加单词 11
    * 删除单词 12
    * 修改单词 13
    */
    while (TRUE)
    {
        if (opt == 0)
        {
            system("cls");
            DrawTheMainMenu();
            SetPosition(35, 16);
            scanf("%d", &now);
        }
        if (opt == 1)
        {
            system("cls");
            DrawLogInPage();
            Account account;
            SetPosition(60, 9);
            scanf("%d", &account.type);
            SetPosition(35, 12);
            scanf("%s", account.ID);
            SetPosition(35, 15);
            scanf("%s", account.password);
            // 账户登录，通过函数判定进入哪一个界面
            int count = 0;
            count = LogIn(AccountListHead, account.type, account.ID, account.password);
            if (count == 1)
            {
                system("cls");
                DrawSuccessMessage("登录");
                if (account.type == 1)
                {
                    now = 6;
                }
                else
                {
                    now = 5;
                }
            }
            else
            {
                system("cls");
                DrawFailMessage("登录");
                now = 0;
            }
            sleep_second(2);
        }
        if (opt == 2)
        {
            system("cls");
            DrawRegisterPage();
            Account account;
            SetPosition(30, 10);
            scanf("%s", account.ID);
            SetPosition(30, 15);
            scanf("%s", account.password);
            // 账户注册
            scanf("%d", &now);//卡住循环，后续会删除
        }
        if (opt == 3)
        {
            SetPosition(33, 20);
            printf("欢迎再次使用\n");
            sleep_second(2);
            //SetPosition(33, 25);
            break;
        }
        if (opt == 4)
        {

        }
        if (opt == 5)
        {
            system("cls");
            DrawUserMenu();
            SetPosition(35, 17);
            int choice = 0;
            scanf("%d", &choice);
            switch (choice)
            {
                case 1:
                    now = 8;
                    break;
                case 2:
                    now = 7;
                    break;
                case 3:
                    now = 9;
                    break;
                case 4:
                    now = 10;
                    break;
                default:
                    now = 0;
                    break;
            }
        }
        if (opt == 6)
        {
            system("cls");
            DrawAdminMenu();
            SetPosition(30, 17);
            int choice = 0;
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                now = 8;
                break;
            case 2:
                now = 7;
                break;
            case 3:
                now = 11;
                break;
            case 4:
                now = 12;
                break;
            case 5:
                now = 13;
                break;
            default:
                now = 0;
                break;
            }
        }
        if (opt == 7)
        {
            system("cls");
            DrawFindEn();
            SetPosition(20, 2);
            char s[50];
            scanf("%s", s);
            SetPosition(5, 10);
            CnToEn(WordListHead, s);
            SetPosition(5, 23);
            int choice = 0;
            scanf("%d", &choice);
            if (choice == 1)
                now = 5;
            else now = 0;
        }
        if (opt == 8)
        {
            system("cls");
            DrawFindCn();
            SetPosition(20, 2);
            char s[50];
            scanf("%s", s);
            SetPosition(5, 10);
            EnToCn(WordListHead, s);
            SetPosition(5, 23);
            int choice = 0;
            scanf("%d", &choice);
            if (choice == 1)
            {
                now = 5;
            }
            else now = 0;
        }
        if (opt == 9)
        {
            now = 0;
        }
        if (opt == 10)
        {
            system("cls");
            //DrawTheStarCase();
            now = 0;
        }
        if (opt == 11)
        {
            system("cls");
            DrawAddPage();
            char En[50], Cn[50];
            scanf("%s%s", En, Cn);
            Add(WordListHead, En, Cn);
            int choice = 0;
            scanf("%d", &choice);
            if (choice == 2)
            {
                now = 6;
            }
            else now = 0;
        }
        opt = now;
    }
    return 0;
}