/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //�ؼ����������ڵ����磬�����ڵ���Ѵ���
void BTree<T>::solveOverflow ( BTNodePosi<T> v ) {
   while ( _m <= v->key.size() ) { //���ǵ�ǰ�ڵ㲢δ����
      Rank s = _m / 2; //��㣨��ʱӦ��_m = key.size() = child.size() - 1��
      BTNodePosi<T> u = new BTNode<T>(); //ע�⣺�½ڵ�����һ���պ���
      for ( Rank j = 0; j < _m - s - 1; j++ ) { //v�Ҳ�_m-s-1�����Ӽ��ؼ������Ϊ�Ҳ�ڵ�u
         u->child.insert ( j, v->child.remove ( s + 1 ) ); //����ƶ�Ч�ʵ�
         u->key.insert ( j, v->key.remove ( s + 1 ) ); //�˲��ԿɸĽ�
      }
      u->child[_m - s - 1] = v->child.remove ( s + 1 ); //�ƶ�v��ҵĺ���
      if ( u->child[0] ) //��u�ĺ����Ƿǿգ���
         for ( Rank j = 0; j < _m - s; j++ ) //�����ǵĸ��ڵ�ͳһ
            u->child[j]->parent = u; //ָ��u
      BTNodePosi<T> p = v->parent; //v��ǰ�ĸ��ڵ�p
      if ( !p ) { _root = p = new BTNode<T>(); p->child[0] = v; v->parent = p; } //��p���򴴽�֮
      Rank r = 1 + p->key.search ( v->key[0] ); //p��ָ��v��ָ�����
      p->key.insert ( r, v->key.remove ( s ) ); //���ؼ�������
      p->child.insert ( r + 1, u );  u->parent = p; //�½ڵ�u�븸�ڵ�p����
      v = p; //����һ�㣬���б�Ҫ��������ѡ�������O(logn)��
   } //while
}