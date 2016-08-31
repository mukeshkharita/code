#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int ans;
class node
{
public:
	int depth;
	int x,y;
	int pi;
};

node NewState(int a,int b,int s)
{
	node t;
	t.x = a;
	t.y = b;
	t.depth = s;
	return t;
}

int gcd(int a,int b)
{
	if(a>b) return(gcd(b,a));
	if(!a) return b;
	return gcd(b%a,a);
}
int b_afull[40001],b_aempty[40001],a_bfull[40001],a_bempty[40001];

int main()
{
	int t,i,j,k,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(c>a && c>b)
		{
			printf("-1\n");
			continue;
		}
		else if(c%gcd(a,b))
		{
			printf("-1\n");
			continue;
		}
		else
		{
			for(i=max(a,b);i>=0;i--)
			{
				b_afull[i] = b_aempty[i] = a_bfull[i] = a_bempty[i] = 0;
			}
			b_aempty[0] = a_bempty[0] = 1;
			queue<node> q;
			node init;
			init.x = init.y = init.depth = 0;
			q.push(init);
			while(!q.empty())
			{
				node *cur = &(q.front());
				q.pop();
				if(cur->x==c || cur->y==c)
				{
					temp = cur->depth;
					while(!q.empty())
						q.pop();
					break;
				}
				//Filling a
				if(!b_afull[cur->y])
				{
					b_afull[cur->y] = 1;
					if(cur->y==0)
					{
						a_bempty[a] = 1;
					}
					q.push(NewState(a,cur->y,cur->depth+1));
				}
				//Filling b
				if(!a_bfull[cur->x])
				{
					a_bfull[cur->x] = 1;
					if(cur->x==0)
					{
						b_aempty[b] = 1;
					}
					q.push(NewState(cur->x,b,cur->depth+1));
				}
				//Emptying a
				if(!b_aempty[cur->y])
				{
					b_aempty[cur->y] = 1;
					if(cur->y==b)
						a_bfull[0] = 1;
					q.push(NewState(0,cur->y,cur->depth+1));
				}
				//Emptying b
				if(!a_bempty[cur->x])
				{
					a_bempty[cur->x] = 1;
					if(cur->x==a)
						b_afull[0] = 1;
					q.push(NewState(cur->x,0,cur->depth+1));
				}
				//Pouring from a to b
				if(cur->y!=b && cur->x!=0)
				{
					if(cur->x < (b - cur -> y))
					{
						if(!b_aempty[cur->x+cur->y])
						{
							b_aempty[cur->x+cur->y] = 1;
							q.push(NewState(0,cur->x+cur->y,cur->depth+1));
						}
						
					}
					else if(cur->x == (b-cur->y))
					{
						if(!b_aempty[b])
						{
							b_aempty[b] = a_bfull[0] = 1;
							q.push(NewState(0,b,cur->depth+1));
						}
					}
					else
					{
						int x = cur->x+cur->y-b;
						if(!a_bfull[x])
						{
							a_bfull[x] = 1;
							q.push(NewState(x,b,cur->depth+1));
						}
					}
				}
				//Pouring from b to a
				if(cur->x!=a && cur->y!=0)
				{
					if(cur->y < (a - cur->x))
					{
						if(b_aempty[cur->y+cur->x])
						{
							a_bempty[cur->y+cur->x] = 1;
							q.push(NewState(cur->x+cur->y,0,cur->depth+1));
						}
					}
					else if(cur->y == (a - cur->x))
					{
						if(!a_bempty[b])
						{
							a_bempty[b] = b_afull[0] = 1;
							q.push(NewState(a,0,cur->depth+1));
						}
					}
					else
					{
						int x = cur->x+cur->y-a;
						if(!b_afull[x])
						{
							b_afull[x] = 1;
							q.push(NewState(a,x,cur->depth+1));
						}
					}
				}
				
			}
			
		}
		printf("%d\n",temp);
	}
	return 0;
}