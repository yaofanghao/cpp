/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> V* Skiplist<K, V>::get ( K k ) { //��ת����������㷨
   QNode< Entry<K, V> >* p = search(k); //�����Ƿ����У�search()�����᷵��NULL
   return (p->pred && p->entry.key == k) ? &(p->entry.value) : NULL; //���������ж�
} //�ж������ʱ����������