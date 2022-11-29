/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "Entry/Entry.h"
template <typename T> struct QNode;
template <typename T> using QNodePosi = QNode<T>*; //��ת��ڵ�λ��
template <typename T> struct QNode { //�����ڵ�
   T entry; //�������
   QNodePosi<T> pred, succ, above, below; //ǰ������̡����ڡ�����
   QNode( T e = T(), QNodePosi<T> p = NULL, QNodePosi<T> s = NULL,
          QNodePosi<T> a = NULL, QNodePosi<T> b = NULL ) //������
      : entry( e ), pred( p ), succ( s ), above( a ), below( b ) {}
   QNodePosi<T> insert( T const& e, QNodePosi<T> b = NULL ); //��e��Ϊ��ǰ�ڵ�ĺ�̡�b�����ڲ���
};

#include "QuadlistNode_implementation.h"