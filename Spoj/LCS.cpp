#include <bits/stdc++.h>
using namespace std;
char a[1000000];
char b[1000000];

int ans(int al,int bl)
{
	if(al==-1 || bl==-1)
		return 0;
	int m = -1;
	if(a[al]==b[bl])
	{
		m = ans(al-1,bl-1)+1;
	}
	return max(m,max(ans(al-1,bl),ans(al,bl-1)));
}

int main()
{
	scanf("%s%s",a,b);
	int l1 = strlen(a);
	int l2 = strlen(b);
	int answer = ans(l1-1,l2-1);
	printf("%d\n",answer);
}