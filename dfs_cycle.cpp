#include <bits/stdc++.h>
using namespace std;

vector<int> v[10000];
int visited[10000];
int parent[10000];

int ans;
int flag = 0;
int des;
std::vector<int> f;

void dfs(int s) {
	visited[s] = 1;
	for(int i = 0; i < v[s].size(); i++) {
		if(visited[v[s][i]] == 0) {
			parent[v[s][i]] = s;
			dfs(v[s][i]);
		}
		else {
			flag = 1;
			ans = s;
			des = v[s][i];
			break;
		}
	}
}

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < m; ++i)
	{
		int u,w;
		scanf("%d%d",&u,&w);
		v[u].push_back(w);
		parent[i+1] = i+1;
	}
	dfs(1);
	int i = ans;
	if(flag) {
		while(1) {
			f.push_back(i);
			i = parent[i];
			if(i == des)
				break;
		}
		f.push_back(i);
		sort(f.begin(), f.end());
		for (int i = 0; i < f.size(); ++i)
		{
			printf("%d ", f[i]);
		}
		printf("\n");
	} else {
		printf("0\n");
	}
}