/*
	Advanced Algorithms Lab I
	Camping Planning

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
using namespace std;

// global
int campsites = 0, nights = 0;
vector<int> dist;

bool bestTime (int guess) {
	int parcial = 0; int c = 0;
	for (int i = 0; i <= campsites; i++) {
		if (dist[i] > guess) return false; // bigger than max
		if (parcial + dist[i] > guess) {
			parcial = dist[i];
			c++;
		} else parcial += dist[i];
	}
	if (parcial) c++;
	return (c <= nights);
}


int main (void) {

	while (cin >> campsites >> nights) {

		for (int i = 0; i < campsites; i++) {
			int aux; cin >> aux;
			dist.push_back(aux);
		}

		// binary search
		int left = 0;
		int middle;
		int right = 100000;

		while (left <= right) {
			middle = left+(right-left)/2;
			if (bestTime(middle)) right = middle-1;
			else left = middle+1;
		}
		cout << right+1 << endl;
		dist.clear();
	}
	return 0;
}