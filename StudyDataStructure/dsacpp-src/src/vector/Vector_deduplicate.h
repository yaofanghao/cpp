/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> Rank Vector<T>::deduplicate() { //ɾ�������������ظ�Ԫ�أ���Ч�棩
   Rank oldSize = _size; //��¼ԭ��ģ
   for ( Rank i = 1; i < _size; ) //��ǰ����������_elem[1,_size)
      if ( find(_elem[i], 0, i) < 0 ) //��ǰ׺[0,i)��Ѱ����֮��ͬ�ߣ�����һ����
         i++; //������ͬ�������������
      else
         remove(i); //����ɾ����ǰԪ��
   return oldSize - _size; //��ɾ��Ԫ������
}