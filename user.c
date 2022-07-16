/*
 * Created by FallenGemini on 2022/7/13.
 * 用户功能实现
 */
#include "user.h"
#include "public.h"
#include "admin.h"
#include "List.h"
#pragma warning(disable:4996)

int Register(AccountLinkList* aList, char* accountID, char* password) {
    Account account;
    account.type = USER;
    strcpy(account.ID, accountID);
    strcpy(account.password, password);
    InsertAccountLinkList(aList, aList->length, account);
    SaveAccountData(aList);
    return 1;
}

/** 英译汉 */
void EnToCn(WordLinkList* wList, char* En)
{
    WordNode* currentNode = wList->next;   //取出第一个结点
    int length = wList->length;  //链表长度

    int pos = 1;
    for (; pos <= length; pos++)
    {
        if (strcmp(currentNode->word.En, En) == 0) break;
        currentNode = currentNode->next;
    }
    if (pos == length)
    {
        printf("没有找到这个单词\n");
        return;
    }

    printf("单词 %s 中文释义为 %s\n", currentNode->word.En
        , currentNode->word.Cn);
}

/** 汉译英 */
void CnToEn(WordLinkList* wList, char* Cn)
{
    WordNode* currentNode = wList->next;   //取出第一个结点
    int length = wList->length;  //链表长度
    int count = 0;
    int pos = 1;
    for (; pos <= length; pos++)
    {
        if (strstr(currentNode->word.Cn, Cn) != NULL) {
            printf("中文释义为 %s  词性为 %s，\n", currentNode->word.Cn,
                currentNode->word.En);
            count++;
        }
        currentNode = currentNode->next;
    }
    if (count == 0)
    {
        printf("没有找到这个单词\n");
        return;
    }
}

/** 收藏词汇 */
void Star(FILE* sPtr);

/** 管理收藏夹 */
void StarCase();