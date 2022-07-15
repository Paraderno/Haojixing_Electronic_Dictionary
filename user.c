/*
 * Created by FallenGemini on 2022/7/13.
 * 用户功能实现
 */
#include "user.h"

int Register();

/** 英译汉 */
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

/** 汉译英 */
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

/** 收藏词汇 */
void Star(FILE *sPtr);

/** 管理收藏夹 */
void StarCase();