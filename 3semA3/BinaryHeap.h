#pragma once
#include "Iterator.h"
#include<iostream>
#include "DuoList.h"

class BinaryHeap
{
private:
	int* h;
	int size_heap;
	int max_size;
	void siftDown(int);
	void siftUp(int);

public:
	BinaryHeap(int max_size = 30) { h = new int[max_size]; size_heap = 0; this->max_size = max_size; };
	~BinaryHeap() { delete h; };
	bool contains(int); // поиск элемента в дереве по ключу
	void insert(int); // добавление элемента в дерево по ключу. Должен работать за O(logN)
	void remove(int); // удаление элемента дерева по ключу

	void out();
	Iterator* create_bft_iterator(); //breadth - first traverse)
	Iterator* create_dft_iterator(); //depth - first traverse

	class bft_iterator : public Iterator
	{
	public:
		bft_iterator(int* cur, int size, int ind = 0) { this->curr = cur; this->size = size; this->cur_index = ind; };
		~bft_iterator() { delete curr; }
		int next() override;
		bool has_next() override;

	private:
		int* curr;
		int size;
		int cur_index;
	};

	class dft_iterator : public Iterator
	{
	public:
		dft_iterator(int* cur, int size, int ind = 0) { 
			this->curr = cur; this->size = size;
			//this->right_stack.push(ind);
			cur_index = ind;
		};
		~dft_iterator() { delete curr; }
		int next() override;
		bool has_next() override;

	private:
		int* curr;
		int size;
		int cur_index;
		DuoList right_stack;
	};
};

