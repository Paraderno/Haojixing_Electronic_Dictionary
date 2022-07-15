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
    Word word1 = {"abandon","v.","����"};
    Word word2 = {"abstract","adj.","�����,�������"};
    Word word3 = {"absent","adj.","ȱϯ��"};

    InsertDoublyLinkList(WordListHead,1,word1);
    PrintDoublyLinkList(WordListHead);

    InsertDoublyLinkList(WordListHead,1,word2);
    PrintDoublyLinkList(WordListHead);

    DeleteDoublyLinkListByPos(WordListHead,2);
    PrintDoublyLinkList(WordListHead);

    InsertDoublyLinkList(WordListHead,1,word3);
    GetDoublyLinkListElement(WordListHead,1);
    PrintDoublyLinkList(WordListHead);

    InsertDoublyLinkList(WordListHead,2,word2);
    PrintDoublyLinkList(WordListHead);

    ChangeDoublyLinkElement(WordListHead,2,word1);
    PrintDoublyLinkList(WordListHead);

    Delete(WordListHead,"abandon","v.","����");
    PrintDoublyLinkList(WordListHead);

    Modify(WordListHead,1,"abandon","v.","����");
    PrintDoublyLinkList(WordListHead);

    EnToCn(WordListHead,"abandon");
    CnToEn(WordListHead,"�����");

    InsertDoublyLinkList(WordListHead,2,word3);
    FuzzySearch(WordListHead,"abs");
}
void test2() {
    DrawTheFrame();
    DrawTheMainMenu();
    system("pause");
}
int main() {
    DoublyNode* WordListTail = (DoublyNode*)malloc(sizeof (DoublyNode));

/*!
 * ˫�������ͷ���
 */
    DoublyLinkList* WordListHead = (DoublyLinkList*)malloc(sizeof(DoublyLinkList));
    WordListHead->length = 1;
    WordListHead->next = WordListTail;
//    test1(WordListHead);
    test2();
    return 0;
}
