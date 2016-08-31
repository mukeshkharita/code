#include <bits/stdc++.h>
using namespace std;
int sieve[2000000];
int prime[1000000];
int main()
{
	
	long long int i,j,k;
	sieve[0]=sieve[1]=1;
	for(i=2;i<2000000;i++){
		if(sieve[i]==0){
			for(j=i+i;j<2000000;j+=i){
				if(sieve[j]==0)
					sieve[j]=1;
			}
		}
	}
	
	int count=0;
	for(i=2;i<2000000;i++){
		if(sieve[i]==0 )
			prime[count++]=i;
	}
	int count2=0;
	for(i=0;i<148933;i++)
	{
		if(sieve[i+1]==0)
		{
			printf("%d ",prime[i]);
			count2++;
		}
		if(count2==10000)
			break;
	}
	
	return 0;
}