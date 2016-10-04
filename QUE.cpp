#include <bits/stdc++.h>
using namespace std;

int ans[10010];

int main()
{
	vector< pair<int,int> > v;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		v.resize(n);
		memset(ans,0,sizeof(ans));
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&v[i].first);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&v[i].second);
		}
		sort(v.begin(),v.end());
		for (int i = 0; i < n; ++i)
		{
			int g = v[i].second;
			for (int j = 0; j < n; ++j)
			{
				if(g == 0 && ans[j] == 0)
				{
					ans[j] = v[i].first;
					break;
				}
				if(ans[j] ==0 )
					g--;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
}