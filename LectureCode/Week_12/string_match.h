#include <iostream>
#include <string>
#include <vector>

bool naiveMatch(string pat, string txt) {
	size_t n = txt.length();
	size_t m = pat.length();

	for (int i = 0; i <= n - m; i++) {	// try all potential starting indices
		bool found = true;
		for (int j = 0; j < m && found; j++) {	// use boolean flag `found'
			if (pat[j] != txt[i + j]) {	// if mismatch found
				found = false;	// abort this, shift starting index i by +1
			}
		}
		if (found) {			// if pat[0 .. m - 1] == txt[i .. i + m - 1]
			return true;
		}
	}
	return false;
}

#define ALPHABET 256
#define Q 101

bool hashMatch(string pat, string txt) {
	size_t n = txt.length(), m = pat.length();
	int i, j, p = 0, t = 0, h = 1;

	// Calculate the hash value of pat and first window of txt
	for (i = 0; i < m; i++) {
		h = (h * ALPHABET) % Q; // precompute
		p = (ALPHABET * p + pat[i]) % Q;
		t = (ALPHABET * t + txt[i]) % Q;
	}

	// Slide the pat over txt one by one
	for (i = 0; i <= n - m; i++) {
		// Check the hash values
		if (p == t) {
			/* Check for characters one by one */
			for (j = 0; j < m; j++) {
				if (txt[i + j] != pat[j])
					break;
			}
			if (j == m) {
				return true;
			}
		}
		// Calculate hash value for next window of txt: Remove
		// leading digit, add trailing digit
		if (i < n - m) {
			t = (ALPHABET * t - txt[i] * h + txt[i + m]) % Q;
			// We might get negative value of t, converting it to positive
			if (t < 0)
				t = (t + Q);
		}
	}
	return false;
}

void prepareMatch(string pat, vector<int>& b) {	// call this before calling fastMatch()
	int i = 0, j = -1;
	size_t m = pat.length();

	b.resize(m);
	b[0] = -1;					// starting values
	while (i < m) {				// pre-process the pat string
		while (j >= 0 && pat[i] != pat[j]) {
			j = b[j];			//if different, reset j using b
		}
		i++;
		j++;					// if same, advance both pointers
		b[i] = j;
	}
}

bool fastMatch(string pat, string txt, vector<int>& b) {	// similar to above, but on txt
	int i = 0, j = 0;	// starting values
	size_t n = txt.length();
	size_t m = pat.length();

	while (i <= n) {			// search through txt string
		while (j >= 0 && txt[i] != pat[j])
			j = b[j];			//if different, reset j using b
		i++;
		j++;					// if same, advance both pointers
		if (j == m) {			// a match found when j == m
			j = b[j];			// prepare j for the next possible match
			return true;
		}
	}
	return false;
}
