/*
	Elephant IQ
	Lab Advanced Algorithms

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

// global variables
int weight, iq;
vector<pair<int,int>> elephants;

// compare function to sort vector of pairs
bool compare (pair<int, int>a, pair<int, int>b) {
	if (a.second > b.second) return true;
	else if (a.second == b.second) return (a.first < b.first);
	return false;
}

// longest increasing subsequence
void iqElephants () {	
	sort (elephants.begin(), elephants.end(), compare);

	int LIS[10000]; int path[10000];
	memset(LIS, -1, sizeof(LIS)); memset(path, -1, sizeof(path));

	LIS[0] = 1;
	int lmax = 1, start = 0, sz = (int)elephants.size();

	// lis algorithm
	for (int i = 1; i <= sz; i++){
		int aux = 0;
		for (int j = 0; j < i; j++) {
			if (elephants[i].first > elephants[j].first && elephants[i].second < elephants[j].second) {
				if (aux < LIS[j]) path[i] = j;
				aux = max(aux, LIS[j]);
			}
		}
		LIS[i] = aux+1;
		if (lmax < LIS[i]) {
			lmax = LIS[i];
			start = i;
		}
	}

	int ans = 0;
	while (start != -1) {
		start = path[start];
		ans++;
	}
	
	cout << ans << endl;
	return;
}

int main (void) {
	
	// read input
	while (cin >> weight >> iq) elephants.push_back(make_pair(weight, iq));
	iqElephants();
	elephants.clear();

	return 0;
}