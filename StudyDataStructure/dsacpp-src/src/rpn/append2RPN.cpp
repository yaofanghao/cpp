/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "rpn.h"

void append ( char* rpn, double opnd ) { //������������RPNĩβ
   char buf[64];
   if ( ( int ) opnd < opnd ) sprintf ( buf, "%6.2f \0", opnd ); //�����ʽ����
   else                       sprintf ( buf, "%d \0", ( int ) opnd ); //������ʽ
   strcat ( rpn, buf ); //RPN�ӳ�
}

void append ( char* rpn, char optr ) { //�����������RPNĩβ
   int n = strlen ( rpn ); //RPN��ǰ���ȣ���'\0'��β������n + 1��
   sprintf ( rpn + n, "%c \0", optr ); //����ָ���������
}