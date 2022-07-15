//
// Created by 绫波真美丽 on 2022/7/14.
//

#ifndef DICTIONARY_DRAW_H
#define DICTIONARY_DRAW_H
#include"ConsoleLib.h"
/*!
 * 绘制开始页面
 */
void DrawTheMainMenu();

/*!
 * 绘制整体框架
 */
void DrawTheFrame();

/*!
 * 绘制可变长的整体框架，旨在输出词库时使用
 * @param sum 链表长度
 */
void DrawChangeableFrame(int sum);

/*!
 * 绘制内部菜单框架
 */
void DrawInnerFrame();

/*!
 * 绘制分割线
 */
void DrawDividingLine();

/*!
 * 绘制可变长的分割线，当词库数量较大时使用
 * @param sum 链表长度
 */
void DrawChangeableDividingLine(int sum);

/*!
 * 绘制管理员菜单
 */
void DrawAdminMenu();

/*!
 * 绘制用户菜单
 */
void DrawUserMenu();

/*!
 * 绘制注册页面
 */
void DrawRegisterPage();

/*!
 * 绘制中文查词页面
 */
void DrawFindEn();

/*!
 * 绘制英文翻译页面
 */
void DrawFindCn();

/*!
 * 绘制收藏夹页面
 * @param sum 链表长度
 */
void DrawTheStarCase(int sum);

/*!
 * 绘制添加单词页面
 */
void DrawAddPage();

/*!
 * 绘制删除单词页面
 */
void DrawDeletePage();

/*!
 * 绘制成功信息
 * @param message 信息字符串（如”注册“）
 */
void DrawSuccessMessage(const char* message);

/*!
 * 绘制失败信息
 * @param message 信息字符串（如”注册“）
 */
void DrawFailMessage(const char* message);

#endif //DICTIONARY_DRAW_H
