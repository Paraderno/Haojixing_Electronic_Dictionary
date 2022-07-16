/*
 * Created by FallenGemini on 2022/7/14.
 * ������غ���
 */

#ifndef HAOJIXING_ELECTRONIC_DICTIONARY_LIST_H
#define HAOJIXING_ELECTRONIC_DICTIONARY_LIST_H

#include <string.h>

#define TRUE 1
#define FALSE 0

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
typedef struct account {
    char ID[SIZE_ID];
    char password[SIZE_PW];
    int type;   // �˻����� ��ͨ�û�USER ����ԱADMIN
}Account;

/*!
 * ��������Ľ��
 * ����һ������������ָ����
 */
typedef struct wordNode
{
    Word word;
    struct wordNode* prev;   //ָ��ǰ׺���
    struct wordNode* next;   //ָ���̽��
}WordNode;

/*!
 * �˻���Ϣ��¼����Ľ��
 * ����һ������������ָ����
 */
typedef struct accountNode
{
    Account account;
    struct accountNode* prev;   //ָ��ǰ׺���
    struct accountNode* next;   //ָ���̽��
}AccountNode;

/** ˫������ͷ��� */
typedef struct wordLinkList
{
    int length;     //ͷ����¼������
    WordNode* next;
}WordLinkList;

/** �˻���Ϣ����ͷ��� */
typedef struct accountLinkList
{
    int length;     //ͷ����¼������
    AccountNode* next;
}AccountLinkList;

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
 * @param wList ����ͷ���
 * @param pos ָ��λ��
 * @param word �����Ԫ��
 */
void InsertWordLinkList(WordLinkList* wList, int pos, Word word);

/*!
 * ���˻���Ϣ������ָ��λ�ò���һ��Ԫ��
 * @param wList ����ͷ���
 * @param pos ָ��λ��
 * @param Account �����Ԫ��
 */
void InsertAccountLinkList(AccountLinkList* aList, int pos, Account account);

/*!
 * ɾ������ָ��λ�õ�Ԫ��
 * @param wList ����ͷ���
 * @param pos ָ��λ��
 */
void DeleteWordLinkListByPos(WordLinkList* wList, int pos);

/*!
 * ɾ����������ָ��Ԫ��
 * @param wList ����ͷ���
 * @param word ָ��Ԫ��
 */
void DeleteWordLinkListByWord(WordLinkList* wList, Word word);

/*!
 * ɾ���˻���Ϣ����ָ��Ԫ��
 * @param
 * */
int DeleteAccountData(AccountLinkList* aList, Account account);

/*!
 * ��ѯ����ָ��λ�õ�Ԫ��
 * @param wList ����ͷ���
 * @param pos ָ��λ��
 */
void GetWordLinkListElement(WordLinkList* wList, int pos);

/*!
 * ��ӡ��������
 * @param wList ����ͷ���
 */
void PrintWordLinkList(WordLinkList* wList);

/*!
 * �޸Ĵ�������ָ��λ�õ�Ԫ��
 * @param wList ����ͷ���
 * @param pos ָ��λ��
 * @param word �µĴ���
 */
void ChangeWordListElement(WordLinkList* wList, int pos, Word word);

#endif //HAOJIXING_ELECTRONIC_DICTIONARY_LIST_H