#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int, lli> pii;

int freq[100000];

class comp {
    public:
        bool operator() (const pii& a, const pii& b) {
            return a.second < b.second;
        }
};

class cmp {
    public:
        bool operator() (const pii& a, const pii& b) {
            return a.second > b.second;
        }
};


bool comparator(const pii& a, const pii& b) {
    return a.second > b.second;
}
int main()
{
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    priority_queue<pii, vector<pii>, comp> pq[m+1];
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            int l;
            scanf("%d",&l);
            pq[i].push(make_pair(j,l));
        }
    }
    
    priority_queue<pii, vector<pii>, cmp> cost;
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
        cost.push(make_pair(i+1,a[i]));
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= k; j++) {
            int u = pq[i].top().first;
            pq[i].pop();
            freq[u]++;
        }
    }
    vector<pii> ans;
    for(int i = 1; i <= m; i++) {
        ans.push_back(make_pair(i,freq[i]));
    }
    
    sort(ans.begin(),ans.end(), comparator);
    for(int i = n-1; i >= n-k;i--)
        cout<<ans[i].first<<" ";
    printf("\n");
    
    return 0;
}
