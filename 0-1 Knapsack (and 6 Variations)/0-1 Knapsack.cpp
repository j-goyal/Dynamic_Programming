#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Recursion
int knapSack(int w, int wt[], int val[], int n)  
{
	if(w==0 || n==0)       // base condition (smallest valid input)
		return 0;
		
	if(wt[n-1]<=w)        // choice
	{
		return max(val[n-1] + knapSack(w-wt[n-1],wt,val,n-1), knapSack(w,wt,val,n-1));   // include or not include
	}
	
	else if(wt[n-1]>w)
	{
		return knapSack(w,wt,val,n-1);
	}		
}


// Top Down (Recursion + memoization)
int knapSack_DP(int w, int wt[], int val[], int n)   
{
	int dp[n+1][w+1];     // 2d matrix because n and w (2 variables) are changing in recursive calls
	memset(dp,-1,sizeof(dp));
	
	if(w==0 || n==0)     
		return 0;
	
	if(dp[n][w]!=-1)
		return dp[n][w];
	
	if(wt[n-1]<=w)        
	{
		dp[n][w] = max(val[n-1] + knapSack_DP(w-wt[n-1],wt,val,n-1), knapSack_DP(w,wt,val,n-1));  
	}
	
	else if(wt[n-1]>w)
	{
		dp[n][w] = knapSack_DP(w,wt,val,n-1);
	}
	
	return dp[n][w];	
}


// Bottom up
int knapSack_bottom_up(int w, int wt[], int val[], int n)          
{
/*  Try to think through recursion.
	Convert recursive code into iterative code.
*/	
	int dp[n+1][w+1];
		
	for(int i=0;i<n+1;i++)     // Recursion base condition used for intializing matrix
	{ 						   // i=n and j=w
		for(int j=0;j<w+1;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j]=0;
			}
				              
			else if(wt[i-1]<=j)              // Same as recursion, instead of recursive calls use dp matrix
			{
				dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
			}
						
			else if(wt[i-1]>j)
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}           

		
	for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= w; j++) 
          printf ("%4d", dp[i][j]); 
       printf("\n"); 
     }
	return dp[n][w];	
}

int main()
{
	int n=3;
	int val[] = {60, 100, 120};  
    int wt[] = {1, 2, 3};  
    int w = 5;  
          
    //cout<<knapSack(w, wt, val, n)<<endl;  
    //cout<<knapSack_DP(w, wt, val, n)<<endl;
	cout<<knapSack_bottom_up(w, wt, val, n);
	return 0;  

}
