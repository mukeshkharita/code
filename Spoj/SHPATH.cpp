#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000
#define MAX 1000010
typedef long long int lli;
typedef pair<int,lli> pii;


struct node
{
int v;
int price;
} temp;
vector<struct node> graph[MAX];
class comp
{
public:
	bool operator() (const pii &a,const pii &b)
	{
		return a.second>b.second;
	}
};
void scanint(int &x)
{
    register int c = getchar_unlocked();
    x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked());
    for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
}
inline void fastRead_string(char *str)
{
    register char c=0;
    register int i = 0;
    while (c < 33)
        c = getchar_unlocked();
    while (c > 65)
    {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }

    str[i] = '\0';
}
int main()
{
	int t;
	scanint(t);
	while(t--)
	{
		map<string,int> city;
		int n;
		scanint(n);
		for (int i = 0; i < n; ++i)
		{
			char a[100];
			fastRead_string(a);
			city[a] = i+1;
			int nr;
			scanint(nr);
			for (int j = 0; j < nr; ++j)
			{
				int index,cost;
				scanint(temp.v);
				scanint(temp.price);

				graph[i+1].push_back(temp);
			}
		}
		int queries;
		scanint(queries);
		while(queries--)
		{
			char s[10000],d[10000];
			fastRead_string(s);
			fastRead_string(d);
			int source = city.find(s)->second;
			int destination = city.find(d)->second;
			
			priority_queue<pii,vector<pii>,comp> pq;
			pq.push(make_pair(source,0));
			lli dist[n + 1];
			for (int i = 0; i <= n; ++i)
			{
				dist[i] = INF;
			}
			
			dist[source] = 0;
			int *done = (int*)calloc(n+10,sizeof(int));
			while(!pq.empty())
			{
				int u = pq.top().first;
				pq.pop();
				if(done[u]==1)
					continue;
				for (int i = 0; i < graph[u].size(); ++i)
				{
					int v = graph[u][i].v;
					lli w = graph[u][i].price;
					if(done[v]!=1 && dist[v]>dist[u]+w)
					{
						dist[v] = dist[u]+w;
						pq.push(make_pair(v,dist[v]));
					}
				}
				done[u] = 1;
			}
			printf("%lld\n",dist[destination]);
			free(done);
		}
		for (int i = 0; i <= n; ++i)
		{
			graph[i].clear();
		}
		
	}
}