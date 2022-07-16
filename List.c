/*
 * Created by FallenGemini on 2022/7/14.
 * 链表及相关函数
 */
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "List.h"

 /** 比较两个单词是否相同 */
int isWordEqual(Word word1, Word word2) {
    int flag = TRUE;
    if (strcmp(word1.En, word2.En) != 0) flag = FALSE;
    if (strcmp(word1.Cn, word2.Cn) != 0) flag = FALSE;
    return flag;
}

/** 比较两条账户信息是否相同 */
int isAccountEqual(Account account1, Account account2) {
    int flag = TRUE;

    if (account1.type != account2.type) { flag = FALSE; }
    if (strcmp(account1.ID, account2.ID) != 0) { flag = FALSE; }
    if (strcmp(account1.password, account2.password) != 0) { flag = FALSE; }

    return flag;
}


/** 在词条链表中指定位置插入一个元素 */
void InsertWordLinkList(WordLinkList* wList, int pos, Word word) {
    WordNode* currentNode = wList->next;   //取出第一个结点
    int length = wList->length;  //链表长度
    WordNode* node = (WordNode*)malloc(sizeof(WordNode));
    node->word = word; node->prev = NULL; node->next = NULL;    //新建一个节点

    if (pos > length)
    {
        printf("您所选择的位置大于链表长度，插入失败\n");
        return;
    }
    if (pos <= 0)
    {
        printf("您所选择的位置小于或等于0，插入失败\n");
        return;
    }

    wList->length = length + 1;  //插入成功

    for (int i = 1; i < pos; i++)    //找到位置
        currentNode = currentNode->next;

    if (currentNode->prev == NULL)    //前缀结点为空
    {
        currentNode->prev = node;
        node->next = currentNode;
        wList->next = node;
    }
    else    //前缀结点不为空
    {
        WordNode* preNode = currentNode->prev;
        preNode->next = node;
        node->prev = preNode;
        node->next = currentNode;
        currentNode->prev = node;
    }
}

/** 在账户信息链表中指定位置插入一个元素 */
void InsertAccountLinkList(AccountLinkList* aList, int pos, Account account) {
    AccountNode* currentNode = aList->next;   //取出第一个结点
    int length = aList->length;  //链表长度
    AccountNode* node = (AccountNode*)malloc(sizeof(AccountNode));
    node->account = account; node->prev = NULL; node->next = NULL;    //新建一个节点

    if (pos > length)
    {
        printf("您所选择的位置大于链表长度，插入失败\n");
        return;
    }
    if (pos <= 0)
    {
        printf("您所选择的位置小于或等于0，插入失败\n");
        return;
    }

    aList->length = length + 1;  //插入成功

    for (int i = 1; i < pos; i++)    //找到位置
        currentNode = currentNode->next;

    if (currentNode->prev == NULL)    //前缀结点为空
    {
        currentNode->prev = node;
        node->next = currentNode;
        aList->next = node;
    }
    else    //前缀结点不为空
    {
        AccountNode* preNode = currentNode->prev;
        preNode->next = node;
        node->prev = preNode;
        node->next = currentNode;
        currentNode->prev = node;
    }
}

/** 删除词条链表指定位置的元素 */
void DeleteWordLinkListByPos(WordLinkList* wList, int pos)
{
    WordNode* currentNode = wList->next;   //取出第一个结点
    int length = wList->length;  //链表长度
    if (pos >= length)
    {
        printf("您所选择的位置大于链表长度，删除失败\n");
        return;
    }
    if (pos <= 0)
    {
        printf("您所选择的位置小于或等于0，删除失败\n");
        return;
    }

    wList->length = length - 1;  //删除成功
    for (int i = 1; i < pos; i++)    //找到位置
        currentNode = currentNode->next;

    if (currentNode->prev == NULL)    //前缀结点为空
    {
        wList->next = currentNode->next;
        currentNode->next->prev = NULL;
        printf("删除成功\n");
    }
    else    //前缀结点不为空
    {
        WordNode* preNode = currentNode->prev;
        WordNode* nxtNode = currentNode->next;
        preNode->next = nxtNode;
        nxtNode->prev = preNode;
        printf("删除成功\n");
    }
}

