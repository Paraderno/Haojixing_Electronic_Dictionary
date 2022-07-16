/*
 * Created by FallenGemini on 2022/7/13.
 * ������������
 */

#ifndef HAOJIXING_ELECTRONIC_DICTIONARY_PUBLIC_H
#define HAOJIXING_ELECTRONIC_DICTIONARY_PUBLIC_H

#include "List.h"

 // �˻����� ��ͨ�û�USER ����ԱADMIN
#define USER 0
#define ADMIN 1

/*!
 * ������Ӣ���ʴʿ�
 * @param wList ����ͷ���
 */
void LoadDictionary(WordLinkList* wList);

/*!
 * �����˻���Ϣ��
 * @param wList ����ͷ�ڵ�
 * @return �����Ƿ���سɹ�
 */
int LoadAccountFile(AccountLinkList* aList);

/*!
 * �˻���¼
 * �����û��˺������룬�������Ƿ���ȷ
 * @param type �˻�����
 * @param accountID �˻�
 * @param password ����
 * @param aFile �˻���Ϣ��(ϵͳĬ���趨)
 * @return 1 ��¼�ɹ�
 * @return 0 ��½ʧ��
 */
int LogIn(AccountLinkList* aList,int type, char* accountID, char* password);

/*!
 * �˻�ע��
 * ע���û��˺������룬�������Ƿ���ȷ
 * @param type ��ǰ�˻�����
 * @param account �˻�
 * @param password ����
 * @return 1 ��¼�ɹ�
 * @return 0 ��¼ʧ��
 */
int LogOut(AccountLinkList* aList, int type, char* accountID, char* password);

/*!
 * ��ʼ���ܲ˵�
 */
void InitialMenu();

/*!
 * ��ȡ�û������Ӣ�����壬չʾ�����������Ӣ�ĵ���
 * @param wList ����ͷ���
 * @param En ģ������
 */
void FuzzySearch(WordLinkList* wList, char* En);

/*!
 * �˳������˳�ʱ���Զ������������
 * @param rPtr �ļ�
 */
void Exit(FILE* rPtr);

#endif //HAOJIXING_ELECTRONIC_DICTIONARY_PUBLIC_H
