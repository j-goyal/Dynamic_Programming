//find length of longest common subsequence

#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int dp[1001][1001]; //global declaration

int LCS(string a, string b, int n, int m)         // recursion
{
	if(n==0 || m==0)
		return 0;
	
	if(a[n-1]==b[m-1])
		return 1+LCS(a,b,n-1,m-1);
	
	else
		return max( LCS(a,b,n-1,m), LCS(a,b,n,m-1) );
	
}

int LCS_DP(string a, string b, int n, int m)         // top down
{
	//int dp[n+1][m+1];
	//memset(dp,-1,sizeof(dp));
	
	if(n==0 || m==0)
		return 0;
	
	if(dp[n][m]!=-1)
		return dp[n][m];
	
	if(a[n-1]==b[m-1])
		return dp[n][m] = 1+LCS(a,b,n-1,m-1);
	
	else
		return dp[n][m] = max( LCS(a,b,n-1,m), LCS(a,b,n,m-1) );
	
			
}

int LCS_bottom_up_DP(string a, string b, int n, int m)         // bottom up
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
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[n][m];
}



int main() 
{ 

	string a,b;
	cin>>a>>b;
	//getline(cin,a);
	//getline(cin,b);
	
	int n = a.length();
	int m = b.length();
	
	memset(dp,-1,sizeof(dp));
	
	cout<<LCS(a,b,n,m)<<endl; 
	cout<<LCS_DP(a,b,n,m)<<endl;
	cout<<LCS_bottom_up_DP(a,b,n,m);
	
	return 0;

}
