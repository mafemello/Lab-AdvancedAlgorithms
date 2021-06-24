/*
	Advanced Algorithms Lab I
	Exercise 8 - Passwords

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <assert.h> 
#include <unordered_map>
using namespace std;

// global
int numWords;
string word, numbers[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
vector<string> dict;

void dfs (int index, string cur) {

	if (index == (int) word.size()) {
		cout << cur << endl;
		return;
	} else if (word[index] == '0') {
		for (int i = 0; i < 10; i++) dfs (index + 1, cur + numbers[i]);
	} else if (word[index] == '#') {
		for (int i = 0; i < numWords; i++) dfs (index + 1, cur + dict[i]);
	}
}


int main (void) {
 

	while (cin >> numWords) {

		dict.clear();
		for (int i = 0; i < numWords; i++) {
			cin >> word;
			dict.push_back(word);
		}

		int numRules; cin >> numRules;
		cout << "--" << endl;

		for (int i = 0; i < numRules; i++) {
			cin >> word; 
			dfs (0, "");
		}
	}
	return 0;
}