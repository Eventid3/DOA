#pragma once
#include<vector>
using namespace std;

/**
 * @brief Min-Heap Class
 * 
 * @tparam T 
 */
template<typename T>
class MinHeap
{
public:
	/**
	 * @brief Inserts an element and updates the Heap
	 * 
	 * @param x Element to insert
	 */
	void insert(const T& x) 
	{
		// YOUR CODE GOES HERE
	}

	/**
	 * @brief Remove minimum (top) element and update Heap
	 * 
	 */
	void remove() 
	{
		// YOUR CODE GOES HERE
	}

	/**
	 * @brief Inspect if Heap is empty 
	 * 
	 * @return true Heap is empty
	 * @return false Heap is not empty
	 */
	bool isEmpty()
	{
		// YOUR CODE GOES HERE
	}

	/**
	 * @brief Access the minimum (top) element of the Heap
	 * 
	 * @return T Minimum element in Heap
	 */
	T peek()
	{
		// YOUR CODE GOES HERE
	}

private:

	/**
	 * @brief Recursive function to percolate node up
	 * 
	 * @param i Index for node to percolate
	 */
	void percolateUp(int i) 
	{
		// YOUR CODE GOES HERE
	}

	/**
	 * @brief Recursive function to percolate node down
	 * 
	 * @param i Index for node to percolate
	 */
	void percolateDown(int i) 
	{
		// YOUR CODE GOES HERE
	}

	/**
	 * @brief Returns index of smallest value 
	 *        of i and its children
	 * 
	 * @param i Index in Heap array
	 * @return int Index to smallest value
	 */
	int smallest(int i) const	 {
		int small = i;

		if (left(i) < data.size() &&
			data[i] > data[left(i)])
			small = left(i);

		if (right(i) < data.size() &&
			data[i] > data[right(i)] &&
			data[right(i)] < data[left(i)])
			small = right(i);

		return small;
	}

	/**
	 * @brief Swaps values in data array
	 * 
	 * @param i1 Array index 1 to swap with 2
	 * @param i2 Array index 2 to swap with 1
	 */
	void swap(int i1, int i2) {
		T temp = data[i1];
		data[i1] = data[i2];
		data[i2] = temp;
	}

	size_t parent(int i) const { return (i - 1) / 2; }
	size_t left(int i)	const { return 2 * i + 1; }
	size_t right(int i)	const { return 2 * i + 2; }

	vector<T> data;
};