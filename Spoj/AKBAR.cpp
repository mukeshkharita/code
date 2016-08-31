#include <bits/stdc++.h>
using namespace std;
list<int> l[10000010];
list<int>::iterator it;
int guard[10000010];
int visited[10000010];
class node
{
public:
	int city,depth;
};

int bfs(int city,int strength)
{
	queue<node> q;
	node Obj;
	Obj.city = city;
	Obj.depth = 0;
	q.push(Obj);
	visited[city] = city;
	while(!q.empty())
	{
		node &n = q.front();
		q.pop();
	//	printf("City: %d Depth: %d Guard: %d Visited: %d\n",n.city,n.depth,guard[city]+1,visited[n.city]);
		if(n.depth>strength)
			break;
		guard[n.city]++;
	//	printf("Visited: %d\n",visited[n.city]);
		if(guard[n.city]>1)
		{
			return -1;
		}
		for(it=l[city].begin();it!=l[city].end();++it)
		{
			node newObj;
			newObj.city = *it;
			newObj.depth = n.depth+1;
			//printf("City: %d Visited1: %d\n",*it,visited[*it]);
			if(visited[*it]!=city)
			{
				visited[*it] = city;
				q.push(newObj);
			}
		}
	}
	return 0;
}

int main()
{
	int t,j,k;
	scanf("%d",&t);
	while(t--)
	{
		int n,r,m;
		scanf("%d%d%d",&n,&r,&m);
		memset(guard,0,sizeof(guard));
		memset(visited,0,sizeof(visited));
		for (int i = 0; i < n+10; ++i)
		{
			l[i].clear();
		}
		for (int i = 0; i < r; ++i)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			l[a].push_back(b);
			l[b].push_back(a);
		}
		int flag2=0;
		for (int i = 0; i < m; ++i)
		{
			int k,s;
			scanf("%d%d",&k,&s);
			int ans = bfs(k,s);
			if(ans==-1){
				//printf("Answer: %d\n",ans);
				flag2=1;
			}
		}
		if(flag2)
		{
			printf("No\n");
			continue;
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			if(guard[i]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("Yes\n");
		else
			printf("No\n");
		
	}
}