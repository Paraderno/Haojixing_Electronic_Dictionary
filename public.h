/*
 * Created by FallenGemini on 2022/7/13.
 * 公共功能声明
 */

#ifndef HAOJIXING_ELECTRONIC_DICTIONARY_PUBLIC_H
#define HAOJIXING_ELECTRONIC_DICTIONARY_PUBLIC_H

#include "List.h"

/*!
 * 把文本词库信息输入到程序中
 * @param WordListHead 链表头结点
 */
void LoadWords(DoublyLinkList *dlList);

/*!
 * 把文本词库信息输入到程序中
 */
void SaveWords(DoublyLinkList *dlList);

/*!
 * 账户登录
 * 读入用户账号与密码，并检验是否正确
 * @param account 账户
 * @param password 密码
 * @param aPtr 文件对比
 */
void LogIn(char* account, char* password, FILE* aPtr);

/*!
 * 账户注销
 * 注销用户账号与密码，并检验是否正确
 * @param account 账户
 * @param password 密码
 * @param aPtr 文件对比
 */
void LogOut(char* account,char* password, FILE* aPtr);

/*!
 * 展示功能菜单
 */
void Menu();

/*!
 * 顺序循环播放背景音乐
 * @param fPtr 声音文件
 */
void Music(FILE* fPtr);

 /*!
  * 读取用户输入的英文单词，展示其中文释义，当输入不存在的单词时会报错
  * @param dlList 链表头结点
  * @param word 所要查找的英文单词
  */
void EnToCn(DoublyLinkList* dlList, char* word);

/*!
 * 读取用户输入的中文释义，展示其英文单词，当输入不存在的单词时会报错
 * @param dlList 链表头结点
 * @param word 索要查找的中文释义
 */
void CnToEn(DoublyLinkList* dlList, char* word);

/*!
 * 退出程序，退出时会自动保存相关数据
 * @param rPtr 文件
 */
void Exit(FILE* rPtr);

#endif //HAOJIXING_ELECTRONIC_DICTIONARY_PUBLIC_H
