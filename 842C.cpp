#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000010];
std::vector<int> v[1000000];

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	for (int i = 0; i < n-1; ++i)
	{
		int s,t;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
}