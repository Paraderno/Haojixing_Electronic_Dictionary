/*
 * Created by FallenGemini on 2022/7/13.
 * ����Ա��������
*/

#ifndef HAOJIXING_ELECTRONIC_DICTIONARY_ADMIN_H
#define HAOJIXING_ELECTRONIC_DICTIONARY_ADMIN_H


#include <stdio.h>
#include <string.h>
#include "List.h"

/*!
 * ����Ա������Ҫ����ĵ��ʡ���������������,������������һ������
 * @param dlList ����ͷ���
 * @param En Ӣ�ĵ���
 * @param attribute ����
 * @param Cn ��������
 */
void Add(DoublyLinkList * dlList, char* En, char* Cn);

/*!
 * ����Ա������Ҫɾ���ĵ��ʣ��ļ��ж�Ӧ�ĵ��ʽ���ɾ���������벻���ڵĵ��ʽ��ᱨ��
 * @param dlList ����ͷ���
 * @param En Ӣ�ĵ���
 * @param attribute ����
 * @param Cn ��������
 */
void Delete(DoublyLinkList * dlList, char* En,  char* Cn);

/*!
 * ����Ա������Ҫ�޸ĵ��ʵ��±꣬�Լ��޸ĺ�ĵ��ʡ����ԡ����ġ������벻���ڵĵ��ʽ��ᱨ��
 * @param dlList ����ͷ���
 * @param pos ���޸ĵ��ʵ��±�
 * @param En Ӣ�ĵ���
 * @param attribute ����
 * @param Cn ��������
 */
void Modify(DoublyLinkList * dlList, int pos, char* En, char* Cn);

#endif //HAOJIXING_ELECTRONIC_DICTIONARY_ADMIN_H