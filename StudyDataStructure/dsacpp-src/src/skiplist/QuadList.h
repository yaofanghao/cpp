/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "QuadListNode.h" //����Quadlist�ڵ���

template <typename T> struct Quadlist { //�����б�
   int _size; //��ģ
   QNodePosi<T> header, trailer; //ͷ�ڱ���β�ڱ�
   void init(); //��ʼ��
   int clear(); //������нڵ�
   Quadlist() { init(); } //����
   ~Quadlist() { clear(); delete header; delete trailer; } //����
   T remove( QNodePosi<T> p ); //ɾ�����Ϸ���λ��p���Ľڵ㣬���ر�ɾ���ڵ����ֵ
   QNodePosi<T> insert( T const& e, QNodePosi<T> p, QNodePosi<T> b = NULL ); //��e��Ϊp�ĺ�̡�b�����ڲ���
   void traverse( void (* ) ( T& ) ); //�������ڵ㣬����ʵʩָ������������ָ�룬ֻ����ֲ��޸ģ�
   template <typename VST> void traverse ( VST& ); //����
}; //Quadlist

#include "Quadlist_implementation.h"