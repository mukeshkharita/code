#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v[1010];
std::vector<int> ans;
int visited[1010];
int occurrence[1010];

void dfs(int s) {
	//printf("Node: %d\n", s);
	visited[s] = 1;
	ans.push_back(s);
	if(occurrence[s] == -1)
		occurrence[s] = ans.size() - 1;
	for (int i = 0; i < v[s].size(); ++i)
	{
		if(visited[v[s][i]] == 0) {
			dfs(v[s][i]);
			ans.push_back(s);
		}
	}
}

int tree[1000010];

void build(int node, int l, int r) {
	if(l > r)
		return;
	if(l == r) {
		tree[node] = ans[l];
		//printf("Node: %d\n", tree[node]);
		return;
	}

	int mid = (l+r)/2;
	build(node*2, l, mid);
	build(node*2+1, mid+1, r);
	tree[node] = min(tree[node*2], tree[node*2+1]);
}

int query(int node, int s, int e, int l, int r) {
	if(s > e || s > r || e < l) {
		return INT_MAX;
	}
	if(s >= l && e <= r) {
		return tree[node];
	}
	int mid = (s+e)/2;
	int p = query(node*2, s , mid, l, r);
	int q = query(node*2 + 1, mid + 1, e, l, r);
	return min(p,q);
}

int main() {
	int t;
	scanf("%d",&t);
	for(int k = 1; k <= t; k++) {
		ans.clear();
		scanf("%d",&n);
		for (int i = 0; i < n; ++i)
		{
			v[i].clear();
			visited[i] = 0;
			occurrence[i] = -1;
		}
		for (int i = 0; i < n; ++i)
		{
			int m;
			scanf("%d",&m);
			for (int j = 0; j < m; ++j)
			{
				int temp;
				scanf("%d",&temp);
				v[i].push_back(temp-1);
				v[temp-1].push_back(i);
			}
		}
		dfs(0);
		int l = ans.size();
		build(1, 0, l-1);
		int m;
		scanf("%d",&m);
		printf("Case %d:\n", k);
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			scanf("%d%d",&a,&b);
			int x, y;
			x = min(occurrence[a-1], occurrence[b-1]);
			y = max(occurrence[a-1], occurrence[b-1]);
			int ans1 = query(1,0,l-1,x,y);
			printf("%d\n", ans1+1);
		}
	}
	return 0;
}

// 1
// 17
// 1 10
// 2 4 6
// 0
// 0
// 2 1 2
// 2 3 17
// 1 15
// 2 12 14
// 3 5 7 8
// 0
// 1 16
// 0
// 0
// 2 11 13
// 0
// 0
// 0
// 15
// 5 7
// 5 8
// 12 14
// 11 13
// 17 16
// 3 17
// 6 4
// 16 12
// 17 10
// 3 1
// 15 12
// 12 8
// 11 12
// 4 15
// 10 4