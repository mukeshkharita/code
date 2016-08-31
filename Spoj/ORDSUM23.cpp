#include <bits/stdc++.h>
using namespace std;
long long int dp[1000010];
/*long long int ans(long long int n)
{
	if(n==2 || n==3)
		return 1;
	dp[n] = dp[n-2]+1;
	dp[n] = dp[n-3]+1;
	return ans(n-2)+1;
	return ans(n-3)+1;
}
*/
int main()
{
	long long int t,i,j,k;
	scanf("%lld",&t);
	dp[0]=0;
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;
	for(i=4;i<=1000001;i++)
	{
		dp[i] = (dp[i-2]+dp[i-3])%1000000007;
	}
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		printf("%lld\n",dp[n]);
	}
}