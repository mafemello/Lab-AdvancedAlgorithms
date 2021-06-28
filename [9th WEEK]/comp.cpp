/*
	Find Connections - graphs
	Lab Advanced Algorithms

	Maria Fernanda Lucio de Mello
	nUSP: 11320860
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// global variables
int computers = 0, connections = 0;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi dist; // vector of vertices
vector<vii> AdjList(200); // lista de adj

queue<int> q;
#define ON 1
#define OFF 0
#define INF 100000
			

int route(int s) {

	q.push(s);
	dist[s] = 0;

	while (!q.empty()) {
		int u = q.front(); q.pop();

		for (int j = 0; j < (int)AdjList[u].size(); j++) {
			ii v = AdjList[u][j];

			if (dist[v.first] == INF) {
				dist[v.first] = dist[u]+1;
				q.push(v.first);
			}
		}
	}

	return dist[computers-1]+1;
	
}

int main (void) {
	
	// read input
	cin >> computers >> connections;

	// marking availabe connections
	for (int i = 0; i < connections; i++) {
		int a, b;
		cin >> a >> b;
		AdjList[a-1].push_back(ii(b-1, ON));
		AdjList[b-1].push_back(ii(a-1, ON));
	}

	dist.assign(computers, INF);

	if (route(0) >= INF) cout << "IMPOSSIBLE" << endl;
	else cout << route(0) << endl;

	return 0;
}