//Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.

#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int dp[1001][1001]; //global declaration

int SCS_bottom_up_DP(string a, string b, int n, int m)
{
	for(int i=0;i<n+1;i++)          // substract length of longest common subsequence from combined string.
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
	
	return n+m-dp[n][m];
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
	
	cout<<SCS_bottom_up_DP(a,b,n,m);
	
	return 0;

}
