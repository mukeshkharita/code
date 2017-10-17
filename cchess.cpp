#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
char s1[2],s2[2];
int dx[8] = {-2,-2,2,2,-1,-1,1,1};
int dy[8] = {-1,1,-1,1,2,-2,2,-2};

int dp[100][100];
bool visited[10][10];

class node {
public:
	int val,a,b;

	node(int a1, int a2, int a3) {
		val = a1;
		a = a2;
		b = a3;
	}

	bool operator < (node no) const {
        return val > no.val;
	}
};

// int ans(int s, int t) {
// 	if(dp[s][t] != 10000000)
// 		return dp[s][t];
// 	if(s == c && t == d)
// 		return 0;
// 	printf("%d %d %d\n", s,t,dp[s][t]);
// 	visited[s][t] = 1;
// 	int temp1 = s;
// 	int temp2 = t;
// 	for (int i = 0; i < 8; ++i) {
// 		temp1 = temp1 + dx[i];
// 		temp2 = temp2 + dy[i];
// 		if(temp1 >= 0 && temp1 < 8 && temp2 >= 0 && temp2 < 8) {
// 			if(visited[temp1][temp2] == -1)
// 				dp[s][t] = min(dp[s][t], ans(temp1, temp2) + temp2*t + temp1*s);
// 		temp1 = s;
// 		temp2 = t;
// 	}
// 	return dp[s][t];
// }

int main() {
	// for (int i = 0; i < 100; ++i) {
	// 	for(int j = 0; j < 100; j++) {
	// 		dp[i][j] = 10000000;
	// 		visited[i][j] = -1;
	// 	}
	// }
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%s %s",s1,s2);
		a = s1[0] - 'a';
		b = s1[1] - '1';
		c = s2[0] - 'a';
		d = s2[1] - '1';
		memset(visited, false, sizeof(visited));
		priority_queue<node> pq;
		pq.push(node(0,a,b));
		int ans = -1;
		while(!pq.empty()) {
			node u = pq.top();
			//printf("U: %d %d %d\n", u.a,u.b,u.val);
			pq.pop();
			if(u.a == c && u.b == d) {
				ans = u.val;
				break;
			}
			if(!visited[u.a][u.b]) {
				visited[u.a][u.b] = true;
				for (int i = 0; i < 8; ++i) {
					int temp1 = u.a + dx[i];
		 			int temp2 = u.b + dy[i];
		 			//printf("%d %d\n", temp1, temp2);
		 			if(temp1 >= 0 && temp1 < 8 && temp2 >= 0 && temp2 < 8 && !visited[temp1][temp2]) {
		 				pq.push(node(u.val + 1, temp1, temp2));
		 			}
				}
			} 
		}
		printf("%d\n", ans);
	}
}