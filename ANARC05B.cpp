/*
 * Copyright Mukesh Kumar Kharita(@kharita)
 SPOJ ANARC05B Problem using dp and binary search
*/

#include <bits/stdc++.h>
using namespace std;

long long int a[10010], b[10010], n, m;

long long int binary_search1(long long int target) {
	long long int lo = 0;
	long long int hi = m;
	while(lo <= hi) {
		long long int mid = (lo + hi) / 2;
		if(b[mid] == target)
			return mid;
		else if(b[mid] < target)
			lo = mid + 1;
		else 
			hi = mid - 1;
	}
	return -1;
}


int main() {
	while(1) {
		scanf("%lld",&n);
		if(n==0)
			break;
		long long int sum1[n];
		for (long long int i = 0; i < n; ++i)
		{
			scanf("%lld",&a[i]);
			if(i == 0)
				sum1[i] = a[i];
			else
				sum1[i] = sum1[i-1] + a[i];
		}
		scanf("%lld",&m);
		long long int sum2[m];
		for (long long int i = 0; i < m; ++i)
		{
			scanf("%lld",&b[i]);
			if(i == 0)
				sum2[i] = b[i];
			else
				sum2[i] = sum2[i-1] + b[i];
		}

		long long int index11 = 0, index12 = 0, index21 = 0, index22 = 0;
		long long int totalsum = 0;
		long long int temp1 = a[0], temp2 = b[0];
		for (long long int i = 0; i < n; ++i)
		{
			long long int returnvalue = binary_search1(a[i]);
			if(returnvalue != -1) {
				index12 = i;
				index22 = returnvalue;
				totalsum += max((sum1[index12]- sum1[index11] + temp1), (sum2[index22] - sum2[index21] + temp2));
				index11 = index12;
				index21 = index22;
				temp1 = temp2 = 0;
			}
		}
		totalsum += max((sum1[n-1]- sum1[index11]+temp1), (sum2[m-1] - sum2[index21]+temp2));
		printf("%lld\n", totalsum);
	}
	return 0;
}