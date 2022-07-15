/*
 * Created by FallenGemini on 2022/7/14.
 * 链表及相关函数
 */
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "List.h"

int equal(Word word1, Word word2) {
    int flag = TRUE;
    if(strcmp(word1.En,word2.En) != 0) flag = FALSE;
    if(strcmp(word1.Cn,word2.Cn) != 0) flag = FALSE;
    return flag;
}

void InsertDoublyLinkList(DoublyLinkList* dlList, int pos, Word word) {
    DoublyNode* currentNode = dlList->next;   //取出第一个结点
    int length = dlList->length;  //链表长度
    DoublyNode* node = (DoublyNode*)malloc(sizeof(DoublyNode));
    node->word = word; node->prev = NULL; node->next = NULL;    //新建一个节点

    if(pos > length)
    {
        printf("您所选择的位置大于链表长度，插入失败\n");
        return;
    }
    if(pos <= 0)
    {
        printf("您所选择的位置小于或等于0，插入失败\n");
        return;
    }

    dlList->length = length + 1;  //插入成功

    for(int i = 1; i < pos; i++)    //找到位置
        currentNode = currentNode->next;

    if(currentNode->prev == NULL)    //前缀结点为空
    {
        currentNode->prev = node;
        node->next = currentNode;
        dlList->next = node;
    }
    else    //前缀结点不为空
    {
        DoublyNode* preNode = currentNode->prev;
        preNode->next = node;
        node->prev = preNode;
        node->next = currentNode;
        currentNode->prev = node;
    }
}

void InsertAccountLinkList(DoublyLinkList* dlList, int pos, Account account){
    AccountNode* currentNode = dlList->next;   //取出第一个结点
    int length = dlList->length;  //链表长度
    AccountNode* node = (AccountNode*)malloc(sizeof(AccountNode));
    node->account = account; node->prev = NULL; node->next = NULL;    //新建一个节点

    if(pos > length)
    {
        printf("您所选择的位置大于链表长度，插入失败\n");
        return;
    }
    if(pos <= 0)
    {
        printf("您所选择的位置小于或等于0，插入失败\n");
        return;
    }

    dlList->length = length + 1;  //插入成功

    for(int i = 1; i < pos; i++)    //找到位置
        currentNode = currentNode->next;

    if(currentNode->prev == NULL)    //前缀结点为空
    {
        currentNode->prev = node;
        node->next = currentNode;
        dlList->next = node;
    }
    else    //前缀结点不为空
    {
        DoublyNode* preNode = currentNode->prev;
        preNode->next = node;
        node->prev = preNode;
        node->next = currentNode;
        currentNode->prev = node;
    }
}

void DeleteDoublyLinkListByPos(DoublyLinkList* dlList, int pos)
{
    DoublyNode* currentNode = dlList->next;   //取出第一个结点
    int length = dlList->length;  //链表长度
    if(pos >= length)
    {
        printf("您所选择的位置大于链表长度，删除失败\n");
        return;
    }
    if(pos <= 0)
    {
        printf("您所选择的位置小于或等于0，删除失败\n");
        return;
    }

    dlList->length = length - 1;  //删除成功
    for(int i = 1; i < pos; i++)    //找到位置
        currentNode = currentNode->next;

    if(currentNode->prev == NULL)    //前缀结点为空
    {
        dlList->next = currentNode->next;
        (currentNode->next)->prev = NULL;
        printf("删除成功\n");
    }
    else    //前缀结点不为空
    {
        DoublyNode* preNode = currentNode->prev;
        DoublyNode* nxtNode = currentNode->next;
        preNode->next = nxtNode;
        nxtNode->prev = preNode;
        printf("删除成功\n");
    }
}

void DeleteDoublyLinkListByWord(DoublyLinkList* dlList, Word word)
{
    DoublyNode* currentNode = dlList->next;   //取出第一个结点
    int length = dlList->length;  //链表长度
    int pos = 1;
    for(; pos <= length; pos++)
    {
        if(equal(currentNode->word,word)) break;
        currentNode = currentNode->next;
    }
    if(pos == length)
    {
        printf("没有找到这个单词，删除失败\n");
        return;
    }
    dlList->length = length - 1;
    if(currentNode->prev == NULL)    //前缀结点为空
    {
        dlList->next = currentNode->next;
        (currentNode->next)->prev = NULL;
        printf("删除成功\n");
    }
    else    //前缀结点不为空
    {
        DoublyNode* preNode = currentNode->prev;
        DoublyNode* nxtNode = currentNode->next;
        preNode->next = nxtNode;
        nxtNode->prev = preNode;
        printf("删除成功\n");
    }
}

void GetDoublyLinkListElement(DoublyLinkList* dlList, int pos)
{
    DoublyNode* currentNode = dlList->next;   //取出第一个结点
    int length = dlList->length;  //链表长度
    Word result = {"",""};
    if(pos >= length)
    {
        printf("您所选择的位置大于链表长度，查询失败\n");
        return;
    }
    if(pos <= 0)
    {
        printf("您所选择的位置小于或等于0，查询失败\n");
        return;
    }
    printf("查询成功\n");
    for(int i = 1; i < pos; i++)
        currentNode = currentNode->next;
    printf("     英文            中文\n");
    printf("     %s\t      %s\n",currentNode->word.En,currentNode->word.Cn);
}

void PrintDoublyLinkList(DoublyLinkList* dlList)
{
    DoublyNode* currentNode = dlList->next;   //取出第一个结点
    int length = dlList->length - 1;  //链表长度
    printf("开始打印，共 %d 个单词：\n",length);
    printf("     英文               中文\n");
    for(int i = 0; i < length; i++)
    {
        printf("%4d、%-15s%-15s\n",i+1,currentNode->word.En,currentNode->word.Cn);
        currentNode = currentNode->next;
    }
}

void ChangeDoublyLinkElement(DoublyLinkList* dlList, int pos, Word word)
{
    DoublyNode* currentNode = dlList->next;   //取出第一个结点
    int length = dlList->length;  //链表长度
    Word result = {"",""};
    if(pos >= length)
    {
        printf("您所选择的位置大于链表长度，修改失败\n");
        return;
    }
    if(pos <= 0)
    {
        printf("您所选择的位置小于或等于0，修改失败\n");
        return;
    }
    for(int i = 1; i < pos; i++)
        currentNode = currentNode->next;
    currentNode->word = word;
    printf("修改成功\n");
}
