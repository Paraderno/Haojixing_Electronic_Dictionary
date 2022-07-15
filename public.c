/*
 * Created by FallenGemini on 2022/7/13.
 * 公共功能实现
 */

#include <stdio.h>
#include <malloc.h>
#include "public.h"
void LoadWords(DoublyLinkList * dlList){
    Word word;
    int size=0;
    //打开文件
    FILE *file=fopen("D:\\clion\\Haojixing_Electronic_Dictionary-master\\resource\\WordInformation.txt","r");
    if(file==NULL)printf("找不到数据库！！！\n");
    else{
        //读入文件
        while(!feof(file))
        {
            size++;
            fscanf(file,"%s %s" ,word.En,word.Cn);
            InsertDoublyLinkList(dlList,size,word);
        }
    }
    printf("加载数据成功\n");
    fclose(file);
}
void SaveWords(DoublyLinkList *dlList){
    FILE *file= fopen("D:\\clion\\Haojixing_Electronic_Dictionary-master\\resource\\SaveInformation.txt","w");
    DoublyNode *head=dlList->next;
    for (int i = 0; i < dlList->length; ++i){
        fprintf(file,"%s %s\n",head->word.En,head->word.Cn);
        head=head->next;
    }
    printf("保存成功\n");
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
    DoublyNode* currentNode = dlList->next;   //取出第一个结点
    int length = dlList->length;  //链表长度

    int pos = 1;
    for(; pos <= length; pos++)
    {
        if(strcmp(currentNode->word.En,En) == 0) break;
        currentNode = currentNode->next;
    }
    if(pos == length)
    {
        printf("没有找到这个单词\n");
        return;
    }

    printf("单词 %s 中文释义为 %s\n",currentNode->word.En
           ,currentNode->word.Cn);
}


void CnToEn(DoublyLinkList* dlList, char* Cn)
{
    DoublyNode* currentNode = dlList->next;   //取出第一个结点
    int length = dlList->length;  //链表长度
    int count = 0;
    int pos = 1;
    for(; pos <= length; pos++)
    {
        if(strstr(currentNode->word.Cn,Cn) != NULL) {
            printf("中文释义为 %s  词性为 %s，\n", currentNode->word.Cn,
                    currentNode->word.En);
            count++;
        }
        currentNode = currentNode->next;
    }
    if(count == 0)
    {
        printf("没有找到这个单词\n");
        return;
    }
}
void FuzzySearch(DoublyLinkList* dlList, char* En)
{
    DoublyNode* currentNode = dlList->next;   //取出第一个结点
    int length = dlList->length;  //链表长度
    int count = 0;
    int pos = 1;
    for(; pos <= length; pos++)
    {
        if(strstr(currentNode->word.En,En) != NULL) {
            printf("你可能在找这个单词？%s %s%s，\n", currentNode->word.En,
                    currentNode->word.Cn);
            count++;
        }
        currentNode = currentNode->next;
    }
    if(count == 0)
    {
        printf("没有找到这个单词\n");
        return;
    }
}

void Exit(FILE* rPtr)
{

}