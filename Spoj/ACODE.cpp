#include <bits/stdc++.h>
using namespace std;
/*int main()
{
	char s[101000];
	int i;
	long long int dp[10100];
	while(1)
	{
		scanf("%s",s);
		if(s[0]=='0')
			break;
		int l = strlen(s);
		dp[0] = 1;
		dp[1] = 1;
		for(i=2;i<=l;++i)
		{
			dp[i] = 0;
			char c1 = s[i-2]-'0';
			char c2 = s[i-1]-'0';
			int x = c1*10+c2;
			if(x>9 && x<=26)
				dp[i]+=dp[i-2];
			if(c2!=0)
				dp[i]+=dp[i-1];
			//printf("X: %d Ans Till : %lld\n",x,dp[i]);

		}
		printf("%lld\n",dp[l]);
	}
}*/
//Recursive Definition
char s[5010];
int l;
long long int dp[5010];
long long int fr(int i)
{
	if(dp[i]!=-1)
		return dp[i];
	if(i==l-1 && s[i]!='0')
		return dp[i]=1;
	else if(i==l-1 && s[i]=='0')
		return dp[i]=0;
	if(i>=l)
	{
		return dp[i]= 1;
	}
	else
	{
		int f=0;
		f += fr(i+1);
		if(i<=l-2)
		{
			char c1 = s[i]-'0';
			char c2 = s[i+1]-'0';
			if(c1==1 || (c1==2 && c2>=0 && c2<=6))
				f += fr(i+2);
		}
		if(s[i]=='0')
			return dp[i] = 0;
		return dp[i]=f;
	}
}
int main()
{
	int i;
	while(1)
	{
		for (int i = 0; i < 5010; i++)
            dp[i] = -1;
		scanf("%s",s);
		l = strlen(s);
		if(s[0]=='0')
			break;
		printf("%lld\n",fr(0));
	}
	return 0;
}