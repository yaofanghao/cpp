/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> bool Splay<T>::remove ( const T& e ) { //����չ����ɾ���ؼ���e
   if ( !_root || ( e != search ( e )->data ) ) return false; //��Ŀ����ڣ�����չ����
   BinNodePosi<T> L = _root->lc, R = _root->rc; release(_root); //������������L��R���ͷ�֮
   if ( !R ) { //��R�գ���
      if ( L ) L->parent = NULL; _root = L; //L��������
   } else { //����
      _root = R; R->parent = NULL; search( e ); //��R���ٴβ���e��ע��ʧ�ܣ������е���С�ڵ��
      if (L) L->parent = _root; _root->lc = L; //��չ�������������ӣ����ʿ�������L��Ϊ������
   }
   if ( --_size ) updateHeight ( _root ); return true; //���¹�ģ�����ߣ�����ɾ���ɹ�
}
