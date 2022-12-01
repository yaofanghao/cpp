/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //TΪ�������ͣ��������ظ�ֵ������'='
void Vector<T>::copyFrom ( T const* A, Rank lo, Rank hi ) { //����������A[lo, hi)Ϊ������������
   _elem = new T[ _capacity = max( DEFAULT_CAPACITY, 2 * ( hi - lo ) ) ]; //����ռ�
   for (_size = 0; lo < hi; _size++, lo++ ) //A[lo, hi)�ڵ�Ԫ����һ
      _elem[ _size ] = A[ lo ]; //������_elem[0, hi - lo)
} //��const���Σ���֤A�е�Ԫ�ز��±��۸ģ�����ʱ�� = O(hi-lo)