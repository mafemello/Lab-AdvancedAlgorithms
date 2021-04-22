/*
	Advanced Algorithms Lab I
	Exercise 1 - Ship Priority

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
using namespace std;

// global
int n; 
std::map <string, int> order; // priority order
vector <pair <string, int>> p; // will keep track of names and status


int main (void) {

	// priority according to status
	order ["rat"] = 0;
	order ["child"] = 1;
	order ["woman"] = 1;
	order ["man"] = 2;
	order ["captain"] = 3;

	cin >> n;
	string name; string status; 

	// lets say this works for now
	for (int i = 1; i <= n; i++) {
		cin >> name >> status;
		p.push_back (make_pair(name, order[status]));
	}

	// sort pairs according to the priority 
	// sort(p.begin(), p.end(), sortbysecond);
	std::sort(p.begin(), p.end(), [](auto &left, auto &right) {
    	return left.second < right.second;
	});

	for (int i = 0; i < n; i++) 
		cout << p[i].first << endl;
	


	return 0;
}