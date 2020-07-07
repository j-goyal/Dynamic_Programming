#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int max_sum(int arr[],int n) //recursive
{
	if(n==1)
	{
		return arr[0];
	}
	
	if (n==2)
		return max(arr[0], arr[1]);
	
	
	return max(max_sum(arr,n-1), max_sum(arr,n-2) + arr[n-1]);  // include or dont include last element
} 

int max_sum_bottom_up(int arr[], int n)
{
	int dp[n]={0};   // return max sum with length upto i
	
	dp[0]=arr[0];
	dp[1]=max(arr[0],arr[1]);
	
	for(int i=2;i<n;i++)
	{
		dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
	}
	int res=0;
 for(int i=0;i<n;i++)
	{
		cout<<dp[i]<<" ";
		res = max(res,dp[i]);
	}
	
	cout<<endl;
	return res;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<max_sum(arr,n)<<" ";
	cout<<endl;
	cout<<max_sum_bottom_up(arr,n);
	return 0;
}
