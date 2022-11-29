/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> template <typename PU> //���ȼ�������ȫͼ��
void Graph<Tv, Te>::pfs ( Rank s, PU prioUpdater ) { //s < n
   reset(); Rank v = s; //��ʼ��
   do //��һ������ж���
      if ( UNDISCOVERED == status ( v ) ) //һ��������δ���ֵĶ���
         PFS ( v, prioUpdater ); //���Ӹö����������һ��PFS
   while ( s != ( v = ( ( v+1 ) % n ) ) ); //����ż�飬�ʲ�©����
}

template <typename Tv, typename Te> template <typename PU> //�������͡������͡����ȼ�������
void Graph<Tv, Te>::PFS ( Rank v, PU prioUpdater ) { //���ȼ�������������ͨ��
   priority ( v ) = 0; status ( v ) = VISITED; parent ( v ) = -1; //��ʼ�������v����PFS����
   while ( 1 ) { //����һ����ͱ߼���PFS����
      for ( Rank u = firstNbr ( v ); -1 < u; u = nextNbr ( v, u ) ) //��v��ÿһ���ھ�u
         prioUpdater ( this, v, u ); //���������ȼ����丸��
      for ( int shortest = INT_MAX, u = 0; u < n; u++ )
         if ( UNDISCOVERED == status ( u ) ) //����δ����������Ķ�����
            if ( shortest > priority ( u ) ) //ѡ����һ��
               { shortest = priority ( u ); v = u; } //���ȼ���ߵĶ���v
      if ( VISITED == status ( v ) ) break; //ֱ�����ж�����Ѽ���
      status ( v ) = VISITED; type ( parent ( v ), v ) = TREE; //��v�����丸�����߼��������
   }
} //ͨ�������������ȼ����²���prioUpdater������ʵ�ֲ�ͬ���㷨����
