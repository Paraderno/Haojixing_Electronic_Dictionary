/*
 * Created by FallenGemini on 2022/7/13.
 * �û�����ʵ��
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

/** Ӣ�뺺 */
void EnToCn(WordLinkList* wList, char* En)
{
    WordNode* currentNode = wList->next;   //ȡ����һ�����
    int length = wList->length;  //������

    int pos = 1;
    for (; pos <= length; pos++)
    {
        if (strcmp(currentNode->word.En, En) == 0) break;
        currentNode = currentNode->next;
    }
    if (pos == length)
    {
        printf("û���ҵ��������\n");
        return;
    }

    printf("%-10s%-10s\n", currentNode->word.En
        , currentNode->word.Cn);
}

/** ����Ӣ */
void CnToEn(WordLinkList* wList, char* Cn)
{
    WordNode* currentNode = wList->next;   //ȡ����һ�����
    int length = wList->length;  //������
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
        printf("û���ҵ��������\n");
        return;
    }
}

/** �ղشʻ� */
void Star(FILE* sPtr);

/** �����ղؼ� */
void StarCase();