#pragma once
/*
 * Created by FallenGemini on 2022/7/13.
 * �û���������
 */

#ifndef HAOJIXING_ELECTRONIC_DICTIONARY_USER_H
#define HAOJIXING_ELECTRONIC_DICTIONARY_USER_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 /*!
  * �û�ע��
  * @return ע��ɹ�����1��ע��ʧ�ܷ���0
  */
int Register();

/*!
 * ��������
 */
void music();

/*!
 * �ղص���
 * @param sPtr �ļ�
 */
void Star(FILE* sPtr);

/*!
 * ��ʾ�ղص���
 */
void ShowStarCase();

#endif //HAOJIXING_ELECTRONIC_DICTIONARY_USER_H
