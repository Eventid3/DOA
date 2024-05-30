#include <vector>
#include "binary_search_tree.h"

using namespace std;

template<typename Comparable>
class Set {
  private:
	size_t theSize;
	BinarySearchTree<Comparable> tree;

  public:
	Set() { }

	~Set() { clear(); }

	Set(const Set& s) {
		for (iterator it = s.begin(); it != s.end(); it++) {
			tree.insert(*it);
		}
	}

	/* Set& operator =(const Set& s) { */
	/* 	if (&s == this) */
	/* 		return *this; */
	/* 	clear(); */
	/* 	for (iterator it = s.begin(); it != s.end(); it++) { */
	/* 		insert(*it); */
	/* 	} */
	/* 	return *this; */
	/* } */

	void clear() {
		tree.makeEmpty();
	}

	size_t size() const {
		return theSize;
	}

	bool empty() const {
		return tree.isEmpty();
	}

	void push(const Comparable& t) {
		tree.insert(t);
	}

	friend class BinarySearchTree<Comparable>;
	typedef typename BinarySearchTree<Comparable>::iterator iterator;

	iterator begin() const {
		return tree.findMin();
	}

	iterator end() const {
		return iterator(nullptr);
	}

	iterator insert(const Comparable& t) {
		return tree.insert(t);
	}

	iterator find(const Comparable& t) {
		return tree.find(t);
	}

	iterator erase(iterator& itr) {
		return tree.erase(itr);
	}
};
