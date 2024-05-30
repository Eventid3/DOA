#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "binary_heap.h"

using namespace std;

// Test program
int main() {
	int minItem = 40;	// same number of digits
	int maxItem = 50;
	vector<int> input;

	int x;

	/* Insert all integers i between min and max out of order. */
	for (int i = minItem; i < maxItem; i++) {
		input.push_back(i);
	}

	for (int i = 0; i < input.size(); i++)
	{
		cout << input[i] << " ";
	}

	cout << endl;

	BinaryHeap<int> h(input);

	h.print();

	for (int i = maxItem-1; i >= minItem; --i) {
		h.deleteMax(x);
		if (x != i) {
			cout << "Oops! " << i << endl;
		}
	}

	cout << "If no Oops! was printed before, no error!" << endl;

	//priority queue
	p_queue<int> pq;

	//initialize queue
	pq.push(4);
	pq.push(5);
	pq.push(6);
	pq.push(7);
	pq.push(8);
	pq.push(9);
	//print
	pq.b.print();

	cout <<"The top of the queue is " << pq.top() << endl;

	//This should remove the 9
	pq.pop();
	pq.b.print();

	// this should return true:
	pq.clear();
	cout <<"Prints 1 if empty, 0 if false (" << pq.empty() <<")" << endl;




	return 0;
}
