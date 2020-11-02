#include "pch.h"
#include "CppUnitTest.h"
#include "../3semA3/BinaryHeap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My3semA3test
{
	TEST_CLASS(Empty)
	{
	public:
		BinaryHeap heap;
		Iterator* test_bft_iterator;
		Iterator* test_dft_iterator;
		
		TEST_METHOD(hasnext_bft) 
		{
			test_bft_iterator = heap.create_bft_iterator();
			Assert::AreEqual(test_bft_iterator->has_next(), false);
		}

		TEST_METHOD(hasnext_dft)
		{
			test_dft_iterator = heap.create_dft_iterator();
			Assert::AreEqual(test_dft_iterator->has_next(), false);
		}

		TEST_METHOD(insert_bft)
		{
			heap.insert(20);
			test_bft_iterator = heap.create_bft_iterator();
			Assert::AreEqual(test_bft_iterator->next(), 20);
			Assert::AreEqual(test_bft_iterator->has_next(), false);
		}
		
		TEST_METHOD(insert_dft)
		{
			heap.insert(20);
			test_dft_iterator = heap.create_dft_iterator();
			Assert::AreEqual(test_dft_iterator->next(), 20);
			Assert::AreEqual(test_dft_iterator->has_next(), false);
		}

		TEST_METHOD(error_bft) {
			heap.insert(20);
			test_bft_iterator = heap.create_bft_iterator(); 
			try {
				test_bft_iterator->next();
				test_bft_iterator->next();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("No more elements", e.what());
			}
		}

		TEST_METHOD(error_dft) {
			heap.insert(20);
			test_dft_iterator = heap.create_dft_iterator();
			try {
				test_dft_iterator->next();
				test_dft_iterator->next();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("No more elements", e.what());
			}
		}

		TEST_METHOD(insert_heapify_correct) {
			for (int i = 0; i < 6; i++) heap.insert(i);
			test_bft_iterator = heap.create_bft_iterator();
			Assert::AreEqual(test_bft_iterator->next(), 5);
			Assert::AreEqual(test_bft_iterator->next(), 3);
			Assert::AreEqual(test_bft_iterator->next(), 4);
			Assert::AreEqual(test_bft_iterator->next(), 0);
			Assert::AreEqual(test_bft_iterator->next(), 2);
			Assert::AreEqual(test_bft_iterator->next(), 1);
		}

		TEST_METHOD(insert_error) {
			BinaryHeap h(1);
			heap.insert(0);
			try {
				heap.insert(20);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Heap is full", e.what());
			}
		}
	};

	TEST_CLASS(NotEmpty)
	{
	public:
		BinaryHeap heap;
		Iterator* test_bft_iterator;
		Iterator* test_dft_iterator;

		TEST_METHOD_INITIALIZE(setup) {
			heap.insert(20);
			heap.insert(2);
			heap.insert(17);
			heap.insert(16);
			heap.insert(18);
		}

		TEST_METHOD_CLEANUP(cleanup) {
			delete test_bft_iterator;
			delete test_dft_iterator;
		}

		TEST_METHOD(bft) {
			test_bft_iterator = heap.create_bft_iterator();
			Assert::AreEqual(test_bft_iterator->next(), 20);
			Assert::AreEqual(test_bft_iterator->next(), 18);
			Assert::AreEqual(test_bft_iterator->next(), 17);
			Assert::AreEqual(test_bft_iterator->next(), 2);
			Assert::AreEqual(test_bft_iterator->next(), 16);
			Assert::AreEqual(test_bft_iterator->has_next(), false);
		}
		TEST_METHOD(dft) {
			test_dft_iterator = heap.create_dft_iterator();
			Assert::AreEqual(test_dft_iterator->next(), 20);
			Assert::AreEqual(test_dft_iterator->next(), 18);
			Assert::AreEqual(test_dft_iterator->next(), 2);
			Assert::AreEqual(test_dft_iterator->next(), 16);
			Assert::AreEqual(test_dft_iterator->next(), 17);
			Assert::AreEqual(test_dft_iterator->has_next(), false);
		}

		TEST_METHOD(remove) {
			heap.remove(18);
			test_bft_iterator = heap.create_bft_iterator();
			Assert::AreEqual(test_bft_iterator->next(), 20);
			Assert::AreEqual(test_bft_iterator->next(), 16);
			Assert::AreEqual(test_bft_iterator->next(), 17);
			Assert::AreEqual(test_bft_iterator->next(), 2);
			Assert::AreEqual(test_bft_iterator->has_next(), false);
		}

		TEST_METHOD(remove2) {
			heap.remove(18);
			heap.remove(2);
			heap.remove(16);
			heap.remove(17);
			test_bft_iterator = heap.create_bft_iterator();
			Assert::AreEqual(test_bft_iterator->next(), 20);
			Assert::AreEqual(test_bft_iterator->has_next(), false);
		}

		TEST_METHOD(remove_top) {
			heap.remove(20);
			test_bft_iterator = heap.create_bft_iterator();
			Assert::AreEqual(test_bft_iterator->next(), 18);
			Assert::AreEqual(test_bft_iterator->next(), 16);
			Assert::AreEqual(test_bft_iterator->next(), 17);
			Assert::AreEqual(test_bft_iterator->next(), 2);
			Assert::AreEqual(test_bft_iterator->has_next(), false);
		}
		TEST_METHOD(contains_top) {
			Assert::AreEqual(heap.contains(20), true);
		}

		TEST_METHOD(contains) {
			Assert::IsTrue(heap.contains(2));
		}

		TEST_METHOD(contains_not) {
			Assert::IsFalse(heap.contains(0));
		}

		TEST_METHOD(remove_error) {
			try {
				heap.remove(0);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Element doesn't exist", e.what());
			}
		}
	};
}
