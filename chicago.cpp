#include <bits/stdc++.h>
using namespace std;
#define MAX 500
#define INF -1
#define mp make_pair
typedef long long int lli;
typedef pair<int , double> pii;

vector<pii> graph[MAX];
bool done[MAX];
double dist[MAX];

class comp {
public:
	bool operator() (const pii& a, const pii& b) {
		return a.second < b.second;
	}
};

int main() {
	while(1) {
		for (int i = 0; i <= MAX; ++i) {
			graph[i].clear();
		}
		int n, m;
		scanf("%d%d",&n,&m);
		if(n == 0)
			break;
		for (int i = 0; i < m; ++i)
		{
			int u,v;
			double w;
			scanf("%d %d %lf",&u,&v,&w);
			double d = w / 100.0;
			graph[u].push_back(mp(v,d));
			graph[v].push_back(mp(u,d));
		}
		priority_queue<pii, vector<pii>, comp> pq;
		pq.push(mp(1,0.0));
		memset(done, false, sizeof(done));
		for (int i = 0; i <= n; ++i) {
			dist[i] = -1.0;
		}
		dist[1] = 1.0;
		while(!pq.empty()) {
			int u = pq.top().first;
			pq.pop();

			for (int i = 0; i < graph[u].size(); ++i) {
				int v = graph[u][i].first;
				double w = graph[u][i].second;
				if(!done[v] && dist[v] < dist[u] * w) {
					dist[v] = dist[u] * w;
					pq.push(mp(v,dist[v]));
				}
			}
			done[u] = true;
		}

		printf("%0.6lf percent\n", dist[n]*100);
	}
	return 0;
}