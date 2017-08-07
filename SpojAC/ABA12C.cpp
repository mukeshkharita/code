#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[1001];
long long int dp[1010][1010];

long long int price(int packets, int kgs) {
	if(kgs == k)
		return 0;
	if(kgs > k) {
		return LLONG_MAX;
	}
	if(packets >= n && kgs < k) {
		return LLONG_MAX;
	}
	if(dp[packets][kgs] != -1)
		return dp[packets][kgs];
	dp[packets][kgs] = LLONG_MAX;
	for (int i = 1; i <= k; ++i)
	{
		if((kgs + i) > k)
			continue;

		long long ans = price(packets+1,kgs+i);
		if(ans == LLONG_MAX)
			continue;

		if(a[i] != -1)
			dp[packets][kgs]=min(dp[packets][kgs], a[i]+ans);
	}
	return dp[packets][kgs];
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		for (int i = 0; i < 1010; ++i)
		{
			for(int j = 0; j < 1010; ++j) 
				dp[i][j] = -1;
		}
		scanf("%d%d",&n,&k);
		for (int i = 1; i <= k; ++i)
		{
			scanf("%d",&a[i]);
		}
		long long x = price(0,0);
		printf("%lld\n", price(0,0) == LLONG_MAX ? -1 : price(0,0));
	}
	return 0;
}