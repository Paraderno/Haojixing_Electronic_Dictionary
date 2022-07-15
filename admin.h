#pragma once
/*
 * Created by FallenGemini on 2022/7/13.
 * 用户功能声明
 */

#ifndef HAOJIXING_ELECTRONIC_DICTIONARY_USER_H
#define HAOJIXING_ELECTRONIC_DICTIONARY_USER_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 /*!
  * 用户注册
  * @return 注册成功返回1，注册失败返回0
  */
int Register();

/*!
 * 播放音乐
 */
void music();

/*!
 * 收藏单词
 * @param sPtr 文件
 */
void Star(FILE* sPtr);

/*!
 * 显示收藏单词
 */
void ShowStarCase();

#endif //HAOJIXING_ELECTRONIC_DICTIONARY_USER_H
