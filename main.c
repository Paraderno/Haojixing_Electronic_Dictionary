/*
 * �������
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
    printf("��������1\n");
    Word word1 = { "abandon","����" };
    Word word2 = { "abstract","�����,�������" };
    Word word3 = { "absent","ȱϯ��" };

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

    //    Delete(WordListHead,"abandon","v.","����");
    PrintDoublyLinkList(WordListHead);

    //    Modify(WordListHead,1,"abandon","v.","����");
    PrintDoublyLinkList(WordListHead);

    EnToCn(WordListHead, "abandon");
    CnToEn(WordListHead, "�����");

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
    //DrawSuccessMessage("��½");
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
     * ˫�������ͷ���
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
            DrawUserMenu();
        }
        if (opt == 3)
        {
            SetPosition(20, 20);
            printf("��ӭ�ٴ�ʹ��\n");
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