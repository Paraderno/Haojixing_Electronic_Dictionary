/*
 * Created by FallenGemini on 2022/7/13.
 * ������������
 */

#ifndef HAOJIXING_ELECTRONIC_DICTIONARY_PUBLIC_H
#define HAOJIXING_ELECTRONIC_DICTIONARY_PUBLIC_H

#include "List.h"

/*!
 * �˻���¼
 * �����û��˺������룬�������Ƿ���ȷ
 * @param account �˻�
 * @param password ����
 * @param aPtr �ļ��Ա�
 */
void LogIn(char* account, char* password, FILE* aPtr);

/*!
 * �˻�ע��
 * ע���û��˺������룬�������Ƿ���ȷ
 * @param account �˻�
 * @param password ����
 * @param aPtr �ļ��Ա�
 */
void LogOut(char* account,char* password, FILE* aPtr);

/*!
 * չʾ���ܲ˵�
 */
void Menu();

/*!
 * ˳��ѭ�����ű�������
 * @param fPtr �����ļ�
 */
void Music(FILE* fPtr);

 /*!
  * ��ȡ�û������Ӣ�ĵ��ʣ�չʾ���������壬�����벻���ڵĵ���ʱ�ᱨ��
  * @param dlList ����ͷ���
  * @param En ��Ҫ���ҵ�Ӣ�ĵ���
  */
void EnToCn(DoublyLinkList* dlList, char* En);

/*!
 * ��ȡ�û�������������壬չʾ��Ӣ�ĵ��ʣ������벻���ڵĵ���ʱ�ᱨ��
 * @param dlList ����ͷ���
 * @param Cn ��Ҫ���ҵ���������
 */
void CnToEn(DoublyLinkList* dlList, char* Cn);

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
