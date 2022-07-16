/*
 * Created by FallenGemini on 2022/7/13.
 * 用户功能实现
 */
#include "user.h"
#include "public.h"
#include "admin.h"
#include "List.h"
#pragma warning(disable:4996)

int Register(char* accountID, char* password) {
    AccountNode* AccountListTail = (AccountNode*)malloc(sizeof(AccountNode));
    AccountListTail->next = NULL;
    AccountListTail->prev = NULL;

    /*!
     * 双向链表的头结点
     */
    AccountLinkList* AccountListHead = (AccountLinkList*)malloc(sizeof(AccountLinkList));
    AccountListHead->length = 1;
    AccountListHead->next = AccountListTail;

    Account account;
    AccountLinkList* aList = AccountListHead;

    account.type = USER;
    strcpy(account.ID, accountID);
    strcpy(account.password, password);

    LoadAccountFile(aList);
    InsertAccountLinkList(aList, aList->length, account);
    SaveAccountData(aList);

}

/** 英译汉 */
void EnToCn(WordLinkList* wList, char* En)
{
    WordNode* currentNode = wList->next;   //取出第一个结点
    int length = wList->length;  //链表长度

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

/** 汉译英 */
void CnToEn(WordLinkList* wList, char* Cn)
{
    WordNode* currentNode = wList->next;   //取出第一个结点
    int length = wList->length;  //链表长度
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

/** 收藏词汇 */
void Star(FILE *sPtr);

/** 管理收藏夹 */
void StarCase();