#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_

#include <stdexcept>
#include <vector>

using namespace std;

template <typename Comparable>
class BinaryHeap {
  private:
	int currentSize;	        // Number of elements in heap
	vector<Comparable> array;	// The heap array

	void buildHeap();
	void minHeapify(int hole);
	void maxHeapify(int hole);


  public:
	BinaryHeap(int capacity = 100) : array(capacity + 1), currentSize(0) {};
	BinaryHeap(const vector<Comparable> &items) {
		array.resize(items.size() + 10);
		for (int i = 0; i < items.size(); ++i)
			array[i + 1] = items[i];
		currentSize = items.size();
		buildHeap();
		
	}
	bool isEmpty() const { return currentSize == 0; }
	void insert(const Comparable& x);
	const Comparable& findMax() const;
	void deleteMax();
	void deleteMax(Comparable& maxItem);

	void print();
	void clear()
	{
		currentSize = 0;
		array.clear();
		array.resize(100);
	}

};

template <typename Comparable>
class p_queue {
	public:
	BinaryHeap<Comparable> b;

	void pop()
	{
		b.deleteMax();
	}
	void push(const Comparable& x)
	{
		b.insert(x);
	}
	const Comparable& top() const
	{
		return b.findMax();
	}
	bool empty()
	{
		return b.isEmpty();
	}
	void clear()
	{
		b.clear();
	}
};

#include "binary_heap.tpp"

#endif
