/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "rpn.h"

void readNumber ( char*& p, Stack<double>& stk ) { //����ʼ��p���Ӵ�����Ϊ��ֵ�������������ջ
   stk.push ( ( double ) ( *p - '0' ) ); //��ǰ��λ��Ӧ����ֵ��ջ
   while ( isdigit ( * ( ++p ) ) ) //���к������֣���λ����������
      stk.push ( stk.pop() * 10 + ( *p - '0' ) ); //׷��֮���������磩
   if ( '.' == *p ) { //������С������
      double fraction = 1; //��
      while ( isdigit ( * ( ++p ) ) ) //��λ
         stk.push ( stk.pop() + ( *p - '0' ) * ( fraction /= 10 ) ); //���루�������磩
   }
}
