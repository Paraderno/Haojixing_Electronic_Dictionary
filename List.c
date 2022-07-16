/*
 * Created by FallenGemini on 2022/7/14.
 * ������غ���
 */
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "List.h"

 /** �Ƚ����������Ƿ���ͬ */
int isWordEqual(Word word1, Word word2) {
    int flag = TRUE;
    if (strcmp(word1.En, word2.En) != 0) flag = FALSE;
    if (strcmp(word1.Cn, word2.Cn) != 0) flag = FALSE;
    return flag;
}

/** �Ƚ������˻���Ϣ�Ƿ���ͬ */
int isAccountEqual(Account account1, Account account2) {
    int flag = TRUE;

    if (account1.type != account2.type) { flag = FALSE; }
    if (strcmp(account1.ID, account2.ID) != 0) { flag = FALSE; }
    if (strcmp(account1.password, account2.password) != 0) { flag = FALSE; }

    return flag;
}


/** �ڴ���������ָ��λ�ò���һ��Ԫ�� */
void InsertWordLinkList(WordLinkList* wList, int pos, Word word) {
    WordNode* currentNode = wList->next;   //ȡ����һ�����
    int length = wList->length;  //������
    WordNode* node = (WordNode*)malloc(sizeof(WordNode));
    node->word = word; node->prev = NULL; node->next = NULL;    //�½�һ���ڵ�

    if (pos > length)
    {
        printf("����ѡ���λ�ô��������ȣ�����ʧ��\n");
        return;
    }
    if (pos <= 0)
    {
        printf("����ѡ���λ��С�ڻ����0������ʧ��\n");
        return;
    }

    wList->length = length + 1;  //����ɹ�

    for (int i = 1; i < pos; i++)    //�ҵ�λ��
        currentNode = currentNode->next;

    if (currentNode->prev == NULL)    //ǰ׺���Ϊ��
    {
        currentNode->prev = node;
        node->next = currentNode;
        wList->next = node;
    }
    else    //ǰ׺��㲻Ϊ��
    {
        WordNode* preNode = currentNode->prev;
        preNode->next = node;
        node->prev = preNode;
        node->next = currentNode;
        currentNode->prev = node;
    }
}

/** ���˻���Ϣ������ָ��λ�ò���һ��Ԫ�� */
void InsertAccountLinkList(AccountLinkList* aList, int pos, Account account) {
    AccountNode* currentNode = aList->next;   //ȡ����һ�����
    int length = aList->length;  //������
    AccountNode* node = (AccountNode*)malloc(sizeof(AccountNode));
    node->account = account; node->prev = NULL; node->next = NULL;    //�½�һ���ڵ�

    if (pos > length)
    {
        printf("����ѡ���λ�ô��������ȣ�����ʧ��\n");
        return;
    }
    if (pos <= 0)
    {
        printf("����ѡ���λ��С�ڻ����0������ʧ��\n");
        return;
    }

    aList->length = length + 1;  //����ɹ�

    for (int i = 1; i < pos; i++)    //�ҵ�λ��
        currentNode = currentNode->next;

    if (currentNode->prev == NULL)    //ǰ׺���Ϊ��
    {
        currentNode->prev = node;
        node->next = currentNode;
        aList->next = node;
    }
    else    //ǰ׺��㲻Ϊ��
    {
        AccountNode* preNode = currentNode->prev;
        preNode->next = node;
        node->prev = preNode;
        node->next = currentNode;
        currentNode->prev = node;
    }
}

/** ɾ����������ָ��λ�õ�Ԫ�� */
void DeleteWordLinkListByPos(WordLinkList* wList, int pos)
{
    WordNode* currentNode = wList->next;   //ȡ����һ�����
    int length = wList->length;  //������
    if (pos >= length)
    {
        printf("����ѡ���λ�ô��������ȣ�ɾ��ʧ��\n");
        return;
    }
    if (pos <= 0)
    {
        printf("����ѡ���λ��С�ڻ����0��ɾ��ʧ��\n");
        return;
    }

    wList->length = length - 1;  //ɾ���ɹ�
    for (int i = 1; i < pos; i++)    //�ҵ�λ��
        currentNode = currentNode->next;

    if (currentNode->prev == NULL)    //ǰ׺���Ϊ��
    {
        wList->next = currentNode->next;
        currentNode->next->prev = NULL;
        printf("ɾ���ɹ�\n");
    }
    else    //ǰ׺��㲻Ϊ��
    {
        WordNode* preNode = currentNode->prev;
        WordNode* nxtNode = currentNode->next;
        preNode->next = nxtNode;
        nxtNode->prev = preNode;
        printf("ɾ���ɹ�\n");
    }
}

