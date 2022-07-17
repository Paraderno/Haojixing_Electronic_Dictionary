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
int Register(AccountLinkList* aList, char* accountID, char* password);

/*!
 * 读取用户输入的英文单词，展示其中文释义，当输入不存在的单词时会报错
 * @param wList 链表头结点
 * @param word 所要查找的英文单词
 * @return 返回单词
 */
Word EnToCn(WordLinkList* wList, char* word);

/*!
 * 读取用户输入的中文释义，展示其英文单词，当输入不存在的单词时会报错
 * @param wList 链表头结点
 * @param word 索要查找的中文释义
 */
void CnToEn(WordLinkList* wList, char* word);

/*!
 * 收藏单词
 * @param currWord 当前词条
 */
void Star(WordLinkList* wList, Word currWord);

/*!
 * 管理收藏夹
 * @param choice 用户的选择：
 *		choice = 1 删除词条
 *		choice = 0 退出收藏夹
 */
void StarCase(int choice);

/*!
* 载入收藏夹
* @param sList 收藏夹链表头结点
*/
int LoadStarCase(WordLinkList* sList);

/*!
* 保存收藏夹
* @param sList 收藏夹链表头结点
*/
void SaveStarCase(WordLinkList* sList);

#endif //HAOJIXING_ELECTRONIC_DICTIONARY_USER_H