//find min no. of operations to make string equal (insertion,deletion,updation)

#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int dp[1001][1001]; //global declaration

int min(int a, int b, int c)
{
	if (a <= b && a <= c) 
        return a; 
  
    else if (b <= a && b <= c) 
        return b; 
  
    else
        return c; 
   
}

int edit_distance(string a, string b, int m, int n)         // recursion
{
	if(n==0)
		return m;
		
	else if(m==0)
		return n;
	
	if(a[m-1]==b[n-1])
		return edit_distance(a,b,n-1,m-1);
	
	else
		return 1 + min( edit_distance(a,b,m-1,n), edit_distance(a,b,m,n-1), edit_distance(a,b,n-1,m-1) );
	
}



int edit_distance_bottom_up_DP(string a, string b, int m, int n)         // bottom up
{
	//int dp[n+1][m+1];
	
	
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if (i == 0) 
                dp[i][j] = j;
                
            else if (j == 0) 
                dp[i][j] = i;
                
			else if(a[i-1]==b[j-1])
				dp[i][j] = dp[i-1][j-1];
			
			else if(a[i-1]!=b[j-1])
				dp[i][j] = 1 + min(dp[i-1][j], //remove
									 dp[i][j-1], //insert
									 dp[i-1][j-1]);  //replace
		}
	}
	
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<setw(4)<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return dp[m][n];
}



int main() 
{ 

	string a,b;
	cin>>a>>b;
	//getline(cin,a);
	//getline(cin,b);
	
	int m = a.length();
	int n = b.length();
	
	memset(dp,-1,sizeof(dp));
	
	//cout<<edit_distance(a,b,m,n)<<endl; 
	cout<<edit_distance_bottom_up_DP(a,b,m,n);
	
	return 0;

}
