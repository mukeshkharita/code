#include <bits/stdc++.h>
using namespace std;

int main()
{
	while(1)
	{
		float n;
		scanf("%f",&n);
		if(n==0.00)
			break;
		float ans=0.0;
		int count=0;
		for (int i = 2;; ++i)
		{
			ans+=1.0/i;
			count++;
			if(ans>=n)
				break;

		}
		printf("%d card(s)\n",count);
	}
}n