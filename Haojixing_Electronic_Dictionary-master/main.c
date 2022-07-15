/*
 * 程序入口
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
 * 双向链表的头结点
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
