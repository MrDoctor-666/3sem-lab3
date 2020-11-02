#include <iostream>
#include "BinaryHeap.h";

int main()
{
    BinaryHeap heap(30);
    heap.insert(21);
    heap.insert(17);
    heap.insert(15);
    heap.insert(28);
    heap.out();

}
