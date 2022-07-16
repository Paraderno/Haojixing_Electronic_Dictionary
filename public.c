/*
 * Created by FallenGemini on 2022/7/13.
 * ��������ʵ��
 */

#include <stdio.h>
#include <malloc.h>
#include "public.h"
#include "admin.h"
#pragma warning(disable:4996)

 /** ����ʿ� */
void LoadDictionary(WordLinkList* wList) {
    Word word;
    int size = 0;

    // ���ļ� ("dFile" is short for "dictionary file")
    FILE* dFile = fopen("resource\\Dictionary.txt", "r");

    if (dFile == NULL) {
        printf("�ʿ��ļ���ʧ������\n");
    }
    else {
        // ��������
        while (!feof(dFile)) {
            size++;
            fscanf(dFile, "%s %s", word.En, word.Cn);
            // ���ʿ�����д�������
            InsertWordLinkList(wList, size, word);
        }
        printf("�������ݳɹ�.\n");
    }

    fclose(dFile);
}

/** �����˻���Ϣ���� */
int LoadAccountFile(AccountLinkList* aList) {
    Account account;
    int size = 0;
    int flag = 0;
    // ���ļ� ("aFile" is short for "account file")
    FILE* aFile = fopen("resource\\Account.txt", "r");

    if (aFile == NULL) {
        printf("�˻���Ϣ�ļ���ʧ������");
        flag = 0;
    }
    else {
        // ��������
        while (!feof(aFile)) {
            size++;
            fscanf(aFile, "%s %s %d", account.ID, account.password, &account.type);
            // ���˻���Ϣ����д�������
            InsertAccountLinkList(aList, size, account);
        }
        flag = 1;
    }

    fclose(aFile);
    return flag;
}


/** ��¼�˻� */
int LogIn(AccountLinkList* aList, int type, char* accountID, char* password)
{
    Account account;  // ��Ŷ�����˻�����
    account.type = type;
    strcpy(account.ID, accountID);
    strcpy(account.password, password);

    AccountNode* currNode = aList->next;
    int countEqual;
    for (countEqual = 0; currNode; currNode = currNode->next) {
        isAccountEqual(account, currNode->account) ? countEqual = 1 : 0;
    }

    // countEqual ֵֻ��Ϊ 1 �� 0��
    // Ϊ 1 �� ���ҵ�����˻�����¼�ɹ�
    // Ϊ 0 �� δ���ҵ�����˻�����½ʧ��
    return countEqual;
}

/** ע���û� */
int LogOut(AccountLinkList* aList, int type, char* accountID, char* password)
{
    Account account;  // ��Ŷ�����˻�����
    account.type = type;
    strcpy(account.ID, accountID);
    strcpy(account.password, password);
    int countEqual = 0;

    while (DeleteAccountData(aList, account) == 1)
        countEqual++;

    return countEqual;
}

/** ��ʼ�˵� */
void InitialMenu() {}

/** �����㷨 */
void FuzzySearch(WordLinkList* wList, char* En)
{
    WordNode* currentNode = wList->next;   //ȡ����һ�����
    int length = wList->length;  //������
    int count = 0;
    int pos = 1;
    for (; pos <= length; pos++)
    {
        if (strstr(currentNode->word.En, En) != NULL) {
            printf("���������������ʣ�%s, %s\n", currentNode->word.En,
                currentNode->word.Cn);
            count++;
        }
        currentNode = currentNode->next;
    }
    if (count == 0)
    {
        printf("û���ҵ��������.\n");
        return;
    }
}

/** �˳����� */
void Exit(FILE* rPtr)
{

}