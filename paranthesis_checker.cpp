#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		string s;
		cin>>s;
		int l = s.length();
		stack<char> st;
		st.push(s[0]);
		for(int i = 1; i < l; i++) {
			if(st.empty()) {
				st.push(s[i]);
				continue;
			}
			char t = st.top();
			//cout<<t << "" <<s[i]<<endl;
			int flag = 1;
			if(s[i] == '}') {
				if(t == '{') {
					st.pop();
					flag = 0;
				}
			} else if(s[i] == ')') {
				if(t == '(') {
					st.pop();
					flag = 0;
				}
			} else if(s[i] == ']') {
				if(t == '[') {
					st.pop();
					flag = 0;
				}
			}
			if(flag)
				st.push(s[i]);
		}
		if(st.empty())
			printf("balanced\n");
		else
			printf("not balanced\n");
	}
}