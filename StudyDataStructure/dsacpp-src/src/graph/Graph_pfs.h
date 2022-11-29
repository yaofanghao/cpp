/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> template <typename PU> //优先级搜索（全图）
void Graph<Tv, Te>::pfs ( Rank s, PU prioUpdater ) { //s < n
   reset(); Rank v = s; //初始化
   do //逐一检查所有顶点
      if ( UNDISCOVERED == status ( v ) ) //一旦遇到尚未发现的顶点
         PFS ( v, prioUpdater ); //即从该顶点出发启动一次PFS
   while ( s != ( v = ( ( v+1 ) % n ) ) ); //按序号检查，故不漏不重
}

template <typename Tv, typename Te> template <typename PU> //顶点类型、边类型、优先级更新器
void Graph<Tv, Te>::PFS ( Rank v, PU prioUpdater ) { //优先级搜索（单个连通域）
   priority ( v ) = 0; status ( v ) = VISITED; parent ( v ) = -1; //初始化，起点v加至PFS树中
   while ( 1 ) { //将下一顶点和边加至PFS树中
      for ( Rank u = firstNbr ( v ); -1 < u; u = nextNbr ( v, u ) ) //对v的每一个邻居u
         prioUpdater ( this, v, u ); //更新其优先级及其父亲
      for ( int shortest = INT_MAX, u = 0; u < n; u++ )
         if ( UNDISCOVERED == status ( u ) ) //从尚未加入遍历树的顶点中
            if ( shortest > priority ( u ) ) //选出下一个
               { shortest = priority ( u ); v = u; } //优先级最高的顶点v
      if ( VISITED == status ( v ) ) break; //直至所有顶点均已加入
      status ( v ) = VISITED; type ( parent ( v ), v ) = TREE; //将v及与其父的联边加入遍历树
   }
} //通过定义具体的优先级更新策略prioUpdater，即可实现不同的算法功能
