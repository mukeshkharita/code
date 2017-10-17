#include <bits/stdc++.h>
using namespace std;
#define MAX 2005

int dp[MAX][MAX];

int ans(int n, int k) {
	if(k == 1)
		return n;
	else {
		if(dp[n][k] != -1) {
			return dp[n][k]%1000000007;
		}
		dp[n][k] = 0;
		int ans1 = 0;
		for (int i = 1; i <= n; ++i) {
			dp[n][k] = (dp[n][k] % 1000000007 +  ans(n/i, k-1) % 1000000007) % 1000000007;
		}
		return dp[n][k] % 1000000007;
	}
}


int main() {
	int n,k;
	scanf("%d %d",&n,&k);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", ans(n,k));
}