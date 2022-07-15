/*
 * Created by FallenGemini on 2022/7/13.
 * 管理员功能声明
 */
#include "admin.h"
#include "List.h"

void Add(DoublyLinkList* dlList, char* En, char* Cn)
{
    Word word;
    strcpy(word.En, En);
    strcpy(word.Cn, Cn);
    InsertDoublyLinkList(dlList, dlList->length, word);
}

void Delete(DoublyLinkList* dlList, char* En, char* Cn)
{
    Word word;
    strcpy(word.En, En);
    strcpy(word.Cn, Cn);
    DeleteDoublyLinkListByWord(dlList, word);
}

void Modify(DoublyLinkList* dlList, int pos, char* En, char* Cn)
{
    Word word;
    strcpy(word.En, En);
    strcpy(word.Cn, Cn);
    ChangeDoublyLinkElement(dlList, pos, word);
}