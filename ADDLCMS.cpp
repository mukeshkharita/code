#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int hcf(int a,int b)
{
	if(b!=0)
		hcf(b%MOD,a%b);
	else
		return a%MOD;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int ans = 0;
		for (int i = a; i <= b; ++i)
		{
			ans  += ((i%MOD*b%MOD)%MOD/(hcf(i,b))%MOD)%MOD;
		}
		printf("%d\n",ans);
	}
}