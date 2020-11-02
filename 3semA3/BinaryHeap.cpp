#include "BinaryHeap.h"
#include "DuoList.h"

void BinaryHeap::siftUp(int elem) {
	if (elem != 0) {
		int parent = (elem - 1) / 2;
		if (h[parent] < h[elem]) {
			std::swap(h[elem], h[parent]);
			siftUp(parent);
		}
	}
}

void BinaryHeap::siftDown(int elem) {
	int child1 = elem*2 + 1, child2 = elem*2 + 2;

	if (child1 < size_heap) {
		if (child2 < size_heap) {
			int bigger;
			if (h[child1] > h[child2]) bigger = child1;
			else bigger = child2;
			if (h[bigger] > h[elem]) {
				std::swap(h[bigger], h[elem]);
				siftDown(bigger);
			}
		}
		else {
			if (h[child1] > h[elem]) {
				std::swap(h[child1], h[elem]);
				siftDown(child1);
			}
		}
	}

}

void BinaryHeap::insert(int info) {
	if (size_heap == max_size) throw std::out_of_range("Heap is full");
	h[size_heap] = info;
	size_heap++;
	siftUp(size_heap - 1);
}

bool BinaryHeap::contains(int info) {
	for (int i = 0; i < size_heap; i++) if (h[i] == info) return true;
	return false;
}

void BinaryHeap::remove(int info) {
	for (int i = 0; i < size_heap; i++) 
		if (h[i] == info) {
			std::swap(h[i], h[size_heap - 1]);
			size_heap--;
			siftDown(i);
			return;
		}
	throw std::out_of_range("Element doesn't exist");
}

void BinaryHeap::out() {
	std::cout << "\n";
	for (int i = 0; i < size_heap; i++) std::cout << h[i] << " ";
}

//breadth iterator
Iterator* BinaryHeap::create_bft_iterator()
{
	return new bft_iterator(h, size_heap, 0);
}

int BinaryHeap::bft_iterator::next()
{
	if (!has_next()) {
		throw std::out_of_range("No more elements");
	}
	int temp = curr[cur_index];
	cur_index++;
	return temp;
}

bool BinaryHeap::bft_iterator::has_next()
{
	if (cur_index == size) return false;
	return true;
}

//deapth iterator
Iterator* BinaryHeap::create_dft_iterator()
{
	return new dft_iterator(h, size_heap, 0);
}

int BinaryHeap::dft_iterator::next()
{
	if (!has_next()) {
		throw std::out_of_range("No more elements");
	}
	int temp = curr[cur_index];
	int child_right = cur_index * 2 + 2, child_left = cur_index * 2 + 1;
	if (cur_index == 0) right_stack.push_back(0);
	if (child_right < size) {
		right_stack.push_back(child_right);
		cur_index = child_left;
	}
	else if (child_left < size) cur_index = child_left;
	else {
		if (right_stack.at(right_stack.get_size() - 1) == 0) right_stack.pop_back();
		else {
			cur_index = right_stack.at(right_stack.get_size() - 1); //"stack" top
			right_stack.pop_back();
		}
		if (size == 1) cur_index = -1;
	}

	return temp;
}

bool BinaryHeap::dft_iterator::has_next()
{
	if (size == 0) return false;
	if (cur_index == 0) return true;
	if (right_stack.IsEmpty() && cur_index != 0) return false;
	else return true;
}