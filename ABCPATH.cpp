#include <bits/stdc++.h>
using namespace std;
string s[200];
int arr1[8] = {-1,-1,-1,0,1,1,1,0};
int arr2[8] = {1,0,-1,-1,-1,0,1,1};
int r,c;
int dis[51][51];
void dfs(int indexX,int indexY,int dist)
{
	dis[indexX][indexY] = dist+1;
	for (int i = 0; i < 8; ++i)
	{
		int tempx = indexX+arr1[i];
		int tempy = indexY+arr2[i];
		//printf("TempX: %d TempY: %d\n", tempx,tempy);
		if(tempx>=0 && tempx <=r && tempy>=0 && tempy<=c)
		{
			char ch = s[tempx][tempy];
			if(ch == s[indexX][indexY]+1 && (dis[tempx][tempy]<dis[indexX][indexY]+1))
			{
				dfs(tempx,tempy,dis[indexX][indexY]);
			}
		}
	}		
}

int main()
{
	int t,i,j,k;
	t = 1;
	while(1)
	{
		int ans1 = 0;
		int flag=0;
		scanf("%d%d",&r,&c);
		if(r==0 && c==0)
			break;
		for (int i = 0; i < r; ++i)
		{
			//printf("%d\n",i);
			cin>>s[i];
			for (int j = 0; j < c; ++j)
			{
				dis[i][j] = 0;
			}
		}
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (s[i][j]=='A' && dis[i][j]==0)
				{
					dfs(i,j,0);
				}
			}
		}
		int max1 = dis[0][0];
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				if(max1 < dis[i][j])
					max1 = dis[i][j];
}
		printf("Case %d: %d\n",t++,max1);
		
	}
}