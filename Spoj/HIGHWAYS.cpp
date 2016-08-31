#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
#define INF 10000000000000
typedef long long int lli;
typedef pair<int,lli> pii;
vector<pii> graph[MAX];


class comp
{
public:
	bool operator() (const pii &a,const pii &b)
	{
		return a.second>b.second;
	}
};

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,source,destination;
		scanf("%d%d%d%d",&n,&m,&source,&destination);
		for (int i = 0; i < m; ++i)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			graph[u].push_back(make_pair(v,w));
			graph[v].push_back(make_pair(u,w));
		}
		priority_queue<pii,vector<pii>,comp> pq;
		pq.push(make_pair(source,0));
		lli dist[n];
		for (int i = 0; i < n; ++i)
		{
			dist[i] = INF;
		}
		
		dist[source] = 0;
		int *done = (int*)calloc(n+10,sizeof(int));
		while(!pq.empty())
		{
			int u = pq.top().first;
			pq.pop();
			for (int i = 0; i < graph[u].size(); ++i)
			{
				int v = graph[u][i].first;
				lli w = graph[u][i].second;
				if(done[v]!=1 && dist[v]>dist[u]+w)
				{
					dist[v] = dist[u]+w;
					pq.push(make_pair(v,dist[v]));
				}
			}
			done[u] = 1;
		}
		if(dist[destination]>=INF)
			printf("NONE\n");
		else
			printf("%lld\n",dist[destination]);
		for (int i = 0; i < MAX; ++i)
		{
			graph[i].clear();
		}
		free(done);
	}
}