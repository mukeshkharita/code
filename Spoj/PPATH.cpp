#include <bits/stdc++.h>
#include <cstdio.h>
using namespace std;
int a,b;
int sieve[10010];

class node
{
public:
	int num,depth;
};

int bfs()
{
	queue<node> q;
	node Obj;
	Obj.num = a;
	Obj.depth = 0;
	q.push(Obj);
	while(!q.empty())
	{
		node n = q.front();
		q.pop();
		int num = n.num;
		int depth = n.depth;
		//printf("Number: %d\n",num);
		if(num==b)
		{
			return depth;
		}
		node newObj;
		int firstDigit = num%10;
		int secondDigit = num/10;
		secondDigit%=10;
		int thirdDigit = num/100;
		thirdDigit%=10;
		int fourthDigit = num/1000;
		int duplicateNo;
		duplicateNo = fourthDigit*1000+thirdDigit*100+secondDigit*10;
		//printf("Duplicate: %d\n",duplicateNo);
		for(int i=0;i<=9;i++)
		{
			int newNumber = duplicateNo+i;
			//printf("Duplicate %d\n",newNumber);
			if(newNumber==b)
				return depth+1;
			if(newNumber!=num && sieve[newNumber]==0)
			{
				newObj.num = newNumber;
				newObj.depth = depth+1;
				q.push(newObj);
			}
		}
		duplicateNo = fourthDigit*1000+thirdDigit*100+firstDigit;
		for(int i=0;i<=9;i++)
		{
			int newNumber = duplicateNo+i*10;
			//printf("Duplicate %d\n",newNumber);
			if(newNumber==b)
				return depth+1;
			if(newNumber!=num && sieve[newNumber]==0)
			{
				newObj.num = newNumber;
				newObj.depth = depth+1;
				q.push(newObj);
			}
		}
		duplicateNo = fourthDigit*1000+secondDigit*10+firstDigit;
		for(int i=0;i<=9;i++)
		{
			int newNumber = duplicateNo+i*100;
			//printf("Duplicate %d\n",newNumber);
			if(newNumber==b)
				return depth+1;
			if(newNumber!=num && sieve[newNumber]==0)
			{
				newObj.num = newNumber;
				newObj.depth = depth+1;
				q.push(newObj);
			}
		}
		duplicateNo = thirdDigit*100+secondDigit*10+firstDigit;
		for(int i=1;i<=9;i++)
		{
			int newNumber = duplicateNo+i*1000;
			//printf("Duplicate %d\n",newNumber);

			if(newNumber!=num && sieve[newNumber]==0)
			{
				newObj.num = newNumber;
				newObj.depth = depth+1;
				q.push(newObj);
			}
		}
	}
	return -1;
}

int main()
{
	int t,i,j,k;
	for(i=2;i<=10010;i++)
	{
		if(sieve[i]==0)
		{
			for(j=i+i;j<=10010;j+=i)
			{
				sieve[j] = 1;
			}
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		int ans = bfs();
		printf("%d\n",ans);
	}
}
