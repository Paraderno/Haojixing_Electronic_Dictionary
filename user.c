/*
 * Created by FallenGemini on 2022/7/13.
 * 用户功能实现
 */
#include "user.h"
#include "public.h"
#include "admin.h"
#include "List.h"
#include "draw.h"
#include <malloc.h>
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
Word EnToCn(WordLinkList* wList, char* En)
{
    WordNode* currentNode = wList->next;   //取出第一个结点
    int length = wList->length;  //链表长度

    int pos = 1;
    for (; pos < length; pos++)
    {
        if (strcmp(currentNode->word.En, En) == 0) break;
        currentNode = currentNode->next;
    }
    if (pos == length)
    {
        printf("没有找到这个单词\n");
        sleep_second(2);
        Word NullWord = {"", ""};
        return NullWord;
    }

    printf("%-10s%-10s\n", currentNode->word.En
        , currentNode->word.Cn);
    return currentNode->word;
}

/** 汉译英 */
void CnToEn(WordLinkList* wList, char* Cn)
{
    WordNode* currentNode = wList->next;   //取出第一个结点
    int length = wList->length;  //链表长度
    int count = 0;
    int pos = 1;
    int X = 5, Y = 10;
    for (; pos <= length; pos++)
    {
        if (strstr(currentNode->word.Cn, Cn) != NULL) {
            SetPosition(X, Y);
            printf("%-15s%-15s\n",currentNode->word.En
                , currentNode->word.Cn);
            Y++;
            count++;
        }
        currentNode = currentNode->next;
    }
    if (count == 0)
    {
        SetPosition(5, 10);
        printf("没有找到这个单词\n");
        return;
    }
}

/** 收藏词汇 */
void Star(WordLinkList* wList, Word currWord) {
    WordLinkList* sList = (WordLinkList*)malloc(sizeof(WordLinkList));
    sList->length = 1;
    sList->next = (WordNode*)malloc(sizeof(WordNode));

    InsertWordLinkList(sList, sList->length, currWord);   // 插入链表
    SaveStarCase(sList);   // 保存（写入）收藏夹
}

/** 管理收藏夹 */
void StarCase(int choice) {
    WordLinkList* sList = (WordLinkList*)malloc(sizeof(WordLinkList));
    sList->length = 1;
    sList->next = (WordNode*)malloc(sizeof(WordNode));

    LoadStarCase(sList);
    // 显示收藏夹内容
    PrintWordLinkList(sList);
    
    if (choice == 1) { // 删除词条
        printf("请输入要删除的英文单词：");

        Word word;
        scanf("%50s", word.En);

        WordNode* currNode = sList->next;
        for ( ; currNode; ) {
            if (strcmp((currNode->word).En, word.En) == 0) {
                strcpy(word.Cn, (currNode->word).Cn);
            }
            currNode = currNode->next;
        }
        DeleteWordLinkListByWord(sList, word);
        SaveStarCase(sList);
    } else {  
        // 退出程序


    }
    
}

/** 载入收藏夹 */
int LoadStarCase(WordLinkList* sList) {
    Word word;
    int size = 0;

    // 打开文件 ("sFile" is short for "StarCase File")
    FILE* sFile = fopen("resource\\StarCase.txt", "r");

    if (sFile == NULL) {
        printf("找不到词库文件！！！\n");
    }
    else {
        // 读入链表
        while (!feof(sFile)) {
            size++;
            fscanf(sFile, "%s %s", word.En, word.Cn);
            // 将词库数据写入空链表
            InsertWordLinkList(sList, size, word);
        }
        //printf("加载数据成功.\n");
    }

    fclose(sFile);
    return 1;
}


/** 保存收藏夹 */
void SaveStarCase(WordLinkList* sList) {
    // 打开文件 ("sFile" is short for "StarCase File")
    FILE* sFile = fopen("resource\\StarCase.txt", "w");
    WordNode* currNode = sList->next;

    // 写入数据
    for (int i = 1; i < sList->length; ++i) {
        if (i != 1)
        {
            fprintf(sFile, "\n");
        }
        fprintf(sFile, "%s %s", currNode->word.En, currNode->word.Cn);
        currNode = currNode->next;
    }
    // printf("保存成功！\n");

    // 关闭文件
    fclose(sFile);
}