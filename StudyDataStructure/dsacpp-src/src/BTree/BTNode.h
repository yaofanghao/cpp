/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "vector/vector.h"
template <typename T> struct BTNode;
template <typename T> using BTNodePosi = BTNode<T>*; //B-���ڵ�λ��

template <typename T> struct BTNode { //B-���ڵ�ģ����
// ��Ա��Ϊ���������ͳһ���ţ����߿ɸ�����Ҫ��һ����װ��
   BTNodePosi<T> parent; //���ڵ�
   Vector<T> key; //�ؼ�������
   Vector<BTNodePosi<T>> child; //�����������ܱȹؼ����һ����
// ���캯��
   BTNode() { parent = NULL; child.insert ( NULL ); } //�޹ؼ���ڵ�
   BTNode ( T e, BTNodePosi<T> lc = NULL, BTNodePosi<T> rc = NULL ) {
      parent = NULL; key.insert ( e ); //��Ϊ���ڵ�ֻ��һ���ؼ��룬�Լ�
      child.insert ( lc ); if ( lc ) lc->parent = this; //����
      child.insert ( rc ); if ( rc ) rc->parent = this; //�Һ���
   }
};