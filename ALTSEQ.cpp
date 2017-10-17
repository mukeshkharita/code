#include <bits/stdc++.h>
using namespace std;

long long int n, a[100100];
long long int dp[100100];

bool signOfValue(int u, int v) {
	return (u > 0 && v < 0) || (u < 0 && v > 0);
}

long long int lis(long long int index) {
	if(dp[index] != -1)
		return dp[index];
	if(index >= n) {
		return  0;
	} else {
		for (long long int i = index + 1; i < n; ++i)
		{
			if(abs(a[i]) > abs(a[index]) && signOfValue(a[index], a[i])) {
				return dp[index] = max(1 + lis(i), lis(index + 1));
			}
		}
	}
	dp[index] = 1;
	return 1;
}

int main() {
	scanf("%lld",&n);
	for (long long int i = 0; i < n; ++i)
	{
		scanf("%lld",&a[i]);
		dp[i] = -1;
	}

	printf("%lld\n", lis(0));
}