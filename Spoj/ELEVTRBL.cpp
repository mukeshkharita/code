#include <bits/stdc++.h>
using namespace std;
int f,s,g,u,d;
int visited[1000001];
class node
{
public:
	int num,depth;
};

int bfs()
{
	int i=-1;
	queue<node> q;
	node Obj;
	Obj.num = s;
	Obj.depth = 0;
	q.push(Obj);
	while(!q.empty())
	{
		node n = q.front();
		q.pop();
		if(n.num==g)
		{
			i = n.depth;
			break;
		}
		if(n.num-d>=1 && !visited[n.num-d])
		{
			visited[n.num-d] = 1;
			node newObj;
			newObj.num = n.num-d;
			newObj.depth = n.depth+1;
			q.push(newObj);
		}
		if(n.num+u<=f && !visited[n.num+u])
		{
			visited[n.num+u] = 1;
			node newObj;
			newObj.num = n.num+u;
			newObj.depth = n.depth+1;
			q.push(newObj);
		}
	}
	return i;
}

int main()
{
	scanf("%d%d%d%d%d",&f,&s,&g,&u,&d);
	int ans = bfs();
	if(ans==-1)
	{
		printf("use the stairs\n");
	}
	else
		printf("%d\n",ans);
}