//Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. 
// find min. no. of such cuts (for 1 cut we got 2 partitions)

#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int dp[1001][1001];

bool isPalindrome(string a, int i, int j)
{
	while(i<j)
	{
		if(a[i]!=a[j])
			return false;
		i++;
		j--;
	}
	
	return true;
}

int solve(string a, int i, int j)   //recursion
{
	if(i>=j)
		return 0;
		
	if(isPalindrome(a,i,j))
		return 0;
		
	int k;
	int res = 0;
	int mini = INT_MAX;
	
	for(k=i;k<=j-1;k++)
	{
		res = solve(a,i,k) + solve(a,k+1,j) + 1;
		
		if(res<mini)
			mini=res;
	}
	
	return mini;
}

int solve_DP(string a, int i, int j)   //topdown
{
	if(i>=j)
		return 0;
		
	if(isPalindrome(a,i,j))
		return 0;
	
	if(dp[i][j]!= -1)
		return dp[i][j];
			
	int k;
	int res=0;
	int mini = INT_MAX;
	
	for(k=i;k<=j-1;k++)
	{
		res = solve_DP(a,i,k) + solve_DP(a,k+1,j) + 1;
		
		if(res<mini)
			mini=res;
	}
	
	return dp[i][j]=mini;
}

int solve_DP_opt(string a, int i, int j)    // topdown+optimized
{
	if(i>=j)
		return 0;
		
	if(isPalindrome(a,i,j))
		return 0;
	
	if(dp[i][j]!= -1)
		return dp[i][j];
			
	int k;
	int res=0;
	int mini = INT_MAX;
	int left,right;
	
	for(k=i;k<=j-1;k++)
	{		
		if(dp[i][k]!=-1)            // do not need to calculate left and right again and again if already computed
			left = dp[i][k];
		else
		{
			left = solve_DP_opt(a,i,k);
			dp[i][k] = left;
		}
			
			
		if(dp[k+1][j]!=-1)
			right = dp[k+1][j];
		else
		{
			right = solve_DP_opt(a,k+1,j);
			dp[k+1][j] = right;
		}	
		
		res = left + right + 1;	
					
		if(res<mini)
			mini=res;
	}
	
	return dp[i][j]=mini;
}



int main()
{
	memset(dp,-1,sizeof(dp));
      
	string a;
	cin>>a;      
	
	int n = a.length();
	//cout<<solve(a,0,n-1)<<endl;
	cout<<solve_DP(a,0,n-1)<<endl;
	cout<<solve_DP_opt(a,0,n-1)<<endl;

	
	return 0;  

}
