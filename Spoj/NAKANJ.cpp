#include <bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2;
class node
{
public:
	int x,y,depth;
};

int bfs()
{
	queue<node> q;
	node Obj;
	Obj.x = a1;
	Obj.y = b1;
	Obj.depth = 0;
	q.push(Obj);
	while(!q.empty())
	{
		int x,y,depth;
		node n = q.front();
		q.pop();
		x = n.x;
		y = n.y;
		depth = n.depth;
		//printf("%d %d %d\n",x,y,depth);
		node newObj;
		if(x==a2 && y==b2)
		{
			return depth;
		}
		if(x+2==a2 && y+1==b2)
		{
			return depth+1;
		}
		if(x+2==a2 && y-1==b2)
		{
			return depth+1;
		}
		if(x-2==a2 && y+1==b2)
		{
			return depth+1;
		}
		if(x-2==a2 && y-1==b2)
		{
			return depth+1;
		}
		if(x+1==a2 && y+2==b2)
		{
			return depth+1;
		}
		if(x-1==a2 && y+2==b2)
		{
			return depth+1;
		}
		if(x+1==a2 && y-2==b2)
		{
			return depth+1;
		}
		if(x-1==a2 && y-2==b2)
		{
			return depth+1;
		}
		if(x+2>=0 && x+2<=7 && y+1>=0 && y+1<=7)
		{
			newObj.x = x+2;
			newObj.y = y+1;
			newObj.depth = depth+1;
			q.push(newObj);
		}
		if(x-2>=0 && x-2<=7 && y+1>=0 && y+1<=7)
		{
			newObj.x = x-2;
			newObj.y = y+1;
			newObj.depth = depth+1;
			q.push(newObj);
		}
		if(x+2>=0 && x+2<=7 && y-1>=0 && y-1<=7)
		{
			newObj.x = x+2;
			newObj.y = y-1;
			newObj.depth = depth+1;
			q.push(newObj);
		}
		if(x-2>=0 && x-2<=7 && y-1>=0 && y-1<=7)
		{
			newObj.x = x-2;
			newObj.y = y-1;
			newObj.depth = depth+1;
			q.push(newObj);
		}
		if(x+1>=0 && x+1<=7 && y+2>=0 && y+2<=7)
		{
			newObj.x = x+1;
			newObj.y = y+2;
			newObj.depth = depth+1;
			q.push(newObj);
		}
		if(x-1>=0 && x-1<=7 && y+2>=0 && y+2<=7)
		{
			newObj.x = x-1;
			newObj.y = y+2;
			newObj.depth = depth+1;
			q.push(newObj);
		}
		if(x+1>=0 && x+1<=7 && y-2>=0 && y-2<=7)
		{
			newObj.x = x+1;
			newObj.y = y-2;
			newObj.depth = depth+1;
			q.push(newObj);
		}
		if(x-1>=0 && x-1<=7 && y-2>=0 && y-2<=7)
		{
			newObj.x = x-1;
			newObj.y = y-2;
			newObj.depth = depth+1;
			q.push(newObj);
		}

	}
}

int main()
{
	int t,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		char a[200],b[200];
		scanf("%s%s",a,b);
		a1 = a[0]-'a';
		b1 = a[1]-'1';
		a2 = b[0]-'a';
		b2 = b[1]-'1';
		//printf("%d %d %d %d\n",a1,b1,a2,b2);
		int ans = bfs();
		printf("%d\n",ans);
	}
}