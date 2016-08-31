#include <bits/stdc++.h>
using namespace std;
#define MAX 10100
 
int adj[MAX][MAX],n;
int visited[MAX];
int flag=0;
 
void dfs(int source)
{
	visited[source]=1;
	int i;
	for(i=1;i<=n;i++)
	{
		if(a	azdj[source][i]==1)
		{
			if(visited[i]==1)
            {
               flag=1;
               break; 
            }
            if(visited[i]==0)
                dfs(i);
		}
        if(flag==1)
            break;
	}
}
 
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	int i,j,k;
	for(i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a][b] = 1;
	}
	dfs(1);
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
            flag=1;
    }
	if(flag==0)
		printf("YES");
	else
		printf("NO");
} 