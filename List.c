/*
 * Created by FallenGemini on 2022/7/14.
 * ������غ���
 */
#include <stdio.h>
#include <malloc.h>
#include "List.h"

void InsertDoublyLinkList(DoublyLinkList* dlList, int pos, Word word) {
    DoublyNode* currentNode = dlList->next;   //ȡ����һ�����
    int length = dlList->length;  //������
    DoublyNode* node = (DoublyNode*)malloc(sizeof(DoublyNode));
    node->word = word; node->prev = NULL; node->next = NULL;    //�½�һ���ڵ�

    if(pos > length)
    {
        printf("����ѡ���λ�ô��������ȣ�����ʧ��\n");
        return;
    }
    if(pos <= 0)
    {
        printf("����ѡ���λ��С�ڻ����0������ʧ��\n");
        return;
    }

    dlList->length = length + 1;  //����ɹ�

    for(int i = 1; i < pos; i++)    //�ҵ�λ��
        currentNode = currentNode->next;

    if(currentNode->prev == NULL)    //ǰ׺���Ϊ��
    {
        currentNode->prev = node;
        node->next = currentNode;
        dlList->next = node;
        printf("����ɹ�\n");
    }
    else    //ǰ׺��㲻Ϊ��
    {
        DoublyNode* preNode = currentNode->prev;
        preNode->next = node;
        node->prev = preNode;
        node->next = currentNode;
        currentNode->prev = node;
        printf("����ɹ�\n");
    }
}

void DeleteDoublyLinkList(DoublyLinkList* dlList, int pos)
{
    DoublyNode* currentNode = dlList->next;   //ȡ����һ�����
    int length = dlList->length;  //������
    if(pos >= length)
    {
        printf("����ѡ���λ�ô��������ȣ�ɾ��ʧ��\n");
        return;
    }
    if(pos <= 0)
    {
        printf("����ѡ���λ��С�ڻ����0��ɾ��ʧ��\n");
        return;
    }

    dlList->length = length - 1;  //ɾ���ɹ�
    for(int i = 1; i < pos; i++)    //�ҵ�λ��
        currentNode = currentNode->next;

    if(currentNode->prev == NULL)    //ǰ׺���Ϊ��
    {
        dlList->next = currentNode->next;
        (currentNode->next)->prev = NULL;
        printf("ɾ���ɹ�\n");
    }
    else    //ǰ׺��㲻Ϊ��
    {
        DoublyNode* preNode = currentNode->prev;
        DoublyNode* nxtNode = currentNode->next;
        preNode->next = nxtNode;
        nxtNode->prev = preNode;
        printf("ɾ���ɹ�\n");
    }
}

void GetDoublyLinkListElement(DoublyLinkList* dlList, int pos)
{
    DoublyNode* currentNode = dlList->next;   //ȡ����һ�����
    int length = dlList->length;  //������
    Word result = {"",""};
    if(pos >= length)
    {
        printf("����ѡ���λ�ô��������ȣ���ѯʧ��\n");
        return;
    }
    if(pos <= 0)
    {
        printf("����ѡ���λ��С�ڻ����0����ѯʧ��\n");
        return;
    }
    printf("��ѯ�ɹ�\n");
    for(int i = 1; i < pos; i++)
        currentNode = currentNode->next;
    printf("     Ӣ��        ����       ����\n");
    printf("     %s\t   %s     %s\n",currentNode->word.En,currentNode->word.attribute,currentNode->word.Cn);
}

void PrintDoublyLinkList(DoublyLinkList* dlList)
{
    DoublyNode* currentNode = dlList->next;   //ȡ����һ�����
    int length = dlList->length - 1;  //������
    printf("��ʼ��ӡ���� %d �����ʣ�\n",length);
    printf("     Ӣ��        ����       ����\n");
    for(int i = 0; i < length; i++)
    {
        printf("%4d:%s\t%s\t%s\n",i+1,currentNode->word.En,currentNode->word.attribute,currentNode->word.Cn);
        currentNode = currentNode->next;
    }
}

void ChangeDoublyLinkElement(DoublyLinkList* dlList, int pos, Word word)
{
    DoublyNode* currentNode = dlList->next;   //ȡ����һ�����
    int length = dlList->length;  //������
    Word result = {"",""};
    if(pos >= length)
    {
        printf("����ѡ���λ�ô��������ȣ��޸�ʧ��\n");
        return;
    }
    if(pos <= 0)
    {
        printf("����ѡ���λ��С�ڻ����0���޸�ʧ��\n");
        return;
    }
    for(int i = 1; i < pos; i++)
        currentNode = currentNode->next;
    currentNode->word = word;
    printf("�޸ĳɹ�\n");
}
