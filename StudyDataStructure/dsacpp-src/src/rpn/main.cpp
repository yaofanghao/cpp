/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "rpn.h"

char* removeSpace ( char* s ) { //�޳�s[]�еİ׿ո�
   for ( char *p = s-1, *q = s; (p < s) || *p; *++p = *q++ )
      while ( isspace( *q ) ) q++;
   return s;
}

int main ( int argc, char* argv[] ) { //���ʽ��ֵ����ڣ�
   for ( int i = 1; i < argc; i++ ) { //��һ����������в��������ʽ��
      /*DSA*/system ( "cls" ); printf ( "\nPress any key to evaluate: [%s]\a\n", argv[i] ); getchar();
      char* rpn = new char[strlen( argv[i] ) * 4];   rpn[0] = '\0'; //�沨�����ʽ��4��ԭ������ͨ�����������
      double value = evaluate ( removeSpace ( argv[i] ), rpn ); //��ֵ
      /*DSA*/printf ( "EXPR\t: %s\n", argv[i] ); //���ԭ���ʽ
      /*DSA*/printf ( "RPN\t: [ %s]\n", rpn ); //���RPN
      /*DSA*/printf ( "Value\t= %f = %d\n\n", value, ( int ) round(value) ); //������ʽ��ֵ
      delete rpn;
      /*DSA*/getchar();
   }
   return 0;
}
