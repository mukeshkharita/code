#include <bits/stdc++.h>
using namespace std;
int sieve[90000000];
int prime[9000000];
int main()
{
	
	long long int i,j,k;
	sieve[0]=sieve[1]=1;
	for(i=2;i<90000000;i++){
		if(sieve[i]==0){
			for(j=i+i;j<90000000;j+=i){
				if(sieve[j]==0)
					sieve[j]=1;
			}
		}
	}
	int count=0;
	for(i=2;i<90000000;i++){
		if(sieve[i]==0)
			prime[count++]=i;
	}
	//printf("%d\n",count);	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",prime[n-1]);
	}
	return 0;
}