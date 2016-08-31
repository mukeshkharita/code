#include <bits/stdc++.h>
using namespace std;
int sieve[100000];
int prime[10000];
int main()
{
	
	long long int i,j,k;
	sieve[0]=sieve[1]=1;
	for(i=2;i<100000;i++){
		if(sieve[i]==0){
			for(j=i+i;j<100000;j+=i){
				if(sieve[j]==0)
					sieve[j]=1;
			}
		}
	}
	
	int count=0;
	for(i=2;i<100000;i++){
		if(sieve[i]==0)
			prime[count++]=i;
	}	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int first,second;
		scanf("%lld%lld",&first,&second);
		for(i=first;i<=second;i++)
		{
			if(i<100000)
			{
				if(sieve[i]==0)
					printf("%lld\n",i);
			}
			else
			{
				for(j=0;j<count;j++)
				{
					if(i%prime[j]==0)
						break;
				}
				if(j==count)
					printf("%lld\n",i);
			}
		}
		printf("\n");
	}
	return 0;
}