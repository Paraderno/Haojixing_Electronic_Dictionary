/*
 * Created by FallenGemini on 2022/7/13.
 * 公共功能声明
 */

#ifndef HAOJIXING_ELECTRONIC_DICTIONARY_PUBLIC_H
#define HAOJIXING_ELECTRONIC_DICTIONARY_PUBLIC_H

#include "List.h"

 // 账户类型 普通用户USER 管理员ADMIN
#define USER 0
#define ADMIN 1

/*!
 * 载入中英单词词库
 * @param wList 链表头结点
 */
void LoadDictionary(WordLinkList* wList);

/*!
 * 载入账户信息库
 * @param wList 链表头节点
 * @return 返回是否加载成功
 */
int LoadAccountFile(AccountLinkList* aList);

/*!
 * 账户登录
 * 读入用户账号与密码，并检验是否正确
 * @param type 账户类型
 * @param accountID 账户
 * @param password 密码
 * @param aFile 账户信息库(系统默认设定)
 * @return 1 登录成功
 * @return 0 登陆失败
 */
int LogIn(AccountLinkList* aList,int type, char* accountID, char* password);

/*!
 * 账户注销
 * 注销用户账号与密码，并检验是否正确
 * @param type 当前账户类型
 * @param account 账户
 * @param password 密码
 * @return 1 登录成功
 * @return 0 登录失败
 */
int LogOut(AccountLinkList* aList, int type, char* accountID, char* password);

/*!
 * 初始功能菜单
 */
void InitialMenu();

/*!
 * 读取用户输入的英文释义，展示其可能搜索的英文单词
 * @param wList 链表头结点
 * @param En 模糊单词
 */
void FuzzySearch(WordLinkList* wList, char* En);

/*!
 * 退出程序，退出时会自动保存相关数据
 * @param rPtr 文件
 */
void Exit(FILE* rPtr);

#endif //HAOJIXING_ELECTRONIC_DICTIONARY_PUBLIC_H
