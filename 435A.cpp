#include <bits/stdc++.h>
using namespace std;

int freq[1000];
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
		freq[a[i]]++;
	}

	int cnt = 0;
	for (int i = 0; i < k ; ++i) {
		if(freq[i] == 0)
			cnt++;
	}
	if(freq[k])
		cnt++;
	printf("%d\n", cnt);

	return 0;
}