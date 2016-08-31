#include <bits/stdc++.h>
using namespace std;


int main()
{
	long long int t,i,j,k;
	scanf("%lld",&t);
	while(t--)
	{
		long long int m,n;
		scanf("%lld%lld",&m,&n);
		for(i=m;i<=n;i++)
		{
			long long int no = i;
			long long int ans=0;
			j = 2;
			//prlong long intf("SQRT %d\n",(long long int)sqrt(no));
			while(j<=(long long int)sqrt(no))
			{
				if(no%j==0)
				{
					ans++;
					if(j!=(no/j))
						ans++;
				}
				j++;
			}
			if(no==1)
				ans=1;
			if(ans==0)
				printf("%lld\n",i);
		}
		printf("\n");
	}
	return 0;
}