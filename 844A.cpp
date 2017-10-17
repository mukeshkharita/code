#include <bits/stdc++.h>
using namespace std;

int freq[26];

int main() {
	string s;
	cin>>s;
	int n;
	cin>>n;
	int l = s.length();
	if(n > l) {
		printf("impossible\n");
	}
	else {
		for (int i = 0; i < 26; ++i)
		{
			freq[i] = 0;
		}
		for (int i = 0; i < l; ++i)
		{
			freq[s[i]-'a']++;
		}
		int count = 0;
		for (int i = 0; i < 26; ++i)
		{
			if(freq[i] != 0)
				count++;
		}
		if(n-count >= 0)
			printf("%d\n", n-count);
		else
			printf("0\n");
	}
	return 0;
}