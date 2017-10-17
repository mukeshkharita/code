#include <bits/stdc++.h>
using namespace std;

#define INF 1001000000
#define mp make_pair
#define MAX 1000100

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
	int t;
	scanf("%d",&t);
	while(t--) {
		for (int i = 0; i < MAX; ++i)
		{
			graph[i].clear();
			rev_graph[i].clear();
		}
		int n,q;
		scanf("%d %d",&n,&q);
		for (int i = 0; i < q; ++i) {
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			graph[u].push_back(mp(v,w));
			rev_graph[v].push_back(mp(u,w));
		}

		//For first graph
		priority_queue<pii, vector<pii>, comp> pq;
		pq.push(mp(1,0));
		for (int i = 1; i <= n; ++i){
			dst[i] = INF;
		}
		dst[1] = 0;
		memset(done, false, sizeof(done));
		while(!pq.empty()) {
			int u = pq.top().first;
			pq.pop();

			for (int i = 0; i < graph[u].size(); ++i) {
				int v = graph[u][i].first;
				lli w = graph[u][i].second;
				if(!done[v] && dst[v] > dst[u] + w) {
					dst[v] = dst[u] + w;
					pq.push(mp(v, dst[u]));
				}
			}
			done[u] = true;
		}

		//For Reversed Graph

		for (int i = 1; i <= n; ++i) {
			dts[i] = INF;
		}
		pq.push(mp(1,0));
		dts[1] = 0;
		memset(done, false, sizeof(done));
		while(!pq.empty()) {
			int u = pq.top().first;
			pq.pop();

			for (int i = 0; i < rev_graph[u].size(); ++i) {
				int v = rev_graph[u][i].first;
				lli w = rev_graph[u][i].second;
				if(!done[v] && dts[v] > dts[u] + w) {
					dts[v] = dts[u] + w;
					pq.push(mp(v, dts[v]));
				}
			}
			done[u] = true;
		}

		lli ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans += (dst[i] + dts[i]);
		}
		printf("%lld\n", ans);

	}
}