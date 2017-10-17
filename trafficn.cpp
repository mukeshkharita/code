#include <bits/stdc++.h>
using namespace std;
#define MAX 10010
#define INF 1000010000
#define mp make_pair
typedef long long int lli;
typedef pair<int , lli> pii;

vector<pii> graph[MAX];
vector<pii> rev_graph[MAX];

bool done[MAX];

lli dst[MAX];
lli dts[MAX];

class comp {
public:
	bool operator() (const pii& a, const pii& b) {
		return a.second > b.second;
	}
};

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		int n,m,k,s,t;
		scanf("%d %d %d %d %d",&n,&m,&k,&s,&t);
		for (int i = 1; i <= n; ++i) {
			graph[i].clear();
			rev_graph[i].clear();
		}
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d",&u,&v,&w);
			graph[u].push_back(mp(v,w));
			rev_graph[v].push_back(mp(u,w));
		}

		priority_queue<pii, vector<pii>, comp> pq;
		//First Directed Graph
		for (int i = 1; i <= n; ++i) {
			dst[i] = INF;
		}
		dst[s] = 0;
		memset(done, false, sizeof(done));
		pq.push(mp(s, 0));
		while(!pq.empty()) {
			int u = pq.top().first;
			pq.pop();
			for (int i = 0; i < graph[u].size(); ++i) {
				int v = graph[u][i].first;
				lli w = graph[u][i].second;
				if(!done[v] && dst[v] > dst[u]+w) {
					dst[v] = dst[u] + w;
					pq.push(mp(v, dst[v]));
				}
			}
			done[u] = true;
		}

		//For Reverse Graph
		for (int i = 1; i <= n; ++i){
			dts[i] = INF;
		}
		memset(done, false, sizeof(done));
		pq.push(mp(t,0));
		dts[t] = 0;

		while(!pq.empty()) {
			int u = pq.top().first;
			pq.pop();
			for (int i = 0; i < rev_graph[u].size(); ++i) {
				int v = rev_graph[u][i].first;
				lli w = rev_graph[u][i].second;
				if(!done[i] && dts[v] > dts[u] + w) {
					dts[v] = dts[u] + w;
					pq.push(mp(v,dts[v]));
				}
			}
			done[u] = true;
		}

		//Logic
		lli ans = dst[t];
		for (int i = 0; i < k; ++i)
		{
			int u, v, w;
			scanf("%d%d%d",&u,&v,&w);
			ans = min(ans, min((dst[u]+w+dts[v]), (dst[v]+w+dts[u])));
		}
		if(ans == INF)
			printf("-1\n");
		else
			printf("%lld\n", ans);
	}
	return 0;
}