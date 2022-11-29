/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

/******************************************************************************************
 * Test of DEPQ
 ******************************************************************************************/
#include "DEPQ_test.h"
#include <windows.h>

/******************************************************************************************
 * ��Ի����б������Լ���ʽ��ʵ�ֵ����ȼ����У�������ͳһ�Ĳ���
 ******************************************************************************************/
void verifySMMH( SMMH<int> H ) {
   int s = H.size(); Rank k = 0;
   while ( ++k < s ) {
      if ( isLC(k) && sib(k) < s  &&  H[k] > H[sib(k)] ) break; //Property #0
      if ( isLC(k) && lc(k) < s && H[k] > H[lc(k)] ) break; //Property #1
      if ( isLC(k) && ln(k) < s && H[k] > H[ln(k)] ) break;
      if ( isRC(k) && rc(k) < s && H[k] < H[rc(k)] ) break; //Property #2
      if ( isRC(k) && rn(k) < s && H[k] < H[rn(k)] ) break;
   }
   if ( k < s ) { print(H); printf("SMMP invalid at H[%d] = %d\n", k, H[k]); exit(-1); }
}

void testSMMH( int n ) {
   SMMH<int> H; //init an empty DEPQ implemented as an SMMH
   /*DSA*/ print(H); printf("\n");
   while ( H.size() < n ) { //�������
      if ( dice ( 100 ) < 70 ) { //insert with a prob. of 70%
         int e = dice ( 7 * n ); /*DSA*/printf ( "Inserting" ); print ( e ); printf ( " ...\n" );
         H.insert ( e ); /*DSA*/printf ( "Insertion done\n" );
      } else { //delMin or delMax with a prob. of 15% resp.
         if ( 1 < H.size() )
            if ( dice( 100 ) < 50 ) { /*DSA*/printf ( "Deleting MIN ...\n" );
               int e = H.delMin();/*DSA*/printf ( "delMIN done with" ); print ( e ); printf ( "\n" );
            } else {                  /*DSA*/printf ( "Deleting MAX ...\n" );
               int e = H.delMax();/*DSA*/printf ( "delMAX done with" ); print ( e ); printf ( "\n" );
            }
      }  /*DSA*/ /* print(H); */ printf("\n");
      verifySMMH( H );
   }
   /*DSA*/printf ( "Purge by delMIN/delMAX ...\n" );
   while ( 1 < H.size() ) { //delMin or delMax with a prob. of 50% resp.
      if ( dice( 100 ) < 50 ) {
         int e = H.delMin(); /*DSA*/ print ( e ); printf("\n"); //print ( H );
      } else {
         int e = H.delMax(); /*DSA*/ printf("\t\t\t"); print ( e ); printf("\n"); //print ( H );
      }
      verifySMMH( H );
      if ( H.size() < 16 ) { print(H); printf("\n"); }
   }
}

/******************************************************************************************
 * ���ȼ����в���
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand ( ( unsigned int ) time ( NULL ) );
#if defined(DSA_DEPQ_SMMH)
   testSMMH( atoi ( argv[1] ) ); //�������Ϳ��ڴ�ָ��
#else
   printf ( "PQ type not defined yet\n" );
#endif
   return 0;
}
