/*
 * Created by FallenGemini on 2022/7/13.
 * �û���������
 */

#ifndef HAOJIXING_ELECTRONIC_DICTIONARY_USER_H
#define HAOJIXING_ELECTRONIC_DICTIONARY_USER_H
#include <stdio.h>
#include "list.h"

 /*!
  * �û�ע��
  * @return ע��ɹ�����1��ע��ʧ�ܷ���0
  */
int Register(AccountLinkList* aList, char* accountID, char* password);

/*!
 * ��ȡ�û������Ӣ�ĵ��ʣ�չʾ���������壬�����벻���ڵĵ���ʱ�ᱨ��
 * @param wList ����ͷ���
 * @param word ��Ҫ���ҵ�Ӣ�ĵ���
 * @return ���ص���
 */
Word EnToCn(WordLinkList* wList, char* word);

/*!
 * ��ȡ�û�������������壬չʾ��Ӣ�ĵ��ʣ������벻���ڵĵ���ʱ�ᱨ��
 * @param wList ����ͷ���
 * @param word ��Ҫ���ҵ���������
 */
void CnToEn(WordLinkList* wList, char* word);

/*!
 * �ղص���
 * @param currWord ��ǰ����
 */
void Star(WordLinkList* wList, Word currWord);

/*!
 * �����ղؼ�
 * @param choice �û���ѡ��
 *		choice = 1 ɾ������
 *		choice = 0 �˳��ղؼ�
 */
void StarCase(int choice);

/*!
* �����ղؼ�
* @param sList �ղؼ�����ͷ���
*/
int LoadStarCase(WordLinkList* sList);

/*!
* �����ղؼ�
* @param sList �ղؼ�����ͷ���
*/
void SaveStarCase(WordLinkList* sList);

#endif //HAOJIXING_ELECTRONIC_DICTIONARY_USER_H