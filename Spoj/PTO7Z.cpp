#include <bits/stdc++.h>
using namespace std;

int adj[10010][10010];
int visited[10010];
int n;
int pathLength;
int dfs(int source)
{
	//printf("%d\n",source);
	int m1=-1,m2=-1,m;
	visited[source] = 1;
	for (int i = 0; i <=10010 ; ++i)
	{
		if(adj[source][i]!=0 && visited[i]==0)
		{
			m = dfs(i);
			if(m>=m1)
			{
				m2=m1;
				m1=m;
			}	
			else if(m>m2)
			{
				m2=m;
			}
		}
	}
	pathLength = max(pathLength,m1+m2+2);
	return m1+1;
}

int main()
{
	
	scanf("%d",&n);
	int d;
	for (int i = 1; i < n; ++i)
	{
		int a,b;
		d=a;
		scanf("%d%d",&a,&b);
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	dfs(d);
	printf("%d\n",pathLength);
}