/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * Skiplist���������㷨�����ڲ����ã�
 * ���عؼ��벻����k�����һ������������Ӧ���Ļ�����
 ******************************************************************************************/
template <typename K, typename V> QNodePosi< Entry<K, V> > Skiplist<K, V>::search( K k ) {
   for ( QNodePosi< Entry<K, V> > p = first()->data->header; ; ) //�Ӷ���Quadlist���׽ڵ�p����
      if ( (p->succ->succ) && (p->succ->entry.key <= k) )  { p = p->succ; } //����������
      else if ( p->below )  { p = p->below; } //ˮƽԽ��ʱ������
      else  return p; //��֤����ʱ��p�������Լ������������ײ��б��header��
} //��᣺�������ڱ������ã���Щ���ڱ����ˣ�
