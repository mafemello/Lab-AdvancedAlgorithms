/*
	Advanced Algorithms Lab I
	Exercise 5 - Badges
	
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
#include <limits>
using namespace std;

int main (void) {

	int n = 0;
	map<int,int> m;

	cin >> n;

	for (int i = 1; i <= n; i++) m[i] = 0;
	

	for (int i = 1; i <= n; i++) {
		int badge = 0;
		cin >> badge;
		m[badge]++;
	}	

	// procura a maior e a menor frequencia no map
	int maior = INT8_MIN, menor = INT8_MAX;
	int ans1 = 0, ans2 = 0;
	for (auto i:m) {
		if (i.second > maior) {
			maior = i.second;
			ans1 = i.first;
		}
		if (i.second < menor) {
			menor = i.second;
			ans2 = i.first;
		}
	}

	cout << ans2-ans1 << endl;
	return 0;
}
