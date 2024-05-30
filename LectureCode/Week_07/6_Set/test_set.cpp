#include <iostream>
#include "set.h"

using namespace std;

int main() {
	Set<int> set;
	set.push(4);
	set.push(0);
	set.push(2);
	set.push(7);
	set.push(0);
	set.push(2);
	set.push(6);
	set.push(4);
	set.push(12);
	set.push(11);
	set.push(8);
	set.push(1);
	set.push(5);
	set.push(0);
	set.push(3);
	set.push(2);
	set.push(7);
	set.push(1);
	set.push(1);
	set.push(1);
	set.push(9);
	set.push(7);
	set.push(11);
	set.push(1);

	Set<int> set2 = set;

	Set<int>::iterator it = set2.insert(-1);
	cout << *it << endl;
	if (++it != set2.end())
		cout << *it << endl;

	// Insert duplicate and print succ to prove that no new node is inserted
	it = set2.insert(4);
	cout << *it << endl;
	if (++it != set2.end())
		cout << *it << endl;

	it = set2.insert(20);
	cout << *it << endl;
	if (++it != set2.end())
		cout << *it << endl;

	it = set2.find(15);
	if (++it != set2.end())
		cout << *it << endl;
	it = set2.find(12);
	cout << *it << endl;
	if (++it != set2.end())
		cout << *it << endl;
	it = set2.erase(it);
	if (it != set2.end())
		cout << *it << endl;

	it = set2.find(4);
	it = set2.erase(it);
	if (it != set2.end())
		cout << *it << endl;

	for (Set<int>::iterator it = set2.begin(); it != set2.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
}
