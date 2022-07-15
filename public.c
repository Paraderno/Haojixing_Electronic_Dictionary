/*
 * Created by FallenGemini on 2022/7/13.
 * ��������ʵ��
 */

#include <stdio.h>
#include <malloc.h>
#include "public.h"

/** ����ʿ� */
void LoadDictionary (DoublyLinkList* dlList) {
    Word word;
    int size=0;

    // ���ļ� ("dFile" is short for "dictionary file")
    FILE* dFile = fopen("resource\\Dictionary.txt", "r");

    if ( dFile == NULL ) {
        printf("�ʿ��ļ���ʧ������\n");
    } else {
        // ��������
        while( !feof(dFile) ) {
            size++;
            fscanf(dFile, "%s %s", word.En, word.Cn);
            // ���ʿ�����д�������
            InsertDoublyLinkList(dlList, size, word);
        }
        printf("�������ݳɹ�.\n");
    }

    fclose(dFile);
}

/** �����˻���Ϣ���� */
void LoadAccountFile (DoublyLinkList* dlList) {
    Account account;
    int size = 0;

    // ���ļ� ("aFile" is short for "account file")
    FILE* aFile = fopen("resource\\Account.txt", "r");

    if (aFile == NULL) {
        printf("�˻���Ϣ�ļ���ʧ������");
    } else {
        // ��������
        while( !feof(aFile) ) {
            size++;
            fscanf(aFile, "%s %s %d", account.ID, account.password, &account.type);
            // ���˻���Ϣ����д�������
            InsertAccountLinkList(dlList, size, account);
        }
        printf("�������ݳɹ�.\n");
    }

    fclose(aFile);
}


/** ��¼�˻� */
int LogIn(int type, char* accountID, char* password)
{
    Account account;  // ��Ŷ�����˻�����

    /*
    printf("�������˻����ͣ�1����Ա 2��ͨ�û�����");
    scanf("%d", &account.type);
    printf("�����������û�ID��");
    scanf("%s", account.ID);
    printf("�����������û����룺");
    scanf("%s", account.password);
     */

    DoublyLinkList* dlLinkList;
    LoadAccountFile(dlLinkList);

    AccountNode* currNode = dlLinkList->next;
    int countEqual;
    for (countEqual = 0; currNode ; ) {
        isAccountEqual(account, currNode->account) ? countEqual++ : 0;
    }

    // countEqual ֵֻ��Ϊ 1 �� 0��
    // Ϊ 1 �� ���ҵ�����˻�����¼�ɹ�
    // Ϊ 0 �� δ���ҵ�����˻�����½ʧ��
    return countEqual;
}

/** �˳���¼ */
int quit();

/** ע���û� */
int LogOut(int type, char* accountID, char* password)
{
    Account account;  // ��Ŷ�����˻�����

    /*
    printf("�����뵱ǰ�˻����ͣ�1����Ա 2��ͨ�û�����");
    scanf("%d", &account.type);
    printf("�����뵱ǰʹ�õĵ��˻�ID��");
    scanf("%s", account.ID);
    printf("�����뵱ǰʹ�õĵ��˻����룺");
    scanf("%s", account.password);
    */

    DoublyLinkList* dlLinkList;
    LoadAccountFile(dlLinkList);

    AccountNode* currNode = dlLinkList->next;
    int countEqual = 0;
    for (int i = 1; currNode ; i++) {
        if (isAccountEqual(account, currNode->account)) {
            DeleteDoublyLinkListByPos(dlLinkList, i);
            countEqual++;
        }
    }
    SaveAccountData(dlLinkList);

    return countEqual;
}

/** ��ʼ�˵� */
void InitialMenu()
{

}

/** �����㷨 */
void FuzzySearch(DoublyLinkList* dlList, char* En)
{
    DoublyNode* currentNode = dlList->next;   //ȡ����һ�����
    int length = dlList->length;  //������
    int count = 0;
    int pos = 1;
    for(; pos <= length; pos++)
    {
        if(strstr(currentNode->word.En,En) != NULL) {
            printf("���������������ʣ�%s %s%s��\n", currentNode->word.En,
                   currentNode->word.Cn);
            count++;
        }
        currentNode = currentNode->next;
    }
    if(count == 0)
    {
        printf("û���ҵ��������\n");
        return;
    }
}

/** �˳����� */
void Exit(FILE* rPtr)
{

}