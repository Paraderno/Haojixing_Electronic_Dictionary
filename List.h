/*
 * Created by FallenGemini on 2022/7/14.
 * ������غ���
 */

#ifndef HAOJIXING_ELECTRONIC_DICTIONARY_LIST_H
#define HAOJIXING_ELECTRONIC_DICTIONARY_LIST_H

#include <string.h>

#define TRUE 1
#define FALSE 0

// �˻����� ��ͨ�û�USER ����ԱADMIN
#define USER 0
#define ADMIN 1

#define SIZE_ID 10
#define SIZE_PW 20

/*!
 * ���ʴ���������Ӣ�� En������������ Cn
 */
typedef struct word
{
    char En[50];
    char Cn[50];
}Word;

/*!
 * �˻���Ϣ��¼������ID�����롢�˻�����
 */
typedef struct account{
    char ID[SIZE_ID];
    char password[SIZE_PW];
    int type;   // �˻����� ��ͨ�û�USER ����ԱADMIN
}Account;

/*!
 * ��������Ľ��
 * ����һ������������ָ����
 */
typedef struct DoublyNode
{
    Word word;
    struct DoublyNode* prev;   //ָ��ǰ׺���
    struct DoublyNode* next;   //ָ���̽��
}DoublyNode;

/*!
 * �˻���Ϣ��¼����Ľ��
 * ����һ������������ָ����
 */
typedef struct AccountNode
{
    Account account;
    struct DoublyNode* prev;   //ָ��ǰ׺���
    struct DoublyNode* next;   //ָ���̽��
}AccountNode;

/*!
 * ˫������ͷ���
 */
typedef struct DoublyLinkList
{
    int length;     //ͷ����¼������
    DoublyNode* next;
}DoublyLinkList;

/*!
 * �Ƚ����������Ƿ���ͬ
 * @param word1 ����1
 * @param word2 ����2
 * @return ��ͬ�򷵻�1����ͬ�򷵻�2
 */
int isWordEqual(Word word1, Word word2);

/*!
 * �Ƚ������˻���Ϣ�Ƿ���ͬ
 * @param account1 �˻�1
 * @param account2 �˻�2
 * @return ��ͬ�򷵻�1����ͬ�򷵻�0
 */
int isAccountEqual(Account account1, Account account2);

/*!
 * �ڴ���������ָ��λ�ò���һ��Ԫ��
 * @param dlList ����ͷ���
 * @param pos ָ��λ��
 * @param word �����Ԫ��
 */
void InsertDoublyLinkList(DoublyLinkList* dlList, int pos, Word word);

/*!
 * ���˻���Ϣ������ָ��λ�ò���һ��Ԫ��
 * @param dlList ����ͷ���
 * @param pos ָ��λ��
 * @param Account �����Ԫ��
 */
void InsertAccountLinkList(DoublyLinkList* dlList, int pos, Account account);

/*!
 * ɾ������ָ��λ�õ�Ԫ��
 * @param dlList ����ͷ���
 * @param pos ָ��λ��
 */
void DeleteDoublyLinkListByPos(DoublyLinkList* dlList, int pos);

/*!
 * ɾ������ָ��Ԫ��
 * @param dlList ����ͷ���
 * @param word ָ��Ԫ��
 */
void DeleteDoublyLinkListByWord(DoublyLinkList* dlList, Word word);

/*!
 * ��ѯ����ָ��λ�õ�Ԫ��
 * @param dlList ����ͷ���
 * @param pos ָ��λ��
 */
void GetDoublyLinkListElement(DoublyLinkList* dlList, int pos);

/*!
 * ��ӡ��������
 * @param dlList ����ͷ���
 */
void PrintDoublyLinkList(DoublyLinkList* dlList);

/*!
 * �޸�����ָ��λ�õ�Ԫ��
 * @param dlList ����ͷ���
 * @param pos ָ��λ��
 * @param word �޸ĺ�ĵ���
 */
void ChangeDoublyLinkElement(DoublyLinkList* dlList, int pos, Word word);
#endif //HAOJIXING_ELECTRONIC_DICTIONARY_LIST_H
