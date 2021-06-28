/*
	Network
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

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 100000

// global variables
vi dist; // vector of vertices
vector<vii> AdjList(5001); // lista de adj
queue<int> q;
int usersInAGroup = 0, a = 0, b = 0, numUsers = 0, groupFriends = 0;

int bfs(int s) {

	q.push(s); dist[s] = 0;

	int ans = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		ans++;
		for (int j = 0; j < (int)AdjList[u].size(); j++) {
			ii v = AdjList[u][j];

			if (dist[v.first] == INF) {
				dist[v.first] = dist[u]+1;
				q.push(v.first);
			}
		}
	}
	return ans;
}


int main (void) {
	cin >> numUsers >> groupFriends;

	for (int i = 0; i < groupFriends; i++) {
		cin >> usersInAGroup;
		if (usersInAGroup != 0) {
			cin >> a;
			for (int j = 0; j < usersInAGroup-1; j++) {
				cin >> b;
				AdjList[a-1].push_back(ii(b-1, 0));
				AdjList[b-1].push_back(ii(a-1, 0));
				a = b;
			}
		}
	}

	for (int i = 0; i < numUsers; i++) {
		dist.assign(numUsers, INF);
		cout << bfs(i) << " ";
	}
	printf("\n");
}