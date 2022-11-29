/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

class Fib { //Fibonacci������
private:
   Rank f, g; //f = fib(k - 1), g = fib(k)����Ϊint�ͣ��ܿ�ͻ���ֵ���
public:
   Fib ( Rank n ) //��ʼ��Ϊ��С��n����СFibonacci��
   { f = 1; g = 0; while ( g < n ) next(); } //fib(-1), fib(0)��O(log_phi(n))ʱ��
   Rank get()  { return g; } //��ȡ��ǰFibonacci�O(1)ʱ��
   Rank next() { g += f; f = g - f; return g; } //ת����һFibonacci�O(1)ʱ��
   Rank prev() { f = g - f; g -= f; return g; } //ת����һFibonacci�O(1)ʱ��
};