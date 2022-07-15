/*
 * Created by FallenGemini on 2022/7/13.
 * ������������
 */

#ifndef HAOJIXING_ELECTRONIC_DICTIONARY_PUBLIC_H
#define HAOJIXING_ELECTRONIC_DICTIONARY_PUBLIC_H

#include "List.h"

/*!
 * ������Ӣ���ʴʿ�
 * @param dlList ����ͷ���
 */
void LoadDictionary(DoublyLinkList* dlList);

/*!
 * �����˻���Ϣ��
 * @param dlList ����ͷ�ڵ�
 */
void LoadAccountFile(DoublyLinkList* dlList) ;




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
int LogIn(int type, char* accountID, char* password);

/** �˳���¼ */
int quit();

/*!
 * �˻�ע��
 * ע���û��˺������룬�������Ƿ���ȷ
 * @param type ��ǰ�˻�����
 * @param account �˻�
 * @param password ����
 * @return 1 ��¼�ɹ�
 * @return 0 ��¼ʧ��
 */
int LogOut(int type, char* account, char* password);

/*!
 * ��ʼ���ܲ˵�
 */
void InitialMenu();

/*!
 * ��ȡ�û������Ӣ�����壬չʾ�����������Ӣ�ĵ���
 * @param dlList ����ͷ���
 * @param En ģ������
 */
void FuzzySearch(DoublyLinkList* dlList, char* En);

/*!
 * �˳������˳�ʱ���Զ������������
 * @param rPtr �ļ�
 */
void Exit(FILE* rPtr);

#endif //HAOJIXING_ELECTRONIC_DICTIONARY_PUBLIC_H
