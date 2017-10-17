#include <bits/stdc++.h>
using namespace std;
#define MAX 1005


int main() {
	int t;
	scanf("%d",&t);
	for (int k = 1; k <= t; ++k) {
		printf("Scenario #%d: ", k);
		int n,value;
		scanf("%d %d",&n,&value);
		int a[n];
		for (int i = 0; i < n; ++i) {
			scanf("%d",&a[i]);
		}
		int dp[n+1][value+1];
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= value; j++) {
				if(i == 0 || j == 0) {
					dp[i][j] = 0;
				} else if(i == 1) {
					if(j >= a[i-1]) {
						dp[i][j] = a[i-1];
					} else
						dp[i][j] = 0;
				} else if(a[i-1] <= j) {
					dp[i][j] = max(a[i-1] + dp[i-2][j-a[i-1]], dp[i-1][j]);
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i-2][j]);
				}
			}
		}
		printf("%d\n", dp[n][value]);
	}
	return 0;
}