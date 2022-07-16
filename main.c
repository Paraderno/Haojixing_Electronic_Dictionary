/*
 * 程序入口
 */

#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <conio.h>
#include "List.h"
#include "admin.h"
#include "public.h"
#include "draw.h"
#include "user.h"

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
    //  test1(WordListHead);
    //  test2(WordListHead);
    //  test3(WordListHead);

    int opt = -1;
    int now = -1;
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
            system("cls");
            DrawUserMenu();
        }
        if (opt == 3)
        {
            SetPosition(33, 20);
            printf("欢迎再次使用\n");
            //SetPosition(33, 25);
            break;
        }
        if (opt == 4)
        {

        }
        opt = now;
    }
    return 0;
}