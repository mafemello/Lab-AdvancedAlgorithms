/*
	Edit Distance
	Lab Advanced Algorithms

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdio>
#include <cstring>
using namespace std;

// global variables
string original, target;
int m = 0, n = 0;

int solvePermutation () {

	vector<vector<int>> DP(m+1,vector<int>(n+1));

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0) DP[i][j] = j;
			else if (j == 0) DP[i][j] = i;
			else if (original[i-1] == target[j-1]) DP[i][j] = DP[i-1][j-1];
			else DP[i][j] = 1 + min(DP[i][j-1], min(DP[i - 1][j], DP[i-1][j-1])); 
		}
	}
	
	return DP[m][n];
}

int main (void) {
	
	// read input
	cin >> original >> target;
	m = original.size();
	n = target.size();

	cout << solvePermutation () << endl;

	return 0;
}