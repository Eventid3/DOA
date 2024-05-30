#ifndef _LIST_H_
#define _LIST_H_

struct LNode
{
    char value;
    LNode *next;
    LNode *prev;
};

class List
{
public:
    int theSize;
    LNode *head;
    LNode *tail;

public:
    List()
    {
        theSize = 0;
        head = new LNode;
        tail = new LNode;
        head->next = tail;
        tail->prev = head;
        head->prev = tail->next = nullptr;
    }

    ~List()
    {
        clear();
        delete head;
        delete tail;
    }

    int size() { return theSize; }
    bool empty() { return (size() == 0); }

    void clear();

    void push_front(const char x);

    void push_back(const char x);

    LNode *begin() { return head; }
    LNode *end() { return tail; }

    char pop_front();

    char pop_back();

    char  find_kth(int pos);
};

#include "double_list.tpp"

#endif
