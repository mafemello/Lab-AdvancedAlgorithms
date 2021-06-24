/*
	SuperSale
	Lab Advanced Algorithms

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;

// global
int test_cases, number_objects, price, weight, number_people, max_weight, ans=0;
vector<pair<int,int>> obj;
int MEMO[31];

void SuperSale (int level, int current) {

	if (MEMO[current] > MEMO[current - obj[level].second] + obj[level].first)
		MEMO[current] = MEMO[current];
	else MEMO[current] = MEMO[current - obj[level].second] + obj[level].first;

	return;
}


int main (void) {

	cin >> test_cases;
	while (test_cases--) {
		ans = 0;
		cin >> number_objects;
		for (int i = 0; i < number_objects; i++) {
			cin >> price >> weight;
			obj.push_back(make_pair(price, weight));
		}
		cin >> number_people;
		for (int i = 0; i < number_people; i++) {
			cin >> max_weight;
			memset(MEMO, 0, sizeof(MEMO));

			for (int j = 0; j < number_objects; j++) {
				int object_weight = obj[j].second;
				for (int k = max_weight; k >= object_weight; k--) {
					SuperSale(j, k);
				}
			}
			ans += MEMO[max_weight];
		}
		obj.clear();
		cout << ans << endl;
	}

	return 0;
}