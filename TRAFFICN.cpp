#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, lli> pii;
typedef pair<int, lli> pii2;
#define INF 1000010000

vector<pii> graph[10010];
vector<pii> graphrev[10010];
lli d[10010];
lli dr[10010];
bool done[10010];

class comp {
public:
	bool operator() (const pii& a, const pii& b) {
		return a.second > b.second;
	}
};

int main() {
	int t1;
	scanf("%d",&t1);
	while(t1--) {
		int n,m,e,s,t;
		scanf("%d%d%d%d%d",&n,&m,&e,&s,&t);
		for (int i = 0; i <= 10010; ++i)
		{
			graph[i].clear();
			graphrev[i].clear();
		}
		for(int i = 0; i < m; i++) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			graph[u].push_back(make_pair(v,w));
			graphrev[v].push_back(make_pair(u,w));
		}

		//For First Graph
		priority_queue<pii2, vector<pii2>, comp> pq;
		pq.push(make_pair(s,0));
		memset(done, false, sizeof(done));
		for (int i = 0; i <= n; ++i)
			d[i] = INF;
		d[s] = 0;
		while(!pq.empty()) {
			int u = pq.top().first;
			pq.pop();
			for (int i = 0; i < graph[u].size(); ++i)
			{
				int v = graph[u][i].first;
				lli w = graph[u][i].second;
				if(!done[v] && d[v] > (d[u] + w)) {
					d[v] = d[u]  + w;
					pq.push(make_pair(v,d[v]));
				}
			}
			done[u] = true;
		}

		//For Reverse Graph
		pq.push(make_pair(t,0));
		memset(done, false, sizeof(int));
		for (int i = 0; i <= n; ++i)
			dr[i] = INF;
		dr[t] = 0;
		while(!pq.empty()) {
			int u = pq.top().first;
			pq.pop();
			for (int i = 0; i < graphrev[u].size(); ++i)
			{
				int v = graphrev[u][i].first;
				lli w = graphrev[u][i].second;
				if(!done[v] && dr[v] > (dr[u] + w)) {
					dr[v] = dr[u]  + w;
					pq.push(make_pair(v,dr[v]));
				}
			}
			done[u] = true;
		}

		//Final Answer
		lli ans = d[t];
		for (int i = 0; i < e; ++i)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			lli l1 = (d[u]+dr[v]+w);
			lli l2 = (d[v]+dr[u]+w);
			if(l1 < ans) {
				ans = l1;
			}
			if(l2 < ans)
				ans = l2;
		}
		if(ans == INF)
			printf("-1\n");
		else
			printf("%lld\n", ans);

	}
	return 0;
}