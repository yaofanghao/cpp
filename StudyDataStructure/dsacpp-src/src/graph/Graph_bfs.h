/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> //�����������BFS�㷨��ȫͼ��
void Graph<Tv, Te>::bfs ( Rank s ) { //s < n
   reset(); int clock = 0; Rank v = s; //��ʼ��
   do //��һ������ж���
      if ( UNDISCOVERED == status ( v ) ) //һ��������δ���ֵĶ���
         BFS ( v, clock ); //���Ӹö����������һ��BFS
   while ( s != ( v = ( ( v+1 ) % n ) ) ); //����ż�飬�ʲ�©����
}

template <typename Tv, typename Te> //�����������BFS�㷨��������ͨ��
void Graph<Tv, Te>::BFS ( Rank v, int& clock ) { //v < n
   Queue<Rank> Q; //���븨������
   status( v ) = DISCOVERED; Q.enqueue ( v ); //��ʼ�����
   dTime( v ) = clock; clock = 0; //dTime�̳���ǰһ��ͨ/�ɴ����
   while ( !Q.empty() ) { //��Q���֮ǰ������
      Rank v = Q.dequeue(); //�ֵ����׶���v���ܷ���
      for ( Rank u = firstNbr( v ); -1 < u; u = nextNbr( v, u ) ) //ö��v�������ھ�u
         if ( UNDISCOVERED == status ( u ) ) { //��u��δ�����֣���
            status( u ) = DISCOVERED; Q.enqueue ( u ); dTime( u ) = dTime( v ) + 1; //���ָö���
            type( v, u ) = TREE; parent( u ) = v; //����������չ֧����
         } else { //��u�ѱ����֣����������ѷ�����ϣ���
            type( v, u ) = CROSS; //��(v, u)�����ڿ��
         }
      status( v ) = VISITED; fTime( v ) = clock++; //v�������
      if ( Q.empty() )
         clock = dTime(v) + 1; //Ϊ���ܵ���һ��ͨ/�ɴ������Ԥ������ʼ�����dTime
      else if ( dTime( v ) < dTime( Q.front() ) )
         clock = 0; //dTime�����ӣ���ζ�ſ����µ�һ��
   }
}