/*
	Advanced Algorithms Lab I
	Exercise 2 - Argus

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
vector<vector<int>> p;

// comparator to make min_heap using priority_queue
struct my_comparator {
	bool operator() (std::vector<int> const& a, std::vector<int> const& b) const {
		assert(a.size() == 3);
		assert(b.size() == 3);

		return a[2] > b[2] || (a[2] == b[2] && a[0] > b[0]);
	}
};


int main (void) {

	string reg;
	int id, t;
	priority_queue <vector<int>, vector<vector<int>>, my_comparator> q;

	cin >> reg;
	while (reg[0] != '#') {
		cin >> id >> t;
		cin >> reg;
		vector<int> v;
		v.push_back (id); v.push_back (t); v.push_back (t);
		p.push_back(v);
		q.push(v);
	}

	int k = 0; cin >> k;

	// counting the time
	while (k--) {
		vector<int> tmp = q.top();
		q.pop();
		cout << tmp[0] << endl; // id
		tmp[2] += tmp[1];
		q.push(tmp);
	}


	return 0;
}