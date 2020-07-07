#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int fibo(int n)   // Using Recursion
{
	if(n==0 || n==1)
		return n;
	
	return fibo(n-1)+fibo(n-2);
}


int fibo_DP(int n, int *dp)  //Top down approach (Recursion + memoization)
{
	if(n==0 || n==1)
	{
		dp[n]=n;
		return n;
	}
	
	// Already computed
	if(dp[n]!=-1)
		return dp[n];
	
	else  // Compute and store
	{
		dp[n] = fibo_DP(n-1,dp)+fibo_DP(n-2,dp);
		return dp[n];	
	}	
}


int fibo_bottom_up(int n)      // Bottom Up 
{
	int *dp = new int[n+1];
	dp[0]=0;
	dp[1]=1;
	
	for(int i=2;i<=n;i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	int out = dp[n];
	
	delete[] dp;
	return out;
}

int main()
{
	int n;
	cin>>n;
	
	int dp[100];
	for(int i=0;i<100;i++)
	{
		dp[i]=-1;
	}
	
	cout<<fibo(n)<<" ";
	cout<<fibo_DP(n,dp)<<" ";
	cout<<fibo_bottom_up(n);
	return 0;
}
