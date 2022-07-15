/*
 * Created by FallenGemini on 2022/7/13.
 * 管理员功能声明
 */
#include "admin.h"
#include "list.h"

/** 新增词库
 * @param
 * @param
 * */
void Add(DoublyLinkList* dlList, char* En, char* Cn)
{
    Word word;
    strcpy(word.En,En);
    strcpy(word.Cn,Cn);
    InsertDoublyLinkList(dlList,dlList->length,word);
}

/** 删除词条
 * @param
 * @param
 * */
void Delete(DoublyLinkList* dlList, char* En, char* Cn)
{
    Word word;
    strcpy(word.En,En);
    strcpy(word.Cn,Cn);
    DeleteDoublyLinkListByWord(dlList,word);
}

/** 修改词条 */
void Modify(DoublyLinkList* dlList, int pos, char* En, char* Cn)
{
    Word word;
    strcpy(word.En,En);
    strcpy(word.Cn,Cn);
    ChangeDoublyLinkElement(dlList, pos, word);
}

/** 保存词库文件修改 */
void SaveDictionary(DoublyLinkList* dlList){
    // 打开文件
    FILE* dFile= fopen("resource\\Dictionary.txt", "w");
    DoublyNode *head = dlList->next;

    // 写入数据
    for (int i = 0; i < dlList->length; ++i) {
        fprintf(dFile,"%s %s\n", head->word.En, head->word.Cn);
        head = head->next;
    }
    printf("词库数据保存成功\n");

    // 关闭文件
    fclose(dFile);
}


/** 保存账户文件修改 */
void SaveAccountData (DoublyLinkList* dlList) {
    // 打开文件
    FILE* aFile = fopen("resource\\Account.txt", "w");
    AccountNode* currNode = dlList->next;

    // 写入数据
    for (int i = 0; i < dlList->length; ++i) {
        fprintf(aFile,"%s %s %d\n", currNode->account.ID, currNode->account.password, currNode->account.type);
        currNode = currNode->next;
    }
    printf("账户数据保存成功\n");

    // 关闭文件
    fclose(aFile);
}