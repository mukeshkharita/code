#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		int l = s.length();
		string p;
		cin>>p;
		int lp = p.length();
		int flag=0,flag2=0;
		for(int i = 0; i < l; i++) 
		{
			int j;
		    for(j = 0; j < lp && i + j < l; j++) 
		    {
		    	//printf("%c %d\n",s[i+j],j);
		    	if(s[i+j]-p[j]==32 || (s[i+j]==p[j]))
		    		continue;
		    	else if(s[i+j]>='A' && s[i+j]<='Z')
		        {
		        	flag2 = 1;
		        	break;
		        }
		    	else if(s[i + j] != p[j])
		        	break;
		    }
		    if(j == lp)
		    {
		    	flag = 1;
		    	printf("YES\n");
		    	break;
		    }
		    if(flag2)
		    {
		    	printf("NO\n");
		    	break;
		    }
		    
		}
		if(!flag && !flag2)
		{
			printf("NO\n");
		}

	}
}