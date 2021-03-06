/*
 * Created by FallenGemini on 2022/7/13.
 * 公共功能实现
 */

#include <stdio.h>
#include <malloc.h>
#include "public.h"
#include "admin.h"
#pragma warning(disable:4996)

 /** 载入词库 */
int LoadDictionary(WordLinkList* wList) {
    Word word;
    int size = 0;

    // 打开文件 ("dFile" is short for "dictionary file")
    FILE* dFile = fopen("resource\\Dictionary.txt", "r");

    if (dFile == NULL) {
        printf("词库文件丢失！！！\n");
        return 0;
    }
    else {
        // 读入链表
        while (!feof(dFile)) {
            size++;
            fscanf(dFile, "%s %s", word.En, word.Cn);
            // 将词库数据写入空链表
            InsertWordLinkList(wList, size, word);
        }
        printf("加载数据成功.\n");
    }

    fclose(dFile);
    return 1;
}

/** 载入账户信息数据 */
int LoadAccountFile(AccountLinkList* aList) {
    Account account;
    int size = 0;
    int flag = 0;
    // 打开文件 ("aFile" is short for "account file")
    FILE* aFile = fopen("resource\\Account.txt", "r");

    if (aFile == NULL) {
        printf("账户信息文件丢失！！！");
        flag = 0;
    }
    else {
        // 读入链表
        while (!feof(aFile)) {
            size++;
            fscanf(aFile, "%s %s %d", account.ID, account.password, &account.type);
            // 将账户信息数据写入空链表
            InsertAccountLinkList(aList, size, account);
        }
        flag = 1;
    }

    fclose(aFile);
    return flag;
}


/** 登录账户 */
int LogIn(AccountLinkList* aList, int type, char* accountID, char* password)
{
    Account account;  // 存放读入的账户数据
    account.type = type;
    strcpy(account.ID, accountID);
    strcpy(account.password, password);

    AccountNode* currNode = aList->next;
    int countEqual;
    for (countEqual = 0; currNode; currNode = currNode->next) {
        isAccountEqual(account, currNode->account) ? countEqual = 1 : 0;
    }

    // countEqual 值只能为 1 或 0；
    // 为 1 ： 查找到相符账户，登录成功
    // 为 0 ： 未查找到相符账户，登陆失败
    return countEqual;
}

/** 注销用户 */
int LogOut(AccountLinkList* aList, int type, char* accountID, char* password)
{
    Account account;  // 存放读入的账户数据
    account.type = type;
    strcpy(account.ID, accountID);
    strcpy(account.password, password);
    int countEqual = 0;

    while (DeleteAccountData(aList, account) == 1)
        countEqual++;
    
    return countEqual;
}

/** 初始菜单 */
void InitialMenu() {}

/** 查找算法 */
void FuzzySearch(WordLinkList* wList, char* En)
{
    WordNode* currentNode = wList->next;   //取出第一个结点
    int length = wList->length;  //链表长度
    int count = 0;
    int pos = 1;
    for (; pos <= length; pos++)
    {
        if (strstr(currentNode->word.En, En) != NULL) {
            printf("你可能在找这个单词？%s, %s\n", currentNode->word.En,
                currentNode->word.Cn);
            count++;
        }
        currentNode = currentNode->next;
    }
    if (count == 0)
    {
        printf("没有找到这个单词.\n");
        return;
    }
}

/** 退出程序 */
void Exit(FILE* rPtr)
{

}