#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
typedef long long ll;
typedef long double lf;
const int N = 500;
const int M = 1000;
const int W = 100;

vector<pair<pii, int> > edges;
vector<int> g[N];
lf INF = 1e18;
lf d[N];
bool visited[N];
bool can_go[N][N];

void dfs(int r, int v)
{
	//printf("%d %d\n",r,v );
	visited[v] = 1;
	can_go[r][v] = 1;
	for (int i = 0; i < g[v].size(); ++i)
	{
		int u = g[v][i];
		//printf("U: %d\n",u);
		if(!visited[u])
			dfs(r,u);
	}
}

int main()
{
	int tests;
	scanf("%d",&tests);
	while(tests--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		edges.clear();
		for (int i = 0; i < n; ++i)
		{
			g[i].clear();
		}
		for (int i = 0; i < m; ++i)
		{
			int u,v,w;
			scanf("%d%d%d",&v,&u,&w);
			--v;
			--u;
			edges.push_back({{v,u},w});
			//edges.push_back(make_pair(make_pair(u,v),w));
			g[v].push_back(u);
		}
		int s,t;
		scanf("%d%d",&s,&t);
		--s;
		--t;
		//printf("Edges: %d\n",(int)edges.size());
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				can_go[i][j] = 0;
			}
		}
		for (int v = 0; v < n; ++v)
		{
			for (int i = 0; i < n; ++i)
			{
				visited[i] = 0;
			}
			//printf("%d\n",v);
			dfs(v,v);
		}
		if(!can_go[s][t])
		{
			printf("-1\n");
			continue;
		}
		//printf("Mukesh\n");
		const lf EPS = 1e-9;
        lf a = -W;
        lf b = W;
		while(b-a > EPS)
		{
			lf m = (a+b)/2;
			//cout<<"M: "<<m<<endl;
			for (int i = 0; i < n; ++i)
			{
				d[i] = INF;
			}
			d[s] = 0;
			for (int k = 1; k <= n-1; ++k)
			{
				for (int i = 0; i < (int)(edges.size()); ++i)
				{
					int v = edges[i].first.first;
					int u = edges[i].first.second;
					lf w = edges[i].second - m;
					d[u] = min(d[u],d[v]+w);
					//printf("%d %d %llf\n", u,v,w);
				}
			}
			bool negative_cycle = 0;
			for (int i = 0; i < (int)(edges.size()); ++i)
			{
				int v = edges[i].first.first;
				int u = edges[i].first.second;
				lf w = edges[i].second - m;
				if(d[v]+w < d[u] && can_go[s][u] && can_go[u][t])
				{
					negative_cycle = 1;
				}
			}
			if(d[t] <= 0 || negative_cycle)
			{
				b = m;
			}
			else
			{
				a = m;
			}

		}
		cout << setprecision(14) <<fixed << (a+b)/2<<endl;

	}
	return 0;
}