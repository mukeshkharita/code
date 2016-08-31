#include <iostream>
#include <cstdio>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

typedef long long ll;
typedef long double lf;

const int N = 500;
const int M = 1000;
const int W = 100;

vector<pair<pii, int>> edges;
vi g[N];

lf INF = 1e18;
lf d[N];

bool visited[N];
bool can_go[N][N];

void dfs(int r, int v)
{
    //cout<< r <<" "<< v<<endl;
    visited[v] = 1;
    can_go[r][v] = 1;
    FOR(i, g[v].size())
    {
        int u = g[v][i];
       // cout<< "U: "<<u<<endl;
        if(!visited[u]) dfs(r, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int tests;
    cin >> tests;
    int cnt = 0;
    while(tests--)
    {
        ++cnt;
        int n, m;
        cin >> n >> m;
        assert(n >= 1 && n <= N);
        assert(m >= 1 && m <= M);
        edges.clear();
        FOR(i, n) g[i].clear();
        FOR(i, m)
        {
            int v, u;
            int w;
            cin >> v >> u >> w;
            assert(v >= 1 && v <= n);
            assert(u >= 1 && u <= n);
            //TODO: no self loops assertion - is it valid?
            assert(v != u);
            //TODO: is this range correct?
            assert(w >= 0 && w <= W);
            --v; --u;
            edges.pb({{v, u}, w});
            g[v].pb(u);
        }
        int s, t;
        cin >> s >> t;
        cout<<"Edges: "<<edges.size()<<endl;
        assert(s >= 1 && s <= n);
        assert(t >= 1 && t <= n);
        --s; --t;
        FOR(i, n) FOR(j, n) can_go[i][j] = 0;
        FOR(v, n)
        {
            FOR(i, n) visited[i] = 0;
            cout<<v<<endl;
            dfs(v, v);
        }
        if(!can_go[s][t])
        {
            cout << -1 << endl;
            continue;
        }
        const lf EPS = 1e-9;
        lf a = -W;
        lf b = W;
        while(b - a > EPS)
        {
            lf m = (a + b) / 2;
            cout<<"M: "<<m<<endl;
            FOR(i, n) d[i] = INF;
            d[s] = 0;
            REP(k, 1, n - 1)
            {
                FOR(i, SZ(edges))
                {
                    int v = edges[i].fi.fi;
                    int u = edges[i].fi.se;
                    lf w = edges[i].se - m;
                    REMIN(d[u], d[v] + w);
                }
            }
            bool negative_cycle = 0;
            FOR(i, SZ(edges))
            {
                int v = edges[i].fi.fi;
                int u = edges[i].fi.se;
                lf w = edges[i].se - m;
                if(d[v] + w < d[u] && can_go[s][u] && can_go[u][t])
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
        cout << setprecision(14) << fixed << (a + b) / 2 << endl;
    }
    return 0;
}
