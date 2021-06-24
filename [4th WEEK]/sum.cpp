/*
	Advanced Algorithms Lab I
	Exercise 7 - sum == total

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
int total, n;
vector<int> vec;
vector<int> candidate;


void backtracking(int index, int current_sum, int &none) {

    if (current_sum == total) {
    	none = 1; // true 
    	int sz = candidate.size();
        for (int i = 0; i < sz; i++) {
            cout << candidate[i];
            if (i != sz-1) cout << "+"; // if not the last element
        }
        cout << endl;
        return;
    }
 
    for (int i = index; i < (int)vec.size(); i++) {
        if (!((current_sum + vec[i] > total) || (i > index && vec[i] == vec[i-1]))) {
	        candidate.push_back(vec[i]);
	        backtracking (i+1, current_sum+vec[i], none); // test candidate vector
	        candidate.pop_back();
	    }
    }
}
 

int main (void) {

	cin >> total >> n;

	while (total != 0 && n != 0) {
	
		vec.clear();

		for (int i = 0; i < n; i++){
			int num = 0; cin >> num;
			vec.push_back(num);
		}
		
		candidate.clear();
		int none = 0; // false 
		cout << "Sums of " << total << ":" << endl;
    	backtracking (0, 0, none);
    	if (none == 0) cout << "NONE" << endl;

    	cin >> total >> n;
	}


	return 0;
}