#include <bits/stdc++.h>
using namespace std;
string s[200];
char a[10]={'A','L','L','I','Z','Z','W','E','L','L'};
int row,col;
int arr1[8] = {-1,-1,-1,0,1,1,1,0};
int arr2[8] = {1,0,-1,-1,-1,0,1,1};
bool visited[1000][1000];
int r,c;
int dfs(int indexX,int indexY,int patternIndex)
{
	int ans;
	visited[indexX][indexY] = true;
	if(patternIndex==9)
	{
		return 1;
	}
	else
	{
		for (int i = 0; i < 8; ++i)
		{
			int tempx = indexX+arr1[i];
			int tempy = indexY+arr2[i];
			//printf("TempX: %d TempY: %d\n", tempx,tempy);
			if(tempx>=0 && tempx <=r && tempy>=0 && tempy<=c)
			{
				char ch = s[tempx][tempy];
				if((ch == a[patternIndex+1]) && (!visited[tempx][tempy]))
				{
					visited[tempx][tempy] = true;
					ans  = dfs(tempx,tempy,patternIndex+1);
					if(ans==1)
					{
						return ans;
						visited[tempx][tempy] = 0;
					}
				}
			}
		}	
	}
	visited[indexX][indexY] = 0;
	return 0;
	
}

int main()
{
	int t,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		memset(visited, 0, sizeof(visited));
		int flag=0;
		scanf("%d%d",&r,&c);
		for (int i = 0; i < r; ++i)
		{
			//printf("%d\n",i);
			cin>>s[i];
		}
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (s[i][j]=='A')
				{
					int ans = dfs(i,j,0);
					if (ans)
					{
						printf("YES\n");
						flag=1;
						break;
					}
				}
			}
			if(flag)
				break;
		}
		if(!flag)
		{
			printf("NO\n");
		}
	}
}