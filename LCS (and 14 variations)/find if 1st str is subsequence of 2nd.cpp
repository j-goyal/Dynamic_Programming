// Given two strings, find if first string is a subsequence of second

// we need to check only length of LCS with len of str1

#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int dp[1001][1001];

bool isSubsequence_bottom_up_DP(string a, string b, int n, int m)         // bottom up
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
	
	if(dp[n][m]==n)
		return true;
	else
		return false;
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
	
	cout<<isSubsequence_bottom_up_DP(a,b,n,m);
	
	return 0;

}
