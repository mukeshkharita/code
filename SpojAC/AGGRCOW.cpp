#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int n, k;

int isPossible(int x) {
	int cowsplaced = 1;
	int	last = a[0];
	for (int i = 1; i < n; ++i)
	{
		if(a[i]-last >= x) {
			if(++cowsplaced == k)
				return 1;
			last = a[i];
		}
	}
	return 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d",&n,&k);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&a[i]);
		}
		sort(a, a+n);
		int lo = 0;
		int hi = a[n-1] - a[0] + 1;
		while(lo < hi) {
			int mid = (lo + hi)/2;
			if(isPossible(mid) == 0)
				hi = mid;
			else
				lo = mid + 1;
		}
		printf("%d\n", lo-1);
	}
}