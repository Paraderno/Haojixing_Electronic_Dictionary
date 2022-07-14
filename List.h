/*
 * Created by FallenGemini on 2022/7/14.
 * ������غ���
 */

#ifndef HAOJIXING_ELECTRONIC_DICTIONARY_LIST_H
#define HAOJIXING_ELECTRONIC_DICTIONARY_LIST_H

/*!
 * ��¼���ʣ�����Ӣ�ġ�����������
 */
typedef struct word
{
    char En[50];
    char attribute[10];
    char Cn[50];
}Word;

/*!
 * ˫������Ľ�㣬����һ������������ָ����
 */
typedef struct DoublyNode
{
    Word word;
    struct DoublyNode* prev;   //ָ��ǰ׺���
    struct DoublyNode* next;   //ָ���̽��
}DoublyNode;

/*!
 * ˫������
 */
typedef struct DoublyLinkList
{
    int length;     //ͷ����¼������
    DoublyNode* next;
}DoublyLinkList;

/*!
 * ��������ָ��λ�ò���һ��Ԫ��
 * @param dlList ����ͷ���
 * @param pos ָ��λ��
 * @param word �����Ԫ��
 */
void InsertDoublyLinkList(DoublyLinkList* dlList, int pos, Word word);

/*!
 * ɾ������ָ��λ�õ�Ԫ��
 * @param dlList ����ͷ���
 * @param pos ָ��λ��
 */
void DeleteDoublyLinkList(DoublyLinkList* dlList, int pos);

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
