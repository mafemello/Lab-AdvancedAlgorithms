 
/*
	Advanced Algorithms Lab I
	Exercise 4 - Polycarp

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
#include<queue>
#include <assert.h> 
#include <unordered_map>
using namespace std;

int main (void) {

	string s; cin >> s;
	int n = s.size();

	for (int i = n-1; i >= 0; i--) { 
		if (s[i] == s[i-1]) 
			s.erase(i-1,2);		
	}

	cout << s;

	return 0;
}