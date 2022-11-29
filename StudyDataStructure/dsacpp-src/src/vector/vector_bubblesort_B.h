/******************************************************************************************
* Data Structures in C++
* ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
* Junhui DENG, deng@tsinghua.edu.cn
* Computer Science & Technology, Tsinghua University
* Copyright (c) 2003-2021. All rights reserved.
******************************************************************************************/

#pragma once

template <typename T> //����������������ǰ��ֹ�棩
void Vector<T>::bubbleSort( Rank lo, Rank hi ) { //assert: 0 <= lo < hi <= size
   for( bool sorted = false; sorted = !sorted; hi-- )
      for( Rank i = lo+1; i < hi; i++ )
         if( _elem[ i-1 ] > _elem[ i ] ) //��������
            swap( _elem[ i-1 ], _elem[ i ] ), sorted = false; //����������˲����ж��Ѿ���������
}
