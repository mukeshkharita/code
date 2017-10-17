#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> a;
int n;
long long int dp[100010];
#define MOD 1000000000
//Binary search to find index of ending time of the process
int next(int target) {
	int lo = 0;
	int hi = n - 1;
	while(lo < hi) {
		int mid = (lo + hi) / 2;
		if(a[mid].first >= target)
			hi = mid;
		else
			lo = mid + 1;
	}
	if(a[n-1].first < target) {
		return -1;
	}
	else
		return  lo;
}

//DP 
long long int solve(int x) {
	if(dp[x] != -1)
		return dp[x]%MOD;
	if(x >= n)
		return 0;
	int index = next(a[x].second);
	if(index != -1)
		dp[x] = (solve(x+1)%MOD + solve(index)%MOD + 1)%MOD;
	else
		dp[x] = (solve(x+1)%MOD + 1)%MOD;
	return dp[x]%MOD;

}


//Strting point of program
int main() {
	while(1) {
		for (int i = 0; i < 100010; ++i)
		{
			dp[i] = -1; 
		}
		scanf("%d",&n);
		if(n == -1)
			break;
		for (int i = 0; i < n; ++i)
		{
			int x,y;
			scanf("%d %d",&x, &y);
			a.push_back(make_pair(x,y));
		}
		sort(a.begin(), a.end());
		long long int ans = solve(0)%MOD;
		string s;
		for(int i = 0; i <= 7; i++) {
			s += ans % 10 + '0';
			ans = ans / 10;
		}
		reverse(s.begin(), s.end());
		cout <<  s << endl;
		a.clear();
	}
}