/*
 * Created by FallenGemini on 2022/7/13.
 * 用户功能声明
 */

#ifndef HAOJIXING_ELECTRONIC_DICTIONARY_USER_H
#define HAOJIXING_ELECTRONIC_DICTIONARY_USER_H
#include <stdio.h>
#include "list.h"

/*!
 * 用户注册
 * @return 注册成功返回1，注册失败返回0
 */
int Register(char* accountID, char* password);

/*!
 * 读取用户输入的英文单词，展示其中文释义，当输入不存在的单词时会报错
 * @param wList 链表头结点
 * @param word 所要查找的英文单词
 */
void EnToCn(WordLinkList* wList, char* word);

/*!
 * 读取用户输入的中文释义，展示其英文单词，当输入不存在的单词时会报错
 * @param wList 链表头结点
 * @param word 索要查找的中文释义
 */
void CnToEn(WordLinkList* wList, char* word);

/*!
 * 收藏单词
 * @param sPtr 文件
 */
void Star(FILE *sPtr);

/*!
 * 管理收藏夹
 * @param
 * @param
 */
void StarCase();

#endif //HAOJIXING_ELECTRONIC_DICTIONARY_USER_H
