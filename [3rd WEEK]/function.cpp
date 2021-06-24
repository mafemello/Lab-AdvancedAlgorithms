/*
	Advanced Algorithms Lab I
	Exercise 6 - Function
	
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
#include <limits>
using namespace std;

int main (void) {

	int num_digits = 0; string number;
	int funct[10];
	funct[0] = 0;

	cin >> num_digits >> number;

	for (int i = 1; i <= 9; i++) cin >> funct[i];

	for (int i = 0; i < num_digits; i++) {
		int current = number[i]-'0'; // converting ascii value of 0-9 characters to numerical value
		int substitute = funct[current]; 
		
		// only make changes if the number is getting bigger
		if (substitute > current) {
			int j = i;
			while (number[j]-'0' <= substitute){
				number[j] = funct[number[j]-'0'] + '0';
				j++;
			}
			break;
		}
	}

	cout << number << endl;

	return 0;	
}

