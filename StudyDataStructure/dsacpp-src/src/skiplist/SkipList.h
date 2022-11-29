/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "List/List.h" //�����б�
#include "Entry/Entry.h" //�������
#include "Quadlist.h" //����Quadlist
#include "Dictionary/Dictionary.h" //����ʵ�

template <typename K, typename V> //key��value
//����Dictionary�ӿڵ�Skiplistģ���ࣨ��������Ԫ��֮��ɱȽϴ�С��
struct Skiplist : public Dictionary<K, V>, public List< Quadlist< Entry<K, V> >* > {
   Skiplist() { insertAsFirst( new Quadlist< Entry<K, V> > ); }; //����Ϊ�գ�Ҳ��һ����б�
   QNodePosi< Entry<K, V> > search( K ); //�ɹؼ����ѯ����
   int size() const { return empty() ? 0 : last()->data->_size; } //��������
   int height() { return List::size(); } //��� == #Quadlist
   V* get( K ); //��ȡ
   bool put(K, V); //���루Skiplist��������ظ����ʱ�Ȼ�ɹ���
   bool remove ( K ); //ɾ��
};

#include "Skiplist_implementation.h"