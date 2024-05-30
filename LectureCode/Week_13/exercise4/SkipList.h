#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

using namespace std;


template<typename T>
class SkipList
{
	template<typename U>
	class SkipListElement
	{
	public:
		SkipListElement(const U& d = U(), size_t h = 1) : data(d), height(h)
		{
			links = new SkipListElement*[height];
			for (size_t n = 0; n<height; n++) links[n] = nullptr;
		}

		~SkipListElement()
		{
			//delete[] links;
		}

		U data;
		SkipListElement** links;
		size_t height;
	};


public:
	SkipList(int maxHeight, double p=0.5) : prob(p), MAX_HEIGHT(maxHeight)
	{
		srand(static_cast<int>(time(nullptr)));
		head = new SkipListElement<T>(INT_MIN, MAX_HEIGHT);
	}

	~SkipList()
	{
		SkipListElement<T>* curr = head->links[0];


		// Traverse list on level 0, delete all nodes found
		if (curr)
		{
			SkipListElement<T>* next = curr->links[0];
			while (next)
			{
				delete curr;
				curr = next;
				next = curr->links[0];
			}
			delete curr;
		}

		delete head;
	}


	bool search(const T& data) const
	{
		size_t height = MAX_HEIGHT-1;
		SkipListElement<T>* current = head;

		while(true)
		{
			if(current->data == data) return true;
			if(current->links[height] == nullptr || current->links[height]->data > data)
			{
				if(height == 0) return false;
				--height;
			}
			else
				current = current->links[height];
		}
	}


	void insert(const T& data)
	{
		// YOUR IMPLEMENTATION GOES HERE
	}

	void remove(const T& data)
	{
		// YOUR IMPLEMENTATION GOES HERE
	}


	bool isEmpty() const
	{
		return head->links[0] == nullptr;
	}

	void dump()
	{
		cout<<"\n*****Skip List*****"<<"\n";
		for(int i=MAX_HEIGHT-1; i>=0; --i)
		{
			SkipListElement<T>* node = head->links[i];
			cout<<"Level "<<i<<": ";
			if(!node) cout << "/";
			else
				while(node != nullptr)
				{
					cout << node->data << "-->";
					node = node->links[i];
				}
			cout << endl;
		}
	}

private:
	size_t generateNodeHeight() const
	{
		size_t height = 1;
		double p;
		while(true)
		{
			p = (static_cast<double>(rand()) / RAND_MAX);
			if( (p < prob ) && ( height < MAX_HEIGHT)) ++height;
			else break;
		}
		return height;
	}

	double prob;
	SkipListElement<T>* head;
	const size_t MAX_HEIGHT;
};
