/*
 * Created by FallenGemini on 2022/7/13.
 * 管理员功能声明
 */
#include "admin.h"

void Add(DoublyLinkList * dlList, char* En, char* attribute, char* Cn)
{
    Word word = {En,attribute,Cn};
    InsertDoublyLinkList(dlList,dlList->length,word);
}

void Delete(DoublyLinkList * dlList, char* En, char* attribute, char* Cn)
{
    Word word;
    strcpy(word.En,En);
    strcpy(word.attribute,attribute);
    strcpy(word.Cn,Cn);
    DeleteDoublyLinkListByWord(dlList,word);
}

void Modify(DoublyLinkList * dlList, int pos, char* En, char* attribute, char* Cn)
{
    Word word;
    strcpy(word.En,En);
    strcpy(word.attribute,attribute);
    strcpy(word.Cn,Cn);
    ChangeDoublyLinkElement(dlList, pos, word);
}