#include <bits/stdc++.h>
using namespace std;

int main() {
	int l,r,x,y;
	float k;
	scanf("%d%d%d%d%f",&l,&r,&x,&y,&k);
	int flag = 0;
	for (int i = x; i <= y; ++i)
	{
		int ans = k * i;
		if(ans >= l && ans <= r) {
			printf("YES\n");
			flag = 1;
			break;
		}
	}
	if(!flag)
		printf("NO\n");
	return 0;
}