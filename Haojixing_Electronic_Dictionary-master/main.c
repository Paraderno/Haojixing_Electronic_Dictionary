/*
 * �������
 */

#include <stdio.h>
#include <malloc.h>
#include "List.h"
#include "public.h"
#include "admin.h"

int main() {
    DoublyNode* WordListTail = (DoublyNode*)malloc(sizeof (DoublyNode));
    WordListTail->next = NULL;
    WordListTail->prev = NULL;

/*!
 * ˫�������ͷ���
 */
    DoublyLinkList* WordListHead = (DoublyLinkList*)malloc(sizeof(DoublyLinkList));
    WordListHead->length = 1;
    WordListHead->next = WordListTail;
    LoadWords(WordListHead);



    PrintDoublyLinkList(WordListHead);
    printf("%d",WordListHead->length);
    SaveWords(WordListHead);
    return 0;
}
