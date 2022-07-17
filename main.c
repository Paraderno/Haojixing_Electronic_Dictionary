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
#include <mmsystem.h>
// #pragma comment(lib, "Winmm.lib")


int main() {
    //播放音乐函数
    //PlaySound(TEXT("./resource/菊次郎的夏天.wav"), NULL, SND_FILENAME | SND_ASYNC);
    
    /*  中英词库    */
    WordNode* WordListTail = (WordNode*)malloc(sizeof(WordNode));
    WordListTail->next = NULL;
    WordListTail->prev = NULL;

    WordLinkList* WordListHead = (WordLinkList*)malloc(sizeof(WordLinkList));
    WordListHead->length = 1;
    WordListHead->next = WordListTail;
    if (LoadDictionary(WordListHead) == 0)
    {
        return 0;
    }

    /*  收藏夹词库   */
    //创建收藏夹词库的结点
    WordNode* starCaseTail = (WordNode*)malloc(sizeof(WordNode));
    starCaseTail->next = NULL;
    starCaseTail->prev = NULL;

    WordLinkList* starCaseHead = (WordLinkList*)malloc(sizeof(WordLinkList));
    starCaseHead->length = 1;
    starCaseHead->next = starCaseTail;
    //加载收藏夹
    if (LoadStarCase(starCaseHead) == 0)
    {
        return 0;
    }

    //账户的链表
    /*  账户      */
    AccountNode* AccountListTail = (AccountNode*)malloc(sizeof(AccountNode));
    AccountListTail->next = NULL;
    AccountListTail->prev = NULL;

    AccountLinkList* AccountListHead = (AccountLinkList*)malloc(sizeof(AccountLinkList));
    AccountListHead->length = 1;
    AccountListHead->next = AccountListTail;
    LoadAccountFile(AccountListHead);

    /*  控制台     */
    int opt = 0;   // 
    int now = 0;   // 
    int TYPE = 0;  // 用户类型
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
    * 收藏夹 9
    * 修改单词 10
    * 增加单词 11
    * 删除单词 12
    */
    while (TRUE)
    {
        if (opt == 0)   // 初始界面
        {
            system("cls");
            DrawTheMainMenu();
            SetPosition(35, 16);
            scanf("%d", &now);
            if (now < 0 || now > 4)
                now = 0;
        }
        if (opt == 1)   // 登录界面
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
            sleep_second(1);
        }
        if (opt == 2)   // 注册界面
        {
            system("cls");
            DrawRegisterPage();
            Account account;
            SetPosition(35, 10);
            scanf("%s", account.ID);
            SetPosition(35, 15);
            scanf("%s", account.password);
            // 账户注册
            if (Register(AccountListHead, account.ID, account.password) == 1)
            {
                system("cls");
                DrawSuccessMessage("注册");
                now = 0;
            }
            else
            {
                system("cls");
                DrawFailMessage("注册");
                now = 0;
            }
            sleep_second(1);
        }
        if (opt == 3)   // 退出程序
        {
            SetPosition(33, 20);
            printf("欢迎再次使用\n");
            sleep_second(1);
            break;
        }
        if (opt == 4)   // 注销账户
        {
            system("cls");
            DrawLogOutPage();
            Account account;
            SetPosition(60, 9);
            scanf("%d", &account.type);
            SetPosition(35, 12);
            scanf("%s", account.ID);
            SetPosition(35, 15);
            scanf("%s", account.password);
            int count = 0;
            count = LogOut(AccountListHead, account.type, account.ID, account.password);
            SaveAccountData(AccountListHead);
            if (count >= 1)
            {
                system("cls");
                DrawSuccessMessage("注销");
                now = 0;
            }
            else
            {
                system("cls");
                DrawFailMessage("注销");
                now = 5;
            }
            sleep_second(1);
        }
        if (opt == 5)   // 用户界面
        {
            system("cls");
            DrawUserMenu();
            TYPE = 0;
            SetPosition(36, 18);
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
                    now = 0;
                    break;
                case 5:
                    now = 4;
                    break;
                default:
                    now = 5;
                    break;
            }
        }
        if (opt == 6) //管理员界面
        {
            system("cls");
            DrawAdminMenu();
            TYPE = 1;
            SetPosition(40, 17);
            int choice = 0;
            scanf("%d", &choice);
            switch (choice)
            {
                case 1:
                    now = 11;
                    break;
                case 2:
                    now = 12;
                    break;
                case 3:
                    now = 10;
                    break;
                case 4:
                    now = 0;
                    break;
                default:
                    now = 6;
                    break;
            }
        }
        if (opt == 7) // 中文查英文
        {
            system("cls");
            DrawFindEn();
            SetPosition(25, 2);
            char s[50];
            scanf("%s", s);
            
            CnToEn(WordListHead, s);
            SetPosition(25, 28);
            int choice = 0;
            scanf("%d", &choice);
            if (choice == 1)
            {
                now = 0;
            }
            else
            {
                if (TYPE == 0) now = 5;
                else now = 6;
            }
        }
        if (opt == 8) // 英文查中文
        {
            system("cls");
            DrawFindCn();
            SetPosition(25, 2);
            char s[50];
            scanf("%s", s);
            SetPosition(5, 10);
            Word currentWord =  EnToCn(WordListHead, s);
            Word NullWord = {"", ""};
            SetPosition(25, 23);
            if (isWordEqual(currentWord, NullWord) == 1)
            {
                now = 5;
            }
            else
            {
                SetPosition(30, 25);
                int choice = 0;
                scanf("%d", &choice);
                if (choice == 1)
                {
                    now = 0;
                }
                else if (choice == 2)
                {
                    Star(starCaseHead,currentWord);
                    now = 5;
                }
                else if(choice == 3)
                {
                    now = 5;
                }
                else
                {
                    now = 8;
                }
            }
           
        }
        if (opt == 9) // 收藏夹功能
        {
            system("cls");
            int length = starCaseHead->length - 1;
            DrawTheStarCase(length);
            WordNode* currentNode = starCaseHead->next;
            for (int i = 0; i < length; i++)
            {
                SetPosition(5, 6 + i);
                printf("%-10s%-10s\n", currentNode->word.En, currentNode->word.Cn);
                currentNode = currentNode->next;
            }

            SetPosition(30, 23 + length);
            int choice = 0;
            scanf("%d", &choice);
            if (choice == 1)
            {
                SetPosition(5, 24 + length);
                printf("请输入要删除的英文单词：");
                SetPosition(35, 24 + length);
                Word word;
                scanf("%s", word.En);

                WordNode* currNode = starCaseHead->next;
                for (int i = 1; i < starCaseHead->length; i++) {
                    if (strcmp((currNode->word).En, word.En) == 0) {
                        strcpy(word.Cn, (currNode->word).Cn);
                    }
                    currNode = currNode->next;
                }
                DeleteWordLinkListByWord(starCaseHead, word);
                SaveStarCase(starCaseHead);
            }
            else if (choice == 2)
            {
                now = 5;
            }
            else
            {
                now = 9;
            }
        }
        if (opt == 10) //修改单词
        {
            system("cls");
            DrawChangePage();
            char En[50], oldCn[50], newCn[50];
            SetPosition(25, 1);
            scanf("%s", En);
            SetPosition(25, 2);
            scanf("%s", newCn);

            WordNode* currNode = WordListHead->next;
            int counter = 1;
            for (counter = 1; counter < WordListHead->length; counter++) {
                if (strcmp((currNode->word).En, En) == 0) {
                    strcpy(oldCn, (currNode->word).Cn);

                    break;
                }
                currNode = currNode->next;
            }

            Delete(WordListHead, En, oldCn);
            Modify(WordListHead, counter, En, newCn);
            SaveDictionary(WordListHead);
            //SetPosition(5, 10);
            //EnToCn(WordListHead, En);
            //SetPosition(25, 23);

            int choice = 0;
            scanf("%d", &choice);
            if (choice == 1)
            {
                now = 0;
            }
            else if (choice == 2)
            {
                now = 6;
            }
            else
            {
                now = 10;
            }
        }
        if (opt == 11) // 增加单词
        {
            system("cls");
            DrawAddPage();
            char En[50], Cn[50];
            SetPosition(25, 1);
            scanf("%s", En);
            SetPosition(25, 2);
            scanf("%s", Cn);
            Add(WordListHead, En, Cn);
            SaveDictionary(WordListHead);
            SetPosition(5, 10);
            EnToCn(WordListHead, En);
            SetPosition(25, 23);
            int choice = 0;
            scanf("%d", &choice);
            if (choice == 2)
            {
                now = 6;
            }
            else now = 0;
        }
        if (opt == 12) // 删除单词
        {
            system("cls");
            DrawDeletePage();
            char En[50], Cn[50];
            SetPosition(25, 1);
            scanf("%s", En);
            SetPosition(25, 2);
            scanf("%s", Cn);
            Delete(WordListHead, En, Cn);
            SaveDictionary(WordListHead);
            //SetPosition(5, 10);
            //EnToCn(WordListHead, En);
            SetPosition(25, 23);
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