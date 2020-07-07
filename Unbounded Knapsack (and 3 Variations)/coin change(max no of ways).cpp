// max no of ways for making given sum using given coin of array

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int max_way_DP(int coin[], int n, int sum)  //Bottom up dp
{
	int dp[n+1][sum+1];
	
	for(int i=0;i<n+1;i++)         // same as subset sum problem (but unbounded)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(j==0)
				dp[i][j]=1;
				
			else if(i==0 && j!=0)
				dp[i][j]=0;
			
			else if(coin[i-1]<=j)
				dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
			
			else if(coin[i-1]>j)
				dp[i][j] = dp[i-1][j];
		}
	}
	
	for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          printf ("%4d", dp[i][j]); 
       printf("\n"); 
     }
	
	return dp[n][sum];
}

int main()
{
	int n=3;
	int coin[]={3,2,1};
	int sum=5;
	cout<<max_way_DP(coin,n,sum);
	return 0;  

}
