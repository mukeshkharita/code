#include <bits/stdc++.h>
using namespace std;

int main() {
	int r,d;
	int n;
	scanf("%d%d",&r,&d);
	scanf("%d",&n);
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		int flag = 0;
		int x,y,ri;
		scanf("%d%d%d",&x,&y,&ri);
		double d1 = sqrt(x*x + y*y);
		if(((d1+ri) <= r) && ((d1-ri) >= (r-d)))
			count++;
	}
	printf("%d\n", count);
}