#include<iostream>
#include"SkipList.h"

using namespace std;


int main()
{
	SkipList<int> sl(5);
	for(int i=0; i< 10; i++) sl.insert(i);
	sl.dump();
	cout << "\n";

	for (int i = 0; i< 20; i+=2) cout << "search(" << i << ") = " << boolalpha << sl.search(i) << endl;
	cout << "\n";

	for(int i=0; i< 10; i+=2) {
		cout << "remove(" << i << ") :";
		sl.remove(i);
		sl.dump();
		cout << endl;
	}

	return 0;
}
