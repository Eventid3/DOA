#include <cassert>

void List::clear() {
	LNode *p = head->next;
	while (p != tail) {
		LNode *t = p->next;
		delete p;
		p = t;
	}
	head->next = tail;
	tail->prev = head;
}

void List::push_front(const char x) {
	LNode *p = new LNode;
	LNode *t = head->next;
	p->value = x;
	p->prev = head;
	p->next = t;
	t->prev = p;
	head->next = p;
	theSize++;
}

void List::push_back(const char x) {
	LNode *p = new LNode;
	LNode *t = tail->prev;
	p->value = x;
	p->prev = t;
	p->next = tail;
	t->next = p;
	tail->prev = p;
	theSize++;
}

char List::pop_front() {
	LNode *p = head->next;
	LNode *t = p->next;
	char x = p->value;
	t->prev = head;
	head->next = t;
	theSize--;
	delete p;
	return x;
}

char List::pop_back() {
	LNode *p = tail->prev;
	LNode *t = p->prev;
	char x = p->value;
	t->next = tail;
	tail->prev = t;
	theSize--;
	delete p;
	return x;
}

char List::find_kth(int pos) {
	assert(pos >= 0 && pos < theSize);
	LNode *p = head->next;
	while (pos > 0) {
		p = p->next;
		pos--;
	}
	return p->value;
}
