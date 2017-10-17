#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100010];
vector<int> set1;
vector<int> set2;
bool done[100010];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n-1; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	queue<int> q;
	q.push(1);

	queue<int> dqueue;

	long long int ans1 = 0, ans2 = 0;
	memset(done, false, sizeof(done));

	dqueue.push(1);

	while(!q.empty()) {
		int u  = q.front();
		q.pop();
		int l = dqueue.front();
		dqueue.pop();
		if(l %2 == 0)
			ans2++;
		else
			ans1++;
		//cout<<"Hello " << l << " "<< u<<endl;
		for (int i = 0; i < graph[u].size(); ++i)
		{
			if(!done[graph[u][i]]) {
				q.push(graph[u][i]);
				dqueue.push(l+1);
			}
		}
		done[u] = true;
	}
	long long int ans = (long long int) (ans1 * ans2) - (n-1);
	printf("%lld\n", ans);

}