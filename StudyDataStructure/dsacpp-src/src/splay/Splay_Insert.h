/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi<T> Splay<T>::insert ( const T& e ) { //���ؼ���e������չ����
   if ( !_root ) { _size = 1; return _root = new BinNode<T> ( e ); } //ԭ��Ϊ��
   BinNodePosi<T> t = search( e ); if ( e == t->data ) return t; //Ŀ��ڵ�t�����ڣ���չ����
   if ( t->data < e ) { //���Ҳ�޽�
      t->parent = _root = new BinNode<T> ( e, NULL, t, t->rc ); //lc == t�طǿ�
      if ( t->rc ) { t->rc->parent = _root; t->rc = NULL; } //rc��Ϊ��
   } else { //�����޽�
      t->parent = _root = new BinNode<T> ( e, NULL, t->lc, t ); //rc == t�طǿ�
      if ( t->lc ) { t->lc->parent = _root; t->lc = NULL; } //lc��Ϊ��
   }
   _size++; updateHeightAbove ( t ); return _root; //���¹�ģ���߶ȣ��������ɹ�
} //����e�Ƿ������ԭ���У�����ʱ����_root->data == e
