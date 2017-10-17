#include <bits/stdc++.h>
using namespace std;

int flag = 1, flag2 = 1;

class node {
public:
	int word;
	node *edge[10];
};

node* initialize() {
	node *temp = new node();
	temp->word = 0;
	for (int i = 0; i < 10; ++i)
	{
		temp->edge[i] = NULL;
	}
	return temp;
}

void add_word(node *vertex, string word) {
	if(word.length() == 0) {
		vertex->word = vertex->word + 1;
		for (int i = 0; i < 10; ++i)
		{
			if(vertex->edge[i] != NULL)
				flag = 0;
		}
	}
	else {
		char k = word[0];
		if(vertex->word != 0) {
			flag2 = 0;
		} 
		if(vertex->edge[k-'0'] == NULL) {
			vertex->edge[k-'0'] = initialize();
		}
		word.erase(word.begin());
		add_word(vertex->edge[k-'0'], word);
	}
}


int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		flag = 1, flag2 = 1;
		int n;
		node *root = initialize();
		scanf("%d",&n);
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin>>s;
			add_word(root, s);
		}
		if(flag2 == 0 || flag == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
}