/** 删除词条链表指定元素 */
void DeleteWordLinkListByWord(WordLinkList* wList, Word word)
{
    WordNode* currentNode = wList->next;   //取出第一个结点
    int length = wList->length;  //链表长度
    int pos = 1;
    for (; pos <= length; pos++)
    {
        if (isWordEqual(currentNode->word, word)) break;
        currentNode = currentNode->next;
    }
    if (pos == length)
    {
        printf("没有找到这个单词，删除失败\n");
        return;
    }
    wList->length = length - 1;
    if (currentNode->prev == NULL)    //前缀结点为空
    {
        wList->next = currentNode->next;
        (currentNode->next)->prev = NULL;
        printf("删除成功\n");
    }
    else    //前缀结点不为空
    {
        WordNode* preNode = currentNode->prev;
        WordNode* nxtNode = currentNode->next;
        preNode->next = nxtNode;
        nxtNode->prev = preNode;
        printf("删除成功\n");
    }
}

/** 删除账户信息链表指定元素 */
void DeleteAccountData(AccountLinkList* aList, Account account) {
    AccountNode* currentNode = aList->next;   //取出第一个结点
    int length = aList->length;  //链表长度
    int pos = 1;
    for (; pos <= length; pos++)
    {
        if (isAccountEqual(currentNode->account, account)) break;
        currentNode = currentNode->next;
    }
    if (pos == length)
    {
        printf("没有找到这个单词，删除失败\n");
        return;
    }
    aList->length = length - 1;
    if (currentNode->prev == NULL)    //前缀结点为空
    {
        aList->next = currentNode->next;
        (currentNode->next)->prev = NULL;
        printf("删除成功\n");
    }
    else    //前缀结点不为空
    {
        AccountNode* preNode = currentNode->prev;
        AccountNode* nxtNode = currentNode->next;
        preNode->next = nxtNode;
        nxtNode->prev = preNode;
        printf("删除成功\n");
    }
}

/** 查询链表指定位置的元素 */
void GetWordLinkListElement(WordLinkList* wList, int pos)
{
    WordNode* currentNode = wList->next;   //取出第一个结点
    int length = wList->length;  //链表长度
    Word result = { "","" };
    if (pos >= length)
    {
        printf("您所选择的位置大于链表长度，查询失败\n");
        return;
    }
    if (pos <= 0)
    {
        printf("您所选择的位置小于或等于0，查询失败\n");
        return;
    }
    printf("查询成功\n");
    for (int i = 1; i < pos; i++)
        currentNode = currentNode->next;
    printf("     英文            中文\n");
    printf("     %s\t      %s\n", currentNode->word.En, currentNode->word.Cn);
}

/** 打印整个链表 */
void PrintWordLinkList(WordLinkList* wList)
{
    WordNode* currentNode = wList->next;   //取出第一个结点
    int length = wList->length - 1;  //链表长度
    printf("开始打印，共 %d 个单词：\n", length);
    printf("     英文               中文\n");
    for (int i = 0; i < length; i++)
    {
        printf("%4d、%-15s%-15s\n", i + 1, currentNode->word.En, currentNode->word.Cn);
        currentNode = currentNode->next;
    }
}

/** 修改词条链表指定位置的元素 */
void ChangeWordListElement(WordLinkList* wList, int pos, Word word)
{
    WordNode* currentNode = wList->next;   //取出第一个结点
    int length = wList->length;  //链表长度
    Word result = { "","" };
    if (pos >= length)
    {
        printf("您所选择的位置大于链表长度，修改失败\n");
        return;
    }
    if (pos <= 0)
    {
        printf("您所选择的位置小于或等于0，修改失败\n");
        return;
    }
    for (int i = 1; i < pos; i++)
        currentNode = currentNode->next;
    currentNode->word = word;
    printf("修改成功\n");
}