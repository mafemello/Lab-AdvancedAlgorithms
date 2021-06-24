/*
	Coins
	Lab Advanced Algorithms

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
#define INF 1000000007

// global
int number_coins, desired_sum;
vector<int> coins;

void distinctWays () {
	long long int MEMO[desired_sum+1] = {0};
	//memset(MEMO, 0, sizeof(MEMO));
	MEMO[0] = 1;
	
	//uptade MEMO value 
	for (int i = 1; i <= desired_sum; i++) {
		for (int j = 0; j < number_coins; j++) {
			// bigger than current coin
			if (i-coins[j] > 0) MEMO[i] += (MEMO[i-coins[j]])%INF;
			else if (i-coins[j] == 0) MEMO[i]+=1;
		}	
	}

	printf ("%lld\n", MEMO[desired_sum]%INF);

	return;
}



int main (void) {

	cin >> number_coins >> desired_sum;
	
	for (int i = 0; i < number_coins; i++) {
		int aux; cin >> aux;
		coins.push_back(aux);
	}

	distinctWays();
	coins.clear();
	return 0;
}