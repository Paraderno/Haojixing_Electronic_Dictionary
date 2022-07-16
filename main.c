/*
 * �������
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
    printf("��������1\n");
    Word word1 = { "abandon","����" };
    Word word2 = { "abstract","�����,�������" };
    Word word3 = { "absent","ȱϯ��" };

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

    //    Delete(WordListHead,"abandon","v.","����");
    PrintWordLinkList(WordListHead);

    //    Modify(WordListHead,1,"abandon","v.","����");
    PrintWordLinkList(WordListHead);

    EnToCn(WordListHead, "abandon");
    CnToEn(WordListHead, "�����");

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
    //DrawSuccessMessage("��½");
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
     * ˫�������ͷ���
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
    * ��¼���� 1
    * ע����� 2
    * �˳����� 3
    * ע���˻� 4
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
            printf("��ӭ�ٴ�ʹ��\n");
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