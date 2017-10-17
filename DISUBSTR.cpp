#include <bits/stdc++.h>
using namespace std;

string word;
int ans = 0;

class node {
public:
	node *edge[256];
};

node tree[1000010];
int tracker = 0;

node* create_node() {
	node *temp = &tree[tracker++];
	for (int i = 0; i < 256; ++i)
	{
		temp->edge[i] = NULL;
	}
	return temp;
}

void add_word(node *vertex, int index) {
	if(index != word.length()) {
		char k = word[index];
		if(vertex->edge[k] == NULL) {
			vertex->edge[k] = create_node();
		}
		add_word(vertex->edge[k], index+1);
	}
}

void dfs(node *root) {
	if(root != NULL) {
		for (int i = 0; i < 26; ++i)
		{
			if(root->edge[i] != NULL) {
				ans++;
				dfs(root->edge[i]);
			}
		}
	}
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		cin>>word;
		tracker = 0;
		node *root = create_node();
		for (int i = 0; i < word.length(); ++i)
		{
			add_word(root, i);
		}
		printf("%d\n", tracker-1);
	}
	return 0;
}