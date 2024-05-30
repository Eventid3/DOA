class iterator {
  private:
	BinaryNode *node;

  public:
	friend class BinarySearchTree<Comparable>;

  	iterator() : node(nullptr) {}

  	iterator(BinaryNode *newNode) : node(newNode) {}

	bool operator ==(iterator it) const {
		return node == it.node;
	}

	bool operator !=(iterator it) const {
		return node != it.node;
	}

	iterator& operator ++() {
		if (node != nullptr) {
			if (node->right != nullptr) {
				node = node->right;
				while (node->left != nullptr) {
					node = node->left;
				}
			} else {
				BinaryNode *p = node->parent;
				while (p != nullptr && node == p->right) {
					node = p;
					p = p->parent;
				}
				node = p;
			}
		}

		return *this;
	}

	iterator operator ++(int) {
		iterator it(*this);
		++(*this);
		return it;
	}

	Comparable& operator*() {
		return node->element;
	}

	Comparable *operator->() {
		return& node->element;
	}

	iterator& operator=(iterator it) {
		node = it.node;
		return *this;
	}
};
