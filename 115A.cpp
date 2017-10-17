#include <bits/stdc++.h>
using namespace std;

vector<int> graph[3000];
int level = 1;

vector<int> roots;

void dfs(int s, int l) {
	for(int i = 0; i < graph[s].size(); i++) {
		level = max(level, l+1);
		dfs(graph[s][i],l+1);
	}
}

int main() {
	int n;
	scanf("%d",&n);
	int root = 4000;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d",&a);
		if(a != -1)
			graph[a].push_back(i+1);
		else {
			roots.push_back(i+1);
		}
	}
	int ans = 0;
	for(int i = 0; i < roots.size(); i++) {
		level = 1;
		dfs(roots[i],1);
		ans = max(ans, level);
	}
	printf("%d\n", ans);
}