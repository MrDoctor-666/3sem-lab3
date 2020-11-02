#include "DuoList.h"

//bool DuoList::IsEmpty() {return head == NULL;}

void DuoList::insert_in_empty(int a) {
	head = new Node(a);
	end = head;
	size++;
}

void DuoList::push_back(int a) {
	if (IsEmpty()) {
		insert_in_empty(a);
	}
	else {
		Node* cur = new Node(a, NULL, end);
		end->next = cur;
		end = cur;
		size++;
	}
}

void DuoList::push_front(int a) {
	if (IsEmpty()) {
		insert_in_empty(a);
	}
	else {
		Node* cur = new Node(a, head, NULL);
		head->prev = cur;
		head = cur;
		size++;
	}
}

void DuoList::pop_back() {
	if (!IsEmpty()) {
		end = end->prev;
		delete end->next;
		end->next = NULL;
		if (size == 1) head = end;
		size--;
	}
	else throw std::out_of_range("Segmentation fault");
}

void DuoList::pop_front() {
	if (!IsEmpty()) {
		head = head->next;
		delete head->prev;
		head->prev = NULL;
		if (size == 1) end = head;
		size--;
	}
	else throw std::out_of_range("Segmentation fault");
}

void DuoList::insert(int elem_info, size_t index) {
	if (index > size) throw std::out_of_range("Index is greater than list size");

	Node* cur = new Node(0); cur = head;
	if (index == 0) push_front(elem_info);
	else if (index == size) push_back(elem_info);
	else {
		for (int i = 0; i < index; i++) {cur = cur->next;}
		Node* new_elem = new Node(elem_info, cur, cur->prev);
		new_elem->prev->next = new_elem;
		cur->prev = new_elem;
		size++;
	}
}

int DuoList::at(size_t n) {
	if (n >= size) throw std::out_of_range("Index is greater than list size");
	Node* cur = new Node; cur = head;
	for (int i = 0; i < n; i++) {
		cur = cur->next;
	}
	return cur->info;
}

void DuoList::remove(size_t index) {
	if (index >= size) throw std::out_of_range("Index is greater than list size");
	
	if (index == 0) pop_front(); //index = first element
	else if (index == size - 1) pop_back(); //index = last element
	else {//index in the middle
		Node* cur = new Node; cur = head;
		for (int i = 0; i < index; i++) cur = cur->next;
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		delete cur;
		size--;
	}
}

void DuoList::set(int elem, size_t index) {
	if (index >= size) throw std::out_of_range("Index is greater than list size");
	if (index == 0) head->info = elem;
	else if (index == size - 1) end->info = elem;
	else {
		Node* cur = new Node; cur = head;
		for (int i = 0; i < index; i++) cur = cur->next;
		cur->info = elem;
	}
}

void DuoList::print_to_console() {
	Node* cur = new Node; cur = head;
	while (cur != NULL) {
		std::cout << cur->info << " ";
		cur = cur->next;
	}
	std::cout << std::endl;
	delete cur;
}

void DuoList::push_back_list(DuoList* L2) {
	/*end->next = (*L2).head; //copy elements
	(*L2).head->prev = end;
	end = (*L2).end;
	size += (*L2).get_size();
	(*L2).head = NULL;*/
	for (int i = 0; i < (*L2).get_size(); i++) {
		push_back((*L2).at(i));
	}
}

void DuoList::Add() {
	int a;
	std::cin >> a;
	while (a != 0) {
		push_back(a);
		std::cin >> a;
	}
}

void DuoList::clear() {
	Node* cur = new Node; cur = head;
	while (cur != NULL) {
		head = cur;
		cur = cur->next;
		delete head;
		size--;
	}
	delete cur;
	head = NULL;
	end = head;
}

DuoList::~DuoList() {
	clear();
}