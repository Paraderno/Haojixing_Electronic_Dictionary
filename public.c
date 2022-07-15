/*
 * Created by FallenGemini on 2022/7/13.
 * ��������ʵ��
 */

#include <stdio.h>
#include <malloc.h>
#include "public.h"
void LoadWords(DoublyLinkList * dlList){
    Word word;
    int size=0;
    //���ļ�
    FILE *file=fopen("D:\\clion\\Haojixing_Electronic_Dictionary-master\\resource\\WordInformation.txt","r");
    if(file==NULL)printf("�Ҳ������ݿ⣡����\n");
    else{
        //�����ļ�
        while(!feof(file))
        {
            size++;
            fscanf(file,"%s %s" ,word.En,word.Cn);
            InsertDoublyLinkList(dlList,size,word);
        }
    }
    printf("�������ݳɹ�\n");
    fclose(file);
}
void SaveWords(DoublyLinkList *dlList){
    FILE *file= fopen("D:\\clion\\Haojixing_Electronic_Dictionary-master\\resource\\SaveInformation.txt","w");
    DoublyNode *head=dlList->next;
    for (int i = 0; i < dlList->length; ++i){
        fprintf(file,"%s %s\n",head->word.En,head->word.Cn);
        head=head->next;
    }
    printf("����ɹ�\n");
    fclose(file);
}
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

    printf("���� %s ��������Ϊ %s\n",currentNode->word.En
           ,currentNode->word.Cn);
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
            printf("��������Ϊ %s  ����Ϊ %s��\n", currentNode->word.Cn,
                    currentNode->word.En);
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
                    currentNode->word.Cn);
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