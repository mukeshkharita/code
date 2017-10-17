#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int l, r, val;
};
int a[1000000];
node tree[1000000];
int track = 0;

int root[1000000];

int build(int l, int r) {
	track++;
	if(l == r) {
		tree[track].val = 0;
		return track;
	}
	int mid = (l+r)/2;
	tree[track].l = build(l,mid);
	tree[track].r = build(mid+1, r);
	tree[track].val = tree[tree[track].l].val + tree[tree[track].r].val;
	return track;
}

int update(int old, int s, int e, int l, int val) {
	track++;
	if(s==e) {
		tree[track].val = val;
		return track;
	}
	int mid = (s+e)/2;
	if(l <= mid) {
		tree[track].l = update(tree[old].l, s, mid, l, val);
		tree[track].r = tree[old].r;
	}
	else {
		tree[track].r = update(tree[old].r, mid+1, e, l, val);
		tree[track].l = tree[old].l;
	}
	tree[track].val = tree[tree[track].l].val + tree[tree[track].r].val;
	return track;
}

int query(int node, int s, int e, int l,int k) {
	if(e > l && s <= 0) {
		return 0;
	}
	if(s>=1 && e<=l) {
		return tree[node].val;
	}
	int mid = (s+e)/2;
	int p = query(tree[node].l, s, mid, l,k);
	int q = query(tree[node].r, mid+1, e, l, k);
	return p + q;
}

int main() {
	int m,n;
	int index = 0;
	scanf("%d%d",&n,&m);
	root[index++] = build(0,n-1);
	printf("%d\n", root[0]);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
		root[index++] = update(root[i], 0, n-1, i, a[i]);
		printf("%d\n", root[i+1]);
	}
	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		scanf("%d%d%d",&u,&v,&w);
		int q1 = 0,q2 = 0;
		if(u!=0) {
			q1 = query(root[u],0,n-1,u-1,w);
			q2 = query(root[v],0,n-1,v-1,w);
		}else {
			q1 = query(root[v],0,n-1,v-1,w);
		}
	}

}