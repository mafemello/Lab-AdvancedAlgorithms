 
/*
	Advanced Algorithms Lab I
	Exercise 3 - IPs

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

int main (void) {

	int servers = 0, commands = 0;
	cin >> servers >> commands;

	map <string,string> m;

	for (int i = 0; i < servers; i++) {
		string name, ips;
		cin >> name >> ips;
		ips += ';';
		m[ips] = name;
	}

	for (int i = 0; i < commands; i++) {
		string com, ip;
		cin >> com >> ip;
		cout << com << " " << ip << " " << "#" << m[ip] << endl;
	}

	return 0;
}