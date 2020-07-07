//Given a sequence of matrices, find the most efficient way to multiply these matrices together

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int dp[1001][1001];

int solve(int arr[], int i, int j)     //recursion
{
	if(i>=j)
		return 0;
		
	int k;	
	int mini=INT_MAX;
	int count=0;
	
	for(k=i; k<=j-1; k++)         // we can also run for k=i+1, k<=j, then   (i to k-1) and (k to j) 
	{
		count = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];
		
		if(count < mini)
			mini = count;
	}
	
	return mini;
}

int solve_DP(int arr[], int i, int j)     //top down
{
	if(i>=j)
		return 0;
		
	if(dp[i][j]!= -1)
		return dp[i][j];
		
	int k;	
	int mini=INT_MAX;
	int count=0;
	
	for(k=i; k<=j-1; k++)         // we can also run for k=i+1, k<=j, then   (i to k-1) and (k to j) 
	{
		count = solve_DP(arr,i,k) + solve_DP(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];
		
		if(count < mini)
			mini = count;
	}
	
	return dp[i][j]=mini;
	
	//return dp[i][j];
}



int main()
{
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
          
	//cout<<solve(arr,1,n-1)<<endl;
	cout<<solve_DP(arr,1,n-1)<<endl;
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
		
	
	return 0;  

}
