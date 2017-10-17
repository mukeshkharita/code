#include <bits/stdc++.h>
using namespace std;
int n, count1 = 1;
int c[100010];
int a[100010], b[100010];

vector<int> ans_arrays[100010];

int b_search(int target) {
	int lo = 0;
	int hi = n - 1 ;
	if(target == b[n-1])
		return n-1;
	while (lo <= hi) {
		int mid = (hi+lo)/2;
		//printf("%d\n", mid);
		if( target ==  b[mid]) {
			return mid;
		}
		else if(b[mid] < target) {
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	} 
}

int main() {
	scanf("%d",&n);
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
		b[i] = a[i];
		c[i] = 0;
	}
	sort(b, b+n);
	int ans = 0;
	int flag = true;
	for (int i = 0; i < n; ++i)
	{
		flag = true;
		int target = a[i];
		//printf("%d\n", a[i]);
		int in = i;
		while(c[in] == 0) {
			flag = false;
			c[in] = count1;
			ans_arrays[count1].push_back(in);
			int index = b_search(target);
			target = a[index];
			in = index;
		}
		if(!flag)
			count1++;
	}
	
	printf("%d\n", count1-1);
	for (int i = 1; i < count1; ++i)
	{
		ans = ans_arrays[i].size();
		printf("%d ", ans);
		for (int j = 0; j < ans; ++j)
		{
			printf("%d ", ans_arrays[i][j]+1);
		}
		printf("\n");
	}
	return 0;
}