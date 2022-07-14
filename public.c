/*
 * Created by FallenGemini on 2022/7/13.
 * ��������ʵ��
 */

#include <stdio.h>
#include "public.h"

void LogIn(char* account, char* password, FILE* aPtr)
{

}

void LogOut(char* account,char* password, FILE* aPtr)
{

}

void Menu()
{

}


void Music(FILE* fPtr)
{

}

void EnToCn(DoublyLinkList* dlList, char* En)
{
    DoublyNode* currentNode = dlList->next;   //ȡ����һ�����
    int length = dlList->length;  //������

    int pos = 1;
    for(; pos <= length; pos++)
    {
        if(strcmp(currentNode->word.En,En) == 0) break;
        currentNode = currentNode->next;
    }
    if(pos == length)
    {
        printf("û���ҵ��������\n");
        return;
    }

    printf("���� %s �Ĵ���Ϊ %s ��������Ϊ %s\n",currentNode->word.En,
           currentNode->word.attribute,currentNode->word.Cn);

}


void CnToEn(DoublyLinkList* dlList, char* Cn)
{
    DoublyNode* currentNode = dlList->next;   //ȡ����һ�����
    int length = dlList->length;  //������
    int count = 0;
    int pos = 1;
    for(; pos <= length; pos++)
    {
        if(strstr(currentNode->word.Cn,Cn) != NULL) {
            printf("��������Ϊ %s �ĵ���Ϊ %s ����Ϊ %s��\n", currentNode->word.Cn,
                   currentNode->word.attribute, currentNode->word.En);
            count++;
        }
        currentNode = currentNode->next;
    }
    if(count == 0)
    {
        printf("û���ҵ��������\n");
        return;
    }
}

void FuzzySearch(DoublyLinkList* dlList, char* En)
{
    DoublyNode* currentNode = dlList->next;   //ȡ����һ�����
    int length = dlList->length;  //������
    int count = 0;
    int pos = 1;
    for(; pos <= length; pos++)
    {
        if(strstr(currentNode->word.En,En) != NULL) {
            printf("���������������ʣ�%s %s%s��\n", currentNode->word.En,
                   currentNode->word.attribute, currentNode->word.Cn);
            count++;
        }
        currentNode = currentNode->next;
    }
    if(count == 0)
    {
        printf("û���ҵ��������\n");
        return;
    }
}

void Exit(FILE* rPtr)
{

}