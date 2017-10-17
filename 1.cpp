#include <bits/stdc++.h>
using namespace std;

int freq[256];
int freq2[256];

bool ans(string s1, string s2) {
	int l1 = s1.length();
	int l2 = s2.length();

	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

	for (int i = 0; i < l1; ++i)
	{
		char s = s1[i];
		if((s -'a' >= 0 && s-'a' <= 122) || (s-'0')>=0 && (s - '0') <= 9) {
			freq[s1[i]]++;
		}
	}

	for (int i = 0; i < l2; ++i)
	{
		char s = s2[i];
		if((s -'a' >= 0 && s-'a' <= 122) || (s-'0')>=0 && (s - '0') <= 9) {
			freq2[s2[i]]++;
		}
	}

	for (int i = 0; i < 256; ++i)
	{
		if(freq[i] != freq2[i])
			return false;
	}
	return true;
}

int main() {
	string s1;
	string s2;
	getline(std::cin,s1);
	getline(std::cin,s2);
	cout<<ans(s1,s2)<<endl;
}