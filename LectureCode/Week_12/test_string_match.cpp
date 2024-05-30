#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include "string_match.h"

int main() {
	string text, pattern;
	vector<int> precompute;

	cout << "entry a pattern for naive matching:" << endl;
	getline(cin, pattern);
	cout << "entry a text for naive matching:" << endl;
	getline(cin, text);
	if (text.size() < pattern.size()) {
		cout << "error: " << pattern << " is longer then " << text;
	}

	if (naiveMatch(pattern, text)) {
		cout << pattern << " is found in " << text << endl;
	} else {
		cout << pattern << " is not found in " << text << endl;
	}

	cout << "entry a pattern for hash matching:" << endl;
	getline(cin, pattern);
	cout << "entry a text for hash matching:" << endl;
	getline(cin, text);
	if (text.size() < pattern.size()) {
		cout << "error: " << pattern << " is longer then " << text;
	}

	if (hashMatch(pattern, text)) {
		cout << pattern << " is found in " << text << endl;
	} else {
		cout << pattern << " is not found in " << text << endl;
	}

	cout << "entry a pattern for the following texts:" << endl;
	getline(cin, pattern);
	prepareMatch(pattern, precompute);
	do {
		cout << "entry a text:" << endl;
		getline(cin, text);
		if (text.size() < pattern.size()) {
			cout << "error: " << pattern << " is longer then " << text;
		}
	} while (fastMatch(pattern, text, precompute));
}
