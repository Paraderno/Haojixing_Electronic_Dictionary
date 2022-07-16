/*
 * Created by FallenGemini on 2022/7/13.
 * 管理员功能声明
 */
#include "admin.h"
#include "List.h"
#pragma warning(disable:4996)

 /** 新增词条
  * @param
  * @param
  * */
void Add(WordLinkList* wList, char* En, char* Cn)
{
    Word word;
    strcpy(word.En, En);
    strcpy(word.Cn, Cn);
    InsertWordLinkList(wList, wList->length, word);
}

/** 删除词条
 * @param
 * @param
 * */
void Delete(WordLinkList* wList, char* En, char* Cn)
{
    Word word;
    strcpy(word.En, En);
    strcpy(word.Cn, Cn);
    DeleteWordLinkListByWord(wList, word);
}

/** 修改词条 */
void Modify(WordLinkList* wList, int pos, char* En, char* Cn)
{
    Word word;
    strcpy(word.En, En);
    strcpy(word.Cn, Cn);
    InsertWordLinkList(wList, pos, word);
}

/** 保存词库文件修改 */
void SaveDictionary(WordLinkList* wList) {
    // 打开文件
    FILE* dFile = fopen("resource\\Dictionary.txt", "w");
    WordNode* head = wList->next;

    // 写入数据
    for (int i = 0; i < wList->length; ++i) {
        fprintf(dFile, "%s %s\n", head->word.En, head->word.Cn);
        head = head->next;
    }
    printf("词库数据保存成功\n");

    // 关闭文件
    fclose(dFile);
}


/** 保存账户文件修改 */
void SaveAccountData(AccountLinkList* aList) {
    // 打开文件
    FILE* aFile = fopen("resource\\Account.txt", "w");
    AccountNode* currNode = aList->next;

    // 写入数据
    for (int i = 1; i < aList->length; ++i) {
        fprintf(aFile, "%s %s %d\n", currNode->account.ID, currNode->account.password, currNode->account.type);
        currNode = currNode->next;
    }
    printf("账户数据保存成功\n");

    // 关闭文件
    fclose(aFile);
}