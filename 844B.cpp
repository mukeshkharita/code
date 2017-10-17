#include <bits/stdc++.h>
using namespace std;

long long int freq[51];

int main() {
	freq[0] = freq[1] = 0;
	freq[2] = 1;
	long long int c = 8;
	for (int i = 3; i < 100; ++i) {
		freq[i] = c - 1 - i;
		c = c * 2;
	}
	int m, n;
	scanf("%d%d",&m,&n);
	int a[m][n];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	//Row
	long long int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		int count2_0 = 0, count2_1 = 0;
		for (int j = 0; j < n; ++j)
		{
			if(a[i][j] == 0)
				count2_0++;
			else
				count2_1++;
		}
		ans += freq[count2_0] + freq[count2_1];
	}

	for (int i = 0; i < n; ++i)
	{
		int count2_0 = 0, count2_1 = 0;
		for (int j = 0; j < m; ++j)
		{
			if(a[j][i] == 0)
				count2_0++;
			else
				count2_1++;
		}
		ans += freq[count2_0] + freq[count2_1];
	}

	printf("%lld\n", ans + m*n);
	return 0;
}