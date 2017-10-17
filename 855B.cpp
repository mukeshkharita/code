#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int n,a1,b1,c1;
	scanf("%lld %lld %lld %lld",&n,&a1,&b1,&c1);
	long long int mi[n];
	long long int ma[n];
	long long int mir[n];
	long long int mar[n];
	long long int a[n];
	long long int ans = LLONG_MIN;

	for (int i = 0; i < n; ++i) {
		mi[i] = INT_MAX;
		ma[i] = INT_MIN;
		mir[i] = INT_MAX;
		mar[i] = INT_MIN;
	}

	for (int i = 0; i < n; ++i) {
		scanf("%lld",&a[i]);
		if(i != 0) {
			mi[i] = min(mi[i-1],a[i]);
			ma[i] = max(ma[i-1],a[i]);
		} else {
			mi[0] = a[0];
			ma[0] = a[0];
		}
	}

	for (int i = n-1; i >= 0; --i) {
		if(i != n-1) {
			mir[i] = min(mir[i+1],a[i]);
			mar[i] = max(mar[i+1],a[i]);
		} else {
			mir[n-1] = a[n-1];
			mar[n-1] = a[n-1];
		}
	}

	// for (int i = 0; i < n; ++i) {
	// 	printf("%lld %lld %lld %lld\n", mi[i],ma[i],mir[i],mar[i]);
	// }

	for (int i = 0; i < n; ++i) {
		long long int temp2 = 0;
		long long int temp = a[i];
		temp2 += b1*temp;
		//printf("%lld %lld %lld %lld %lld\n", temp2, mi[i],ma[i],mir[i],mar[i]);
		if(a1 < 0) {
			temp2 += mi[i]*a1;
		} else {
			temp2 += ma[i]*a1;
		}
		if(c1 < 0) {
			temp2 += mir[i]*c1;
		} else {
			temp2 += mar[i]*c1;
		}
		ans = max(ans,temp2);
	}
	printf("%lld\n", ans);
	return 0;

}