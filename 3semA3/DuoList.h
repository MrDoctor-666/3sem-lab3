#pragma once
#include <iostream>

class DuoList
{
private:
	class Node
	{
	public:
		Node(int data = 0, Node* next = nullptr, Node* prev = NULL)
		{
			this->info = data;
			this->next = next;
			this->prev = prev;
		};
		//Node(Node* cur) { this = cur; }
		~Node() {};
		int info;
		Node* next;
		Node* prev;
	};

	Node* head;
	Node* end;
	size_t size;

	void insert_in_empty(int); //additional to insert into empty list
public:
	DuoList(Node* head = NULL, Node* end = NULL) { 
		size = 0;  
		this->head = head; 
		this->end = end; 
	}
	bool IsEmpty() { return head == NULL; }
	void push_back(int); //insert in the end
	void push_front(int); //insert in the beggining
	void pop_back(); //delete from the end
	void pop_front(); //delete from the beg
	void insert(int, size_t); //adding new element (int) after element with index (size_t)
	int at(size_t); //getting element by index
	void remove(size_t); // removing element number size_t
	size_t get_size() {	return size;}// obv just number of elements
	void print_to_console(); 
	void set(int, size_t); // change element num size_t to new element int 
	void Add(); //not needed. to insert a list
	void push_back_list(DuoList*); //adds another list at the end of this one
	void clear(); //clears everything
	~DuoList();
};

