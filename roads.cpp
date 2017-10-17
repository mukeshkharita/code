#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define MAX 10010
#define INF 1000000000

typedef long long int lli;
typedef pair<int, lli> pii1;
typedef pair<pii1, lli> pii;

vector<pii> graph[MAX];
bool done[110][MAX];

class comp {
public:
	bool operator() (const pii& a, const pii& b) {
		if(a.first.second == b.first.second)
			return a.second > b.second;
		else
			return a.first.second > b.first.second;
	}
};

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		for (int i = 0; i < MAX; ++i) {
			graph[i].clear();
		}
		int k, n, m;
		scanf("%d %d %d",&k,&n,&m);
		for (int i = 0; i < m; ++i) {
			int u, v, w, x;
			scanf("%d %d %d %d",&u,&v,&w,&x);
			graph[u].push_back(mp(mp(v,w),x));
		}

		priority_queue<pii, vector<pii>, comp> pq;
		pq.push(mp(mp(1,0),0));
		memset(done, false, sizeof(done));
		lli ans = -1;
		while(!pq.empty()) {
			pii u = pq.top();
			int so = u.first.first;
			pq.pop();
			if(done[so][u.second])
				continue;
			done[so][u.second] = true;
			if(so == n) {
				ans = u.first.second;
				break;
			}

			for (int i = 0; i < graph[so].size(); ++i) {
				int v = graph[so][i].first.first;
				lli w = graph[so][i].first.second;
				lli tol = graph[so][i].second;
				if((u.second + tol) <= k) {
					pq.push(mp(mp(v,u.first.second + w), u.second + tol));
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}