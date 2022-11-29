/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> bool Skiplist<K, V>::remove( K k ) { //��ת�����ɾ���㷨
   QNodePosi< Entry<K, V> > p = search ( k ); //����Ŀ�����
   if ( !p->pred || (k != p->entry.key) )  return false; //�������ڣ�ֱ�ӷ���
   ListNodePosi< Quadlist< Entry<K, V> >* > qlist = last(); //�ӵײ�Quadlist��ʼ
   while ( p->above ) { qlist = qlist->pred; p = p->above; } //��������
   do { //������
      QNodePosi< Entry<K, V> > lower = p->below; //��ס��һ��ڵ㣬��
      qlist->data->remove( p ); //ɾ����ǰ��ڵ㣬��
      p = lower; qlist = qlist->succ; //ת����һ��
   } while ( qlist->succ ); //ֱ������
   while ( (1 < height()) && (first()->data->_size < 1) ) { //������
      List::remove( first() ); 
      first()->data->header->above = NULL;
   } //�Ѳ���������Quadlist�����ٱ�����ײ�ձ�
   return true; //ɾ���ɹ�
} //��᣺�������ڱ������ã���Щ���ڱ����ˣ�
