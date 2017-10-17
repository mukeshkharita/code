#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int a = 1, b = 1, c = 2;
	for (int i = 3; i <= n; ++i)
	{
		int d = a + b + c;
		a = b;
		b = c;
		c = d;
	}
	printf("%d\n", c);

}