/** ɾ����������ָ��Ԫ�� */
void DeleteWordLinkListByWord(WordLinkList* wList, Word word)
{
    WordNode* currentNode = wList->next;   //ȡ����һ�����
    int length = wList->length;  //������
    int pos = 1;
    for (; pos <= length; pos++)
    {
        if (isWordEqual(currentNode->word, word)) break;
        currentNode = currentNode->next;
    }
    if (pos == length)
    {
        printf("û���ҵ�������ʣ�ɾ��ʧ��\n");
        return;
    }
    wList->length = length - 1;
    if (currentNode->prev == NULL)    //ǰ׺���Ϊ��
    {
        wList->next = currentNode->next;
        (currentNode->next)->prev = NULL;
        printf("ɾ���ɹ�\n");
    }
    else    //ǰ׺��㲻Ϊ��
    {
        WordNode* preNode = currentNode->prev;
        WordNode* nxtNode = currentNode->next;
        preNode->next = nxtNode;
        nxtNode->prev = preNode;
        printf("ɾ���ɹ�\n");
    }
}

/** ɾ���˻���Ϣ����ָ��Ԫ�� */
void DeleteAccountData(AccountLinkList* aList, Account account) {
    AccountNode* currentNode = aList->next;   //ȡ����һ�����
    int length = aList->length;  //������
    int pos = 1;
    for (; pos <= length; pos++)
    {
        if (isAccountEqual(currentNode->account, account)) break;
        currentNode = currentNode->next;
    }
    if (pos == length)
    {
        printf("û���ҵ�������ʣ�ɾ��ʧ��\n");
        return;
    }
    aList->length = length - 1;
    if (currentNode->prev == NULL)    //ǰ׺���Ϊ��
    {
        aList->next = currentNode->next;
        (currentNode->next)->prev = NULL;
        printf("ɾ���ɹ�\n");
    }
    else    //ǰ׺��㲻Ϊ��
    {
        AccountNode* preNode = currentNode->prev;
        AccountNode* nxtNode = currentNode->next;
        preNode->next = nxtNode;
        nxtNode->prev = preNode;
        printf("ɾ���ɹ�\n");
    }
}

/** ��ѯ����ָ��λ�õ�Ԫ�� */
void GetWordLinkListElement(WordLinkList* wList, int pos)
{
    WordNode* currentNode = wList->next;   //ȡ����һ�����
    int length = wList->length;  //������
    Word result = { "","" };
    if (pos >= length)
    {
        printf("����ѡ���λ�ô��������ȣ���ѯʧ��\n");
        return;
    }
    if (pos <= 0)
    {
        printf("����ѡ���λ��С�ڻ����0����ѯʧ��\n");
        return;
    }
    printf("��ѯ�ɹ�\n");
    for (int i = 1; i < pos; i++)
        currentNode = currentNode->next;
    printf("     Ӣ��            ����\n");
    printf("     %s\t      %s\n", currentNode->word.En, currentNode->word.Cn);
}

/** ��ӡ�������� */
void PrintWordLinkList(WordLinkList* wList)
{
    WordNode* currentNode = wList->next;   //ȡ����һ�����
    int length = wList->length - 1;  //������
    printf("��ʼ��ӡ���� %d �����ʣ�\n", length);
    printf("     Ӣ��               ����\n");
    for (int i = 0; i < length; i++)
    {
        printf("%4d��%-15s%-15s\n", i + 1, currentNode->word.En, currentNode->word.Cn);
        currentNode = currentNode->next;
    }
}

/** �޸Ĵ�������ָ��λ�õ�Ԫ�� */
void ChangeWordListElement(WordLinkList* wList, int pos, Word word)
{
    WordNode* currentNode = wList->next;   //ȡ����һ�����
    int length = wList->length;  //������
    Word result = { "","" };
    if (pos >= length)
    {
        printf("����ѡ���λ�ô��������ȣ��޸�ʧ��\n");
        return;
    }
    if (pos <= 0)
    {
        printf("����ѡ���λ��С�ڻ����0���޸�ʧ��\n");
        return;
    }
    for (int i = 1; i < pos; i++)
        currentNode = currentNode->next;
    currentNode->word = word;
    printf("�޸ĳɹ�\n");
}