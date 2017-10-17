#include <bits/stdc++.h>
using namespace std;
vector<string> v;

int main() {
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n; i++) {
		string s;
		cin>>s;
		int flag = 0;
		for(int i = 0; i < v.size(); i++) {
			if(v[i].compare(s) == 0) {
				printf("YES\n");
				flag = 1;
				break;
			}
		}
		v.push_back(s);
		if(!flag)
			printf("NO\n");
	}
	return 0;
}