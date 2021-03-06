//
// Created by 绫波真美丽 on 2022/7/14.
//

#ifndef DICTIONARY_DRAW_H
#define DICTIONARY_DRAW_H
#include"ConsoleLib.h"
#include "List.h"
/*!
 * 绘制开始页面
 * @brief 已包含外边框与内边框
 * --------------------------------------------------------------------------------
*                                                                              *
*                                                                              *
*                           欢迎使用好记星电子词典！                               *
*                                                                              *
*                                                                              *
*       -----------------------------------------------------------------      *
*      |                                                                 |     *
*      |          1.登录                                                  |     *
*      |                                                                 |     *
*      |          2.注册                                                  |     *
*      |                                                                 |     *
*      |          3.退出                                                  |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |          请输入您的选择：                                          |     *
*      |                                                                 |     *
*      |                                                                 |     *
*       -----------------------------------------------------------------      *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
--------------------------------------------------------------------------------
 */
void DrawTheMainMenu();

/*!
 * 绘制整体框架
 *--------------------------------------------------------------------------------
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
--------------------------------------------------------------------------------
 */
void DrawTheFrame();

/*!
 * 绘制可变长的整体框架
 * @brief 旨在输出词库时使用
 * @param sum 链表长度
 */
void DrawChangeableFrame(int sum);

/*!
 * 绘制内部菜单框架
 *      -----------------------------------------------------------------
       |                                                                 |
       |                                                                 |
       |                                                                 |
       |                                                                 |
       |                                                                 |
       |                                                                 |
       |                                                                 |
       |                                                                 |
       |                                                                 |
       |                                                                 |
       |                                                                 |
       |                                                                 |
        -----------------------------------------------------------------
 */
void DrawInnerFrame();

/*!
 * 绘制分割线
 * ------------------------------------------------------------------------------












 *------------------------------------------------------------------------------
 */
void DrawDividingLine();

/*!
 * 绘制可变长的分割线
 * @brief 当收藏夹数量较大时配合void DrawChangeableFrame(int sum)使用
 * @param sum 链表长度
 */
void DrawChangeableDividingLine(int sum);

/*!
 * 绘制管理员菜单
--------------------------------------------------------------------------------
*                                                                              *
*                                                                              *
*                              *好记星电子词典*                                   *
*                                                                              *
*                                                                              *
*       -----------------------------------------------------------------      *
*      |          1.查询中文释义                                           |     *
*      |                                                                 |     *
*      |          2.查询单词                                              |     *
*      |                                                                 |     *
*      |          3.增添单词                                               |     *
*      |                                                                 |     *
*      |          4.删除单词                                               |     *
*      |                                                                 |     *
*      |          5.修改单词                                               |     *
*      |                                                                 |     *
*      |          请输入您的选择：                                          |     *
*      |                                                                 |     *
*       -----------------------------------------------------------------      *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
--------------------------------------------------------------------------------
 */
void DrawAdminMenu();

/*!
 * 绘制用户菜单
*--------------------------------------------------------------------------------
*                                                                              *
*                                                                              *
*                              *好记星电子词典*                                   *
*                                                                              *
*                                                                              *
*       -----------------------------------------------------------------      *
*      |          1.查询中文释义                                         |     *
*      |                                                                 |     *
*      |          2.查询单词                                             |     *
*      |                                                                 |     *
*      |          3.收藏夹功能                                             |     *
*      |                                                                 |     *
*      |          4.退出登录                                           |     *
* *      |                                                                 |     *
*      |          5.注销账号                                           |     *
*      |                                                                 |     *
*      |          请输入您的选择：                                       |     *
*      |                                                                 |     *
*       -----------------------------------------------------------------      *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
--------------------------------------------------------------------------------
 */
void DrawUserMenu();

/*!
 * 绘制注册页面
*--------------------------------------------------------------------------------
*                                                                              *
*                                                                              *
*                              *欢迎注册用户*                                     *
*                                                                              *
*                                                                              *
*       -----------------------------------------------------------------      *
*      |                                                                 |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |          请输入用户名：                                           |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |          请输入密码：                                             |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |                                                                 |     *
*       -----------------------------------------------------------------      *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
--------------------------------------------------------------------------------
 */
void DrawRegisterPage();

/*!
 * 绘制登录页面
*--------------------------------------------------------------------------------
*                                                                              *
*                                                                              *
*                              *欢迎登录*                                     *
*                                                                              *
*                                                                              *
*       -----------------------------------------------------------------      *
*      |                                                                 |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |          请输入账户类型（管理员为1，用户为0）：                          |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |          请输入用户名：                                           |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |          请输入密码：                                             |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |                                                                 |     *
*       -----------------------------------------------------------------      *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
--------------------------------------------------------------------------------
 */
void DrawLogInPage();

