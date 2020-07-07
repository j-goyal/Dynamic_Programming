/*
You are given N floor and K eggs. You have to minimize the number of times you have to drop the eggs to find the critical floor 
where critical floor means the floor beyond which eggs start to break. Assumptions of the problem:

If egg breaks at ith floor then it also breaks at all greater floors.
If egg does not break at ith floor then it does not break at all lower floors.
Unbroken egg can be used again.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int dp[10001][10001];

int solve(int f, int e)
{
	if(f==0||f==1)
		return f;
		
	if(e==1)
		return f;
		
	int mini=INT_MAX;
	for(int k=1;k<=f;k++)
	{
		int temp = 1+max(solve(k-1,e-1), solve(f-k,e));
		
		if(temp<mini)
			mini=temp;
	}
	
	return mini;
}


int solve_DP(int f, int e)
{
	if(f==0||f==1)
		return f;
		
	if(e==1)
		return f;
	
	if(dp[f][e]!=-1)
		return dp[f][e];
		
	int mini=INT_MAX;
	for(int k=1;k<=f;k++)
	{
		int temp = 1+max(solve_DP(k-1,e-1), solve_DP(f-k,e));
		
		if(temp<mini)
			mini=temp;
	}
	
	return dp[f][e]=mini;
}


int solve_DP_opt(int f, int e)
{
	if(f==0||f==1)
		return f;
		
	if(e==1)
		return f;
	
	if(dp[f][e]!=-1)
		return dp[f][e];
		
	int mini=INT_MAX;
	int low,high;
	for(int k=1;k<=f;k++)
	{
		if(dp[k-1][e-1]!=-1)
			low = dp[k-1][e-1];
		else
		{
			low = solve_DP_opt(k-1,e-1);
			dp[k-1][e-1]=low;
		}

		if(dp[f-k][e]!=-1)
			high = dp[f-k][e];
		else
		{
			high = solve_DP_opt(f-k,e);
			dp[f-k][e]=high;
		}		
		
		int temp = 1+max(low,high);
		
		if(temp<mini)
			mini=temp;
	}
	
	return dp[f][e]=mini;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int F,E;
	cin>>F>>E;
	
	//cout<<solve(F,E)<<endl;
	cout<<solve_DP(F,E)<<endl;
	//cout<<solve_DP_opt(F,E);
	
	return 0;  

}
