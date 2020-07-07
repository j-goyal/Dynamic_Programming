#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int dp[1001][1001];

void LCS_bottom_up_DP(string a, string b, int n, int m)
{
	//int dp[n+1][m+1];
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
				
			else if(a[i-1]==b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			
			else if(a[i-1]!=b[j-1])
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	/*for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	int p=n;
	int q=m;
	vector<char> v;
	
	while(p>0 && q>0)
	{
		if(a[p-1]==b[q-1])
		{
			v.push_back(a[p-1]);         //store that character
			p--;
			q--;
		}
		else 
		{
			if (dp[p-1][q] > dp[p][q-1]) 
        		p--; 
			else
        		q--; 	
		}
	}
	
	reverse(v.begin(),v.end());
	
	for(int i=0;i<v.size();i++)
		cout<<v[i];
}

int main() 
{ 

	string a,b;
	cin>>a>>b;
	
	int n = a.length();
	int m = b.length();
	
	memset(dp,-1,sizeof(dp));
	
	LCS_bottom_up_DP(a,b,n,m);
	
	return 0;

}