/*!
 * 绘制注销页面
*--------------------------------------------------------------------------------
*                                                                              *
*                                                                              *
*                              *注销*                                     *
*                                                                              *
*                                                                              *
*       -----------------------------------------------------------------      *
*      |                                                                 |     *
*      |                                                                 |     *
*      |         请输入账户类型（管理员为1，用户为0）：                      |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |          请输入用户名：                                           |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |          请输入密码：                                             |     *
*      |                                                                 |     *
*      |                                                                 |     *
*      |                                                                 |     *
*       -----------------------------------------------------------------      *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
--------------------------------------------------------------------------------
 */
void DrawLogOutPage();

/*!
 * 绘制中文查词页面
 * @brief 已包含分割线
* --------------------------------------------------------------------------------
*                                                                              *
*    请输入中文释义：                                                             *
*                                                                              *
*------------------------------------------------------------------------------*
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*------------------------------------------------------------------------------*
*                                                                              *
*    1.回到主菜单                                                                *
*                                                                              *
*    2.退出                                                                    *
*                                                                              *
*    请输入您的选择：                                                             *
*                                                                              *
--------------------------------------------------------------------------------
 */
void DrawFindEn();

/*!
 * 绘制英文翻译页面
 * @brief 已包含分割线
--------------------------------------------------------------------------------
*                                                                              *
*    请输入英文单词：                                                             *
*                                                                              *
*------------------------------------------------------------------------------*
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*------------------------------------------------------------------------------*
*                                                                              *
*    1.回到主菜单                                                                *
*                                                                              *
*    2.收藏此单词                                                              *
*                                                                              *
*    3.退出                                                                     *
*                                                                              *
*    请输入您的选择：                                                             *
*                                                                              *
--------------------------------------------------------------------------------
 */
void DrawFindCn();

/*!
 * 绘制收藏夹页面
 * @param sum 链表长度
 * @brief 已包含分割线与可变长边框
--------------------------------------------------------------------------------
*                                                                              *
*   *收藏夹*                                                                    *
*                                                                              *
*------------------------------------------------------------------------------*
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*------------------------------------------------------------------------------*
*                                                                              *
*    1.删除词条                                                               *
*                                                                              *
*    2.退出                                                                     *
*                                                                              *
*    请输入您的选择：                                                             *
*                                                                              *
--------------------------------------------------------------------------------
 */
void DrawTheStarCase(int sum);

/*!
 * 绘制添加单词页面
 * @brief 已包含分割线，但并不包含可变长边框！
*--------------------------------------------------------------------------------
*                                                                              *
*    请输入要增加的单词：                                                          *
*                                                                              *
*------------------------------------------------------------------------------*
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*------------------------------------------------------------------------------*
*                                                                              *
*    1.回到主菜单                                                                *
*                                                                              *
*    2.退出                                                                     *
*                                                                              *
*    请输入您的选择：                                                             *
*                                                                              *
--------------------------------------------------------------------------------
 */
void DrawAddPage();

/*!
 * 绘制删除单词页面
 * @brief 已包含分割线，但并不包含可变长边框！
*--------------------------------------------------------------------------------
*                                                                              *
*    请输入要删除的单词：                                                          *
*                                                                              *
*------------------------------------------------------------------------------*
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*------------------------------------------------------------------------------*
*                                                                              *
*    1.回到主菜单                                                                *
*                                                                              *
*    2.退出                                                                     *
*                                                                              *
*    请输入您的选择：                                                             *
*                                                                              *
--------------------------------------------------------------------------------
 */
void DrawDeletePage();

/*!
 * 绘制修改单词页面
 * @brief 已包含分割线，但并不包含可变长边框！
*--------------------------------------------------------------------------------
*                                                                              *
*    请输入要修改的单词：                                                          *
*                                                                              *
*------------------------------------------------------------------------------*
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*------------------------------------------------------------------------------*
*                                                                              *
*    1.回到主菜单                                                                *
*                                                                              *
*    2.退出                                                                     *
*                                                                              *
*    请输入您的选择：                                                             *
*                                                                              *
--------------------------------------------------------------------------------
 */
void DrawChangePage();

/*!
 * 绘制成功信息
 * @param message 信息字符串（如”注册“）
 * @brief 已包含内边框与外边框，输入任意键时自动清空屏幕
*--------------------------------------------------------------------------------
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                     ---------------------------------                        *
*                    |                                 |                       *
*                    |                                 |                       *
*                    |                                 |                       *
*                    |        ——*登陆成功*——             |                       *
*                    |                                 |                       *
*                    |                                 |                       *
*                     ---------------------------------                        *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
--------------------------------------------------------------------------------
 */
void DrawSuccessMessage(const char* message);

/*!
 * 绘制失败信息
 * @param message 信息字符串（如”注册“）
 * @brief 已包含内边框与外边框，输入任意键时自动清空屏幕
*--------------------------------------------------------------------------------
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                     ---------------------------------                        *
*                    |                                 |                       *
*                    |                                 |                       *
*                    |                                 |                       *
*                    |        ——*登陆失败*——             |                       *
*                    |                                 |                       *
*                    |                                 |                       *
*                     ---------------------------------                        *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
--------------------------------------------------------------------------------
 */
void DrawFailMessage(const char* message);

#endif //DICTIONARY_DRAW_H
