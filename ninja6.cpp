#include <bits/stdc++.h>
using namespace std;

#define MAX 3010
#define INF 1000000000

class node {
public:
	int u,weight,cartaken;
	node(int a, int b, int c) {
		u = a;
		weight = b;
		cartaken = c;
	}
};

class cmp {
public:
	bool operator() (const node& a, const node& b) {
		return a.weight > b.weight;
	}
};

vector<int> adj[MAX];
vector<int> w[MAX];
vector<int> car[MAX];

long long int d[3010][2];
bool done[3010][2];


int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		for (int i = 0; i < MAX; ++i) {
			adj[i].clear();
			w[i].clear();
			car[i].clear();
		}
		int n,m;
		scanf("%d %d",&n,&m);
		for (int i = 0; i < m; ++i) {
			int a, b, c, d;
			scanf("%d %d %d %d",&a,&b,&c,&d);
			adj[a].push_back(b);
			w[a].push_back(c);
			car[a].push_back(d);
			adj[b].push_back(a);
			w[b].push_back(c);
			car[b].push_back(d);
		}
		int s, dest;
		scanf("%d%d",&s,&dest);
		priority_queue<node,vector<node>,cmp> pq;
		pq.push(node(s,0,0));
		for (int i = 0; i < MAX; ++i) {
			d[i][0] = INF;
			d[i][1] = INF;
		}
		long long int ans = -1;
		memset(done,false, sizeof(done));
		d[s][0] = 0;
		while(!pq.empty()) {
			node n = pq.top();
			pq.pop();
			int u = n.u;
			//printf("U: %d\n", u);
			int dist = n.weight;
			int taken = n.cartaken;
			if(u == dest) {
				ans = dist;
				break;
			}

			for (int i = 0; i < adj[u].size(); ++i) {
				int v = adj[u][i];
				long long int wp = w[u][i];
				int car1 = car[u][i];
				if(taken == 0) {
					if(!done[v][0] && d[v][0] > dist + wp) {
						d[v][0] = dist + wp;
						pq.push(node(v,d[v][0],0));
					}
					if(!done[v][1] && d[v][1] >dist + car1) {
						d[v][1] = dist + car1;
						pq.push(node(v,d[v][1],1));
					}
				} else {
					if(!done[v][1] && d[v][1] > dist + wp) {
						d[v][1] = dist + wp;
						pq.push(node(v,d[v][1],1));
					}
				}
			}
			done[u][taken] = true;
		}
		printf("%lld\n", ans);
	}
}