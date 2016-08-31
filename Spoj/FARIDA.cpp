#include <bits/stdc++.h>
using namespace std;

long long int dp[10001];
int main()
{
	long long int t,i,j,k,testcase=1;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		long long int arr[n];
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		dp[0] = arr[0];
		dp[1] = max(arr[0],arr[1]);
		for(i=2;i<n;i++)
		{
			dp[i] = max(dp[i-2]+arr[i],dp[i-1]);
		}
		printf("Case %lld: %lld\n",testcase,dp[n-1]);
		testcase++;
	}
}