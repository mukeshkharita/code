#include <bits/stdc++.h>
using namespace std;

typedef map<int, string> M;

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        map<string , int> m;
        int max1 = INT_MIN, max2 = INT_MIN;
        string s1;
        for(int i = 0; i < n; i++) {
            string s;
            cin>>s;
            m[s]++;
            if(m.at(s) > max1) {
                max1 = m.at(s);
            }
        }
        map<string , int>::iterator it;
        for (it = m.begin(); it != m.end() ; ++it)
        {
            if(it->second != max1) {
                if(it->second > max2) {
                    max2 = it->second;
                    s1 = it->first;
                }
            }
        }
        cout<<s1<<endl;
        
    }
	return 0;
}