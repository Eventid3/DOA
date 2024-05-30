/**
 * Insert item x, allowing duplicates.
 */
template<typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable& x) {
	if (currentSize == array.size() - 1)
		array.resize(array.size() * 2);

	// Move up
	int node = ++currentSize;
	//currentSize++;
	Comparable copy = x;

	array[0] = std::move(copy);
	for (; x > array[node / 2]; node /= 2)
		array[node] = std::move(array[node / 2]);
	array[node] = std::move(array[0]);
}

/**
 * Find the largest item in the priority queue.
 * Return the smallest item, or throw Underflow if empty.
 */
template<typename Comparable>
const Comparable& BinaryHeap<Comparable>::findMax() const {
	if (isEmpty()) throw underflow_error{"heap is empty."};
	return array[1];
}

/**
 * Remove the maximum item.
 * Throws UnderflowException if empty.
 */
template<typename Comparable>
void BinaryHeap<Comparable>::deleteMax() {
	if (isEmpty()) throw underflow_error("heap is empty.");
	array[1] = std::move(array[currentSize--]);
	maxHeapify(1);
}

/**
 * Remove the maximum item and place it in maxItem.
 * Throws Underflow if empty.
 */
template<typename Comparable>
void BinaryHeap<Comparable>::deleteMax(Comparable & maxItem) {
	if (isEmpty()) throw underflow_error("heap is empty.");
	maxItem = std::move(array[1]);
	array[1] = std::move(array[currentSize--]);
	maxHeapify(1);
}

/**
 * Establish heap order property from an arbitrary
 * arrangement of items. Runs in linear time.
 */
template<typename Comparable>
void BinaryHeap<Comparable>::buildHeap() {
	for (int i = currentSize / 2; i > 0; --i) {
		maxHeapify(i);
	}
}

/**
 * Internal method to percolate down in the heap.
 * node is the index at which the percolate begins.
 */
template<typename Comparable>
void BinaryHeap<Comparable>::maxHeapify(int node) {
	int child;
	Comparable tmp = std::move(array[node]);
	//cout << "heapify ";

	for (; node * 2 <= currentSize; node = child) {
		child = node * 2;
		if (child != currentSize && array[child + 1] > array[child])
			++child;
		if (array[child] > tmp)
			array[node] = std::move(array[child]);
		else
			break;
	}
	array[node] = std::move(tmp);
}

//Prints the heap
template<typename Comparable>
void BinaryHeap<Comparable>::print() {

	cout << endl;
	for (int i = 1; i <= currentSize; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

