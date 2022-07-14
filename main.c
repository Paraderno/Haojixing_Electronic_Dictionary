/*
 * �������
 */

#include <stdio.h>
#include <malloc.h>
#include "List.h"
#include "admin.h"
#include "public.h"

int main() {
    DoublyNode* WordListTail = (DoublyNode*)malloc(sizeof (DoublyNode));

/*!
 * ˫�������ͷ���
 */
    DoublyLinkList* WordListHead = (DoublyLinkList*)malloc(sizeof(DoublyLinkList));
    WordListHead->length = 1;
    WordListHead->next = WordListTail;

    printf("��������\n");
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
    return 0;
}
